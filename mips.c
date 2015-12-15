#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"
#include "quad.h"
#include "mips.h"

void creat_mips(struct symbol** tds,struct quad* code){
	FILE* output = fopen("swag.s","w+");
	//printf("coucou");
	
	fputs("\t.data\n",output);
	struct symbol* scan = *tds;
	while(scan!= NULL)
	{
		printf("type %i \n",scan->type);
		fputs(scan->id,output);
		//si c'est une chaine de caracteres, on fait .asciiz
		if(scan->type==STRING_TYPE)
		{
			fputs(": .asciiz ",output);
			fputs(scan->value.string,output);
			fputs("\n",output);
		}
		//sinon si cest un float .float
		else if (scan->type==REAL_TYPE)
		{
			fputs(": .float ",output);
			char buffer[16] = {0};
			sprintf(buffer, "%f", scan->value.real);
			fputs(buffer,output);
			fputs("\n",output);	
		}
		//sinon si c'est un array .space
		else if (scan->type==ARRAY_TYPE)
		{
			fputs(": .space ",output);
			char buffer[16] = {0};
			sprintf(buffer, "%i", (scan->value.array.length)*4);
			fputs(buffer,output);
			fputs("\n",output);	
		}
		//sinon entier : .word
		else 
		{
			fputs(": .word ",output);
			char buffer[16] = {0};
			sprintf(buffer, "%d", scan->value.integer);
			fputs(buffer,output);
			fputs("\n",output);
		}
		scan = scan->next;
	}
	fputs("\n\n\t.text\n",output);
	fputs("main :\n",output);
	struct quad* lol=code;
	while(lol != NULL)
	{
		int operateur=lol->op;
		printf("operateur2 : %i \n",operateur);
		switch(operateur)
		{	
			//cas addition
			case _PLUS : 
				if(lol->arg1->type== INTEGER_TYPE)
				{
					fputs("lw $t0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("lw $t1,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("add $t2,$t0,$t1\n",output);
					fputs("sw $t2,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
				}
				else
				{
					fputs("l.s $f0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("l.s $f1,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("add.s $f2,$f0,$f1\n",output);
					fputs("s.s $f2,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
				}
				break;
			//cas soustraction
			case _MOINS : 
				if(lol->arg1->type== INTEGER_TYPE)
				{
					fputs("lw $t0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("lw $t1,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("sub $t2,$t0,$t1\n",output);
					fputs("sw $t2,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
				}
				else
				{
					fputs("l.s $f0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("l.s $f1,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("sub.s $f2,$f0,$f1\n",output);
					fputs("s.s $f2,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
				}
				break;
			//cas multiplication
			case _MUL :
				if(lol->arg1->type== INTEGER_TYPE)
				{
					fputs("lw $t0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("lw $t1,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("mul $t2,$t0,$t1\n",output);
					fputs("sw $t2,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
				}	
				else
				{
					fputs("l.s $f0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("l.s $f1,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("mul.s $f2,$f0,$f1\n",output);
					fputs("s.s $f2,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
				}
				break;
			//cas division
			case _DIV :
				if(lol->arg1->type== INTEGER_TYPE)
				{
					fputs("lw $t0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("lw $t1,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("div $t2,$t0,$t1\n",output);
					fputs("sw $t2,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
				}
				else
				{
					fputs("l.s $f0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("l.s $f1,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("div.s $f2,$f0,$f1\n",output);
					fputs("s.s $f2,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
				}
				break;
			//cas print	
			case _PRINT :
				if(lol->arg1->type==REAL_TYPE)
				{
					fputs("li $v0,2\n",output);
					fputs("l.s $f12,",output);
				}
				else
				{
					fputs("li $v0,1\n",output);
					fputs("lw $a0,",output);
				}
				fputs(lol->arg1->id,output);
				fputs("\n",output);
				fputs("syscall\n",output);
				break;
			//cas printf
			case _PRINTF :
				fputs("li $v0,4\n",output);
				fputs("la $a0,",output);
				fputs(lol->arg1->id,output);
				fputs("\n",output);
				fputs("syscall\n",output);
				break;
			//cas affectation
			case _AFFECT :
				if(lol->arg1->type==REAL_TYPE)
				{
					fputs("l.s $f0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("s.s $f0,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);	
				}
				else
				{
					fputs("lw $t0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("sw $t0,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
				}
				break;
			//cas array affectation
			case _ARRAY_AFFECT :
				{
					fputs("#----------ARRAY_AFFECT-----------\n",output);
					fputs("lw $t0,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("la $t1,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
					fputs("lw $t2,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("li $t3,4",output);
					fputs("\n",output);		
					fputs("mult $t3,$t2\n",output);
					fputs("mflo $t4\n",output);
					fputs("add $t5,$t1,$t4\n",output);
					fputs("sw $t0,($t5)\n",output);	
					fputs("#---------FIN ARRAY_AFFECT----------\n",output);
				}
				break;
			//cas array access
			case _ARRAY_ACCESS :
				{
					fputs("#----------ARRAY_ACCESS-----------\n",output);
					fputs("lw $t2,",output);
					fputs(lol->arg1->id,output);
					fputs("\n",output);
					fputs("la $t1,",output);
					fputs(lol->arg2->id,output);
					fputs("\n",output);
					fputs("li $t3,4",output);
					fputs("\n",output);		
					fputs("mult $t3,$t2\n",output);
					fputs("mflo $t4\n",output);
					fputs("add $t5,$t1,$t4\n",output);
					fputs("lw $t0,($t5)\n",output);	
					fputs("sw $t0,",output);
					fputs(lol->res->id,output);
					fputs("\n",output);
					fputs("#---------FIN ARRAY_ACCESS----------\n",output);
				}
				break;
			default : 
				break;
		}		
		lol=lol->next;
	}
	
	

	fputs("li $v0,10\n",output);
	fputs("syscall\n",output);
	fclose(output);
	
}
