prefixe=projet

all: $(prefixe).y $(prefixe).l
	yacc -d $(prefixe).y
	flex $(prefixe).l
	gcc y.tab.c lex.yy.c symbol.c quad.c mips.c -ly -lfl 

clean:
	rm y.tab.c lex.yy.c y.tab.h 

debug: $(prefixe).y $(prefixe).l
	yacc -d --verbose $(prefixe).y
	flex $(prefixe).l
	gcc -DYYDEBUG y.tab.c lex.yy.c symbol.c quad.c mips.c -ly -lfl 
