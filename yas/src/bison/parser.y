%{
    #include <stdio.h>
    #include "var_list.c"
    #define YYDEBUG 1
	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" void yyerror(const char *s);
%}

%union {
	float 	fval;
	char* 	sval;
}

%token CR ADD SUB MUL DIV LB RB MMUL EQ
%token <fval> FLOAT
%token <sval> STRING VAR

%type <fval> exp primary_exp NUM mid_exp stmt
%%

line_list:
	line
	|line_list line
	;

line:
	CR
	| stmt CR {printf("%f\n",$1);}

stmt:
	exp
	| VAR EQ exp { $$ = $3; set_var($1,$3);}

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
	|VAR { $$ = get_var($1);}
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