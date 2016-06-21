%{
	#include <stdlib.h>
	#include "parse.tab.h"
	#define YY_DECL  int yylex()
%}

%%
[ \t\n] ;
[1-9][0-9]*|[0-9]+\.[0-9]+|0 {yylval.fval = atof(yytext);return FLOAT;}
"+"|"-"|"*"|"/" {yylval.sval = yytext;printf("<%s>",yytext);
	return STRING;}
%%