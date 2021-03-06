%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "y.tab.h"
#include "asm.h"	
#define TAM_PILA 100
#define TODO_OK 1
#define ERROR 0
#define EXISTE 1
#define NO_EXISTE 0
#define PILA_IF 0
#define PILA_DECLARACION 1
#define PILA_WHILE 2
#define PILA_ASIGNACION 3
#define PILA_REPEAT 4
#define PILA_BETWEEN 5
#define TRUE 1
#define FALSE 0

//DECLARACION FUNCIONES

int yyerror();
int yylex();
int yyparse();

void finAnormal(char *, char * );
void validarDeclaracionTipoDato(char *);
int insertarEnListaAsig(char *);
void debugListaAsignacion();
int insertarEnListaDeclaracion(char *);
int verificarExistencia(char* );
char * valorComparacionCICLO(char * ); // utilizado en repeat
// TABLA DE SIMBOLOS

struct struct_tablaSimbolos
{
	char nombre[100];
	char tipo[100];
	char valor[50];
	char longitud[100];
};

int puntero_ts = 0;
struct struct_tablaSimbolos tablaSimbolos[10000];
////////////////////////////
int insertar_TS(char*, char*);
int crearArchivoTS();
void debugTS();
char * recuperarValorTS(char* nombre);

int crearArchivoIntermedia();
char * aux;
char valorFactor[5],valorTermino[5],valorElemento[5];
double sumTermino = 0;
double sumElemento = 0;

int cont = 0;
int iPosCondDos;
int insertarEnLista(char*);
void escribirEnLista(int, char*);
char * valorComparacion(char * );
char comparador_usado[2];

// PILAS 
char * pilaIF[TAM_PILA];			// pila 0
char * pilaWhile[TAM_PILA];			// pila 1
char * pilaAsignacion[TAM_PILA];	// pila 3
char * pilaRepeat[TAM_PILA];		// pila 4
char * pilaBetween[TAM_PILA];		// pila 5
int tope_pila_if=0;				// pila 0
int tope_pila_while=0;			// pila 1
int tope_pila_asignacion=0;		// pila 3
int tope_pila_repeat=0;			// pila 4
int tope_pila_between=0;			// pila 5

////////////////////
void apilar(int nroPila, char * val);
int desapilar(int nroPila);
int pilaVacia(int tope);
int pilaLlena(int tope);
void debugPila(int nroPila, int tope);

// LISTAS

char * listaDeclaracion[100];	// lista para declaraciones
char * listaTokens[10000];		// lista de tokens para gci polaca inversa
char * listaAux[100];		// lista de tokens para gci polaca inversa
char * listaAsignacion[30];	// lista para acumular la asignacion multiple
int puntero_declaracion = 0;
int puntero_asignacion = 0;
int puntero_tokens=1; // arranca en uno para comparar en notepad++
int puntero_aux=0;
// DECLARACION DE VARIABLES - FUNCIONES
void debugListaDeclaracion();
int flagWHILE = FALSE;
int flagIFOR = FALSE;
int flagIFAND = FALSE;
int flagWHILEOR = FALSE;
int flagWHILEAND = FALSE;
int flagELSE = FALSE;
int flagPrimero = FALSE;		// para identificar los token en asign multiple
int flagREPEAT = FALSE;
int flagAsigMul = FALSE;
//DECLARACION VARIABLES
char posAuxA[5], posAuxB[5];	// posicion auxiliar para pivotear con la condicion OR
char posTrue[5], posFalse[5],posCondDos[5];
char inicioCuerpoRepeat[5];
//int posTrue, posFalse, posCondDos;
int pos_actual=0;
int yystopparser=0;

FILE *yyin;
FILE *fIntermedia; //ARCHIVO CON INTERMEDIA


%}

%union {
	char * int_val;
	char * real_val;
	char * str_val;
	char * cmp_val;
}

%start programa
%token <str_val>ID
%token <int_val>CONST_INT
%token <str_val>CONST_STR
%token <real_val>CONST_REAL
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
%token <cmp_val>OP_COMPARACION
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
	{printf("\tFin COMPILADOR ok\n"); if(crearArchivoIntermedia()==TODO_OK){printf("\nArchivo con intermedia generado\n");}else{printf("Hubo un error al generar el archivo de intermedia");}}
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
           lista_var OP_DOSP REAL {validarDeclaracionTipoDato("REAL");}; 
			| lista_var OP_DOSP STRING { validarDeclaracionTipoDato("STRING"); }
			| lista_var OP_DOSP INTEGER { validarDeclaracionTipoDato("INTEGER"); }
           ;

lista_var:  
	ID  {	insertarEnListaDeclaracion(yylval.str_val);	}
	 | lista_var CAR_COMA ID {  insertarEnListaDeclaracion(yylval.str_val);	} 
 	 ;
	 
algoritmo: 
         BEGINP{printf("COMIENZO de BLOQUES\n");} bloque ENDP
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
     REPEAT 
	 { 
		flagREPEAT = TRUE; 
		printf("REPEAT\n");
		
		sprintf(inicioCuerpoRepeat, "CELDA %d", puntero_tokens);
		//itoa(puntero_tokens,sPosActual,10);
		//apilar(PILA_REPEAT,inicioCuerpo);
	} bloque UNTIL 
		condicion 
		{ 
			//debugPila(PILA_REPEAT,tope_pila_repeat);
			int x;
			char sPosActual[5];
			escribirEnLista(puntero_tokens-1,inicioCuerpoRepeat);
			x = desapilar(PILA_REPEAT);
			
			sprintf(sPosActual, "CELDA %d", puntero_tokens);
			
			escribirEnLista(x,sPosActual);	// %%%%
			
			printf("FIN DEL REPEAT\n");
		}
	 | WHILE { flagWHILE = TRUE; printf("WHILE\n");} CAR_PA  condicion CAR_PC bloque endw_

endw_: ENDW {
			int x, i, iPosActual;
			char wPosActual[5], wPosActualTrue[5], wPosCondDos[5];
			// debugPila(PILA_WHILE,tope_pila_while);
			
			x=desapilar(PILA_WHILE); // Primero que desapilo -> apunta a la parte verdadera
			sprintf(wPosActualTrue, "CELDA %s", posTrue);
			escribirEnLista(x,wPosActualTrue);
			
			x=desapilar(PILA_WHILE); // Segundo que desapilo -> apunta al final
			sprintf(wPosActual, "CELDA %d", puntero_tokens);
			escribirEnLista(x,wPosActual);
			//debugPila(PILA_WHILE,tope_pila_while);
			
			if(flagWHILEAND == TRUE){
				
				if(pilaVacia(tope_pila_while) == FALSE){
					
					x=desapilar(PILA_WHILE); // Tercero que desapilo -> apunta a la segunda condicion
					sprintf(wPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,wPosCondDos);
					
					x=desapilar(PILA_WHILE); // Cuarto que desapilo -> apunta al final
					sprintf(wPosActual, "CELDA %d", puntero_tokens);
					escribirEnLista(x,wPosActual);
					//debugPila(PILA_WHILE,tope_pila_while);
				}
			
			} else if (flagWHILEOR == TRUE) {
				
				if(pilaVacia(tope_pila_while) == FALSE){
					
					x=desapilar(PILA_WHILE);// Tercero que desapilo -> apunta a la parte verdadera
					sprintf(wPosActualTrue, "CELDA %s", posTrue);
					escribirEnLista(x,wPosActualTrue);
					
					x=desapilar(PILA_WHILE);// Tercero que desapilo -> apunta a la segunda condicion
					sprintf(wPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,wPosCondDos);
				}			
				
			}
			flagWHILEOR = FALSE;
			flagWHILEAND = FALSE;
			flagWHILE = FALSE;

		}
	 
asignacion: // estaria faltando actualizar la tabla de simbolos
			lista_id OP_ASIG 
			expresion {
				int i,x,limit;
				char sAux[5];
				sprintf(sAux,yylval.str_val);
				//debugPila(PILA_ASIGNACION,tope_pila_asignacion);
				
			
			limit = tope_pila_asignacion;
			for (i=0; i < limit;i++)
			{
				x=desapilar(PILA_ASIGNACION);
				//printf("Voy a escribir en la posiciion %d el valor %s\n",x,valorFactor);
				escribirEnLista(x,valorFactor);
				
			}
			insertarEnLista(":=");
				
			puntero_asignacion = 0;	// reset
			
			// ya se, es horrible esto
			if(flagAsigMul == TRUE){
				puntero_tokens = puntero_tokens -2;
			}
			flagAsigMul = FALSE;
			printf("FIN LINEA ASIGNACION\n");
			
		}
		| lista_id OP_ASIG 
			between
	  ;

lista_id:		
			lista_id OP_ASIG ID {
				flagAsigMul = TRUE;
				//printf("Lei el ID A %s  \n",$3);
				if(flagPrimero == TRUE){
					insertarEnLista("###");
					char sPos[5];
					sprintf(sPos,"%d",puntero_tokens-1);
					apilar(PILA_ASIGNACION,sPos);
					insertarEnLista(":=");
					flagPrimero = FALSE;
				}
				char * strPos;
				if(verificarExistencia($3) == EXISTE)
				{
					strPos = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
					insertarEnLista($3);
					insertarEnLista("###");
					sprintf(strPos,"%d",puntero_tokens-1);
					apilar(PILA_ASIGNACION,strPos);
					insertarEnLista(":=");
					
					
				} else {
					// No existe en la tabla de simbolos
					finAnormal("Syntax Error","Variable no declarada");
				}
			}
			| ID {
				//printf("Lei el ID B %s  \n",$1);
				if(verificarExistencia($1) == EXISTE)
				{
					insertarEnLista($1);
					flagPrimero = TRUE;

				} else {
					// No existe en la tabla de simbolos
					finAnormal("Syntax Error","Variable no declarada");
				}
				
			}
		;
	  
entrada_salida: 
	READ{printf("\t\tREAD\n"); } ID 
	|WRITE{printf("\t\tWRITE\n");} ID 
	|WRITE{printf("\t\tWRITE\n");} CONST_STR
;

seleccion: 
    	IF CAR_PA condicion CAR_PC then_ bloque { 
				char sPosActual[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_IF,sPosActual);
			} 
			ENDIF {
				
				int x, i, iPosActual;
				char sPosActual[5], sPosActualTrue[5], sPosActualFalse[5], sPosCondDos[5];
				
				x=desapilar(PILA_IF); // Primero que desapilo -> apunta a la posicion actual
				sprintf(sPosActual, "CELDA %d", puntero_tokens);
				escribirEnLista(x,sPosActual);
				
				x=desapilar(PILA_IF);// Segundo que desapilo -> apunta a la parte verdadera
				sprintf(sPosActualTrue, "CELDA %s", posTrue);
				escribirEnLista(x,sPosActualTrue);
				
				x=desapilar(PILA_IF); // Tercero que desapilo -> apunta al final
				sprintf(sPosActual, "CELDA %d", puntero_tokens);
				escribirEnLista(x,sPosActual);
				
					
				if(flagIFOR == TRUE){
					x=desapilar(PILA_IF); // Cuarto que desapilo -> apunta a la parte verdadera
					escribirEnLista(x,sPosActualTrue);
					
					x=desapilar(PILA_IF); // Quinto que desapilo -> apunta a la segunda condicion
					sprintf(sPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,sPosCondDos);
					
				} else if (flagIFAND == TRUE){
					x=desapilar(PILA_IF); // Cuarto que desapilo -> apunta a la segunda condicion
					sprintf(sPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,sPosCondDos);
					
					x=desapilar(PILA_IF);// Quinto que desapilo -> apunta a la parte falsa
					escribirEnLista(x,sPosActualFalse);
				} else {
					// NO HAGO NADA - IF DE CONDICION SIMPLE	
				}
				
				flagIFAND = FALSE;
				flagIFOR = FALSE;
				
				sprintf(sPosActual, "-1");
				sprintf(posCondDos, "-1");
				sprintf(posFalse, "-1");
				sprintf(posTrue, "-1");
				
				printf("FIN DEL IF\n"); 
			}
				
		| IF CAR_PA condicion CAR_PC then_ bloque { 
				char sPosActual[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_IF,sPosActual);} 
				
			else_ bloque  				
			ENDIF {
				int x, i, iPosActual;
				char sPosActual[5], sPosActualTrue[5], sPosActualFalse[5], sPosCondDos[5];
				
				x=desapilar(PILA_IF); // Primero que desapilo -> apunta a la posicion actual
				sprintf(sPosActual, "CELDA %d", puntero_tokens);
				escribirEnLista(x,sPosActual);
				
				x=desapilar(PILA_IF); // Segundo que desapilo -> apunta a la parte verdadera
				sprintf(sPosActualTrue, "CELDA %s", posTrue);
				escribirEnLista(x,sPosActualTrue);
				
				x=desapilar(PILA_IF); // Tercero que desapilo -> apunta a la posicion actual
				sprintf(sPosActualFalse, "CELDA %s", posFalse);
				escribirEnLista(x,sPosActualFalse);
				
				if(flagIFOR == TRUE){
					
					x=desapilar(PILA_IF); // Cuarto que desapilo -> apunta a la parte verdadera
					sprintf(sPosActualTrue, "CELDA %s", posTrue);
					escribirEnLista(x,sPosActualTrue);
					
					x=desapilar(PILA_IF); // Quinto que desapilo -> apunta a la segunda condicion
					sprintf(sPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,sPosCondDos);
					
				} else if (flagIFAND == TRUE){
					
					x=desapilar(PILA_IF); // Cuarto que desapilo -> apunta a la segunda condicion
					sprintf(sPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,sPosCondDos);
					
					x=desapilar(PILA_IF); // Quinto que desapilo -> apunta a la parte falsa
					sprintf(sPosActualFalse, "CELDA %s", posFalse);
					escribirEnLista(x,sPosActualFalse);
				} else {
					// NO HAGO NADA - IF DE CONDICION SIMPLE	
				}
				
				flagIFAND = FALSE;
				flagIFOR = FALSE;
				sprintf(sPosActual, "-1");
				sprintf(posCondDos, "-1");
				sprintf(posFalse, "-1");
				sprintf(posTrue, "-1");
				
			printf("FIN DEL IF CON ELSE\n");
		}	
;

then_: THEN {
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				char sPosActual[5];
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_IF,sPosActual);
				
				char sPosActualB[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActualB, "%d", puntero_tokens-1);
				apilar(PILA_IF,sPosActualB);	
			
				sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true				
					
			}
;

else_: ELSE {	sprintf(posFalse, "%d", puntero_tokens); /*guardo la posicion del false*/ } 	
;

condicion:
         comparacion {
			 if(flagWHILE == TRUE){ //Manejo del While
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				char sPosActual[5];
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActual); // usado en el while
				
				char sPosActualB[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActualB, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActualB);	
				sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true						
			 
				flagWHILE = FALSE; //agregado lucas (dsp fijate mauro es para q no vuelva a entrar)
			 }
			 
			 if(flagREPEAT == TRUE){
				
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				char sPosActual[5];
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_REPEAT,sPosActual); // usado en el while
				
				char sPosActualB[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActualB, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActualB);	
				sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true						
			 
				flagREPEAT = FALSE;
				
			 }
			 
			 
			 
		 }
         |OP_NOT comparacion{printf("NOT CONDICION\n");}
         |comparacion op_and_ {sprintf(posCondDos, "%d", puntero_tokens);}  
			comparacion {
			 
			 if(flagWHILE == TRUE){
				flagWHILEAND = TRUE;
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				char sPosActual[5];
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActual);
				
				char sPosActualB[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActualB, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActualB);	
				sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true				
				//debugPila(PILA_WHILE,tope_pila_while);		
			 }
			}
		 |comparacion op_or_ { sprintf(posCondDos, "%d", puntero_tokens); } 
			comparacion { 
				if(flagWHILE == TRUE){
					// flagWHILEOR = TRUE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActualB);	
					sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true				
					//debugPila(PILA_WHILE,tope_pila_while);		
				 }
				printf("CONDICION DOBLE OR\n"); 
			}
		 |OP_NOT CAR_PA comparacion OP_AND comparacion CAR_PC {printf("NOT CONDICION DOBLE AND\n");}
		 |OP_NOT CAR_PA comparacion OP_OR  comparacion  CAR_PC{printf("NOT CONDICION DOBLE OR\n");}
		 |between {insertarEnLista("1");}
		 |OP_NOT between {insertarEnLista("0");}
	 ;

op_and_: OP_AND{
			
				if(flagWHILE == TRUE){
					flagWHILEAND = TRUE;
					flagWHILEOR = FALSE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActualB);
				} else {
					flagIFAND = TRUE;
					flagIFOR = FALSE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_IF,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_IF,sPosActualB);
				}
			
			}	 
;

op_or_: OP_OR{
				
				if(flagWHILE == TRUE){
					flagWHILEOR = TRUE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActualB);	
				} else {
					flagIFAND = FALSE;
					flagIFOR = TRUE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_IF,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_IF,sPosActualB);	
				}
				
			}	 
;

	 
comparacion:
	   expresion OP_COMPARACION { strcpy(comparador_usado,yylval.cmp_val);}  expresion
	   ;

expresion:
		expresion OP_SUM termino {insertarEnLista("+");}
		|expresion OP_RES termino {insertarEnLista("-");}
        | termino
 	 ;
	 
between: 
	{printf("INICIO BETWEEN\n");}BETWEEN CAR_PA ID {
													int iPosID = insertarEnLista(yylval.str_val);
													char * sPosID = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
													itoa(iPosID,sPosID,10);
													apilar(PILA_BETWEEN,sPosID);
												   } CAR_COMA CAR_CA 
		expresion {
					int iPosActual, iPosID;
					char * sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
				
					iPosID = desapilar(PILA_BETWEEN);
					insertarEnLista("CMP");
					insertarEnLista("BLT");
					
					iPosActual = insertarEnLista("###");
					sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
					itoa(iPosActual,sPosActual,10);
					apilar(PILA_BETWEEN,sPosActual);
					
					insertarEnLista("BI");
					iPosActual = insertarEnLista("###");
					sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
					itoa(iPosActual,sPosActual,10);
					apilar(PILA_BETWEEN,sPosActual);
					iPosCondDos = puntero_tokens;
					insertarEnLista(listaTokens[iPosID]);		
					
					} CAR_PYC expresion {
											int x, i, iPosActual, posTrue, posFalse;
											char sPosActualTrue[5], sPosActualFalse[5], sPosCondDos[5];
											char * sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
											insertarEnLista("CMP");
											insertarEnLista("BGT");
											
											iPosActual = insertarEnLista("###");
											itoa(iPosActual,sPosActual,10);
											apilar(PILA_BETWEEN,sPosActual);
											
											insertarEnLista("BI");
											iPosActual = insertarEnLista("###");
											sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
											itoa(iPosActual,sPosActual,10);
											apilar(PILA_BETWEEN,sPosActual);
											
											insertarEnLista("1");
											posTrue = puntero_tokens-1;
											
											insertarEnLista("BI");
											iPosActual = insertarEnLista("###");
											sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
											itoa(iPosActual,sPosActual,10);
											apilar(PILA_BETWEEN,sPosActual);
											insertarEnLista("0");
											posFalse = puntero_tokens-1;
											
											x=desapilar(PILA_BETWEEN); // Primero que desapilo -> apunta a la posicion actual
											sprintf(sPosActual, "CELDA %d", puntero_tokens);
											escribirEnLista(x,sPosActual);
											
											x=desapilar(PILA_BETWEEN); // Segundo que desapilo -> apunta a la parte verdadera
											sprintf(sPosActualTrue, "CELDA %d", posTrue);
											escribirEnLista(x,sPosActualTrue);
											
											x=desapilar(PILA_BETWEEN); // Tercero que desapilo -> apunta a la posicion actual
											sprintf(sPosActualFalse, "CELDA %d", posFalse);
											escribirEnLista(x,sPosActualFalse);
											
											x=desapilar(PILA_BETWEEN); // Cuarto que desapilo -> apunta a la segunda condicion
											sprintf(sPosCondDos, "CELDA %d", iPosCondDos);
											escribirEnLista(x,sPosCondDos);
												
											x=desapilar(PILA_BETWEEN); // Quinto que desapilo -> apunta a la parte falsa
											sprintf(sPosActualFalse, "CELDA %d", posFalse);
											escribirEnLista(x,sPosActualFalse);
											
										} CAR_CC CAR_PC {printf("\t\tFIN BETWEEN\n");}
	 ;
	 
termino: 
	   termino OP_MUL 
		   factor 
		   {
			   insertarEnLista("*"); 
			   sumTermino = sumTermino * atof(valorFactor);
			}
	   |termino OP_DIV 
			factor 
			{
				insertarEnLista("/"); 
				sumTermino = sumTermino / atof(valorFactor);
			}
       |factor { 
			sumTermino = 0;
			sumTermino = atof(valorFactor);
			sprintf(valorTermino,"%f",sumTermino); 
			
			
		   }
	   ;

factor: 
      ID { 
			if(verificarExistencia(yylval.str_val) == NO_EXISTE)
			{ 
				finAnormal("Syntax Error","Variable no declarada"); 
			} 
			insertarEnLista(yylval.str_val);
			
			
			
		}
      | CONST_INT {
					  if(verificarExistencia(yylval.str_val) == NO_EXISTE)
						{ 
							insertar_TS("CONST_INT",yylval.int_val);
						} 
					  insertarEnLista(yylval.int_val); 
					  sprintf(valorFactor,"%s",yylval.int_val);
				  }
      | CONST_REAL 
		{
			if(verificarExistencia(yylval.real_val) == NO_EXISTE)
			{ 
				insertar_TS("CONST_REAL",yylval.real_val);
			} 
			insertarEnLista(yylval.real_val); 
			sprintf(valorFactor,"%s",yylval.real_val);
			//printf("Guarde el valor real %s\n",valorFactor);
		}
					 
      | CONST_STR  
		{
			if(verificarExistencia(yylval.str_val) == NO_EXISTE)
			{ 
				insertar_TS("CONST_STR",yylval.str_val);
			} 
			insertarEnLista(yylval.str_val); 
			sprintf(valorFactor,"%s",yylval.str_val);
		}
	  | CAR_PA expresion CAR_PC 	  
      ;

%%
// FUNCIONES DE TABLA DE SIMBOLOS
int insertar_TS(char* tipo, char* nombre)
{
	int i, posicion;
	
	for(i = 0; i < puntero_ts; i++)
	{
		if(strcmp(tablaSimbolos[i].nombre, nombre) == 0)
		{
			return i;
		}
	}
	strcpy(tablaSimbolos[puntero_ts].tipo, tipo);
	strcpy(tablaSimbolos[puntero_ts].nombre, nombre);
	
	if(strcmp(tipo,"CONST_STR") == 0)
	{
		int longitud = strlen(tablaSimbolos[i].nombre);
		sprintf(tablaSimbolos[puntero_ts].longitud, "%d", longitud );		
	} 
	else if (strcmp(tipo,"CONST_INT") == 0  || strcmp(tipo,"CONST_REAL") == 0)
	{
		strcpy(tablaSimbolos[puntero_ts].valor, tablaSimbolos[i].nombre);
	}
	
	posicion = puntero_ts;
	puntero_ts++;
	return posicion;
}

int verificarExistencia(char* nombre)
{
	int i;
	for (i=0;i < puntero_ts;i++)
	{
		//printf("Voy a comprar %s con %s \n",nombre, tablaSimbolos[i].nombre);
		if(strcmp(nombre,tablaSimbolos[i].nombre) == 0)
		{
			return EXISTE;
		}
	}
	return NO_EXISTE;
}

char * recuperarValorTS(char* nombre)
{
	int i;
	for (i=0;i < puntero_ts;i++)
	{
		//printf("Voy a comprar %s con %s \n",nombre, tablaSimbolos[i].nombre);
		if(strcmp(nombre,tablaSimbolos[i].nombre) == 0)
		{
			return tablaSimbolos[i].valor;
		}
	}
	finAnormal("Syntax Error","Variable no inicializada");
	return "ERROR";
}

int crearArchivoTS()
{
	FILE *archivo; 
	int i;
	archivo = fopen("ts.txt","w"); 

	if (!archivo){	return ERROR; }

	fprintf(archivo, "Nombre                        Tipo                  Valor                Longitud\n");
	
	for (i = 0; i < puntero_ts; i++)
	{
		if (strcmp(tablaSimbolos[i].tipo, "INTEGER") == 0 || strcmp(tablaSimbolos[i].tipo, "REAL") == 0  || strcmp(tablaSimbolos[i].tipo, "STRING") == 0 )
		{  
			fprintf(archivo,"%-30s%-10s\n", tablaSimbolos[i].nombre, tablaSimbolos[i].tipo);
		}
		else if(strcmp(tablaSimbolos[i].tipo, "CONST_STR") == 0 )
		{
			fprintf(archivo,"%-29s%-10s                                    %-30d\n", tablaSimbolos[i].nombre, tablaSimbolos[i].tipo,strlen(tablaSimbolos[i].nombre));
		}
		else if(strcmp(tablaSimbolos[i].tipo, "CONST_INT") == 0 || strcmp(tablaSimbolos[i].tipo, "CONST_REAL") == 0)
		{
			fprintf(archivo,"_%-29s%-10s           %-30s\n", tablaSimbolos[i].nombre, tablaSimbolos[i].tipo,tablaSimbolos[i].valor);
		}
		else 
		{
			fprintf(archivo,"%-30s%-10s                                %-30s\n", tablaSimbolos[i].nombre, tablaSimbolos[i].tipo,tablaSimbolos[i].valor);
		}
	}
	fclose(archivo); 

	return TODO_OK;
}


// FUNCIONES DE PILA
void apilar(int nroPila, char * val)
{
	switch(nroPila){
		case PILA_IF:
			
			
			if(pilaLlena(PILA_IF) == TRUE){
				printf("Error: Se exedio el tamano de la pila de IF.\n");
				system ("Pause");
				exit (1);
			}
			pilaIF[tope_pila_if]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_if++;
			break;
		
		case PILA_WHILE:
		
			if(pilaLlena(PILA_WHILE) == TRUE){
				printf("Error: Se exedio el tamano de la pila de WHILE.\n");
				system ("Pause");
				exit (1);
			}
			pilaWhile[tope_pila_while]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_while++;
			break;
		case PILA_ASIGNACION:
		
			if(pilaLlena(PILA_ASIGNACION) == TRUE){
				printf("Error: Se exedio el tamano de la pila de ASIGNACION.\n");
				system ("Pause");
				exit (1);
			}
			pilaAsignacion[tope_pila_asignacion]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_asignacion++;
			break;	
		case PILA_REPEAT:
			if(pilaLlena(PILA_REPEAT) == TRUE){
				printf("Error: Se exedio el tamano de la pila de REPEAT.\n");
				system ("Pause");
				exit (1);
			}
			pilaRepeat[tope_pila_repeat]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_repeat++;
			break;	
			
		case PILA_BETWEEN:
			if(pilaLlena(PILA_BETWEEN) == TRUE){
				printf("Error: Se exedio el tamano de la pila de BETWEEN.\n");
				system ("Pause");
				exit (1);
			}
			pilaBetween[tope_pila_between]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_between++;
			break;	
		
		default:
			printf("\tError: La pila recibida no se reconoce\n",val);
			system ("Pause");
			exit (1);
			break;
	}

}

int desapilar(int nroPila)
{
	switch(nroPila){
		case PILA_IF:
			if(pilaVacia(tope_pila_if) == 0)
			{
				char * dato = pilaIF[tope_pila_if-1];
				tope_pila_if--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				printf("Error: La pila esta vacia.\n");
				system ("Pause");
				exit (1);
			}
			
			break;
		
		case PILA_WHILE:
		
			if(pilaVacia(tope_pila_while) == 0)
			{
				char * dato = pilaWhile[tope_pila_while-1];
				tope_pila_while--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				finAnormal("Stack Error","La pila esta vacia");
			}
		
			break;
		case PILA_ASIGNACION:
		
			if(pilaVacia(tope_pila_asignacion) == 0)
			{
				char * dato = pilaAsignacion[tope_pila_asignacion-1];
				tope_pila_asignacion--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				finAnormal("Stack Error","La pila esta vacia");
			}
		
			break;	
		case PILA_REPEAT:
		
			if(pilaVacia(tope_pila_repeat) == 0)
			{
				char * dato = pilaRepeat[tope_pila_repeat-1];
				tope_pila_repeat--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				finAnormal("Stack Error","La pila esta vacia");
			}
		
			break;	
		
		case PILA_BETWEEN:
		
			if(pilaVacia(tope_pila_between) == 0)
			{
				char * dato = pilaBetween[tope_pila_between-1];
				tope_pila_between--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				finAnormal("Stack Error","La pila esta vacia");
			}
		
			break;	

		default:
			finAnormal("Stack Error","La pila recibida no se reconoce");
			break;
		
	}
	
}

int pilaVacia(int tope)
{
	if (tope-1 == -1){
		return TRUE;
	} 
	return FALSE;
}

int pilaLlena(int tope)
{
	if (tope-1 == TAM_PILA-1){
		return TRUE;
	} 
	return FALSE;
}

void debugPila(int nroPila, int tope)
{
	char * nombre;
	char * pila[TAM_PILA];
	int i;
	printf("====== DEBUG PILA ======\n\n");
	
	switch(nroPila){
		case PILA_IF:
			printf("posCondDos: %s\n",posCondDos);
			printf("posTrue: %s\n",posTrue);
			printf("posFalse: %s\n",posFalse);
			printf("El tope de la pila es %d \n",tope_pila_if);		
			printf("Lista de elementos: \n");		
			for (i=0; i<tope_pila_if;i++){
				printf("%d => %s\n",i,pilaIF[i]);		
			}
			
			break;
		
		case PILA_WHILE:
			printf("posCondDos: %s\n",posCondDos);
			printf("posTrue: %s\n",posTrue);
			printf("posFalse: %s\n",posFalse);
			printf("El tope de la pila es %d \n",tope_pila_while);		
			printf("Lista de elementos: \n");		
			for (i=0; i<tope_pila_while;i++){
				printf("%d => %s\n",i,pilaWhile[i]);		
			}
			
			break;
		case PILA_ASIGNACION:
			
			printf("El tope de la pila es %d \n",tope_pila_asignacion);		
			printf("Lista de elementos: \n");			
			for (i=0; i<tope_pila_asignacion;i++){
				printf("%d => %s\n",i,pilaAsignacion[i]);		
			}
			
			break;	
		case PILA_BETWEEN:
			
			printf("El tope de la pila es %d \n",tope_pila_between);		
			printf("Lista de elementos: \n");			
			for (i=0; i<tope_pila_between;i++){
				printf("%d => %s\n",i,pilaBetween[i]);		
			}
			
			break;		
		case PILA_REPEAT:
			
			printf("El tope de la pila es %d \n",tope);		
			printf("Lista de elementos: \n");			
			for (i=0; i<tope_pila_repeat;i++){
				printf("%d => %s\n",i,pilaRepeat[i]);		
			}
			
			break;			
		default:
			printf("Error interno: Pila no reconocida \n");
			system("Pause");
			exit(1);
			break;
	}
	printf("\n====== FIN DEBUG PILA ======\n\n");	
	
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
		printf("\tinsertar_en_polaca(%s)\n", aux);
	}
	return (puntero_tokens-1); // devuelvo posicion
}

int insertarEnListaDeclaracion(char * val)
{
	
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// Agrego al array de tokens
	listaDeclaracion[puntero_declaracion] = aux;
	puntero_declaracion++;
	
	return (puntero_declaracion-1); // devuelvo posicion
	
}

int insertarEnListaAsig(char * val)
{
	
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// Agrego al array de tokens
	listaAsignacion[puntero_asignacion] = aux;
	puntero_asignacion++;
	
	return (puntero_asignacion-1); // devuelvo posicion
	
}

void debugListaDeclaracion()
{
	int i;
	printf("====== DEBUG LISTA DECLARACION ======\n\n");
	printf("La cantidad de elementos es %d \n",puntero_declaracion);		
	printf("Lista de elementos: \n");		
	for (i=0; i < puntero_declaracion;i++){
		printf("%d => %s\n",i,listaDeclaracion[i]);		
	}
	
	printf("\n====== FIN DEBUG LISTA DECLARACION ======\n\n");	
	
}

void debugListaAsignacion()
{
	int i;
	printf("====== DEBUG LISTA ASIGNACION ======\n\n");
	printf("La cantidad de elementos es %d \n",puntero_asignacion);		
	printf("Lista de elementos: \n");		
	for (i=0; i < puntero_asignacion;i++){
		printf("%d => %s\n",i,listaAsignacion[i]);		
	}
	
	printf("\n====== FIN DEBUG LISTA ASIGNACION ======\n\n");	
	
}

void debugTS()
{
	int i;
	printf("====== DEBUG TABLA SIMBOLOS ======\n\n");
	printf("La cantidad de elementos es %d \n",puntero_ts);		
	printf("Lista de elementos: \n");		
	for (i=0; i < puntero_ts;i++){
		printf("%d => %s | %s | %s | %s \n",i,tablaSimbolos[i].nombre,tablaSimbolos[i].tipo,tablaSimbolos[i].valor,tablaSimbolos[i].longitud );		
	}
	
	printf("\n====== FIN DEBUG TABLA SIMBOLOS ======\n\n");	
	
}

void escribirEnLista(int pos, char * val)
{
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// escribo en vector
	listaTokens[pos] = aux;
	
	printf("\tEscribio en %i el valor %s\n",pos,aux);
	
}

char * valorComparacionCICLO(char * val){
	if(strcmp("=", val) == 0){
		return "BEQ";
	} else if(strcmp(">=", val) == 0){
		return "BGE";
	} else if(strcmp(">", val) == 0){
		return "BGT";
	} else if(strcmp("<=", val) == 0){
		return "BLE";
	} else if(strcmp("<", val) == 0){
		return "BLT";
	} else if(strcmp("><", val) == 0){
		return "BNE";
	} else {
		// NUNCA DEBERIA CAER ACA
		return val;
	}
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
	printf("** FIN DEL PROGRAMA **\n\n");
	system ("Pause");
	exit (1);
}

void finAnormal(char * tipo, char * mensaje)
{
	printf("[ERROR]: %s - %s\n",tipo,mensaje);
	yyerror();
}

int crearArchivoIntermedia()
{
	FILE * archivo; 
	int i;
	archivo = fopen("intermedia.txt", "wt");

	if (!archivo){	return ERROR; }

	for (i = 1; i < puntero_tokens; i++)
	{
		fprintf(archivo,"%s\n", listaTokens[i]);
		//fprintf(archivo,"CELDA %d: %s\n", i, listaTokens[i]);
	}
	fclose(archivo); 

	return TODO_OK;
}

void validarDeclaracionTipoDato(char * tipo)
{
	int i;
	for (i=0; i < puntero_declaracion; i++)
	{
	//printf("Voy a verificar la existencia del elemento %s: \n",listaDeclaracion[i]);
		if(verificarExistencia(listaDeclaracion[i]) == NO_EXISTE)
		{
		//printf("No existe, la inserto en tabla de simbolos \n");
		insertar_TS(tipo,listaDeclaracion[i]);
		//debugListaDeclaracion();
		//debugTS();
		}
		else 
		{
			printf("Syntax error: Variable ya declarada\n");
			system("Pause");
			exit(1);
		}
	}
	// reinicio el contador para leer otro tipo de dato
	puntero_declaracion = 0;
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
	
	if(crearArchivoTS() == TODO_OK)
	{
		printf("Se genero el archivo de tabla de simbolos\n");
	}
	else 
	{
		printf("ERROR - Syntax error\n");
		system ("Pause");
		exit(1);
	}
	
	fclose(yyin);
	return 0;
}