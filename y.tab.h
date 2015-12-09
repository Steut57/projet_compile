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
     NBFLOAT = 261,
     PLUS = 262,
     MOINS = 263,
     MUL = 264,
     DIV = 265,
     PARGAU = 266,
     PARDRO = 267,
     PRINT = 268,
     PRINTF = 269,
     INT = 270,
     FLOAT = 271,
     MATRIX = 272,
     WHILE = 273,
     DO = 274,
     DONE = 275,
     IF = 276,
     THEN = 277,
     ELSE = 278,
     ENDIF = 279,
     AFFECT = 280,
     EQUAL = 281,
     SUPEQ = 282,
     INFEQ = 283,
     SUP = 284,
     INF = 285,
     AND = 286,
     OR = 287,
     NOT = 288,
     TRUE = 289,
     FALSE = 290
   };
#endif
/* Tokens.  */
#define ID 258
#define CHAINE 259
#define NUMBER 260
#define NBFLOAT 261
#define PLUS 262
#define MOINS 263
#define MUL 264
#define DIV 265
#define PARGAU 266
#define PARDRO 267
#define PRINT 268
#define PRINTF 269
#define INT 270
#define FLOAT 271
#define MATRIX 272
#define WHILE 273
#define DO 274
#define DONE 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define AFFECT 280
#define EQUAL 281
#define SUPEQ 282
#define INFEQ 283
#define SUP 284
#define INF 285
#define AND 286
#define OR 287
#define NOT 288
#define TRUE 289
#define FALSE 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 20 "projet.y"

	int value;
	char* string;
	float nbfloat;
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
#line 137 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


