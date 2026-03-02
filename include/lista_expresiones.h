#ifndef _listaexpresiones_H
#define _listaexpresiones_H
#include "arbol_expresion.h"
#include "archivo.h"

typedef struct NodoL
{
    int indice;
    ArbolExp raiz;
    NodoL *sig;
} NodoLista;

typedef NodoLista *ListaExp;

// básicas
void crearListaExp(ListaExp &l);
void destruirListaExp(ListaExp &l);
boolean vaciaListaExp(ListaExp l);

// insertar
void insertarExpresion(ListaExp &l, ArbolExp a);

// consultas
int largoListaExp(ListaExp l);
ArbolExp obtenerExpresion(ListaExp l, int indice);

// recorrido
void mostrarListaExp(ListaExp l);

#endif