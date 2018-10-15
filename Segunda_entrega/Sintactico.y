%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "y.tab.h"
#define TAM_PILA 100
#define TODO_OK 1
#define ERROR 0

//DECLARACION FUNCIONES

int yyerror();
int yylex();
int yyparse();

int crearArchivoIntermedia();
char * aux;
int cont = 0;
int insertarEnLista(char*);
void escribirEnLista(int, char*);
char * valorComparacion(char * );
char comparador_usado[2];

//DECLARACION PILA
char * pila[TAM_PILA];
int tope_pila=0;
//int puntero_pila;
void apilar(char * val);
int desapilar();
int pilaVacia();
int pilaLlena();

//DECLARACION VARIABLES
int puntero_tokens=1; // arranca en uno para comparar en notepad++
int pos_actual=0;
int yystopparser=0;
char * listaTokens[10000];
FILE *yyin;
FILE *fIntermedia; //ARCHIVO CON INTERMEDIA


%}

%union {
	int intval;
	char *str_val;
}

%start programa
%token <str_val>ID
%token <str_val>CONST_INT
%token <str_val>CONST_STR
%token <str_val>CONST_REAL
%token PROGRAM
%token DECVAR
%token ENDDEC
%token DEFVAR
%token ENDDEF
%token REAL
%token INTEGER
%token STRING
%token BEGINP
%token ENDP
%token IF THEN ELSE ENDIF
%token FOR TO DO ENDFOR
%token WHILE ENDW
%token REPEAT UNTIL
%token OP_AND
%token OP_OR
%token OP_NOT
%token <str_val>OP_COMPARACION
%token OP_ASIG 
%token OP_DOSP
%token OP_SUM
%token OP_RES
%token OP_MUL
%token OP_DIV
%token CAR_COMA
%token CAR_PUNTO
%token CAR_PYC
%token CAR_PA 
%token CAR_PC
%token CAR_CA 
%token CAR_CC 
%token LONG
%token BETWEEN
%token IN
%token WRITE
%token READ


%%
programa:  	   
	PROGRAM {printf("\tInicia el COMPILADOR\n");} est_declaracion algoritmo    
	{printf("\tFin COMPILADOR ok\n"); if(crearArchivoIntermedia()==TODO_OK){printf("Archivo con intermedia generado");}else{printf("Hubo un error al generar el archivo de intermedia");}}
	;

est_declaracion:
	DECVAR {printf("\t\tDECLARACIONES\n");} declaraciones ENDDEC {printf("\tFin de las Declaraciones\n");}
        ;
		
est_declaracion:
	DEFVAR {printf("\t\tDECLARACIONES DEF\n");} declaraciones ENDDEF {printf("\tFin de las Declaraciones DEF\n");}
        ;

declaraciones:         	        	
             declaracion
             | declaraciones declaracion
    	     ;

declaracion:  
           lista_var OP_DOSP REAL
			| lista_var OP_DOSP STRING
			| lista_var OP_DOSP INTEGER
           ;

lista_var:  
	ID 
	 | lista_var CAR_COMA ID  
 	 ;
	 
algoritmo: 
         BEGINP{printf("\tCOMIENZO de BLOQUES\n");} bloque ENDP
         ;

bloque:  
      bloque sentencia
      |sentencia
      ;

sentencia:
  	 ciclo
	 |seleccion  
	 |asignacion
	 |entrada_salida
	 |between	 
	 ;

ciclo:
     REPEAT { printf("\t\tREPEAT\n");}bloque UNTIL condicion { printf("\t\tFIN DEL REPEAT\n");}
	 | WHILE {printf("\t\tWHILE\n");} CAR_PA condicion CAR_PC bloque ENDW{ printf("\t\tFIN DEL WHILE\n");}
     ;

asignacion:
			lista_id OP_ASIG expresion {insertarEnLista(":="); printf("\t\tFIN LINEA ASIGNACION\n");}
	  ;

lista_id:
			lista_id OP_ASIG ID {insertarEnLista(":="); insertarEnLista(yylval.str_val);}
			| ID {insertarEnLista(yylval.str_val);}
		;
	  
entrada_salida: 
	READ{printf("\t\tREAD\n"); } ID 
	|WRITE{printf("\t\tWRITE\n");} ID 
	|WRITE{printf("\t\tWRITE\n");} CONST_STR
;

seleccion: 
    	IF CAR_PA condicion CAR_PC then_ bloque  ENDIF {
				int x;
				x=desapilar();
				char sPosActual[5];
				itoa(puntero_tokens,sPosActual,10);
				sprintf(listaTokens[x],"CELDA %s",sPosActual);
				printf("\t\tFIN DEL IF\n"); 
			}
		| IF CAR_PA condicion CAR_PC then_ bloque else_ bloque ENDIF {printf("\t\tFIN DEL IF\n");}	
;

then_: THEN {
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				int iPosActual;
				char sPosActual[5];
				iPosActual = insertarEnLista("###"); // ACA estoy aumentando el tope de pila (avanzo) no inserta nada, pero avanza el puntero y devuelve en que celda estaba
				itoa(iPosActual,sPosActual,10);
				apilar(sPosActual);
				
				
			}
;			
else_: ELSE {
				int x;
				x=desapilar();
				char sPosActual[5];
				itoa(puntero_tokens,sPosActual,10);
				escribirEnLista(x,sPosActual);
				sprintf(listaTokens[x],"CELDA %s",sPosActual);	
		}
;

condicion:
         comparacion 
         |OP_NOT comparacion{printf("\t\tNOT CONDICION\n");}
         |comparacion op_and_ comparacion{	
											int x;
											x=desapilar();
											char sPosActual[5];
											itoa(puntero_tokens,sPosActual,10);
											escribirEnLista(x,sPosActual);
											sprintf(listaTokens[x],"CELDA %s",sPosActual);
											printf("\t\tCONDICION DOBLE AND\n");
										}
		 |comparacion OP_OR comparacion{printf("\t\tCONDICION DOBLE OR\n");}
		 |OP_NOT CAR_PA comparacion OP_AND comparacion CAR_PC {printf("\t\tNOT CONDICION DOBLE AND\n");}
		 |OP_NOT CAR_PA comparacion OP_OR  comparacion CAR_PC{printf("\t\tNOT CONDICION DOBLE OR\n");}
		 |between
		 |OP_NOT between
	 ;

op_and_: OP_AND{
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				int iPosActual;
				char sPosActual[5];
				iPosActual = insertarEnLista("###"); // no inserta nada, pero avanza el puntero y devuelve en que celda estaba
				itoa(iPosActual,sPosActual,10);
				apilar(sPosActual);
			}	 
;	 
comparacion:
	   expresion OP_COMPARACION {strcpy(comparador_usado,yylval.str_val);}  expresion
	   ;

expresion:
		expresion OP_SUM termino {insertarEnLista("+");}
		|expresion OP_RES  termino {insertarEnLista("-");}
        | termino
 	 ;
	 
between: 
	{printf("\t\tINICIO BETWEEN\n");}BETWEEN CAR_PA ID CAR_COMA CAR_CA expresion CAR_PYC expresion CAR_CC CAR_PC {printf("\t\tFIN BETWEEN\n");}
	 ;
	 
termino: 
	   termino OP_MUL factor {insertarEnLista("*");}
	   |termino OP_DIV factor {insertarEnLista("/");}
       |factor
	   ;

factor: 
      ID {insertarEnLista(yylval.str_val);}
      | CONST_INT {insertarEnLista(yylval.str_val);}
      | CONST_REAL {insertarEnLista(yylval.str_val);}
      | CONST_STR  {insertarEnLista(yylval.str_val);}
	  | CAR_PA expresion CAR_PC 	  
      ;

%%
// FUNCIONES DE PILA
void apilar(char * val)
{
	tope_pila++;
	if(pilaLlena() == 1){
		printf("Error: Se exedio el tamano de la pila.\n");
		system ("Pause");
		exit (1);
	}
	pila[tope_pila]=val;
	printf("APILAR #CELDA ACTUAL -> %s\n",val);
}

int desapilar()
{
	if(pilaVacia() == 0)
	{
		char * dato = pila[tope_pila];
		tope_pila--;	
		printf("DESAPILAR #CELDA -> %s\n",dato);
		return atoi(dato);		
	} else {
		printf("Error: La pila esta vacia.\n");
		system ("Pause");
		exit (1);
	}
	
}

int pilaVacia()
{
	if (tope_pila == -1){
		return 1;
	} 
	return 0;
}

int pilaLlena()
{
	if (tope_pila == TAM_PILA-1){
		return 1;
	} 
	return 0;
}


int insertarEnLista(char * val)
{
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// Agrego al array de tokens
	listaTokens[puntero_tokens] = aux;
	puntero_tokens++;
	
	//escribo en archivo
	//fprintf(fintermedia,"%s\n",aux);
	
	// DEBUG por consola
	if(strcmp(aux,"###")!=0){
		printf("insertar_en_polaca(%s)\n", aux);
	}
	return (puntero_tokens-1); // devuelvo posicion
	
}

void escribirEnLista(int pos, char * val)
{
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// escribo en vector
	listaTokens[pos] = aux;
	
	printf("Escribio en %i el valor %s\n",pos,aux);
	
}

char * valorComparacion(char * val){
	if(strcmp("=", val) == 0){
		return "BNE";
	} else if(strcmp(">=", val) == 0){
		return "BLT";
	} else if(strcmp(">", val) == 0){
		return "BLE";
	} else if(strcmp("<=", val) == 0){
		return "BGT";
	} else if(strcmp("<", val) == 0){
		return "BGE";
	} else if(strcmp("><", val) == 0){
		return "BEQ";
	} else {
		// NUNCA DEBERIA CAER ACA
		return val;
	}
}

int yyerror()
{
	printf("ERROR - Syntax error\n");
	system ("Pause");
	exit (1);
}

int main(int argc,char *argv[])
{
	
	if ((yyin = fopen(argv[1], "rt")) == NULL)
	{	
		printf("\nError al abrir archivo: %s\n", argv[1]); 
	} 
	else
	{ 
		yyparse();
	}
			
	fclose(yyin);
	return 0;
}

int crearArchivoIntermedia()
{
	FILE * archivo; 
	int i;
	archivo = fopen("intermedia.txt", "wt");

	if (!archivo){	return ERROR; }

	for (i = 1; i < puntero_tokens; i++)
	{
		fprintf(archivo,"CELDA %d: %s\n", i, listaTokens[i]);
		
	}
	fclose(archivo); 

	return TODO_OK;
}
