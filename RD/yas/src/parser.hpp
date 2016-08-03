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

#ifndef YY_YY_USERS_OCEAN_DOCUMENTS_PROJECTS_WORKSPACE_TOOLS_YAS_SRC_PARSER_HPP_INCLUDED
# define YY_YY_USERS_OCEAN_DOCUMENTS_PROJECTS_WORKSPACE_TOOLS_YAS_SRC_PARSER_HPP_INCLUDED
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
    IF = 258,
    Then = 259,
    End = 260,
    False = 261,
    True = 262,
    EQ = 263,
    SEM = 264,
    Add = 265,
    Sub = 266,
    Mul = 267,
    Div = 268,
    LB = 269,
    RB = 270,
    Numeral = 271,
    Name = 272,
    LiteralString = 273,
    NEG = 274,
    BRACE = 275
  };
#endif
/* Tokens.  */
#define IF 258
#define Then 259
#define End 260
#define False 261
#define True 262
#define EQ 263
#define SEM 264
#define Add 265
#define Sub 266
#define Mul 267
#define Div 268
#define LB 269
#define RB 270
#define Numeral 271
#define Name 272
#define LiteralString 273
#define NEG 274
#define BRACE 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "/Users/ocean/Documents/projects/workspace/tools/yas/src/bison/parser.y" /* yacc.c:1915  */

	float 	fval;
	char* 	sval;

#line 99 "/Users/ocean/Documents/projects/workspace/tools/yas/src/parser.hpp" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_USERS_OCEAN_DOCUMENTS_PROJECTS_WORKSPACE_TOOLS_YAS_SRC_PARSER_HPP_INCLUDED  */
