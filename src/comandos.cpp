#include "comandos.h"
#include <cstdlib>

int codigoComando(string comando)
{
    if (streq(comando, (string) "simple") == TRUE)
        return 1;
    if (streq(comando, (string) "compuesta") == TRUE)
        return 2;
    if (streq(comando, (string) "mostrar") == TRUE)
        return 3;
    if (streq(comando, (string) "calcular") == TRUE)
        return 4;
    if (streq(comando, (string) "iguales") == TRUE)
        return 5;
    if (streq(comando, (string) "guardar") == TRUE)
        return 6;
    if (streq(comando, (string) "recuperar") == TRUE)
        return 7;
    if (streq(comando, (string) "salir") == TRUE)
        return 8;

    return 0; // comando invalido
}

void ejecutarComando(ListaPalabras lpalabras, ListaExp &lexp)
{
    // Primer nodo = nombre del comando
    string comando = lpalabras->palabra;
    int codigo = codigoComando(comando);

    switch (codigo)
    {
    case 1:
        ejecutar_simple(lpalabras->sig, lexp);
        break;

    case 2:
        ejecutar_compuesta(lpalabras->sig, lexp);
        break;

    case 3:
        ejecutar_mostrar(lpalabras->sig, lexp);
        break;

    case 4:
        ejecutar_calcular(lpalabras->sig, lexp);
        break;

    case 5:
        ejecutar_iguales(lpalabras->sig, lexp);
        break;

    case 6:
        ejecutar_guardar(lpalabras->sig, lexp);
        break;

    case 7:
        ejecutar_recuperar(lpalabras->sig, lexp);
        break;

    case 8:
        ejecutar_salir(lpalabras->sig, lexp);
        break;

    default:
        printf("\n<<< ERROR: COMANDO INVALIDO >>>");
        break;
    }
}

void ejecutar_simple(ListaPalabras lpal, ListaExp &lexp)
{
    printf("\nComando ejecutado: SIMPLE");

    if (largoListaPalabras(lpal) != 1)
    {
        printf("\n<<< ERROR: CANTIDAD DE PARAMETROS INCORRECTA >>>");
        return;
    }

    if (esNumerico(lpal->palabra))
    {
        ArbolExp a;
        crearArbol(a);
        a->tipo = NUMERO;
        a->dato.valor = convertirAEntero(lpal->palabra);
        insertarExpresion(lexp, a);
        printf("\n --> EXPRESION SIMPLE INGRESADA CORRECTAMENTE: ");
        mostrarArbol(a);
        printf("\n");
    }

    else if (streq(lpal->palabra, (string) "x") == TRUE)
    {
        ArbolExp a;
        crearArbol(a);
        a->tipo = VARIABLE;
        a->dato.variable = 'x';
        insertarExpresion(lexp, a);
        printf("\n --> EXPRESION SIMPLE INGRESADA CORRECTAMENTE: ");
        mostrarArbol(a);
        printf("\n");
    }

    else
        printf("\n<<< ERROR: PARAMETRO INVALIDO >>>");
}

void ejecutar_compuesta(ListaPalabras listaPars, ListaExp &lista)
{
    printf("\nComando ejecutado: COMPUESTA");

    if (largoListaPalabras(listaPars) != 3)
    {
        printf("\n<<< ERROR: CANTIDAD DE PARAMETROS INCORRECTA >>>");
        return;
    }

    // crea las variables con los parametros
    string izqStr = listaPars->palabra;
    string opStr = listaPars->sig->palabra;
    string derStr = listaPars->sig->sig->palabra;

    // crea el nodo operador como raiz
    ArbolExp raiz;
    crearArbol(raiz);
    raiz->tipo = OPERADOR;
    raiz->dato.operador = opStr[0]; // el [0] lo pasa a char

    // crea subarbol izquierdo
    ArbolExp izq;
    crearArbol(izq);

    if (esNumerico(izqStr))
    {
        izq->tipo = NUMERO;
        izq->dato.valor = convertirAEntero(izqStr);
    }

    else if (streq(izqStr, (string) "x") == TRUE)
    {
        izq->tipo = VARIABLE;
        izq->dato.variable = 'x';
    }

    else
    {
        printf("\n<<< ERROR: PARAMETRO IZQUIERDO INVALIDO >>>");
        destruirArbol(raiz);
        return;
    }

    raiz->izq = izq;

    // crea subarbol derecho
    ArbolExp der;
    crearArbol(der);

    if (esNumerico(derStr))
    {
        der->tipo = NUMERO;
        der->dato.valor = convertirAEntero(derStr);
    }

    else if (streq(derStr, (string) "x") == TRUE)
    {
        der->tipo = VARIABLE;
        der->dato.variable = 'x';
    }

    else
    {
        printf("\n<<< ERROR: PARAMETRO DERECHO INVALIDO >>>");
        destruirArbol(raiz);
        return;
    }

    raiz->der = der;

    // inserta en la lista de expresiones
    insertarExpresion(lista, raiz);
    printf("\n --> EXPRESION COMPUESTA INGRESADA CORRECTAMENTE: ");
    mostrarArbol(raiz);
    printf("\n");
}

void ejecutar_mostrar(ListaPalabras listaPars, ListaExp lista)
{
    printf("\nComando ejecutado: MOSTRAR\n");
    mostrarListaExp(lista);
}

void ejecutar_calcular(ListaPalabras listaPars, ListaExp lista)
{
    printf("\nComando ejecutado: CALCULAR");
}

void ejecutar_iguales(ListaPalabras listaPars, ListaExp lista)
{
    printf("\nComando ejecutado: IGUALES");
}

void ejecutar_guardar(ListaPalabras listaPars, ListaExp lista)
{
    printf("\nComando ejecutado: GUARDAR");
}

void ejecutar_recuperar(ListaPalabras listaPars, ListaExp &lista)
{
    printf("\nComando ejecutado: RECUPERAR");
}

void ejecutar_salir(ListaPalabras listaPars, ListaExp &lista)
{
    printf("\nComando ejecutado: SALIR");
    destruirListaExp(lista);
    printf("\n<<< PROGRAMA FINALIZADO >>>\n");
    exit(0);
}
