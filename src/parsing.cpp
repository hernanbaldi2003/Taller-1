#include "parsing.h"

void crearListaPalabras(ListaPalabras &l)
{
    l = NULL;
}

boolean vaciaListaPalabras(ListaPalabras l)
{
    if (l == NULL)
        return TRUE;
    else
        return FALSE;
}

void destruirListaPalabras(ListaPalabras &l)
{
    ListaPalabras aux;

    while (l != NULL)
    {
        aux = l;
        l = l->sig;
        strdestruir(aux->palabra);
        delete aux;
    }
}

int largoListaPalabras(ListaPalabras l)
{
    int cont = 0;
    ListaPalabras aux = l;

    while (aux != NULL)
    {
        cont++;
        aux = aux->sig;
    }

    return cont;
}

void insertarPalabra(ListaPalabras &l, const string palabra)
{
    if (vaciaListaPalabras(l) == TRUE)
    {
        l = new NodoP;
        strcrear(l->palabra);
        strcop(l->palabra, palabra);
        l->sig = NULL;
    }
    else
        insertarPalabra(l->sig, palabra);
}

void mostrarListaPalabras(ListaPalabras l)
{
    ListaPalabras aux = l;
    while (aux != NULL)
    {
        print(aux->palabra);
        aux = aux->sig;
    }
}

void parsearStr(string texto, ListaPalabras &l)
{
    int i = 0;
    int largo = strlar(texto);

    while (i < largo)
    {

        while (i < largo && texto[i] == ' ')
            i++;

        int inicio = i;

        while (i < largo && texto[i] != ' ')
            i++;

        int fin = i;
        int largoPalabra = fin - inicio;

        string palabra;
        palabra = new char[largoPalabra + 1];

        for (int j = 0; j < largoPalabra; j++)
            palabra[j] = (char)tolower((unsigned char)texto[inicio + j]);

        palabra[largoPalabra] = '\0';

        insertarPalabra(l, palabra);
    }
}