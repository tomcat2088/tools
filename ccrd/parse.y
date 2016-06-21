%{
#include <stdio.h>
	int yylex();
	int yyparse();
	void yyerror(const char *s);
%}

%union {
	float 	fval;
	char* 	sval;
}

%token <fval> FLOAT
%token <sval> STRING

%type <fval> exp
%%

exp:
	FLOAT { $$ = $1;printf(">%f>",$1);}
	| exp '+' exp  { $$ = $1 + $3;}
	;

%%

int main(int argc,char** argv)
{
	return yyparse();
}

void yyerror (char const *s) {
   printf ("%s\n", s);
 }