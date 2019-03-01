#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "src/debug/debug.h"
#include "src/dfa/determinization.h"
#include "src/dfa/dfa.h"
#include "src/dfa/tcmd.h"
#include "src/nfa/nfa.h"
#include "src/regexp/rule.h"
#include "src/util/hash32.h"


namespace re2c
{

/* note [mapping ignores items with lookahead tags]
 *
 * Consider two items X and Y being mapped.
 *
 * If tag T belongs to lookahead tags of item X, then all
 * outgoing transitions from item X update T. Which means
 * that it doesn't matter what particular version T has in X:
 * whatever version it has, it will be overwritten by any
 * outgoing transition.
 *
 * Note that lookahead tags are identical for both items
 * X and Y, because we only try to map DFA states with
 * identical lookahead tags.
 */


/* note [save(X), copy(Y,X) optimization]
 *
 * save(X) command followed by a copy(Y,X) command can be optimized to
 * save(Y). This helps reduce the number commands and versions (new version
 * X is gone), but what is more important, it allows to put copy commands
 * in front of save commands. This order is necessary when it comes to
 * fallback commands.
 *
 * Note that in case of injective mapping there may be more than one copy
 * command matching the same save command: save(X), copy(Y,X), copy(Z,X).
 * In this case save command must be replicated for each copy command:
 * save(Y), save(Z).
 *
 * For each save(X) command there must be at least one copy(Y,X) command
 * (exactly one case of bijective mapping). This is because X version in
 * save(X) command must be a new version which cannot occur in the older
 * DFA state. Thus all save commands are transformed (maybe replicated) by
 * copy commands, and some copy commands are erased by save commands.
 *
 * This optimization is applied after checking priority violation, so it
 * cannot affect the check.
*/


/* note [bijective mappings]
 *
 * Suppose we have just constructed a new DFA state Y and want to map it
 * to an existing DFA state X. States must have identical sets of NFA
 * substates and identical sets of lookahead tags for each substate.
 * Furtermore, there must be bijective mapping between versions of X and Y
 * and this mapping must preserve version order (respect priorities).
 *
 * Bijective mappings have a nice property: there is only one possible state
 * X to which Y can be mapped. Indeed, if there was another state Z that
 * can be bijectively mapped to Y preserving priorities, then Z itself can
 * be mapped to X: both (1) and (2) are symmetrical in case of bijection
 * and the relation is transitive. So the existence of Z is a contradiction.
 *
 * In principle, non-bijective mappings are also possible if the new state
 * is less versatile than the old one (surjection from X to Y). However,
 * non-bijective mappings lack the 'unique counterpart' property and need
 * more complex analysis (and are not so useful after all), so we drop them.
 */


struct kernel_eq_t
{
    determ_context_t &ctx;
    bool operator()(const kernel_t *, const kernel_t *) const;
};


struct kernel_map_t
{
    determ_context_t &ctx;
    bool operator()(const kernel_t *, const kernel_t *);
};


static kernel_t *make_new_kernel(size_t, allocator_t &);
static kernel_t *make_kernel_copy(const kernel_t *, allocator_t &);
static void copy_to_buffer_kernel(const closure_t &, const prectable_t *, kernel_t *);
static void reserve_buffers(determ_context_t &);
static uint32_t hash_kernel(const kernel_t *kernel);
static bool equal_lookahead_tags(determ_context_t &, const kernel_t *, const kernel_t *);
static void group_by_tag(tag_path_t &path, tag_path_t &buf, std::vector<uint32_t> &count);
static void unwind(const tag_history_t &hist, tag_path_t &path, hidx_t idx);
static bool do_find_state(determ_context_t &ctx);
static tcmd_t *final_actions(determ_context_t &ctx, const clos_t &fin);


void find_state(determ_context_t &ctx)
{
    dfa_t &dfa = ctx.dc_dfa;

    // find or add the new state in the existing set of states
    const bool is_new = do_find_state(ctx);

    if (is_new) {
        // create new DFA state
        dfa_state_t *t = new dfa_state_t(dfa.nchars);
        dfa.states.push_back(t);

        // check if the new state is final
        // see note [at most one final item per closure]
        cclositer_t
            b = ctx.dc_closure.begin(),
            e = ctx.dc_closure.end(),
            f = std::find_if(b, e, clos_t::fin);
        if (f != e) {
            t->tcmd[dfa.nchars] = final_actions(ctx, *f);
            t->rule = f->state->rule;
        }
    }

    if (ctx.dc_origin == dfa_t::NIL) {
        // initial state
        dfa.tcmd0 = ctx.dc_actions;
    }
    else {
        dfa_state_t *s = dfa.states[ctx.dc_origin];
        s->arcs[ctx.dc_symbol] = ctx.dc_target;
        s->tcmd[ctx.dc_symbol] = ctx.dc_actions;
    }

    DDUMP_DFA_RAW(ctx, is_new);
}


bool do_find_state(determ_context_t &ctx)
{
    kernels_t &kernels = ctx.dc_kernels;
    const closure_t &closure = ctx.dc_closure;

    // empty closure corresponds to default state
    if (closure.size() == 0) {
        ctx.dc_target = dfa_t::NIL;
        ctx.dc_actions = NULL;
        return false;
    }

    // resize buffer if closure is too large
    reserve_buffers(ctx);
    kernel_t *k = ctx.dc_buffers.kernel;

    // copy closure to buffer kernel
    copy_to_buffer_kernel(closure, ctx.dc_prectbl, k);

    // hash "static" part of the kernel
    const uint32_t hash = hash_kernel(k);

    // try to find identical kernel
    kernel_eq_t cmp_eq = {ctx};
    ctx.dc_target = kernels.find_with(hash, k, cmp_eq);
    if (ctx.dc_target != kernels_t::NIL) return false;

    // else try to find mappable kernel
    // see note [bijective mappings]
    kernel_map_t cmp_map = {ctx};
    ctx.dc_target = kernels.find_with(hash, k, cmp_map);
    if (ctx.dc_target != kernels_t::NIL) return false;

    // otherwise add new kernel
    kernel_t *kcopy = make_kernel_copy(k, ctx.dc_allocator);
    ctx.dc_target = kernels.push(hash, kcopy);
    return true;
}


tcmd_t *final_actions(determ_context_t &ctx, const clos_t &fin)
{
    dfa_t &dfa = ctx.dc_dfa;
    const Rule &rule = dfa.rules[fin.state->rule];
    const tagver_t *vers = ctx.dc_tagvertbl[fin.tvers];
    const hidx_t look = fin.tlook;
    const tag_history_t &thist = ctx.dc_taghistory;
    tcpool_t &tcpool = dfa.tcpool;
    tcmd_t *copy = NULL, *save = NULL, **p;

    for (size_t t = rule.ltag; t < rule.htag; ++t) {

        const Tag &tag = dfa.tags[t];
        if (fixed(tag)) continue;

        const tagver_t v = abs(vers[t]), l = thist.last(look, t);
        tagver_t &f = dfa.finvers[t];
        if (l == TAGVER_ZERO) {
            copy = tcpool.make_copy(copy, f, v);
        } else if (history(tag)) {
            save = tcpool.make_add(save, f, v, thist, look, t);
        } else {
            save = tcpool.make_set(save, f, l);
        }
    }

    // join 'copy' and 'save' commands
    for (p = &copy; *p; p = &(*p)->next);
    *p = save;

    return copy;
}


kernel_buffers_t::kernel_buffers_t(allocator_t &alc)
    : maxsize(0) // usually ranges from one to some twenty
    , kernel(make_new_kernel(maxsize, alc))
    , cap(0)
    , max(0)
    , memory(NULL)
    , x2y(NULL)
    , y2x(NULL)
    , x2t(NULL)
    , indegree(NULL)
    , backup_actions(NULL)
{}


kernel_t *make_new_kernel(size_t size, allocator_t &alc)
{
    kernel_t *k = alc.alloct<kernel_t>(1);
    k->size = size;
    k->prectbl = NULL;
    k->state = alc.alloct<nfa_state_t*>(size);
    k->tvers = alc.alloct<uint32_t>(size);
    k->tlook = alc.alloct<hidx_t>(size);
    return k;
}


kernel_t *make_kernel_copy(const kernel_t *kernel, allocator_t &alc)
{
    const size_t n = kernel->size;

    kernel_t *k = make_new_kernel(n, alc);

    memcpy(k->state, kernel->state, n * sizeof(void*));
    memcpy(k->tvers, kernel->tvers, n * sizeof(uint32_t));
    memcpy(k->tlook, kernel->tlook, n * sizeof(hidx_t));

    prectable_t *ptbl = NULL;
    if (kernel->prectbl) {
        ptbl = alc.alloct<prectable_t>(n * n);
        memcpy(ptbl, kernel->prectbl, n * n * sizeof(prectable_t));
    }
    k->prectbl = ptbl;

    return k;
}


uint32_t hash_kernel(const kernel_t *kernel)
{
    const size_t n = kernel->size;

    // seed
    uint32_t h = static_cast<uint32_t>(n);

    // TNFA states
    h = hash32(h, kernel->state, n * sizeof(void*));

    // precedence table
    if (kernel->prectbl) {
        h = hash32(h, kernel->prectbl, n * n * sizeof(prectable_t));
    }

    return h;
}


void copy_to_buffer_kernel(const closure_t &closure,
    const prectable_t *prectbl, kernel_t *buffer)
{
    const size_t n = closure.size();

    buffer->size = n;

    buffer->prectbl = prectbl;

    for (size_t i = 0; i < n; ++i) {
        const clos_t &c = closure[i];
        buffer->state[i] = c.state;
        buffer->tvers[i] = c.tvers;
        buffer->tlook[i] = c.tlook;
    }
}


void reserve_buffers(determ_context_t &ctx)
{
    kernel_buffers_t &kbufs = ctx.dc_buffers;
    allocator_t &alc = ctx.dc_allocator;
    const tagver_t maxver = ctx.dc_dfa.maxtagver;
    const size_t nkern = ctx.dc_closure.size();

    if (kbufs.maxsize < nkern) {
        kbufs.maxsize = nkern * 2; // in advance
        kbufs.kernel = make_new_kernel(kbufs.maxsize, alc);
    }

    // +1 to ensure max tag version is not forgotten in loops
    kbufs.max = maxver + 1;
    if (kbufs.cap < kbufs.max) {
        kbufs.cap = kbufs.max * 2; // in advance

        const size_t
            n = static_cast<size_t>(kbufs.cap),
            m = 2 * n + 1,
            sz_x2y = 2 * m * sizeof(tagver_t),
            sz_x2t = m * sizeof(size_t),
            sz_idg = n * sizeof(uint32_t),
            sz_act = n * sizeof(tcmd_t);

        char *p = alc.alloct<char>(sz_x2y + sz_x2t + sz_idg + sz_act);
        kbufs.memory = p;

        // point to the center (zero index) of each buffer
        // indexes in range [-N .. N] must be valid, where N is capacity
        kbufs.x2y = reinterpret_cast<tagver_t*>(p) + n;
        kbufs.y2x = kbufs.x2y + m;
        p += sz_x2y;
        kbufs.x2t = reinterpret_cast<size_t*>(p) + n;
        p += sz_x2t;
        kbufs.indegree = reinterpret_cast<uint32_t*>(p);
        p += sz_idg;
        kbufs.backup_actions = reinterpret_cast<tcmd_t*>(p);
    }
}


bool equal_lookahead_tags(determ_context_t &ctx
    , const kernel_t *x, const kernel_t *y)
{
    DASSERT(x->size == y->size);

    if (memcmp(x->tlook, y->tlook, x->size * sizeof(hidx_t)) == 0) {
        return true;
    }

    tag_history_t &thist = ctx.dc_taghistory;
    tag_path_t &p1 = ctx.dc_path1, &p2 = ctx.dc_path2, &p3 = ctx.dc_path3;
    std::vector<uint32_t> &count = ctx.dc_tagcount;

    for (size_t i = 0; i < x->size; ++i) {
        const hidx_t xl = x->tlook[i], yl = y->tlook[i];

        if (xl == yl) continue;

        unwind(thist, p1, xl);
        unwind(thist, p2, yl);

        if (p1.size() != p2.size()) return false;

        group_by_tag(p1, p3, count);
        group_by_tag(p2, p3, count);

        if (p1 != p2) return false;
    }

    return true;
}


void group_by_tag(tag_path_t &path, tag_path_t &buf, std::vector<uint32_t> &count)
{
    // counting sort with tag index as key
    // must preserve relative order of elements with the same tag

    const size_t clen = count.size(), plen = path.size();
    std::fill(count.begin(), count.end(), 0);
    buf.resize(plen);

    for (size_t i = 0; i < plen; ++i) {
        ++count[path[i].idx];
    }

    for (size_t i = 1; i < clen; ++i) {
        count[i] += count[i - 1];
    }

    for (size_t i = plen; i --> 0; ) {
        buf[--count[path[i].idx]] = path[i];
    }

    path.swap(buf);
}


void unwind(const tag_history_t &hist, tag_path_t &path, hidx_t idx)
{
    // Simple tags need only the last value, so in principle we could
    // increase the chance of mapping by recording only the last value.
    // But this would complicate unwind procedure quite a bit, and the
    // cases when it makes any difference are rare.
    path.clear();
    for (; idx != HROOT; ) {
        const tag_history_t::node_t &n = hist.node(idx);
        path.push_back(n.info);
        idx = n.pred;
    }
}


bool kernel_eq_t::operator()(const kernel_t *x, const kernel_t *y) const
{
    // check that kernel sizes, NFA states, tags versions,
    // lookahead tags and precedence table coincide
    const size_t n = x->size;
    return n == y->size
        && memcmp(x->state, y->state, n * sizeof(void*)) == 0
        && memcmp(x->tvers, y->tvers, n * sizeof(uint32_t)) == 0
        && (!x->prectbl || memcmp(x->prectbl, y->prectbl, n * n * sizeof(prectable_t)) == 0)
        && equal_lookahead_tags(ctx, x, y);
}


bool kernel_map_t::operator()(const kernel_t *x, const kernel_t *y)
{
    // check that kernel sizes, NFA states lookahead tags
    // and precedence table coincide (versions might differ)
    const size_t n = x->size;
    const bool compatible = n == y->size
        && memcmp(x->state, y->state, n * sizeof(void*)) == 0
        && (!x->prectbl || memcmp(x->prectbl, y->prectbl, n * n * sizeof(prectable_t)) == 0)
        && equal_lookahead_tags(ctx, x, y);
    if (!compatible) return false;

    const std::vector<Tag> &tags = ctx.dc_dfa.tags;
    const size_t ntag = tags.size();
    kernel_buffers_t &bufs = ctx.dc_buffers;
    tagver_t *x2y = bufs.x2y, *y2x = bufs.y2x, max = bufs.max;
    size_t *x2t = bufs.x2t;

    // map tag versions of one kernel to that of another
    // and check that lookahead versions (if any) coincide
    std::fill(x2y - max, x2y + max, TAGVER_ZERO);
    std::fill(y2x - max, y2x + max, TAGVER_ZERO);
    for (size_t i = 0; i < n; ++i) {
        const tagver_t
            *xvs = ctx.dc_tagvertbl[x->tvers[i]],
            *yvs = ctx.dc_tagvertbl[y->tvers[i]];
        const hidx_t xl = x->tlook[i];

        for (size_t t = 0; t < ntag; ++t) {
            // see note [mapping ignores items with lookahead tags]
            if (!history(tags[t])
                && ctx.dc_taghistory.last(xl, t) != TAGVER_ZERO) continue;

            const tagver_t xv = xvs[t], yv = yvs[t];
            tagver_t &xv0 = y2x[yv], &yv0 = x2y[xv];

            if (yv0 == TAGVER_ZERO && xv0 == TAGVER_ZERO) {
                xv0 = xv;
                yv0 = yv;
                x2t[xv] = t;
            } else if (yv != yv0 || xv != xv0) {
                return false;
            }
        }
    }

    // we have bijective mapping; now try to create list of commands
    tcmd_t **pacts = &ctx.dc_actions, *a, **pa, *copy = NULL;
    tcmd_t *b1 = bufs.backup_actions, *b2 = b1;

    // backup 'save' commands: if topsort finds cycles, this mapping
    // will be rejected and we'll have to revert all changes
    for (b2->next = a = *pacts; a; a = a->next) {
        *++b2 = *a;
    }

    // fix LHS of 'save' commands to reuse old version
    // see note [save(X), copy(Y,X) optimization]
    for (a = *pacts; a; a = a->next) {
        const tagver_t
            yv = a->lhs * (a->history[0] == TAGVER_BOTTOM ? -1 : 1),
            xv = y2x[yv];
        a->lhs = abs(xv);
        y2x[yv] = x2y[xv] = TAGVER_ZERO;
    }

    // create 'copy' commands
    for (tagver_t xv = -max; xv < max; ++xv) {
        const tagver_t yv = x2y[xv], axv = abs(xv), ayv = abs(yv);
        if (yv != TAGVER_ZERO && xv != yv && !fixed(tags[x2t[xv]])) {
            DASSERT(axv != ayv);
            copy = ctx.dc_dfa.tcpool.make_copy(copy, axv, ayv);
        }
    }

    // join 'copy' and 'save' commands
    for (pa = &copy; (a = *pa); pa = &a->next);
    *pa = *pacts;
    *pacts = copy;

    // see note [topological ordering of copy commands]
    const bool nontrivial_cycles = tcmd_t::topsort(pacts, bufs.indegree);

    // in case of cycles restore 'save' commands and fail
    if (nontrivial_cycles) {
        for (*pacts = a = b1->next; a; a = a->next) {
            *a = *++b1;
        }
    }

    return !nontrivial_cycles;
}

} // namespace re2c
