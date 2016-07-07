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

%token <sval> IF Then End False True EQ
%token <fval> Numeral
%token <sval> Name LiteralString

%%

chunk:
	block
	
block:
    stat
	|block stat
	;
	
stat:
	exp                         {printf("exp Found\n");}
    |var                        {printf("var Found\n");}
    |var EQ exp                 {printf("assign Found\n");}
	|IF exp Then block End      {printf("if Found\n");}

exp:
	False
	|True
	|Numeral            {printf("Numeral Found\n");}
	|LiteralString      {printf("LiteralString Found\n");}
	|exp binop exp
	|unop exp
	
var:
    Name    

binop:
	'+'
	|'-'
	|'*'
	|'/'
	
unop:
	'-'

%%

int main(int argc,char** argv)
{
    return yyparse();
}

void yyerror (char const *s) {
    printf ("%s\n", s);
}