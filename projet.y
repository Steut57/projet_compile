%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"
#include "quad.h"
#include "mips.h"
extern FILE *yyin;
struct codegen;
struct code_condition;
struct symbol* tds = NULL;
struct quad* code = NULL;
int next_quad = 0;
int yylex();
void yyerror(const char *s)
{
	fprintf (stderr, "%s\n", s);
}
%}
%union{
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
}
%token <string> ID
%token <string> CHAINE
%token <value> NUMBER
%token PLUS MOINS MUL DIV PARGAU PARDRO PRINT PRINTF INT FLOAT
%token WHILE DO DONE IF THEN ELSE ENDIF AFFECT
%token EQUAL SUPEQ INFEQ SUP INF AND OR NOT TRUE FALSE
%type <codegen>	expr
%type <codegen>	statement
%type <code_condition> condition
%type <codegen> tag

%right AFFECT
%left OR
%left AND
%left NOT
%left EQUAL SUPEQ INFEQ SUP INF
%left PLUS MOINS
%left MUL DIV


%%


axiom:
    axiom statement{ 
                        printf("Match\n");                      
                        quad_add(&code, $2.code);
    }
    | 
    {
		printf("ici");
	}
    ;
statement:
	expr{
		$$ = $1;
	}
	|
	condition '\n'{
		struct symbol* cst_true  	= symbol_add(&tds,"1");
		struct symbol* cst_false 	= symbol_add(&tds,"0");
		struct symbol* result 		= symbol_add(&tds,"result");
		struct quad* is_true;
		struct quad* is_false;
		struct quad* jump;
		struct symbol* label_true;
		struct symbol* label_false;
		
		label_true	= symbol_newtemp(&tds);
		quad_add(&is_true, quad_malloc(':',cst_true,NULL,result));
		quad_add(&jump, quad_malloc('G',NULL,NULL,NULL));
		label_false	= symbol_newtemp(&tds);
		quad_add(&is_false, quad_malloc(':',cst_false,NULL,result));
		quad_list_complete($1.truelist,  label_true);
		quad_list_complete($1.falselist, label_false);
		
		code = $1.code;
		quad_add(&code,is_true);
		quad_add(&code,jump);
		quad_add(&code,is_false);
		return 0;
	}
	|
	PRINT PARGAU expr PARDRO	{
							$$.code	= $3.code;
							quad_add(&$$.code, quad_malloc(_PRINT,$3.result,NULL,NULL));
						}
	|
	PRINTF PARGAU  CHAINE  PARDRO    {
                            $$.code    = NULL;
                            $$.result = NULL;
                            struct symbol *chaine=symbol_newtemp(&tds);
                            chaine->str_value=$3;
                            quad_add(&$$.code, quad_malloc(_PRINTF,chaine,NULL,NULL));
                            }
	| INT ID AFFECT expr	{	printf("affectation int \n");
								$$.result	= symbol_add(&tds,$2);							
								$$.code=NULL;
								quad_add(&$$.code, quad_malloc(_AFFECT,$4.result,NULL,$$.result));
							};
condition:
	expr SUP expr { 
		printf("contition -> expression > expression \n");
		struct quad* goto_true;
		struct quad* goto_false;
		quad_add(&goto_true, quad_malloc(_SUP,$1.result,$3.result,NULL));
		quad_add(&goto_false, quad_malloc('G',NULL,NULL,NULL));
		$$.code		= $1.code;
		quad_add(&$$.code, $3.code);
		quad_add(&$$.code, goto_true);
		quad_add(&$$.code, goto_false);
		$$.truelist		= quad_list_new(goto_true);
		$$.falselist	= quad_list_new(goto_false);	
		}
	| condition OR tag condition{
		printf("condition -> condition OR condition \n");
		quad_list_complete($1.falselist,$3.result);
		quad_list_add($$.truelist,$4.truelist);
		quad_list_add($$.truelist,$1.truelist);
		
		$$.falselist	= $4.falselist;
		
		$$.code = $1.code;
		quad_add(&$$.code,$4.code);

		}
	| condition AND tag condition{
		printf("condition -> condition AND condition");
		quad_list_complete($1.falselist,$3.result);
		$$.code = $1.code;
		quad_add(&$1.code,$4.code);
		$$.falselist = $4.falselist;
		$$.truelist = $1.truelist;
		quad_list_add($$.truelist,$4.truelist);}
	| NOT condition
	{
		printf("condition -> NOT condition \n");
		$$.code = $2.code;
		$$.truelist = $2.truelist;
		$$.falselist = $2.falselist;
	}
	| PARGAU condition PARDRO
	{
		printf("condition -> ( condition )\n");
		$$.code = $2.code;
		$$.truelist = $2.truelist;
		$$.falselist = $2.falselist;
		
	};
tag:
	{ 	$$.result = symbol_newtemp(&tds);
		$$.result->value = next_quad; // incrémenter dans malloc extern int 
		$$.code = NULL;
	};
	
expr:
	expr PLUS expr 	{ 	printf("expr -> expr + expr\n");
						$$.result	= symbol_newtemp(&tds);
						$$.code	= $1.code;
						quad_add(&$$.code,$3.code);
						quad_add(&$$.code, quad_malloc(_PLUS,$1.result,$3.result,$$.result));
					}
	| expr MOINS expr {
						printf("expr -> expr - expr\n");
						$$.result	= symbol_newtemp(&tds);
						$$.code	= $1.code;
						quad_add(&$$.code,$3.code);
						quad_add(&$$.code, quad_malloc(_MOINS,$1.result,$3.result,$$.result));
					}
	| expr MUL expr	{	printf("expr -> expr * expr\n");
						$$.result = symbol_newtemp(&tds);
						$$.code = $1.code;
						quad_add(&$$.code,$3.code);
						quad_add(&$$.code, quad_malloc(_MUL,$1.result,$3.result,$$.result));
					}
	| expr DIV expr	{	printf("expr -> expr * expr\n");
						$$.result = symbol_newtemp(&tds);
						$$.code = $1.code;
						quad_add(&$$.code,$3.code);
						quad_add(&$$.code, quad_malloc(_DIV,$1.result,$3.result,$$.result));
					}
	| PARGAU expr PARDRO 	{ 	printf("expr -> ( expr ) \n");
						$$.result	= $2.result;
						$$.code	= $2.code;
					}

	
	| ID			{ 	printf("expr -> ID\n");
						$$.result	= symbol_lookup(&tds,$1);
						$$.code	= NULL;
					}
	| NUMBER		{ 	printf("expr -> NUMBER\n");
						$$.result = symbol_newtemp(&tds);
						$$.result->value = $1;
						$$.code = NULL;
					}
	;
%%

int main(int argc, char* argv[])
{
	yyin = fopen(argv[1], "r" );
	yyparse();
	printf("\nTable des symboles\n");
	symbol_print(&tds);
	printf("\nCode\n");
	quad_print(code);
	creat_mips(&tds,code);
	return 0;
}
