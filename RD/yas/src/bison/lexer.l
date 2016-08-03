%{
	#include <stdlib.h>
	#include "parser.hpp"
	#define YY_DECL extern "C" int yylex()
%}

%START STR
%%
<INITIAL>[ \t\n] ;

<INITIAL>[1-9][0-9]*|[0-9]+\.[0-9]+|0 {yylval.fval = atof(yytext);return Numeral;}
<INITIAL>"(" return LB;
<INITIAL>")" return RB;
<INITIAL>"if" return IF;
<INITIAL>"then" return Then;
<INITIAL>"end" return End;
<INITIAL>"false" return False;
<INITIAL>"true" return True;
<INITIAL>"=" return EQ;
<INITIAL>";" return SEM;
<INITIAL>"+" return Add;
<INITIAL>"-" return Sub;
<INITIAL>"*" return Mul;
<INITIAL>"/" return Div;

<INITIAL>[a-zA-Z][a-zA-Z0-9]* {yylval.sval = strdup(yytext);return Name;}
<INITIAL>\" {BEGIN(STR);}
<STR>[^"]* {yylval.sval = strdup(yytext);return LiteralString;}
<STR>\" {BEGIN(INITIAL);}
%%