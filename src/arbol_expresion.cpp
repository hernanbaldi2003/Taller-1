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

ArbolExp copiarArbol(ArbolExp a)
{
    if (a == NULL)
    {
        return NULL;
    }

    ArbolExp nuevo;
    crearArbol(nuevo);

    nuevo->tipo = a->tipo;
    switch (a->tipo)
    {
    case NUMERO:
        nuevo->dato.valor = a->dato.valor;
        break;
    case VARIABLE:
        nuevo->dato.variable = a->dato.variable;
        break;
    case OPERADOR:
        nuevo->dato.operador = a->dato.operador;
        break;
    case PARENTESIS:
        nuevo->dato.parentesis = a->dato.parentesis;
        break;
    }

    nuevo->izq = copiarArbol(a->izq);
    nuevo->der = copiarArbol(a->der);

    return nuevo;
}

int evaluarExpresion(ArbolExp a, int valor)
{
    if (a == NULL)
        return 0;

    switch (a->tipo)
    {

    case NUMERO:
        return a->dato.valor;

    case VARIABLE:
        return valor;

    case OPERADOR:
    {
        int izq = evaluarExpresion(a->izq, valor);
        int der = evaluarExpresion(a->der, valor);

        switch (a->dato.operador)
        {
        case '+':
            return izq + der;
        case '-':
            return izq - der;
        case '*':
            return izq * der;
        case '/':
            if (der == 0)
            {
                printf("\n<<< ERROR: DIVISION POR CERO >>>");
                return 0;
            }
            return izq / der;
        default:
            printf("\n<<< ERROR: OPERADOR DESCONOCIDO >>>");
            return 0;
        }
    }

    case PARENTESIS:
        return evaluarExpresion(a->izq, valor);

    default:
        return 0;
    }
}

boolean igualesExpresiones(ArbolExp a1, ArbolExp a2)
{
    if (a1 == NULL && a2 == NULL)
        return TRUE;

    if (a1 == NULL || a2 == NULL)
        return FALSE;

    if (a1->tipo != a2->tipo)
        return FALSE;

    switch (a1->tipo)
    {
    case NUMERO:
        if (a1->dato.valor != a2->dato.valor)
            return FALSE;
        break;

    case VARIABLE:
        if (a1->dato.variable != a2->dato.variable)
            return FALSE;
        break;

    case OPERADOR:
        if (a1->dato.operador != a2->dato.operador)
            return FALSE;
        break;

    case PARENTESIS:
        if (a1->dato.parentesis != a2->dato.parentesis)
            return FALSE;
        break;
    }

    if (igualesExpresiones(a1->izq, a2->izq) && igualesExpresiones(a1->der, a2->der))
        return TRUE;
    else 
        return FALSE;
}