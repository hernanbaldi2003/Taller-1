#ifndef _parsing_H
#define _parsing_H
#include "stringdin.h"

typedef struct NodoP
{
    string palabra;
    NodoP *sig;
} NodoPalabra;

typedef NodoPalabra *ListaPalabras;

// básicas
void crearListaPalabras(ListaPalabras &L);
boolean vaciaListaPalabras(ListaPalabras L);
int largoListaPalabras(ListaPalabras L);
void destruirListaPalabras(ListaPalabras &l);

// insertar
void insertarPalabra(ListaPalabras &L, const string palabra);

// recorrido
void mostrarListaPalabras(ListaPalabras L);

// parsing
void parsearStr(string texto, ListaPalabras &L);
#endif