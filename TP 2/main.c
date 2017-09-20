#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 2

int main()
{
    char seguir='s';
    int opcion;
    EPersona listaPersona[TAM];
    cambiarEstado(listaPersona,TAM);

    do
    {
        opcion = mostrarMenu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n5- Salir\nIngrese la opcion a usar:");

        switch(opcion)
        {
        case 1:
            funAlta(listaPersona,TAM);
            break;
        case 2:
            funBorrar(listaPersona,TAM);
            break;
        case 3:
            funOrdenarporNombre(listaPersona,TAM);
            break;
        case 4:
            funGrafico(listaPersona, TAM);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }
    while(seguir=='s');

    return 0;
}
