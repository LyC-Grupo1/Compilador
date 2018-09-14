%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
int yystopparser=0;
FILE  *yyin;

%}

%token PROGRAM
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
	PROGRAM {printf(" Inicia COMPILADOR\n");} est_declaracion algoritmo    
	{printf(" Fin COMPILADOR ok\n");};

est_declaracion:
	DEFVAR {printf("     DECLARACIONES\n");} declaraciones ENDDEF {printf(" Fin de las Declaraciones\n");}
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
	 |ID CAR_COMA lista_var 
 	 ;

algoritmo: 
         BEGINP{printf("      COMIENZO de BLOQUES\n");} bloque ENDP
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
     REPEAT { printf("     REPEAT\n");}bloque UNTIL condicion | 
	 WHILE { printf("	WHILE\n");}CAR_PA condicion CAR_PC bloque ENDW 
     ;

asignacion: 
          ID OP_ASIG expresion {printf("    ASIGNACION\n");}
	  ;

entrada_salida: 
	READ{printf("\t\tREAD\n"); } ID 
	|WRITE{printf("\t\tWRITE\n");} ID 
	|WRITE{printf("\t\tWRITE\n");} CONST_STR
;

seleccion: 
    	 IF  CAR_PA condicion CAR_PC THEN bloque ENDIF{printf("     IF\n");}
		| IF  CAR_PA condicion CAR_PC THEN bloque ELSE bloque ENDIF {printf("     IF con ELSE\n");}	 
;

condicion:
         comparacion 
         |comparacion OP_AND comparacion{printf("     CONDICION DOBLE AND\n");}
		 |comparacion OP_OR  comparacion{printf("     CONDICION DOBLE OR\n");}
	 ;

comparacion:
	   expresion OP_COMPARACION expresion
	   ;

expresion:
         termino
		|expresion OP_SURES termino
 	 ;
	 
between: 
	BETWEEN CAR_PA ID CAR_COMA CAR_CA expresion CAR_PYC expresion CAR_CC CAR_PC 
	 ;
	 
termino: 
       factor
       |termino OP_MULTDIV factor
       ;

factor: 
      ID
      | CONST_INT
      | CONST_REAL
      | CONST_STR 
	  | CAR_PA expresion CAR_PC 	  
      ;

%%
int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	yyparse();
  }
  fclose(yyin);
  return 0;
}
int yyerror(void)
     {
       printf("Syntax Error\n");
	 system ("Pause");
	 exit (1);
     }

