#!/bin/zsh
/usr/local/Cellar/bison/3.0.4/bin/bison -d parse.y
lex lex.l
gcc parse.tab.c lex.yy.c -ll -o cc
./cc