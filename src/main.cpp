#include "comandos.h"

int main()
{
    string texto;
    printf("\nIngrese un texto: ");
    strcrear(texto);
    scan(texto);

    ListaPalabras L;
    crearListaPalabras(L);
    parsearStr(texto, L);

    printf("\nPalabras parseadas:");
    mostrarListaPalabras(L);

    destruirListaPalabras(L);
    strdestruir(texto);

}