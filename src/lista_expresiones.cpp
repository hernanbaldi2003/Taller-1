#include "lista_expresiones.h"

void crearListaExp(ListaExp &l)
{
    l = NULL;
}

boolean vaciaListaExp(ListaExp l)
{
    if (l == NULL)
        return TRUE;
    else
        return FALSE;
}

void insertarExpresion(ListaExp &l, ArbolExp a)
{
    if (l == NULL)
    {
        l = new NodoLista;
        l->raiz = a;
        l->sig = NULL;
        l->indice = 0;
    }
    else
    {
        ListaExp aux = l;
        while (aux->sig != NULL)
            aux = aux->sig;

        aux->sig = new NodoLista;
        aux->sig->raiz = a;
        aux->sig->sig = NULL;
        aux->sig->indice = aux->indice + 1;
    }
}

int largoListaExp(ListaExp l)
{
    int contador = 0;
    while (l != NULL)
    {
        contador++;
        l = l->sig;
    }
    return contador;
}

ArbolExp obtenerExpresion(ListaExp l, int indice)
{
    while (l != NULL)
    {
        if (l->indice == indice)
        {
            return l->raiz;
        }
        l = l->sig;
    }
    return NULL;
}

void mostrarListaExp(ListaExp l)
{
    while (l != NULL)
    {
        printf("[%d] ", l->indice);
        mostrarArbol(l->raiz);
        printf("\n");
        l = l->sig;
    }
}

void destruirListaExp(ListaExp &l)
{
    while (l != NULL)
    {
        ListaExp aux = l;
        destruirArbol(l->raiz);
        l = l->sig;
        delete aux;
    }
}