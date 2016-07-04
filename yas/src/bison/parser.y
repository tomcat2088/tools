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

%token chunk block stat var exp
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
	var '=' exp
	|functioncall
	|if exp then block end

exp:
	nil
	|false
	|true
	|Numeral
	|LiteralString
	|exp binop exp
	|unop exp
	
functioncall:
	Name '()'
	
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