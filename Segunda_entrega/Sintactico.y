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
int apilar(int);

char * aux;
int cont = 0;
void insertarEnLista(char*);
char * valorComparacion(char * );

//DECLARACION VARIABLES
int pila[TAM_PILA];
int puntero_pila;
int puntero_tokens=0;
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
	{printf("\tFin COMPILADOR ok\n"); if(crearArchivoIntermedia()==TODO_OK){printf("Archivo con intermedia generado");}else{printf("Hubo un error al generar el archivo de intermedia");}};

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
	ID {fprintf(fIntermedia,"%i-ID | ",pos_actual);}
	 | lista_var CAR_COMA ID {fprintf(fIntermedia,"%i-ID | ",pos_actual);}  
 	 ;
	 
algoritmo: 
         BEGINP{printf("\tCOMIENZO de BLOQUES\n");} bloque ENDP
         ;

bloque:  
      sentencia
      |bloque sentencia
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
	 | WHILE { printf("\t\tWHILE\n");}CAR_PA condicion CAR_PC bloque ENDW{ printf("\t\tFIN DEL WHILE\n");}
     ;

asignacion:
			lista_id OP_ASIG {insertarEnLista(":=");} expresion {printf("\t\tFIN LINEA ASIGNACION\n");}
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
    	IF CAR_PA condicion CAR_PC THEN bloque ENDIF{printf("\t\tENDIF\n");}
		| IF CAR_PA condicion CAR_PC THEN bloque ELSE bloque ENDIF {printf("\t\t IF CON ELSE\n");}	
;

condicion:
         comparacion {insertarEnLista(yylval.str_val);}
         |OP_NOT comparacion{insertarEnLista(yylval.str_val); printf("\t\tNOT CONDICION\n");}
         |comparacion OP_AND comparacion{insertarEnLista(yylval.str_val); printf("\t\tCONDICION DOBLE AND\n");}
		 |comparacion OP_OR  comparacion{insertarEnLista(yylval.str_val); printf("\t\tCONDICION DOBLE OR\n");}
		 |OP_NOT CAR_PA comparacion {insertarEnLista(yylval.str_val);} OP_AND comparacion CAR_PC{printf("\t\tNOT CONDICION DOBLE AND\n");}
		 |OP_NOT CAR_PA comparacion {insertarEnLista(yylval.str_val);} OP_OR  comparacion CAR_PC{printf("\t\tNOT CONDICION DOBLE OR\n");}
		 |between
		 |OP_NOT between
	 ;

comparacion:
	   expresion OP_COMPARACION {insertarEnLista("CMP"); insertarEnLista(valorComparacion(yylval.str_val));} expresion
	   ;

expresion:
         termino
		|expresion OP_SUM {insertarEnLista("+");} termino
		|expresion OP_RES {insertarEnLista("-");} termino
 	 ;
	 
between: 
	BETWEEN CAR_PA ID CAR_COMA CAR_CA expresion CAR_PYC expresion CAR_CC CAR_PC {printf("\t\tBETWEEN\n");}
	 ;
	 
termino: 
       factor
       |termino OP_MUL {insertarEnLista("*");}factor
	   |termino OP_DIV {insertarEnLista("/");}factor
       ;

factor: 
      ID {insertarEnLista(yylval.str_val);}
      | CONST_INT {insertarEnLista(yylval.str_val);}
      | CONST_REAL {insertarEnLista(yylval.str_val);}
      | CONST_STR  {insertarEnLista(yylval.str_val);}
	  | CAR_PA expresion CAR_PC 	  
      ;

%%

int apilar(int pos)
{
	puntero_pila++;
	if(puntero_pila > TAM_PILA){
		printf("Error: Se exedio el tamano de la pila.\n");
		system ("Pause");
		exit (1);
	}
	pila[puntero_pila]=pos;
}

char * desapilar()
{
	
}

void insertarEnLista(char * val)
{
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// Agrego al array de tokens
	listaTokens[puntero_tokens] = aux;
	puntero_tokens++;
	
	// DEBUG por consola
    printf("insertar_en_polaca(%s)\n", aux);
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
	puntero_pila = -1;
	// Si no abro el archivo antes de leer prueba no escribe
	//printf("Abriendo archivo intermedia.txt ------------------------------------------");
	//fIntermedia=fopen("intermedia.txt", "wt");
	//if(fIntermedia==NULL)
	//{
	//	printf("Error al crear archivo intermedia.txt \n");
//		system("PAUSE");
//		return 0;
//	}
	
	if ((yyin = fopen(argv[1], "rt")) == NULL)
	{	
		printf("\nError al abrir archivo: %s\n", argv[1]); 
	} 
	else
	{ 
		yyparse();
	}
			
	fclose(yyin);
//	fclose(fIntermedia);
	return 0;
}

int crearArchivoIntermedia()
{
	FILE * archivo; 
	int i;
	archivo = fopen("intermedia.txt", "wt");

	if (!archivo){	return ERROR; }

	for (i = 0; i < puntero_tokens; i++)
	{
		fprintf(archivo,"%s\n", listaTokens[i]);
		
	}
	fclose(archivo); 

	return TODO_OK;
}
