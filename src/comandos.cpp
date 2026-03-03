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
        printf("\n<<< ERROR: CANTIDAD DE PARAMETROS INCORRECTA >>>\n");
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
        printf("\n<<< ERROR: PARAMETRO INVALIDO >>>\n");
}

void ejecutar_compuesta(ListaPalabras listaPars, ListaExp &lista)
{
    printf("\nComando ejecutado: COMPUESTA");

    if (largoListaPalabras(listaPars) != 3) {
        printf("\n<<< ERROR: CANTIDAD DE PARAMETROS INCORRECTA >>>\n");
        return;
    }

    string izqIndice = listaPars->palabra;
    string operador   = listaPars->sig->palabra;
    string derIndice = listaPars->sig->sig->palabra;

    // valido indices
    if (!esPositivo(izqIndice) || !esPositivo(derIndice)) {
        printf("\n<<< ERROR: INDICES DEBEN SER ENTEROS POSITIVOS >>>\n");
        return;
    }

    int id1 = convertirAEntero(izqIndice);
    int id2 = convertirAEntero(derIndice);

    // valido operadores
    char op = operador[0];
    if (!(op == '+' || op == '-' || op == '*' || op == '/')) {
        printf("\n<<< ERROR: OPERADOR INVALIDO >>>\n");
        return;
    }

    // tomo las expresiones guardadas
    ArbolExp exp1 = obtenerExpresion(lista, id1);
    ArbolExp exp2 = obtenerExpresion(lista, id2);

    if (exp1 == NULL || exp2 == NULL) {
        printf("\n<<< ERROR: ALGUNO DE LOS INDICES NO EXISTE >>>\n");
        return;
    }

    // creo la raiz operador
    ArbolExp raiz;
    crearArbol(raiz);
    raiz->tipo = OPERADOR;
    raiz->dato.operador = op;

    // copio los subarboles
    raiz->izq = copiarArbol(exp1);
    raiz->der = copiarArbol(exp2);

    // insertar en lista
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

    if (largoListaPalabras(listaPars) != 2) {
        printf("\n<<< ERROR: CANTIDAD DE PARAMETROS INCORRECTA >>>\n");
        return;
    }

    string indice = listaPars->palabra;
    string valor= listaPars->sig->palabra;

    // valido indice
    if (!esPositivo(indice)) {
        printf("\n<<< ERROR: INDICE DEBE SER ENTERO POSITIVO >>>\n");
        return;
    }
    int id = convertirAEntero(indice);

    // valido valor numerico
    if (!esNumerico(valor)) {
        printf("\n<<< ERROR: VALOR DEBE SER NUMERICO >>>\n");
        return;
    }
    int valorNum = convertirAEntero(valor);

    // obtengo la expresion
    ArbolExp exp = obtenerExpresion(lista, id);
    if (exp == NULL) {
        printf("\n<<< ERROR: NO EXISTE EXPRESION CON ESE INDICE >>>\n");
        return;
    }

    // Evaluar
    int resultado = evaluarExpresion(exp, valorNum);

    printf("\n --> RESULTADO DE LA EXPRESION [%d] CON X = %d: %d\n", id, valorNum, resultado);
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
