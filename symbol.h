#include <stdbool.h>
#define SYMBOL_MAX_NAME 64
typedef enum {
	_PLUS,_MOINS,_MUL,_DIV,_PARGAU,_PARDRO,_PRINT,_PRINTF,_WHILE,_DO,_DONE,_IF,_UNMIN,
	_GOTO,_THEN,_ELSE,_ENDIF,_AFFECT,_EQ,_GE,_LE,_NE,_SUP,_INF,_AND,_OR,_NOT,_TRUE,_FALSE,
	_ARRAY_AFFECT,_ARRAY_ACCESS,_MATRIX_AFFECT,_MATRIX_ACCESS,_PRINTTAB
}op;
typedef enum {
	BOOLEAN_TYPE, 
	INTEGER_TYPE, 
	REAL_TYPE, 
	COMPLEX_TYPE, 
	ARRAY_TYPE,
	MATRIX_TYPE,
	FUNCTION_TYPE,
	STRING_TYPE,
	NO_TYPE
} symbol_type;

typedef union {
	char* string;
	int integer;
	float real;
	struct {
		symbol_type type;
		int dimensions;
		int length;
	} array;
	
	struct {
		symbol_type type;
		int nbCols;
		int nbRows;
	} matrix;
} value_union;

struct symbol{
	char* id;
	unsigned int label;
	bool isconstant; 
	symbol_type type;
	value_union value;

	struct symbol* next;
};

struct symbol* 	symbol_alloc();
struct symbol* 	symbol_newtemp(struct symbol** tds,int next_quad);
struct symbol* 	symbol_add(struct symbol** tds, char* id);
void		symbol_print(struct symbol** tds);
struct symbol* symbol_lookup(struct symbol** tds,char* id);
