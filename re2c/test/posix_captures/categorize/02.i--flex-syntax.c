/* Generated by re2c */

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		yyt1 = yyt2 = yyt3 = YYCURSOR;
		goto yy3;
	case 'b':
		yyt3 = yyt4 = NULL;
		yyt1 = yyt2 = yyt5 = YYCURSOR;
		goto yy5;
	default:
		yyt3 = yyt4 = NULL;
		yyt1 = yyt2 = yyt5 = yyt6 = YYCURSOR;
		goto yy2;
	}
yy2:
	{
		const size_t yynmatch = 7;
		const YYCTYPE *yypmatch[yynmatch * 2];
		yypmatch[4] = yyt1;
		yypmatch[5] = yyt2;
		yypmatch[6] = yyt3;
		yypmatch[7] = yyt4;
		yypmatch[10] = yyt5;
		yypmatch[12] = yyt6;
		yypmatch[0] = yyt1;
		yypmatch[1] = YYCURSOR;
		yypmatch[2] = yyt1;
		yypmatch[3] = yyt5;
		yypmatch[8] = yyt5;
		yypmatch[9] = YYCURSOR;
		yypmatch[11] = yyt6;
		yypmatch[13] = YYCURSOR;
		{}
	}
yy3:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		yyt2 = yyt3 = YYCURSOR;
		goto yy3;
	case 'b':	goto yy7;
	default:
		yyt3 = yyt4 = NULL;
		yyt2 = yyt5 = yyt6 = YYCURSOR;
		goto yy2;
	}
yy5:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		yyt6 = YYCURSOR;
		goto yy8;
	case 'b':	goto yy5;
	default:
		yyt6 = YYCURSOR;
		goto yy2;
	}
yy7:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		yyt4 = yyt5 = yyt6 = YYCURSOR;
		goto yy10;
	case 'b':
		yyt4 = yyt5 = YYCURSOR;
		goto yy5;
	default:
		yyt4 = yyt5 = yyt6 = YYCURSOR;
		goto yy2;
	}
yy8:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy8;
	default:	goto yy2;
	}
yy10:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy8;
	case 'b':
		yyt3 = yyt4;
		goto yy7;
	default:	goto yy2;
	}
}

re2c: warning: line 5: rule matches empty string [-Wmatch-empty-string]
re2c: warning: line 6: rule matches empty string [-Wmatch-empty-string]
re2c: warning: line 6: unreachable rule (shadowed by rule at line 5) [-Wunreachable-rules]
