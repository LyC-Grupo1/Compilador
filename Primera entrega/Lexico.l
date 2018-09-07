%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
%}

%option noyywrap
%option yylineno

DIGITO			[0-9]
NUMERO			{DIGITO}+
NUMERO_REAL		({NUMERO}*){CAR_DECIMAL}({NUMERO}*)
STRING			{CAR_COMILLA}{CADENA}{CAR_COMILLA}
CADENA			({DIGITO}|{LETRA}|{CARACTER_ESP})+

ID				"$"({MINUS}|{MAYUS})+
CONTENIDO_MUL	[({MINUS}|{MAYUS}|{NUMERO})* \n]
CONTENIDO_LIN	[({MINUS}|{MAYUS}|{NUMERO}]*
MINUS			[a-z]
MAYUS			[A-Z]

LETRA			({MINUS}|{MAYUS})+
OPERADOR		({OP_SUM}|{OP_RES}|{OP_MUL}|{OP_DIV})

WHILE			"WHILE"
DO				"DO"
IF				"IF" 	
THEN			"THEN"	
ELSE			"ELSE"
DECVAR			"DECVAR"
ENDDEF			"ENDDEF"
BETWEEN			"BETWEEN"
OP_SUM			"+"
OP_RES			"-"
OP_MUL			"*"
OP_DIV			"/"
OP_IGU			"="
OP_ASIG			":="
COMP_IGU		"=="
COMP_DIS		"!="
COMP_MAY		">"
COMP_MEN		"<"
COMP_MAYI		">="
COMP_MINI		"<="
CAR_DECIMAL		"."
CAR_PYC			";"
CAR_COM			","
CAR_PUN			"."
CAR_DOSP		":"
CAR_ARROBA		"@"
CAR_CONBA		"\\"
CAR_PREGCIE		"?"	
CAR_PREGABR		"¿"
CAR_PA			"("
CAR_PC			")"
CAR_LLA			"{"
CAR_LLC			"}"
CAR_CA			"["
CAR_CC			"]"
CAR_COMILLA		"\""
COM_ABRE		"/-"
COM_CIERRA		"*/"
COM_BARRA		"-/"


%%
{}
{NUMERO} {yylval = atoi(yytext) ;return NUMERO;}
{NUMERO_REAL} {yylval = atof(yytext) ;return NUMERO_REAL;}
STRING			{return STRING;}
ID				{return ID;}
WHILE			{return WHILE;}
DO				{return DO;}
IF				{return IF;}	
THEN			{return THEN;}
ELSE			{return ELSE;}
DECVAR			{return DECVAR;}
ENDDEF			{return ENDDEF;}
BETWEEN			{return OP_SUM;}
OP_SUM			{return OP_SUM;}
OP_RES			{return OP_RES;}
OP_MUL			{return OP_MUL;}
OP_DIV			{return OP_DIV;}
OP_IGU			{return OP_IGU;}
OP_ASIG			{return OP_ASIG;}
COMP_IGU		{return COMP_IGU;}
COMP_DIS		{return COMP_DIS;}
COMP_MAY		{return COMP_MAY;}
COMP_MEN		{return COMP_MEN;}
COMP_MAYI		{return COMP_MAYI;}
COMP_MINI		{return COMP_MINI;}
CAR_DECIMAL		{return CAR_DECIMAL;}
CAR_PYC			{return CAR_PYC;}
CAR_COM			{return CAR_COM;}
CAR_PUN			{return CAR_PUN;}
CAR_DOSP		{return CAR_DOSP;}
CAR_CONBA		{return CAR_CONBA;}
CAR_PREGCIE		{return CAR_PREGCIE;}	
CAR_PREGABR		{return CAR_PREGABR;}
CAR_PA			{return CAR_PA;}
CAR_PC			{return CAR_PC;}
CAR_LLA			{return CAR_LLA;}
CAR_LLC			{return CAR_LLC;}
CAR_CA			{return CAR_CA;}
CAR_CC			{return CAR_CC;}
CAR_COMILLA		{return CAR_COMILLA;}
COM_ABRE		{return COM_ABRE;}
COM_CIERRA		{return COM_CIERRA;}
COM_BARRA		{return COM_BARRA;}
%%

