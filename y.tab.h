/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     CHAINE = 259,
     NUMBER = 260,
     PLUS = 261,
     MOINS = 262,
     MUL = 263,
     DIV = 264,
     PARGAU = 265,
     PARDRO = 266,
     PRINT = 267,
     PRINTF = 268,
     WHILE = 269,
     DO = 270,
     DONE = 271,
     IF = 272,
     THEN = 273,
     ELSE = 274,
     ENDIF = 275,
     AFFECT = 276,
     EQUAL = 277,
     SUPEQ = 278,
     INFEQ = 279,
     SUP = 280,
     INF = 281,
     AND = 282,
     OR = 283,
     NOT = 284,
     TRUE = 285,
     FALSE = 286
   };
#endif
/* Tokens.  */
#define ID 258
#define CHAINE 259
#define NUMBER 260
#define PLUS 261
#define MOINS 262
#define MUL 263
#define DIV 264
#define PARGAU 265
#define PARDRO 266
#define PRINT 267
#define PRINTF 268
#define WHILE 269
#define DO 270
#define DONE 271
#define IF 272
#define THEN 273
#define ELSE 274
#define ENDIF 275
#define AFFECT 276
#define EQUAL 277
#define SUPEQ 278
#define INFEQ 279
#define SUP 280
#define INF 281
#define AND 282
#define OR 283
#define NOT 284
#define TRUE 285
#define FALSE 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 20 "projet.y"

	int value;
	char* string;
	struct{
		struct symbol* result;
		struct quad* code;
	}codegen;
	struct{
		struct quad* code;
		struct quad_list* truelist;
		struct quad_list* falselist;
	}code_condition;



/* Line 2068 of yacc.c  */
#line 128 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


