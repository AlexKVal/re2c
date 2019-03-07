#!/bin/bash

set -e

if [ $# -ne 1 ]
then
    echo "usage: ./distcheck.sh <builddir>"
    exit 1
fi
builddir="$1"

autoreconf -i -W all

# try to be portable on various MAKEs
for make_prog in make bmake
do
    rm -rf $builddir
    mkdir $builddir
    cd $builddir
        # 'make' implies 'make docs'; running both in parallel may cause data races
        # configure without --enable-debug, this is the release binary
        ../configure --enable-docs --enable-libs \
        && $make_prog bootstrap -j5 \
        && $make_prog distcheck -j5
    cd ..
done
