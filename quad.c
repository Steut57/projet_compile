#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"
#include "quad.h"

struct quad* quad_malloc(	int* label,
							int op, 
							struct symbol* arg1, 
							struct symbol* arg2, 
							struct symbol* res){

	struct quad* new = malloc(sizeof(*new));
	new->op		 	= op;
	new->arg1 		= arg1;
	new->arg2 		= arg2;
	new->res  		= res;
	new->next		= NULL;

	new->label		 = *label;
	(*label)++;

	return new;
}

void quad_add(struct quad** list, struct quad* new){
	if(*list == NULL){
		*list = new;
	}else{
		struct quad* scan = *list;
		while(scan->next != NULL)
			scan = scan->next;
		scan->next = new;
	}
}

void quad_print(struct quad* list){
	while(list != NULL){
		
		printf("%i lu\t", list->label);
		char* s;
		switch(list->op) {
			case _EQ:
				s = "==";
				break;
			case _GE:
				s = ">=";
				break;
			case _LE:
				s = "<=";
				break;
			case _NE:
				s = "!=";
				break;
			case _AFFECT:
				s = "=";
				break;
			case '<':
				s = "<";
				break;
			case _SUP:
				s = ">";
				break;
			case _PLUS:
				s = "+";
				break;
			case _MOINS:
				s = "-";
				break;
			case _GOTO:
				s = "goto";
				break;
			case 'G':
				s = "G";
				break;
			case ':':
				s = ":";
				break;
			case _PRINT:
				s = "print";
				break;
			case _PRINTF:
				s="printf";
				break;
			default:
				s = "UNKNOWN";
		}
		printf(" %s\t", s);
		if(list->arg1 != NULL) printf(" %s \t",list->arg1->id);
		else printf(" vide\t");
		if(list->arg2 != NULL) printf(" %s \t",list->arg2->id);
		else printf(" vide\t");
		if(list->res != NULL) printf(" %s \t",list->res->id);
		else printf(" vide\t");


		printf("\n");
		list = list->next;
	}
}


struct quad_list* quad_list_new(struct quad* node){
	struct quad_list* new = malloc(sizeof(struct quad_list));
	new->node = node;
	new->next = NULL;
	return new;
}
void quad_list_add(struct quad_list** dest, struct quad_list* src)
{
	if(*dest== NULL){
		*dest = src;
	}else{
		struct quad_list* scan = *dest;
		while(scan->next != NULL){
			scan = scan->next;
		}
		scan->next =src;
	}
}
void quad_list_complete(struct quad_list* list, struct symbol* node)
{
	while(list != NULL){
		list->node->res = node;
		list = list->next;
	}
}

void quad_list_print(struct quad_list* list){
	int i = 0;
	while(list != NULL){
		printf("Node %2d:\n",i);
		quad_print(list->node);
		printf("\n");
		list = list->next;
	}
}
