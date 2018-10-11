%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"
#define COTA_INT 2147483647
#define COTA_FLOAT	3.402823E+38
#define TODO_OK 1
#define ERROR 0

FILE  *yyin;
int yylval;


%}
%option noyywrap  
%option yylineno 

DIGITO			[0-9]
NUM_INT			({DIGITO})+
NUM_REAL		({DIGITO})+"."({DIGITO})*|({DIGITO})*"."({DIGITO})+
LETRA			[a-zA-Z]
COMENTARIO_SIMPLE		"-/"({LETRA}|{DIGITO}|_|" "|":"|"="|"."|"-"|",")*"/-"
COMENTARIO_DOBLE		"-/"({LETRA}|{DIGITO}|_|" "|":"|"="|"."|"-"|","|{COMENTARIO_SIMPLE})*"/-"
CONST_STR               {CAR_COMILLAS}({LETRA}|{DIGITO}|" "|_|@|%|{OP_COMPARACION}|{OP_SURES}|{OP_MULTDIV})+{CAR_COMILLAS}
CONST_REAL              ({DIGITO}*"."{DIGITO}+)|({DIGITO}+"."{DIGITO}*)
CONST_INT               {DIGITO}+
ID						{LETRA}({LETRA}|{DIGITO}|_)*
OP_COMPARACION          ["<"|"="|">"|"<="|">="|"><"]
OP_SURES                ["+"|"-"]
OP_MULTDIV              ["*"|"/"]
OP_ASIG   				[":="]
OP_DOSP   				[":"]
OP_AND					["AND"|"and"|"&&"]
OP_OR					["OR"|"or"|"||"]
OP_NOT					["NOT"|"not"]
BETWEEN					["BETWEEN"|"between"]
CAR_COMA                   [","]
CAR_PYC                    [";"]
CAR_PUNTO                  ["."]
CAR_CA                     ["["]
CAR_CC                     ["]"]
CAR_PA                     ["("]
CAR_PC                     [")"]
CAR_COMILLAS			   ["\""]
%%
"program"		{ return PROGRAM;}
"DECVAR"		{ return DECVAR;}
"decvar"		{ return DECVAR;}
"ENDDEC"		{ return ENDDEC;}
"enddec"		{ return ENDDEC;}
"DEFVAR"		{ return DEFVAR;}
"defvar"		{ return DEFVAR;}
"ENDDEF"		{ return ENDDEF;}
"enddef"		{ return ENDDEF;}
"beginp"		{ return BEGINP;}
"endp"			{ return ENDP; 	}
"ENDP"			{ return ENDP; 	}
{COMENTARIO_DOBLE}	{  }
{COMENTARIO_SIMPLE}	{  }
"real"			{ return REAL;}
"REAL"			{ return REAL;}
"float"			{ return REAL;}
"FLOAT"			{ return REAL;}
"integer"		{ return INTEGER;}
"INTEGER"		{ return INTEGER;}
"INT"			{ return INTEGER;}
"string"		{ return STRING;}
"STRING"		{ return STRING;}
"if"			{ return IF;}
"IF"			{ return IF;}
"then"   		{ return THEN;}
"THEN"   		{ return THEN;}
"else"   		{ return ELSE;}
"ELSE"   		{ return ELSE;}
"endif"	      { return ENDIF;}
"ENDIF"	      { return ENDIF;}
"for"			{ return FOR;}
"FOR"			{ return FOR;}
"to"		      { return TO;}
"TO"		      { return TO;}
"do"	         	{ return DO;}
"DO"	         	{ return DO;}
"endfor"		{ return ENDFOR;}
"ENDFOR"		{ return ENDFOR;}
"while"	      {return WHILE;}
"WHILE"	      {return WHILE;}
"in"	         	{return IN;}
"IN"	         	{return IN;}
"endw"  		{ return ENDW;}
"ENDW"  		{ return ENDW;}
"repeat"		{ return REPEAT;}
"REPEAT"		{ return REPEAT;}
"until"		{ return UNTIL;}
"UNTIL"		{ return UNTIL;}
"WRITE"		{ return WRITE; }
"write"		{ return WRITE; }
"READ"		{ return READ; }
"read"		{ return READ; }
":="			{ return OP_ASIG;}
"+"			{ return OP_SURES;}
"-"			{ return OP_SURES;}
"*"			{ return OP_MULTDIV;}
"/"			{ return OP_MULTDIV;}
"["			{ return CAR_CA;}
"]"			{ return CAR_CC;}
"("			{ return CAR_PA;}
")"			{ return CAR_PC;}
";"			{ return CAR_PYC;}
">"                     { return OP_COMPARACION;}
">="                    { return OP_COMPARACION;}
"<"                     { return OP_COMPARACION;}
"<="                    { return OP_COMPARACION;}
"><"                    { return OP_COMPARACION;}
"="                     { return OP_COMPARACION;}
":"                     { return OP_DOSP;}
"&&"                   { return OP_AND;}
"AND"                   { return OP_AND;}
"and"                   { return OP_AND;}
"OR"                   { return OP_OR;}
"or"                   { return OP_OR;}
"||"                   { return OP_OR;}
"NOT"                   { return OP_NOT;}
"not"                   { return OP_NOT;}
"BETWEEN"		{ return BETWEEN;}
"between"		{ return BETWEEN;}
{ID}			{ return ID; }
{CONST_INT}		{ return CONST_INT;}
{CONST_STR}		{ return CONST_STR;}
{CONST_REAL}	{ return CONST_REAL;}
{CAR_COMA}		{ return CAR_COMA;}
{CAR_PUNTO}		{ return CAR_PUNTO;}
{NUM_INT}	{ 
				int num = atoi(yytext); 
				if(num >= 0 && num <= COTA_INT){
					
					return CONST_INT; 
				}else{
					printf("ERROR - Int fuera de rango.\n");
					system ("Pause");
					exit(1);
				}
			}
{NUM_REAL}	{ 
				double n;
				n = atof(yytext);
				
				if(n >= 0 && n <= COTA_FLOAT){
					
					return CONST_REAL; 
				}else{
					printf("ERROR - Real fuera de rango.\n");
					system ("Pause");
					exit(2);
				}
			}

"\n"      		
"\t"		
" "

%%

