%option nounput
%option noyywrap
%{
  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"

%}

identifier	[a-zA-Z_]+[0-9a-zA-Z_]*
number     	[0-9]+
chaine		\"(\\.|[^\"\\])*\"
%%
"while"		{return WHILE;}
"do"		{return DO;}
"done"		{return DONE;}
"if"		{return IF;}
"then"		{return THEN;}
"else"		{return ELSE;}
"endif"		{return ENDIF;}
"="		{return AFFECT;}
"print"		{return PRINT;}
"printf"	{return PRINTF;}

"=="		{return EQUAL;}
">="		{return SUPEQ;}
"<="		{return INFEQ;}
">"		{return SUP;}
"<"		{return INF;}
"and"		{return AND;}
"or"		{return OR;}
"not"		{return NOT;}
"true"		{return TRUE;}
"false"		{return FALSE;}

"+"		{return PLUS;}
"-"		{return MOINS;}
"*"		{return MUL;}
"/"		{return DIV;}
"("		{return PARGAU;}
")"		{return PARDRO;}

{identifier}   	{yylval.string = strdup(yytext);return ID;}
{number}      	{yylval.value = atoi(yytext); return NUMBER; }
{chaine}	{yylval.string = strdup(yytext);return CHAINE;}
[\n]		{}	
.          	{}
%%
