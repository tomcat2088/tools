/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_USERS_OCEAN_DOCUMENTS_PROJECTS_WORKSPACE_TOOLS_CALC_SRC_PARSER_HPP_INCLUDED
# define YY_YY_USERS_OCEAN_DOCUMENTS_PROJECTS_WORKSPACE_TOOLS_CALC_SRC_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CR = 258,
    ADD = 259,
    SUB = 260,
    MUL = 261,
    DIV = 262,
    LB = 263,
    RB = 264,
    MMUL = 265,
    EQ = 266,
    FLOAT = 267,
    STRING = 268,
    VAR = 269
  };
#endif
/* Tokens.  */
#define CR 258
#define ADD 259
#define SUB 260
#define MUL 261
#define DIV 262
#define LB 263
#define RB 264
#define MMUL 265
#define EQ 266
#define FLOAT 267
#define STRING 268
#define VAR 269

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "/Users/ocean/Documents/projects/workspace/tools/calc/src/bison/parser.y" /* yacc.c:1915  */

	float 	fval;
	char* 	sval;

#line 87 "/Users/ocean/Documents/projects/workspace/tools/calc/src/parser.hpp" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_USERS_OCEAN_DOCUMENTS_PROJECTS_WORKSPACE_TOOLS_CALC_SRC_PARSER_HPP_INCLUDED  */
