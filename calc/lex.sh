#!/bin/zsh
/usr/local/Cellar/bison/3.0.4/bin/bison -dv parse.y
lex lex.l
g++ parse.tab.c lex.yy.c -ll -o cc
./cc