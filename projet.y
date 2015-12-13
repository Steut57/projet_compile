%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"
#include "quad.h"
#include "mips.h"
extern FILE *yyin;

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
	int val_num;
	char* val_str;
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
}
%type <code_jump> tag
%type <code_goto> tagoto
%type <code_statement> stmt
%type <code_statement> stmtlist
%type <code_condition> condition
%type <code_expression> expr
%token <val_str> ID
%token <val_str> CHAINE
%token <val_num> NUMBER

%token MAIN RETURN PRINT PRINTF
%token INT FLOAT MATRIX
%token IF ELSE WHILE THEN DO DONE ENDIF

%nonassoc IFX
%nonassoc ELSE

%right '='
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%left UNMIN
%%


program:
    INT MAIN '(' ')' '{' stmtlist RETURN NUMBER ';' '}' {
															printf("MATCH\n");
															code = $6.code;}
    |
    ;
    
stmtlist:
	stmt 									{printf("stmt\n");$$.code = $1.code;}
	| stmtlist stmt 						{	printf("stmtlist stmt\n");	
												$$.code = $1.code; 
												quad_add(&$$.code,$2.code);}
	;
	
stmt:
	expr ';'										{	$$.code = $1.code;
														
													}
	| PRINT '(' expr ')' ';'						{	printf("print expr\n");
															$$.code	= $3.code;
															quad_add(&$$.code, quad_malloc(&next_quad,_PRINT,$3.result,NULL,NULL));
													}
	| PRINTF '(' CHAINE ')' ';'   					{
														$$.code   = NULL;
														struct symbol* chaine=symbol_newtemp(&tds,next_quad);
														chaine->value.string=$3;
														quad_add(&$$.code, quad_malloc(&next_quad,_PRINTF,chaine,NULL,NULL));
													}
	| ID '=' expr ';'								{	printf("id = expr\n");
														struct symbol* lookup = symbol_lookup(&tds,$1);
														if(lookup == NULL) {
															printf("mmmh le caca c'est très bon \n");
														}else{
															$$.code = $3.code;
															quad_add(&$$.code,quad_malloc(&next_quad,_AFFECT,$3.result,NULL,lookup));
														}
													}
	| WHILE tag '(' condition ')' tag stmt			{printf("WHILE '(' expr ')' stmt\n");}
	| IF '(' condition ')' tag stmt %prec IFX		{	printf("IF '(' expr ')' stmt ENDIF \n");
														
													}
	| IF '(' condition ')' tag stmt ELSE tagoto stmt{printf("IF '(' expr ')' stmt ELSE stmt ENDIF \n");
														
														struct symbol* cst_true  	= symbol_add(&tds,"1");
														struct symbol* cst_false 	= symbol_add(&tds,"0");
														struct symbol* result 		= symbol_add(&tds,"result");
														struct quad* is_true;
														struct quad* is_false;
														struct quad* jump;
														struct symbol* label_true;
														struct symbol* label_false;
														
														label_true	= symbol_newtemp(&tds,next_quad);
														quad_add(&is_true, quad_malloc(&next_quad,':',cst_true,NULL,result));
														quad_add(&jump,    quad_malloc(&next_quad,_GOTO,NULL,NULL,NULL));
														label_false	= symbol_newtemp(&tds,next_quad);
														quad_add(&is_false, quad_malloc(&next_quad,':',cst_false,NULL,result));
														quad_list_complete($3.truelist,  label_true);
														quad_list_complete($3.falselist, label_false);
														
														$$.code = $6.code;
														quad_add(&$$.code,is_true);
														quad_add(&$$.code,jump);
														quad_add(&$$.code,is_false);}
	| '{' stmtlist '}'								{printf("'{' stmtlist '}'\n");
														$$.code = $2.code;
														
													}
	;
	
condition:
	expr '<' expr			{printf("expr -> expr '<' expr\n");
							}
	| expr '>' expr			{	printf("expr -> expr '>' expr\n");
								struct quad* goto_true;
								struct quad* goto_false;
								quad_add(&goto_true,  quad_malloc(&next_quad,_SUP,$1.result,$3.result,NULL));
								quad_add(&goto_false, quad_malloc(&next_quad,'G',NULL,NULL,NULL));
								$$.code		= $1.code;
								quad_add(&$$.code, $3.code);
								quad_add(&$$.code, goto_true);
								quad_add(&$$.code, goto_false);
								$$.truelist		= quad_list_new(goto_true);
								$$.falselist	= quad_list_new(goto_false);
							}
	| expr GE expr        	{printf("expr -> expr '>=' expr\n");
							}
	| expr LE expr          {printf("expr -> expr '<=' expr\n");
							}
	| expr NE expr          {printf("expr -> expr '!=' expr\n");
							}
	| expr EQ expr          {printf("expr -> expr '==' expr\n");
							}
tag :	{	$$ = symbol_newtemp(&tds,next_quad);
			}

tagoto :{	$$.code = quad_malloc(&next_quad,_GOTO,NULL,NULL,NULL);
			$$.quad = symbol_newtemp(&tds,next_quad);
			$$.nextlist = quad_list_new($$.code);
			}

expr:
	NUMBER					{	printf("expr -> NUMBER\n");
								
								$$.result = symbol_newtemp(&tds,next_quad);
								$$.result->type = INTEGER_TYPE;
								$$.result->isconstant = true;
								$$.result->value.integer = $1;
								//printf("YOLOLOLOOLO %d",$$.result->value.integer );
								$$.code = NULL;
							}
	| ID					{	printf("expr -> ID\n");
								if(symbol_lookup(&tds,$1)==NULL){
								$$.result = symbol_newtemp(&tds,next_quad);
								}
								$$.result->id = $1;
								$$.code = NULL;
							}
	| '-' expr %prec UNMIN  {	printf("expr -> - expr\n");
								$$.result	= symbol_newtemp(&tds,next_quad);
								$$.code	= $2.code;
								quad_add(&$$.code, quad_malloc(&next_quad,_UNMIN,$2.result,NULL,$$.result));
							}
	| expr '+' expr 		{	printf("expr -> expr + expr\n");
								$$.result	= symbol_newtemp(&tds,next_quad);
								$$.code	= $1.code;
								quad_add(&$$.code,$3.code);
								quad_add(&$$.code, quad_malloc(&next_quad,_PLUS,$1.result,$3.result,$$.result));
							}
	| expr '-' expr 		{	printf("expr -> expr '-' expr\n");
								$$.result	= symbol_newtemp(&tds,next_quad);
								$$.code	= $1.code;
								quad_add(&$$.code,$3.code);
								quad_add(&$$.code, quad_malloc(&next_quad,_MOINS,$1.result,$3.result,$$.result));
							}
	| expr '*' expr 		{	printf("expr -> expr '*' expr\n");
								$$.result	= symbol_newtemp(&tds,next_quad);
								$$.code	= $1.code;
								quad_add(&$$.code,$3.code);
								quad_add(&$$.code, quad_malloc(&next_quad,_MUL,$1.result,$3.result,$$.result));
							}
	| expr '/' expr 		{	printf("expr -> expr '/' expr\n");
								$$.result = symbol_newtemp(&tds,next_quad);
								$$.code = $1.code;
								quad_add(&$$.code,$3.code);
								quad_add(&$$.code, quad_malloc(&next_quad,_DIV,$1.result,$3.result,$$.result));
							}
	| '(' expr ')'			{	printf("expr -> '(' expr ')'\n");
								$$.result	= $2.result;
								$$.code	= $2.code;
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
	
	//creat_mips(&tds,code);
}
