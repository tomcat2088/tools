%{
	#include <stdlib.h>
	#include "parser.hpp"
	#define YY_DECL extern "C" int yylex()
%}

%START STR
%%
<INITIAL>[ \t] ;
<INITIAL>"\n" {return CR;};

<INITIAL>[1-9][0-9]*|[0-9]+\.[0-9]+|0 {yylval.fval = atof(yytext);return FLOAT;}
<INITIAL>[a-zA-Z][a-zA-Z0-9]* {yylval.sval = strdup(yytext);return VAR;}

<INITIAL>"=" return EQ;
<INITIAL>"**" return MMUL;
<INITIAL>"+" return ADD;
<INITIAL>"-" return SUB;
<INITIAL>"*" return MUL;
<INITIAL>"/" return DIV;
<INITIAL>"(" return LB;
<INITIAL>")" return RB;

<INITIAL>\" {BEGIN(STR);}
<STR>[^"]* {printf("str : %s",yytext);}
<STR>\" {BEGIN(INITIAL);}
%%