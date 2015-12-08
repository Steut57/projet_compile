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
		
		fputs(scan->id,output);
		//si c'est une chaine de caracteres, on fait .asciiz
		if(scan->str_value!=NULL)
		{
			fputs(": .asciiz ",output);
			fputs(scan->str_value,output);
			fputs("\n",output);
		}
		//sinon .word
		else
		{
			fputs(": .word ",output);
			char buffer[16] = {0};
			sprintf(buffer, "%d", scan->value);
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
		switch(operateur)
		{
			//cas addition
			case 0 : 
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
				break;
			//cas soustraction
			case 1 : 
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
				break;
			//cas multiplication
			case 2 :
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
				break;
			//cas division
			case 3 :
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
				break;
			//cas print	
			case 6 :
				fputs("li $v0,1\n",output);
				fputs("move $a0,$t2\n",output);
				fputs("syscall\n",output);
				break;
			//cas printf
			case 7 :
				fputs("li $v0,4\n",output);
				fputs("la $a0,",output);
				fputs(lol->arg1->id,output);
				fputs("\n",output);
				fputs("syscall\n",output);
				break;
			default : 
				break;
		}		
		lol=lol->next;
	}
	//printf("operateur2 : %i",lol->op);
	

	fputs("li $v0,10\n",output);
	fputs("syscall\n",output);
	fclose(output);
	
}
