#include <stdbool.h>
#define SYMBOL_MAX_NAME 64
enum op{
	_PLUS,_MOINS,_MUL,_DIV,_PARGAU,_PARDRO,_PRINT,_PRINTF,_WHILE,_DO,_DONE,_IF,
	_THEN,_ELSE,_ENDIF,_AFFECT,	_EQUAL,_SUPEQ,_INFEQ,_SUP,_INF,_AND,_OR,_NOT,_TRUE,_FALSE
};

enum type{
	_entier,_flottant,_string
};

struct symbol{
	char* id;
	bool isconstant;
	int type;
	int value;
	float nbfloat;
	char* str_value;
	struct symbol* next;
};

struct symbol* 	symbol_alloc();
struct symbol* 	symbol_newtemp(struct symbol** tds);
struct symbol* 	symbol_add(struct symbol** tds, char* id, int type);
void		symbol_print(struct symbol** tds);
struct symbol* symbol_lookup(struct symbol** tds, char* id);
