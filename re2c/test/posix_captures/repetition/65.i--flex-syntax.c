/* Generated by re2c */

{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if ((YYLIMIT - YYCURSOR) < 10) YYFILL(10);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 'X':
		yyt1 = YYCURSOR;
		goto yy3;
	default:	goto yy2;
	}
yy2:
	{
		const size_t yynmatch = 1;
		const YYCTYPE *yypmatch[yynmatch * 2];
		yypmatch[0] = YYCURSOR;
		yypmatch[1] = YYCURSOR;
		{}
	}
yy3:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy4;
	case 'Y':
		yyt2 = YYCURSOR;
		goto yy6;
	default:	goto yy5;
	}
yy4:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
	case 0: 	goto yy2;
	case 1: 	goto yy7;
	default:
		yyt2 = yyt3;
		goto yy7;
	}
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy4;
	case 'Y':
		yyt2 = YYCURSOR;
		goto yy9;
	default:	goto yy8;
	}
yy6:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x00:	goto yy7;
	case 'Y':
		yyt2 = YYCURSOR;
		goto yy9;
	default:	goto yy8;
	}
yy7:
	{
		const size_t yynmatch = 2;
		const YYCTYPE *yypmatch[yynmatch * 2];
		yypmatch[0] = yyt1;
		yypmatch[2] = yyt2;
		yypmatch[1] = YYCURSOR;
		yypmatch[3] = YYCURSOR - 1;
		{}
	}
yy8:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy4;
	case 'Y':
		yyt2 = YYCURSOR;
		goto yy11;
	default:	goto yy10;
	}
yy9:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x00:	goto yy7;
	case 'Y':
		yyt2 = YYCURSOR;
		goto yy11;
	default:	goto yy10;
	}
yy10:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy4;
	case 'Y':
		yyt2 = YYCURSOR;
		goto yy13;
	default:	goto yy12;
	}
yy11:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x00:	goto yy7;
	case 'Y':
		yyt2 = YYCURSOR;
		goto yy13;
	default:	goto yy12;
	}
yy12:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy4;
	case 'Y':
		yyt2 = YYCURSOR;
		goto yy15;
	default:	goto yy14;
	}
yy13:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x00:	goto yy7;
	case 'Y':
		yyt2 = YYCURSOR;
		goto yy15;
	default:	goto yy14;
	}
yy14:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy4;
	case 'Y':
		yyt3 = YYCURSOR;
		goto yy17;
	default:
		yyt3 = YYCURSOR;
		goto yy16;
	}
yy15:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x00:	goto yy7;
	case 'Y':
		yyt3 = YYCURSOR;
		goto yy17;
	default:
		yyt3 = YYCURSOR;
		goto yy16;
	}
yy16:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy4;
	case 'Y':
		yyt4 = YYCURSOR;
		goto yy19;
	default:
		yyt4 = YYCURSOR;
		goto yy18;
	}
yy17:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x00:
		yyt2 = yyt3;
		goto yy7;
	case 'Y':
		yyt4 = YYCURSOR;
		goto yy19;
	default:
		yyt4 = YYCURSOR;
		goto yy18;
	}
yy18:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy4;
	case 'Y':
		yyt5 = YYCURSOR;
		goto yy21;
	default:
		yyt5 = YYCURSOR;
		goto yy20;
	}
yy19:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x00:
		yyt2 = yyt3;
		goto yy7;
	case 'Y':
		yyt5 = YYCURSOR;
		goto yy21;
	default:
		yyt5 = YYCURSOR;
		goto yy20;
	}
yy20:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'Y':	goto yy22;
	default:	goto yy4;
	}
yy21:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'Y':	goto yy22;
	default:
		yyt2 = yyt4;
		goto yy7;
	}
yy22:
	++YYCURSOR;
	yyt2 = yyt5;
	goto yy7;
}

re2c: warning: line 6: rule matches empty string [-Wmatch-empty-string]
