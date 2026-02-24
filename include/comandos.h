#ifndef _comandos_H
#define _comandos_H
#include "lista_expresiones.h"
#include "archivo.h"
#include "parsing.h"

void ejecutar_simple(ListaPalabras listaPars, ListaExp &lista);

void ejecutar_compuesta(ListaPalabras listaPars, ListaExp &lista);

void ejecutar_mostrar(ListaPalabras listaPars, ListaExp lista);

void ejecutar_calcular(ListaPalabras listaPars, ListaExp lista);

void ejecutar_iguales(ListaPalabras listaPars, ListaExp lista);

void ejecutar_guardar(ListaPalabras listaPars, ListaExp lista);

void ejecutar_recuperar(ListaPalabras listaPars, ListaExp &lista);

void ejecutar_salir(ListaPalabras listaPars, ListaExp &lista);

#endif