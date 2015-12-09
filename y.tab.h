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
     INT = 269,
     FLOAT = 270,
     WHILE = 271,
     DO = 272,
     DONE = 273,
     IF = 274,
     THEN = 275,
     ELSE = 276,
     ENDIF = 277,
     AFFECT = 278,
     EQUAL = 279,
     SUPEQ = 280,
     INFEQ = 281,
     SUP = 282,
     INF = 283,
     AND = 284,
     OR = 285,
     NOT = 286,
     TRUE = 287,
     FALSE = 288
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
#define INT 269
#define FLOAT 270
#define WHILE 271
#define DO 272
#define DONE 273
#define IF 274
#define THEN 275
#define ELSE 276
#define ENDIF 277
#define AFFECT 278
#define EQUAL 279
#define SUPEQ 280
#define INFEQ 281
#define SUP 282
#define INF 283
#define AND 284
#define OR 285
#define NOT 286
#define TRUE 287
#define FALSE 288




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
#line 132 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


