%option nounput
%option noyywrap
%{
  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"

%}

identifier	[a-zA-Z_]+[0-9a-zA-Z_]*
number     	[0-9]+
real		[0-9]+\.[0-9]+
chaine		\"(\\.|[^\"\\])*\"
%%
"main"			{return MAIN;}
"return"		{return RETURN;}

"int"			{return INT;}
"float"			{return FLOAT;}
"matrix"		{return MATRIX;}

[-+()=/*;(){}<>]		{return yytext[0];}

"["				{return yytext[0];}
"]"				{return yytext[0];}
">="            {return GE;}
"<="            {return LE;}
"=="            {return EQ;}
"!="            {return NE;}

"while"         {return WHILE;}
"if"            {return IF;}
"else"          {return ELSE;}
"print"         {return PRINT;}
"printf"        {return PRINTF;}
"printtab"      {return PRINTTAB;}
"then"			{return THEN;}
"do"			{return DO;}
"done"			{return DONE;}
"endif"			{return ENDIF;}

[ \t\n]+		;

{identifier}   	{yylval.val_str = strdup(yytext);return ID;}
{number}     	{yylval.val_num = atoi(yytext);return NUMBER;}
{real}			{yylval.val_real = atof(yytext);return REAL;}
{chaine}		{yylval.val_str = strdup(yytext);return CHAINE;}

%%
