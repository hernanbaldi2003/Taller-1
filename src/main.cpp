#include "comandos.h"

int main()
{
    ListaExp lexp;
    crearListaExp(lexp);

    while (TRUE)
    {
        string texto;
        printf("\nIngrese un texto: ");
        strcrear(texto);
        scan(texto);

        ListaPalabras L;
        crearListaPalabras(L);
        parsearStr(texto, L);
        strdestruir(texto);

        ejecutarComando(L, lexp);
        destruirListaPalabras(L);
    }
}