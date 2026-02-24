#ifndef _archivo_H
#define _archivo_H
#include "arbol_expresion.h"

void guardarExp(ArbolExp a, string nombreArchivo);
void recuperarExp(ArbolExp &a, FILE *f);

#endif