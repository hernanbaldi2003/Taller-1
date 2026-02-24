#ifndef _string_H
#define _string_H
#include "boolean.h"

// cota auxiliar para implementar funciones de copia de strings y otras
const int MAX = 80;

typedef char * string;

// crear y destruir
void strcrear(string &s);
void strdestruir(string &s);

// básicas
int strlar(const char *s);
void strcop(string &s1, const char *s2);
void strcon(string &s1, const string s2);
int strcomp(const string s1, const string s2);

// entrada y salida
void scan(string &s);
void print(const string s);

#endif