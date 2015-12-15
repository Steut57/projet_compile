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
     REAL = 261,
     MAIN = 262,
     RETURN = 263,
     PRINT = 264,
     PRINTF = 265,
     PRINTTAB = 266,
     INT = 267,
     FLOAT = 268,
     MATRIX = 269,
     IF = 270,
     ELSE = 271,
     WHILE = 272,
     THEN = 273,
     DO = 274,
     DONE = 275,
     ENDIF = 276,
     IFX = 277,
     NE = 278,
     EQ = 279,
     LE = 280,
     GE = 281,
     UNMIN = 282
   };
#endif
/* Tokens.  */
#define ID 258
#define CHAINE 259
#define NUMBER 260
#define REAL 261
#define MAIN 262
#define RETURN 263
#define PRINT 264
#define PRINTF 265
#define PRINTTAB 266
#define INT 267
#define FLOAT 268
#define MATRIX 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define THEN 273
#define DO 274
#define DONE 275
#define ENDIF 276
#define IFX 277
#define NE 278
#define EQ 279
#define LE 280
#define GE 281
#define UNMIN 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 21 "projet.y"

	int val_num;
	char* val_str;
	float val_real;
	struct symbol* code_jump;
	struct{
		struct symbol* result;
		struct quad* code;
	}code_expression;
	struct{
		struct quad * code ;
		struct quad_list* truelist ;
		struct quad_list* falselist ;
	}code_condition;
	struct{
		struct quad* code ;
		struct quad_list* nextlist;
	}code_statement;
	struct{
		struct symbol* quad ;
		struct quad* code ;
		struct quad_list* nextlist;
	}code_goto;



/* Line 2068 of yacc.c  */
#line 131 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


