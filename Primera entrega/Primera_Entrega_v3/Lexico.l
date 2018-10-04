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

struct struct_tablaSimbolos
{
	char nombre[100];
	char tipo[100];
	char valor[50];
	char longitud[100];
};

int push_TS(char*, char*);
int crear_TS();

int puntero_array = 0;
FILE  *yyin;
int yylval;
struct struct_tablaSimbolos tablaSimbolos[10000];

%}
%option noyywrap  
%option yylineno 

DIGITO			[0-9]
NUM_INT			"-"?({DIGITO})+
NUM_REAL		"-"?({DIGITO})+"."({DIGITO})*|({DIGITO})*"."({DIGITO})+
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
"endp"			{ 					
					if (crear_TS() == 0)
					{
						printf("Error al crear tabla de símbolos\n");
					}
					return ENDP; 	
				}
"ENDP"			{ 					
					if (crear_TS() == 0)
					{
						printf("Error al crear tabla de símbolos\n");
					}
					return ENDP; 	
				}
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
{ID}			{ push_TS("ID", yytext); return ID; }
{CONST_INT}		{ return CONST_INT;}
{CONST_STR}		{ 
					int cantCaracteres = strlen(yytext);
					if(cantCaracteres <= 200) {
						push_TS("CONST_STR", yytext);
						return CONST_STR;
					} else {
						printf("ERROR - String muy largo. Maximo 200 caracteres\n");
						system ("Pause");
						exit(3);
					}
				}
{CONST_REAL}	{ return CONST_REAL;}
{CAR_COMA}		{ return CAR_COMA;}
{CAR_PUNTO}		{ return CAR_PUNTO;}
{NUM_INT}	{ 
				int num = atoi(yytext); 
				if(num >= COTA_INT*(-1) && num <= COTA_INT){
					push_TS("CONST_INT", yytext);
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
				
				if(n >= COTA_FLOAT*(-1) && n <= COTA_FLOAT){
					push_TS("CONST_REAL", yytext);
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
int push_TS(char* tipo, char* nombre)
{
	int i, posicion;
	
	for(i = 0; i < puntero_array; i++)
	{
		if(strcmp(tablaSimbolos[i].nombre, nombre) == 0)
		{
			return i;
		}
	}
	strcpy(tablaSimbolos[puntero_array].tipo, tipo);
	strcpy(tablaSimbolos[puntero_array].nombre, nombre);
	posicion = puntero_array;
	puntero_array++;
	return posicion;
}

int crear_TS()
{
	FILE *archivo; 
	int i;
	archivo = fopen("ts.txt","w"); 

	if (!archivo){	return ERROR; }

	fprintf(archivo, "Nombre \t \t Tipo \t \t Valor \t \t Longitud\n");
	
	for (i = 0; i < puntero_array; i++)
	{
		if (strcmp(tablaSimbolos[i].tipo, "ID") == 0 )
		{  
			fprintf(archivo,"%s\n", tablaSimbolos[i].nombre);
		}
		else
		{
			fprintf(archivo,"_%s\n", tablaSimbolos[i].nombre);
		}
	}
	fclose(archivo); 

	return TODO_OK;
}

