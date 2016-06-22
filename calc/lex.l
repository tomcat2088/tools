%{
	#include <stdlib.h>
	#include "parse.tab.h"
	#define YY_DECL extern "C" int yylex()
%}

%%
[ \t] ;
"\n" {return CR;};

[1-9][0-9]*|[0-9]+\.[0-9]+|0 {yylval.fval = atof(yytext);return FLOAT;}
[a-zA-Z][a-zA-Z0-9]* {yylval.sval = strdup(yytext);return VAR;}

"=" return EQ;
"**" return MMUL;
"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"(" return LB;
")" return RB;
%%