%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "y.tab.h"

#define TAM_PILA 100
#define TODO_OK 1
#define ERROR 0

struct struct_tablaSimbolos
{
	char nombre[100];
	char tipo[100];
	char valor[50];
	char longitud[100];
};


//DECLARACION FUNCIONES
int yylex();
int yyparse();
//int yyerror(void);
int apilar(int);

//DECLARACION VARIABLES
int pila[TAM_PILA];
int puntero_pila;
int pos_actual=0;
int yystopparser=0;
FILE  *yyin;
FILE *fIntermedia; //ARCHIVO CON INTERMEDIA

int puntero_array = 0;
struct struct_tablaSimbolos tablaSimbolos[1000];
char* matrizTipoVariable[100][100];
int punteroColumnaTipo = 0;
int punteroFilaTipo = 0;
char* matrizNombreVariable[100][100];

int punteroColumnaNombre = 0;
int punteroFilaNombre = 0;
void guardarTipoEnMatriz(char*);
void guardarNombreEnMatriz(char*);
char* buscarTipoConNombre(char*);
char* buscarTipoConPosiciones(int, int);
int push_TS(char*, char*);
int crear_TS();

%}

%start programa
%token PROGRAM
%token DECVAR
%token ENDDEC
%token DEFVAR
%token ENDDEF
%token CONST_INT
%token CONST_REAL
%token CONST_STR
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
%token ID
%token OP_COMPARACION
%token OP_ASIG 
%token OP_DOSP
%token OP_SURES
%token OP_MULTDIV
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
	{printf("\tFin COMPILADOR ok\n"); crear_TS();};

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
           lista_var OP_DOSP REAL { guardarTipoEnMatriz("REAL"); }
			| lista_var OP_DOSP STRING { guardarTipoEnMatriz("STRING"); }
			| lista_var OP_DOSP INTEGER { guardarTipoEnMatriz("INTEGER"); }
           ;

lista_var:  
	 ID {fprintf(fIntermedia,"%i-ID | ",pos_actual);}
	 | lista_var CAR_COMA ID   
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
     /*|asignacion_multiple*/
	 |entrada_salida
	 |between	 
	 ;

ciclo:
     REPEAT { printf("\t\tREPEAT\n");}bloque UNTIL condicion { printf("\t\tFIN DEL REPEAT\n");}
	 | WHILE { printf("\t\tWHILE\n");}CAR_PA condicion CAR_PC bloque ENDW{ printf("\t\tFIN DEL WHILE\n");}
     ;

asignacion:
			lista_id OP_ASIG expresion {printf("\t\tFIN LINEA ASIGNACION\n");}
	  ;

lista_id:
			lista_id OP_ASIG ID 
			| ID 
		;
	  
entrada_salida: 
	READ{printf("\t\tREAD\n"); } ID 
	|WRITE{printf("\t\tWRITE\n");} ID 
	|WRITE{printf("\t\tWRITE\n");} CONST_STR
;

seleccion: 
    	 IF CAR_PA condicion CAR_PC THEN bloque ENDIF{printf("\t\tIF\n");}
		| IF CAR_PA condicion CAR_PC THEN bloque ELSE bloque ENDIF {printf("\t\t IF CON ELSE\n");}	 
;

condicion:
         comparacion 
         |comparacion OP_AND comparacion{printf("\t\tCONDICION DOBLE AND\n");}
		 |comparacion OP_OR  comparacion{printf("\t\tCONDICION DOBLE OR\n");}
	 ;

comparacion:
	   expresion OP_COMPARACION expresion
	   ;

expresion:
         termino
		|expresion OP_SURES termino
 	 ;
	 
between: 
	BETWEEN CAR_PA ID CAR_COMA CAR_CA expresion CAR_PYC expresion CAR_CC CAR_PC {printf("\t\tBETWEEN\n");}
	 ;
	 
termino: 
       factor
       |termino OP_MULTDIV factor
       ;

factor: 
      ID { guardar_TS("ID", $1);}
      | CONST_INT 
      | CONST_REAL 
      | CONST_STR 
	  | CAR_PA expresion CAR_PC 	  
      ;

%%

void guardarTipoEnMatriz(char* tipo){
	matrizTipoVariable[punteroFilaTipo][punteroColumnaTipo] = tipo;
	punteroColumnaTipo++;
}

void guardarNombreEnMatriz(char* nombre){
	matrizNombreVariable[punteroFilaNombre][punteroColumnaNombre] = nombre;
	punteroColumnaNombre++;
}

char* buscarTipoConNombre(char* nombre){
	int i, j;
	char* tipo = "";
	for(i = 0; i <= punteroFilaNombre; i++){
		for(j = 0; j < 100; j++){
			if(matrizNombreVariable[i][j] && strcmp(matrizNombreVariable[i][j], nombre) == 0){
				tipo = buscarTipoConPosiciones(i, j);
			}
		}
	}
	return tipo;
}

char* buscarTipoConPosiciones(int i, int j){
	char* tipo = matrizTipoVariable[i][j];
	if(tipo)
		return tipo;
	else
		return "";
}

int push_TS(char* tipo, char* nombre)
{
	int i;
	int retornar;
	for(i = 0; i < puntero_array; i++){
		if(strcmp(tablaSimbolos[i].nombre, nombre) == 0){
			return i;
		}
	}
	strcpy(tablaSimbolos[puntero_array].tipo, tipo);
	strcpy(tablaSimbolos[puntero_array].nombre, nombre);
	retornar = puntero_array;
	puntero_array++;
	return retornar;
}

int crear_TS(){
	FILE *pf; 
	int i;
	pf = fopen("ts.txt","w"); 
	char* tipo;

	if (!pf)
		return 0;

	fprintf(pf, "Nombre\t\t\tTipo\t\t\tValor\t\t\tLongitud\n");
	for (i = 0; i < puntero_array; i++)
		if (strcmp(tablaSimbolos[i].tipo, "ID") == 0 ){
			tipo = buscarTipoConNombre(tablaSimbolos[i].nombre);
			if(strcmp(tipo, "") != 0)
				fprintf(pf,"%s\t\t\t%s\n", tablaSimbolos[i].nombre, tipo);
		}else
			fprintf(pf,"_%s\t\t\t%s\t\t\t%s\n", tablaSimbolos[i].nombre, tablaSimbolos[i].tipo, tablaSimbolos[i].nombre);
	fclose(pf); 

	return 1;
}


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

int yyerror(void)
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
	fIntermedia=fopen("intermedia.txt", "wt");
	if(fIntermedia==NULL)
	{
		printf("Error al crear archivo intermedia.txt \n");
		system("PAUSE");
		return 0;
	}
	
	if ((yyin = fopen(argv[1], "rt")) == NULL)
	{	
		printf("\nError al abrir archivo: %s\n", argv[1]); 
	} 
	else
	{ 
		yyparse();
	}
			
	fclose(yyin);
	fclose(fIntermedia);
	return 0;
}



