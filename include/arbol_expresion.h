#ifndef _arbol_H
#define _arbol_H
#include "stringdin.h"

typedef enum
{
    NUMERO,
    VARIABLE,
    OPERADOR,
    PARENTESIS
} TipoNodo;

typedef struct NodoA
{

    TipoNodo tipo;
    union
    {
        int valor;
        char variable;
        char operador;
        char parentesis;
    } dato;

    NodoA *izq;
    NodoA *der;
} NodoABB;

typedef NodoABB *ArbolExp;

// básicas
void crearArbol(ArbolExp &a);
boolean vacioArbol(ArbolExp a);
void destruirArbol(ArbolExp &a);

// construcción
void crearNodo(ArbolExp &a, TipoNodo tipo, char operador, int valor);
ArbolExp copiarArbol(ArbolExp a);

// recorridos
void mostrarInOrden(ArbolExp a);

// evaluación
int evaluarExpresion(ArbolExp a, int valor);

// comparación
boolean igualesExpresiones(ArbolExp a1, ArbolExp a2);

#endif