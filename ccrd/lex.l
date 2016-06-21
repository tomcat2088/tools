%{
	#include <stdlib.h>
	#include "parse.tab.h"
	#define YY_DECL  int yylex()
%}

%%
[ \t] ;
"\n" {return CR;};

[1-9][0-9]*|[0-9]+\.[0-9]+|0 {yylval.fval = atof(yytext);return FLOAT;}

"**" return MMUL;
"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"(" return LB;
")" return RB;
%%