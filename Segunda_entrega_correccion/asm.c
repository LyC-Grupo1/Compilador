#include "asm.h"
#define TRUE 1
#define FALSE 0
#define PILA_LLENA -1
#define PILA_VACIA 0
#define TAM_PILA 100

FILE *pfASM; //Final.asm
//t_pila pila; //pila operandos

char * pila[TAM_PILA];       // pila 5
int topePila=0;             // pila 0

void ponerEnPila(char * str);
char* sacarDePila();
int pVacia(int tope);
int pLlena(int tope);
void debugP(int tope);

void generarASM() {

    //Abrir archivo Final.asm
    if(!(pfASM = fopen("bin/Final.asm", "wt+"))) {
        if(!(pfASM = fopen("Final.asm", "wt+"))) {
            informeError("Error al crear el archivo Final.asm, verifique los permisos de escritura.");
        }
    }
	
    //Crear pila para ponerEnPila operandos
    //crear_pila(&pila);

    //Generar archivo ASM
    fprintf(pfASM, ";\n;ARCHIVO FINAL.ASM\n;\n");

    generarEncabezado();
    //generarDatos();
    generarCodigo();
    generarFin();
	
    //Cerrar archivo
    fclose(pfASM);
}

void generarEncabezado() {
    //Encabezado del archivo
    fprintf(pfASM, "\nINCLUDE macros2.asm\t\t ;incluye macros\n");
    fprintf(pfASM, "INCLUDE number.asm\t\t ;incluye el asm para impresion de numeros\n");
    //fprintf(pfASM, "INCLUDE string.asm\t\t ;incluye el asm para manejo de strings\n");    		 
    fprintf(pfASM, "\n.MODEL LARGE ; tipo del modelo de memoria usado.\n");
    fprintf(pfASM, ".386\n");
    fprintf(pfASM, ".STACK 200h ; bytes en el stack\n"); 
}

/*
void generarDatos() {
    int i = 0;
    TS elemento;
    char aux[STR_VALUE];
    //Encabezado del sector de datos
    fprintf(pfASM, "\t\n.DATA ; comienzo de la zona de datos.\n");    
    fprintf(pfASM, "\tTRUE equ 1\n");
    fprintf(pfASM, "\tFALSE equ 0\n");
    fprintf(pfASM, "\tMAXTEXTSIZE equ %d\n",200); //cota STR
    

    //Recorrer tabla de simbolos y armar el sector .data
    for(i = 0; i < getTopeTS(); i++){
        elemento = getItemTS(i);        
        switch(elemento.tipo){                        
            case CTE_INT:
                fprintf(pfASM, "\t");            
                fprintf(pfASM, "%s dd %.6f\n",elemento.nombre,elemento.valor);        
                break;
            case CTE_STR:
                fprintf(pfASM, "\t");
                if(strcmp(elemento.valorString,"-") == 0)
                    fprintf(pfASM, "%s db MAXTEXTSIZE dup(?), '$'\n", elemento.nombre, elemento.valorString, (COTA_STR - elemento.longitud));
                else
                    fprintf(pfASM, "%s db \"%s\", '$', %d dup(?)\n", elemento.nombre, elemento.valorString, (COTA_STR - elemento.longitud));
                break;
            case CTE_FLT:
                fprintf(pfASM, "\t");
                fprintf(pfASM, "%s dd %.10f\n",elemento.nombre,elemento.valor);
                break;
            case VRBL_AUX:
                if(strcmp(elemento.nombre,"@aux4STR") == 0){ //variable aux para strings.
                    fprintf(pfASM, "\t%s db MAXTEXTSIZE dup(?), '$'\n", elemento.nombre, elemento.valorString, (COTA_STR - elemento.longitud));
                    break;                
                }
                fprintf(pfASM, "\t");
                fprintf(pfASM, "%s dd %.10f\n",elemento.nombre,elemento.valor);
                break;
        }
    }    
}
*/

/*
void imprimirFuncString(){
    if(!cFlag)
        return;
    
    int c;
    FILE *file;
    file = fopen("bin/string.asm", "r");
    if (file) {
        fprintf(pfASM,"\n");
        while ((c = getc(file)) != EOF)
            fprintf(pfASM,"%c",c);
        fprintf(pfASM,"\n\n");
        fclose(file);
    }else{        
        file = fopen("string.asm", "r");
        if (file) {
            fprintf(pfASM,"\n");
            while ((c = getc(file)) != EOF)
                fprintf(pfASM,"%c",c);
            fprintf(pfASM,"\n\n");
            fclose(file);
        }else{
            informeError("Error no se puede abrir string.asm");
        }
    }

}
*/

void generarCodigo() {
    FILE *pfINT;
    char linea[30];
    //Abrir archivo intermedia.txt
    if(!(pfINT = fopen("intermedia.txt", "rt"))) {
         informeError("Error al abrir el archivo intermedia.txt, verifique los permisos de escritura.");
    }

    //Encabezado del sector de codigo
    fprintf(pfASM, "\n.CODE ;Comienzo de la zona de codigo\n");

    //Imprimo funciones de manejo de strings
    //imprimirFuncString();

    //Inicio codigo usuario
    fprintf(pfASM, "START: \t\t ;Código assembler resultante de compilar el programa fuente.\n");
    fprintf(pfASM, "\tmov AX,@DATA \t\t ;Inicializa el segmento de datos\n");
    fprintf(pfASM, "\tmov DS,AX\n");
    //fprintf(pfASM, "\tfinit\n\n");

    //Leer de archivo y generar assembler

    size_t lin;
    while(fgets(linea, 30, pfINT) != NULL) {
    	lin = strlen(linea)-1;
    	if (linea[lin] == '\n')     
    		linea[lin] = '\0';
        printf("LINEA: %s FIN_DE_LINEA\n", linea);
        imprimirInstruccionPolaca(linea);
    }
    debugP(topePila);
}


void imprimirInstruccionPolaca(char* linea){
	char op1[STR_VALUE];
    char op2[STR_VALUE] = "";
    
	char* opp1;
    char* opp2;
	char aux[STR_VALUE]; // usada para las variables auxiliares @aux
	char opp_aux[STR_VALUE]; //usada solo para apilar
	int cont_aux=1; // incrementa cada vez que guardo un @aux en pila 
	
	// comento switch porque no funciona con variables char*

	//switch(linea){
	if(strcmp(linea,"+") == 0){
	
		fprintf(pfASM,"\t;SUMA\n");
		opp1=(char *) malloc(sizeof(char) * 31); 
		opp2=(char *) malloc(sizeof(char) * 31); 
		strcpy(opp1, sacarDePila());
		strcpy(opp2, sacarDePila());
		
		// no esta asi en el apunte pero lo dejo x las dudas
		//fprintf(pfASM, "\tfld %s\n",op1);
		//fprintf(pfASM, "\tfld %s\n",op2);
		//fprintf(pfASM, "\tfadd\n");
		
		fprintf(pfASM, "\tmov R1, %s\n",opp1);
		fprintf(pfASM, "\tadd R1, %s\n",opp2);
		sprintf(aux,"@aux%d",cont_aux);		
		fprintf(pfASM, "\tmov %s, R1\n",aux); // guardo aux
		ponerEnPila(aux);
		cont_aux++;
		return;
					
		/*
		//fprintf(pfASM, "\tlocal %s\n",aux); // Variable local en vez de los aux de arriba
		//guardar valor en aux
		if(strcmp(aux,"@aux2") == 0){
			fprintf(pfASM, "\tfstp @aux3\n\n");                    
			ponerEnPila("@aux3");
		}else{
			fprintf(pfASM, "\tfstp @aux2\n\n");                    
			ponerEnPila("@aux2");
		}*/
				                
			
	}
			/*if(sacar_de_pila(&pila, op2, 255) != PILA_VACIA){
				if(sacar_de_pila(&pila, op1, 255) != PILA_VACIA){
					fprintf(pfASM, "\t\nadd %s" + ", " + "%s\n", op1, op2); 
					printf("\t\nadd %s" + ", " + "%s\n", op1, op2);	
				}					
			}*/
	if(strcmp(linea,"-") == 0){
			fprintf(pfASM,"\t;RESTA\n");
			if(sacarDePila() != PILA_VACIA){
				if(sacarDePila() != PILA_VACIA){
					fprintf(pfASM, "\tfld %s\n",op2);
					fprintf(pfASM, "\tfld %s\n",op1);                   
					fprintf(pfASM, "\tfsub\n");


					//guardar valor en aux
					if(strcmp(aux,"@aux2") == 0){
						fprintf(pfASM, "\tfstp @aux3\n\n");                    
						ponerEnPila("@aux3");
					}else{
						fprintf(pfASM, "\tfstp @aux2\n\n");                    
						ponerEnPila("@aux2");
					}
					fprintf(pfASM, "\t\nmov %s, %s\n", op1, op2); 
					printf("\t\nmov %s, %s\n", op1, op2);	
				}					
			}
	}
	
	if(strcmp(linea,"*")==0){
			fprintf(pfASM,"\t;MULTIPLICACION\n");
			if(sacarDePila() != PILA_VACIA)
			{
				if(sacarDePila() != PILA_VACIA)
				{
					fprintf(pfASM, "\tfld %s\n",op1);
					fprintf(pfASM, "\tfld %s\n",op2);
					fprintf(pfASM, "\tfmul\n");
					//fprintf(pfASM, "\tlocal %s\n",aux); // Variable local en vez de los aux de arriba

					//guardar valor en aux
					if(strcmp(op1,"@aux2") == 0){
						fprintf(pfASM, "\tfstp @aux3\n\n");                    
						ponerEnPila("@aux3");
					}else{
						fprintf(pfASM, "\tfstp @aux2\n\n");                    
						ponerEnPila("@aux2");
					}
				}                
			}  
	}
			/*if(sacar_de_pila(&pila, op2, 255) != PILA_VACIA){
				if(sacar_de_pila(&pila, op1, 255) != PILA_VACIA){
					fprintf(pfASM, "\t\nmul %s" + ", " + "%s\n", op1, op2); 
					printf("\t\nmul %s" + ", " + "%s\n", op1, op2);	
				}					
			}*/
	if(strcmp(linea,"/")==0){
			fprintf(pfASM,"\t;DIVISION\n");
			if(sacarDePila() != PILA_VACIA)
			{
				if(sacarDePila() != PILA_VACIA)
				{
					fprintf(pfASM, "\tfld %s\n",op1);
					fprintf(pfASM, "\tfld %s\n",op2);
					fprintf(pfASM, "\tfdiv\n");
					//fprintf(pfASM, "\tlocal %s\n",aux); // Variable local en vez de los aux de arriba

					//guardar valor en aux
					if(strcmp(op1,"@aux2") == 0){
						fprintf(pfASM, "\tfstp @aux3\n\n");                    
						ponerEnPila("@aux3");
					}else{
						fprintf(pfASM, "\tfstp @aux2\n\n");                    
						ponerEnPila("@aux2");
					}
				}                
			}  
	}
			/*if(sacar_de_pila(&pila, op2, 255) != PILA_VACIA){
				if(sacar_de_pila(&pila, op1, 255) != PILA_VACIA){
					fprintf(pfASM, "\t\nmov %s" + ", " + "%s\n", op1, op2); 
					printf("\t\nmov %s" + ", " + "%s\n", op1, op2);	
				}					
			}*/

	if(strcmp(linea,":=")==0){
	
			fprintf(pfASM,"\t;ASIGNACION\n");
			opp1=(char *) malloc(sizeof(char) * 31); 
			opp2=(char *) malloc(sizeof(char) * 31); 
			strcpy(opp1, sacarDePila());
			strcpy(opp2, sacarDePila());
			fprintf(pfASM,"\tmov R1, %s\n",opp1);
			fprintf(pfASM,"\tmov %s, R1\n",opp2);
			//fprintf(pfASM, "\tmov %s, %s\n", opp2, opp1); 
			printf("\t\nmov %s, %s\n", opp2, opp1);	
			return;
	}

	if(strcmp(linea,"CMP")==0){
		fprintf(pfASM,"\t;CMP\n");
		if(sacarDePila() != PILA_VACIA)
		{
			if(sacarDePila() != PILA_VACIA)
			{
				fprintf(pfASM, "\tfld %s\n",op1);
				fprintf(pfASM, "\tfld %s\n",op2);                    
				fprintf(pfASM, "\tfcomp\n");
				fprintf(pfASM, "\tfstsw ax\n");
				fprintf(pfASM, "\tfwait\n");
				fprintf(pfASM, "\tsahf\n\n");                            
			}
		}            
	}
	/*case TERC_ETIQ:
		sprintf(aux,"ETIQUETA%d:",nTerc);                            
		fprintf(pfASM,"ETIQUETA%d:\n",nTerc);                
		strcpy(last,aux);            
		break;*/
	if(strcmp(linea,"BI")==0){
		//sprintf(op1,"ETIQUETA%d", terc.opIzq);
		fprintf(pfASM, "\tjmp %s\n",op1);
	}
	if(strcmp(linea,"BEQ")==0){
		//sprintf(op1,"ETIQUETA%d", terc.opDer);
		fprintf(pfASM, "\tje %s\n",op1); //JE	Jump if Equal	salta si igual	A=B
	}
	if(strcmp(linea,"BNE")==0){
		//sprintf(aux,"ETIQUETA%d", terc.opDer);
		fprintf(pfASM, "\tjne %s\n",op1);
	}
	if(strcmp(linea,"BLT")==0){
		//sprintf(aux,"ETIQUETA%d", terc.opDer);
		fprintf(pfASM, "\tjl %s\n",op1); //JL	Jump if Less	salta si menor	A<B (con signo)
	}
	if(strcmp(linea,"BLE")==0){
		//sprintf(aux,"ETIQUETA%d", terc.opDer);
		fprintf(pfASM, "\tjle %s\n",op1); //JLE	Jump if Less or Equal	salta si menor o igual
	}
	if(strcmp(linea,"BGT")==0){
		//sprintf(aux,"ETIQUETA%d", terc.opDer);
		fprintf(pfASM, "\tjg %s\n",op1); //JG	Jump if Greater	salta si mayor	A>B (con signo)
	}                           
	if(strcmp(linea,"BGE")==0){
		//sprintf(aux,"ETIQUETA%d", terc.opDer);
		fprintf(pfASM, "\tjge %s\n",op1);  //JGE	Jump if Greater or Equal	salta si mayor o igual	A>=B (con signo)  
	}else{ //apilo operando 
		printf("poner en pila %s \n", linea);
		//poner_en_pila(&pila, linea, 255); //todo lo que sea operando lo apilo, para luego sacarDePila cuando llegue a operador
		strcpy(opp_aux,"_");
		strcat(opp_aux,linea);		
		ponerEnPila(opp_aux);//todo lo que sea operando lo apilo, para luego sacarDePila cuando llegue a operador

	}		
	
}

/* 
// ESTO ES PARA ELIMINAR
void imprimirInstrucciones(terceto_t terc, int nTerc){
    char tConst,tConst2;
    char aux[STR_VALUE];
    char aux2[STR_VALUE] = "";
    char last[STR_VALUE] = "";
    char concat[STR_VALUE];
    TS simbolo,simbolo2;
    int pos;
    //Verificar operación e imprimir instrucciones. 
    switch(terc.operacion){
        case TERC_ASIG:
            fprintf(pfASM,"\t;ASIGNACIÓN\n");
            if(sacar_de_pila(&pVariables,aux,255) != PILA_VACIA)
            {
                pos = existeTokenEnTS(aux,VRBL);
                ObtenerItemTS(pos,&simbolo);
                if(sacar_de_pila(&pVariables,aux2,255) != PILA_VACIA)
                {
                    if(strcmp(aux2,"@aux4STR") == 0){                               	                    
                        fprintf(pfASM, "\tmov ax,@DATA\n");
                        fprintf(pfASM, "\tmov es,ax\n");
                        fprintf(pfASM, "\tmov si,OFFSET %s ;apunta el origen al auxiliar\n",aux2);
                        fprintf(pfASM, "\tmov di,OFFSET %s ;apunta el destino a la cadena\n",aux);
                        fprintf(pfASM, "\tcall COPIAR ;copia los string\n\n");
                    }else if(simbolo.tipo == CTE_STR){
                        fprintf(pfASM, "\tmov ax,@DATA\n");
                        fprintf(pfASM, "\tmov es,ax\n");
                        fprintf(pfASM, "\tmov si,OFFSET %s ;apunta el origen al auxiliar\n",aux2);
                        fprintf(pfASM, "\tmov di,OFFSET %s ;apunta el destino a la cadena\n",aux);
                        fprintf(pfASM, "\tcall COPIAR ;copia los string\n\n");
                    }else{
                        fprintf(pfASM, "\tfld %s\n",aux2);
                        fprintf(pfASM, "\tfstp %s\n\n",aux);
                    }
                }
            }            
            break;
        case TERC_CMP:
            fprintf(pfASM,"\t;CMP\n");
            if(sacar_de_pila(&pVariables,aux,255) != PILA_VACIA)
            {
                if(sacar_de_pila(&pVariables,aux2,255) != PILA_VACIA)
                {
                    fprintf(pfASM, "\tfld %s\n",aux);
                    fprintf(pfASM, "\tfld %s\n",aux2);                    
                    fprintf(pfASM, "\tfcomp\n");
                    fprintf(pfASM, "\tfstsw ax\n");
                    fprintf(pfASM, "\tfwait\n");
                    fprintf(pfASM, "\tsahf\n\n");                            
                }
            }            
            break;
        case TERC_ETIQ:
            sprintf(aux,"ETIQUETA%d:",nTerc);                            
            fprintf(pfASM,"ETIQUETA%d:\n",nTerc);                
            strcpy(last,aux);            
            break;
        case TERC_JMP:
            sprintf(aux,"ETIQUETA%d", terc.opIzq);
            fprintf(pfASM, "\tjmp %s\n",aux);
            break;
        case TERC_JE:
            sprintf(aux,"ETIQUETA%d", terc.opDer);
            fprintf(pfASM, "\tje %s\n",aux);
            break;
        case TERC_JNE:
            sprintf(aux,"ETIQUETA%d", terc.opDer);
            fprintf(pfASM, "\tjne %s\n",aux);
            break;
        case TERC_JB:
            sprintf(aux,"ETIQUETA%d", terc.opDer);
            fprintf(pfASM, "\tjb %s\n",aux);
            break;
        case TERC_JBE:
            sprintf(aux,"ETIQUETA%d", terc.opDer);
            fprintf(pfASM, "\tjbe %s\n",aux);
            break;   
        case TERC_JA:
            sprintf(aux,"ETIQUETA%d", terc.opDer);
            fprintf(pfASM, "\tja %s\n",aux);
            break;                             
        case TERC_JAE:
            sprintf(aux,"ETIQUETA%d", terc.opDer);
            fprintf(pfASM, "\tjae %s\n",aux);      
            break;
        case TERC_RESTA:
            fprintf(pfASM,"\t;RESTA\n");
            if(sacar_de_pila(&pVariables,aux,255) != PILA_VACIA)
            {
                if(sacar_de_pila(&pVariables,aux2,255) != PILA_VACIA)
                {
                    fprintf(pfASM, "\tfld %s\n",aux2);
                    fprintf(pfASM, "\tfld %s\n",aux);                   
                    fprintf(pfASM, "\tfsub\n");
                    //fprintf(pfASM, "\tlocal %s\n",aux); // Variable local en vez de los aux de arriba

                    //guardar valor en aux
                    if(strcmp(aux,"@aux2") == 0){
                        fprintf(pfASM, "\tfstp @aux3\n\n");                    
                        poner_en_pila(&pVariables,"@aux3",255);
                    }else{
                        fprintf(pfASM, "\tfstp @aux2\n\n");                    
                        poner_en_pila(&pVariables,"@aux2",255);
                    }
                }                
            }                        
            break;        
        case TERC_SUMA:
            fprintf(pfASM,"\t;SUMA\n");
            if(sacar_de_pila(&pVariables,aux,255) != PILA_VACIA)
            {
                if(sacar_de_pila(&pVariables,aux2,255) != PILA_VACIA)
                {
                    fprintf(pfASM, "\tfld %s\n",aux);
                    fprintf(pfASM, "\tfld %s\n",aux2);
                    fprintf(pfASM, "\tfadd\n");
                    //fprintf(pfASM, "\tlocal %s\n",aux); // Variable local en vez de los aux de arriba

                    //guardar valor en aux
                    if(strcmp(aux,"@aux2") == 0){
                        fprintf(pfASM, "\tfstp @aux3\n\n");                    
                        poner_en_pila(&pVariables,"@aux3",255);
                    }else{
                        fprintf(pfASM, "\tfstp @aux2\n\n");                    
                        poner_en_pila(&pVariables,"@aux2",255);
                    }
                }                
            }     
                                 
            break;
        case TERC_MULT:
            fprintf(pfASM,"\t;MULTIPLICACION\n");
            if(sacar_de_pila(&pVariables,aux,255) != PILA_VACIA)
            {
                if(sacar_de_pila(&pVariables,aux2,255) != PILA_VACIA)
                {
                    fprintf(pfASM, "\tfld %s\n",aux);
                    fprintf(pfASM, "\tfld %s\n",aux2);
                    fprintf(pfASM, "\tfmul\n");
                    //fprintf(pfASM, "\tlocal %s\n",aux); // Variable local en vez de los aux de arriba

                    //guardar valor en aux
                    if(strcmp(aux,"@aux2") == 0){
                        fprintf(pfASM, "\tfstp @aux3\n\n");                    
                        poner_en_pila(&pVariables,"@aux3",255);
                    }else{
                        fprintf(pfASM, "\tfstp @aux2\n\n");                    
                        poner_en_pila(&pVariables,"@aux2",255);
                    }
                }                
            }  
            break;
        case TERC_DIV:
            fprintf(pfASM,"\t;DIVISION\n");
            if(sacar_de_pila(&pVariables,aux,255) != PILA_VACIA)
            {
                if(sacar_de_pila(&pVariables,aux2,255) != PILA_VACIA)
                {
                    fprintf(pfASM, "\tfld %s\n",aux2);
                    fprintf(pfASM, "\tfld %s\n",aux);
                    fprintf(pfASM, "\tfdiv\n");
                    //fprintf(pfASM, "\tlocal %s\n",aux); // Variable local en vez de los aux de arriba

                    //guardar valor en aux
                    if(strcmp(aux,"@aux2") == 0){
                        fprintf(pfASM, "\tfstp @aux3\n\n");                    
                        poner_en_pila(&pVariables,"@aux3",255);
                    }else{
                        fprintf(pfASM, "\tfstp @aux2\n\n");                    
                        poner_en_pila(&pVariables,"@aux2",255);
                    }
                }                
            }  
            break;
        case TERC_CONCAT:            
            if(sacar_de_pila(&pVariables,aux,255) != PILA_VACIA)
            {
                if(sacar_de_pila(&pVariables,aux2,255) != PILA_VACIA)
                {
                    fprintf(pfASM,"\t;CONCATENACIÓN\n");
                    fprintf(pfASM, "\tmov ax,@DATA\n");
                    fprintf(pfASM, "\tmov es,ax\n");
                    fprintf(pfASM, "\tmov si,OFFSET %s ;apunta el origen a la primer cadena\n",aux2);
                    fprintf(pfASM, "\tmov di,OFFSET @aux4STR ;apunta el destino al auxiliar\n");
                    fprintf(pfASM, "\tcall COPIAR ;copia los string\n\n");

                    fprintf(pfASM, "\tmov ax,@DATA\n");
                    fprintf(pfASM, "\tmov es,ax\n");
                    fprintf(pfASM, "\tmov si,OFFSET %s ;apunta el origen a la segunda cadena\n",aux);
                    fprintf(pfASM, "\tmov di,OFFSET @aux4STR ;concatena los string\n");
                    fprintf(pfASM, "\tcall CONCAT\n\n");

                    poner_en_pila(&pVariables,"@aux4STR",255);
                }
            }
            break;
        case TERC_WRITE:            
            sprintf(aux,"%s",terc.opIzq);            
            fprintf(pfASM,"\t;WRITE\n");
            tConst = aux[0];
            switch(tConst){                
                case '_':
                    pos = existeTokenEnTS(terc.opIzq,VRBL);
                    ObtenerItemTS(pos,&simbolo);
                    switch(simbolo.tipo){
                        case CTE_STR:
                            fprintf(pfASM,"\tdisplayString %s\n",aux);
                            fprintf(pfASM, "\tnewLine 1\n\n");
                            break;
                        default:
                            fprintf(pfASM,"\tDisplayFloat %s 2\n",aux);
                            fprintf(pfASM, "\tnewLine 1\n\n");
                            break;
                    }
                    break;
                case '&':
                    fprintf(pfASM,"\tDisplayInteger %s 2\n",aux);
                    fprintf(pfASM, "\tnewLine 1\n\n");                    
                    break;
                case '$':
                    fprintf(pfASM,"\tDisplayFloat %s 2\n",aux);
                    fprintf(pfASM, "\tnewLine 1\n\n");                    
                    break;
                case '@':
                    fprintf(pfASM,"\tDisplayFloat %s 2\n",aux);
                    fprintf(pfASM, "\tnewLine 1\n\n");                
                    break;                
                default:
                    fprintf(pfASM,"\tdisplayString %s\n",aux);
                    fprintf(pfASM, "\tnewLine 1\n\n");
                    break;
            }                        
            break;
        case TERC_READ:
            sprintf(aux,"%s",terc.opIzq);
            fprintf(pfASM,"\t;READ\n");
            pos = existeTokenEnTS(terc.opIzq,VRBL);
            ObtenerItemTS(pos,&simbolo);
            switch(simbolo.tipo){
                case CTE_STR:
                    fprintf(pfASM,"\tgetString %s\n\n",aux);
                    break;
                default:
                    fprintf(pfASM,"\tGetFloat %s\n\n",aux);
                    break;
            }             
            break;
        case TERC_END:
            sprintf(aux,"ETIQUETA%d:",nTerc);                            
            fprintf(pfASM,"ETIQUETA%d:\n",nTerc);                
            strcpy(last,aux);            
            fprintf(pfASM,"\tdisplayString cte5\n");
            fprintf(pfASM,"\tnewLine 1\n");
            fprintf(pfASM,"\tgetChar\n");
            break;        
        default:
            sprintf(aux,"%s",terc.operacion);            
            poner_en_pila(&pVariables,&aux,255);
            break;
    }
}
*/

void generarFin(){
    //Fin de ejecución
    fprintf(pfASM, "\nTERMINAR: ;Fin de ejecución.\n");
    fprintf(pfASM, "\tmov ax, 4C00h ; termina la ejecución.\n");
    fprintf(pfASM, "\tint 21h; syscall\n");
    fprintf(pfASM, "\nEND START;final del archivo.");    
}

int informeError(char * error){
		printf("\n%s",error);
		getchar();
		exit(1);
}

void ponerEnPila(char * str)
{
    if(pLlena(topePila) == TRUE){
        printf("Error: Se excedio el tamano de la pila.\n");
        system ("Pause");
        exit (1);
    }
    

    char *aux = (char *) malloc(sizeof(char) * (strlen(str) + 1));     
	strcpy(aux, str);
	pila[topePila] = aux;
	//free(aux);

	topePila++;
    printf("\tponerEnPila en ASM -> %s\n",str);
        
}

char* sacarDePila()
{
    if(pVacia(topePila) == 0)
    {
        char * dato = pila[topePila-1];
        topePila--; 
        printf("\tsacarDePila en ASM -> %s\n",dato);
        return dato;      
    } else {
        printf("Error: La pila esta vacia.\n");
        system ("Pause");
        exit (1);
    }
}

int pVacia(int tope)
{
    if (tope-1 == -1){
        return TRUE;
    } 
    return FALSE;
}

int pLlena(int tope)
{
    if (tope-1 == TAM_PILA-1){
        return TRUE;
    } 
    return FALSE;
}

void debugP(int tope)
{
    int i,e;
    e=tope;
    printf("====== DEBUG PILA ======\n\n");
    printf("El tope de la pila es %d \n",tope);        
    printf("Lista de elementos: \n");           
    for (i=0; i<e;i++){
        printf("%d => %s\n",i,pila[i]);      
    }                    
    printf("\n====== FIN DEBUG PILA ======\n\n");   
    
}