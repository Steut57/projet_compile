#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"
#include "quad.h"
#include "mips.h"

void creat_mips(struct symbol** tds,struct quad* code){
	FILE* output = fopen("swag.s","w+");
	//printf("coucou");
	/*struct symbol* t1 = code->arg1;
	struct symbol* t2 = code->arg2;
	printf("t1 value %i\n",t1->value);
	printf("t1 id %s\n",t1->id);
	printf("t2 value %i\n",t2->value);
	printf("t2 id %s\n",t2->id);*/
	fputs("\t.data\n",output);
	struct symbol* scan = *tds;
	while(scan->next != NULL)
	{
		fputs(scan->id,output);
		fputs(": .word ",output);
		char buffer[16] = {0};
		sprintf(buffer, "%d", scan->value);
		fputs(buffer,output);
		fputs("\n",output);
		scan = scan->next;
	}
	fputs(scan->id,output);
	fputs(": .word ",output);
	char buffer[16] = {0};
	sprintf(buffer, "%d", scan->value);
	fputs(buffer,output);
	fputs("\n\n\t.text\n",output);
	fputs("main :\n",output);
	struct quad* lol=code;
	while(lol->next != NULL)
	{
		//printf("operateur : %i",lol->op);
		switch(lol->op)
		{
			//cas addition
			case 260 : 
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
			//cas multiplication
			case 262 :
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
			//cas print	
			case 266 :
				fputs("li $v0,1\n",output);
				fputs("move $a0,$t2\n",output);
				fputs("syscall\n",output);
			default : 
				//printf("je suis dans le case default\n");
				break;
		}		
		lol=lol->next;
	}
	//printf("operateur2 : %i",lol->op);
	switch(lol->op)
	{
		//cas addition
		case 260 : 
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
		//cas multiplication	
		case 262 :
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
		//cas print	
		case 266 :
			fputs("li $v0,1\n",output);
			fputs("move $a0,$t2\n",output);
			fputs("syscall\n",output);
		default : 
			//printf("je suis dans le case default\n");
			break;
	}	

	fputs("li $v0,10\n",output);
	fputs("syscall\n",output);
	fclose(output);
	
}
