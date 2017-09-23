#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20

int main()
{
    system("color 2");
    char seguir='s';
    int opcion;
    int  auxInt=0;
    EPersona listaPersona[TAM];
    funcambiarEstadoyDNI(listaPersona,TAM);

    do
    {
        opcion = funmostrarMenu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n5- Salir\nIngrese la opcion a usar:");

        switch(opcion)
        {
        case 1:
            auxInt = funAlta(listaPersona,TAM);
            if(auxInt == 0)
            {
                printf("Se a dado de alta\n");
            }
            else if (auxInt == -1)
            {
                printf("No hay mas espacio para ingresar personas.\n");
            }
            else
            {
                printf("El DNI ingresado ya figura en la lista\n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            funMostrarTodasPersonas(listaPersona,TAM);
            funBorrar(listaPersona,TAM);
            break;
        case 3:
            funOrdenarporNombre(listaPersona,TAM);
            funMostrarTodasPersonas(listaPersona,TAM);
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
