%{
#include <stdio.h>
#define YYDEBUG 1
	int yylex();
	int yyparse();
	void yyerror(const char *s);
%}

%union {
	float 	fval;
	char* 	sval;
}

%token CR ADD SUB MUL DIV LB RB MMUL
%token <fval> FLOAT
%token <sval> STRING

%type <fval> exp primary_exp NUM mid_exp
%%

line_list:
	line
	|line_list line
	;

line:
	exp CR {printf("%f\n",$1);}

exp:
	primary_exp
	| exp ADD primary_exp  { $$ = $1 + $3;}
	| exp SUB primary_exp  { $$ = $1 - $3;}
	;

primary_exp:
	mid_exp
	| primary_exp MUL mid_exp { $$ = $1 * $3; }
	| primary_exp DIV mid_exp { $$ = $1 / $3; }
	
mid_exp:
	NUM
	|mid_exp MMUL mid_exp { 
		int i=0;
		float res = 1;
		for(i=0;i<$3;i++)
		{
			res *= $1;
		}
		$$ = res;
	}
NUM:
	FLOAT
	|SUB NUM {$$ = - $2;}
	|LB exp RB {$$ = $2;}
	
%%

int main(int argc,char** argv)
{
	return yyparse();
}

void yyerror (char const *s) {
   printf ("%s\n", s);
 }