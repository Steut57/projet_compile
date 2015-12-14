/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,
    CHAINE = 259,
    NUMBER = 260,
    REAL = 261,
    MAIN = 262,
    RETURN = 263,
    PRINT = 264,
    PRINTF = 265,
    INT = 266,
    FLOAT = 267,
    MATRIX = 268,
    IF = 269,
    ELSE = 270,
    WHILE = 271,
    THEN = 272,
    DO = 273,
    DONE = 274,
    ENDIF = 275,
    IFX = 276,
    GE = 277,
    LE = 278,
    EQ = 279,
    NE = 280,
    UNMIN = 281
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
#define INT 266
#define FLOAT 267
#define MATRIX 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define THEN 272
#define DO 273
#define DONE 274
#define ENDIF 275
#define IFX 276
#define GE 277
#define LE 278
#define EQ 279
#define NE 280
#define UNMIN 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "projet.y" /* yacc.c:1909  */

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

#line 131 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
