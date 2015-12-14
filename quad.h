#ifndef __QUAD_H__
#define __QUAD_H__

struct quad{
	int label;
	int op;
	struct symbol* arg1;
	struct symbol* arg2;
	struct symbol* res;
	struct quad* next;
};

struct quad* quad_malloc(	int* label,
							int op, 
							struct symbol* arg1, 
							struct symbol* arg2, 
							struct symbol* res);

struct quad_list{
	struct quad* node;
	struct quad_list* next;
};
void quad_add(struct quad** list, struct quad* new);
void quad_print(struct quad* list);

struct quad_list* quad_list_new(struct quad* node);
void quad_list_add(struct quad_list** dest, struct quad_list* src);
void quad_list_complete(struct quad_list* list, struct symbol* node);
void quad_list_print(struct quad_list* list);
#endif
