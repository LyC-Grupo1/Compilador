#ifndef ASM_H
#define ASM_H
#define PILA_LLENA -1
#define PILA_VACIA 0
#define TODO_OK 1
#define STR_VALUE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s_nodo
{
    void *dato;
    struct s_nodo *psig;
}t_nodo;

typedef t_nodo *t_pila;

//generadorASM
void generarEncabezado();
void generarFin();
void generarDatos();
void generarCodigo();
void generarASM();
void imprimirInstrucciones();
void imprimirFuncString();
int informeError(char *);

//Pila
int poner_en_pila(t_pila *,const void * ,int);
int sacar_de_pila(t_pila *,void * ,int);
int tope_pila(const t_pila *,void * ,int);
void vaciar_pila(t_pila *);
int pila_llena(const t_pila *);
int pila_vacia(const t_pila *);
void crear_pila(t_pila *);

#endif