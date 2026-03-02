#include "arbol_expresion.h"

void crearArbol(ArbolExp &a)
{
    a = new NodoABB;
    a->izq = NULL;
    a->der = NULL;
}

boolean vacioArbol(ArbolExp a)
{
    if (a == NULL)
        return TRUE;
    else
        return FALSE;
}

void destruirArbol(ArbolExp &a)
{
    if (a != NULL)
    {
        destruirArbol(a->izq);
        destruirArbol(a->der);
        delete a;
        a = NULL;
    }
}

void mostrarArbol(ArbolExp a)
{
    if (a != NULL)
    {
        if (a->tipo == OPERADOR)
        {
            printf("(");
        }

        mostrarArbol(a->izq);

        switch (a->tipo)
        {
        case NUMERO:
            printf("%d", a->dato.valor);
            break;
        case VARIABLE:
            printf("%c", a->dato.variable);
            break;
        case OPERADOR:
            printf(" %c ", a->dato.operador);
            break;
        case PARENTESIS:
            printf("%c", a->dato.parentesis);
            break;
        }

        mostrarArbol(a->der);

        if (a->tipo == OPERADOR)
        {
            printf(")");
        }
    }
}

ArbolExp copiarArbol(ArbolExp a) {}

int evaluarExpresion(ArbolExp a, int valor) {}

boolean igualesExpresiones(ArbolExp a1, ArbolExp a2) {}
