#include "comandos.h"

int main()
{
    printf("##################################################\n");
    printf("  EVALUADOR DE EXPRESIONES MATEMATICAS ENTERAS\n");
    printf("##################################################\n");
    ListaExp lexp;
    crearListaExp(lexp);

    while (TRUE)
    {
        string texto;
        printf("\nIngrese un comando: ");
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