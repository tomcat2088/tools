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

%token IF Then End False True EQ SEM Add Sub Mul Div
%token LB RB
%token <fval> Numeral
%token <sval> Name LiteralString

%left EQ
%left Add Sub
%left Mul Div
%precedence NEG
%precedence BRACE
%%

chunk:
	block
	
block:
    stat
	|block stat
	;
	
stat:
	exp SEM                         {printf("exp Found\n");}
    |var EQ exp SEM                 {printf("assign Found\n");}
	|IF exp Then block End      {printf("if Found\n");}

exp:
	False
	|True
	|Numeral            {printf("Numeral Found: %.f\n",$1);}
	|LiteralString      {printf("LiteralString Found\n");}
	|var 				{printf("Var in exp Found\n");}
	|exp Add exp		{printf("Add found\n");}
	|exp Sub exp		{printf("Sub found\n");}
	|exp Mul exp		{printf("Mul found\n");}
	|exp Div exp		{printf("Div found\n");}
	|Sub exp %prec NEG		{printf("NEG found\n");}
	|LB exp RB %prec BRACE   {printf("BRACE found\n");}
	
var:
    Name    

	

%%

int main(int argc,char** argv)
{
    return yyparse();
}

void yyerror (char const *s) {
    printf ("%s\n", s);
}