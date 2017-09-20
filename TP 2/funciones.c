#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

void cambiarEstado(EPersona lista[],int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        lista[i].estado = 0;
    }
}

int mostrarMenu(char texto[])
{
    int opcion = 0;
    printf(texto);
    scanf("%d",&opcion);
    return opcion;
}

void mostrarPersona(EPersona lista)
{
    printf("%d--%s--%d\n", lista.dni,lista.nombre,lista.edad);
}
int obtenerEspacioLibre(EPersona lista[], int t)
{
    int i;
    int index;
    for (i=0; i<t; i++)
    {
        if (lista[i].estado == 0)
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }
    }
    return index;
}
void funAlta(EPersona lista[],int t)
{
    int index;
    index = obtenerEspacioLibre(lista,t);
    if (index != -1)
    {
        printf("Ingrese el DNI: ");
        scanf("%d", &lista[index].dni);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(lista[index].nombre);
        printf("Ingrese la edad: ");
        scanf("%d", &lista[index].edad);
        lista[index].estado = 1;
    }
    else
    {
        printf("No hay mas espacio para ingresar personas.\n");
    }

}

int buscarPorDni(EPersona lista[], int dni, int t)
{
    int i;
    int index;
    for (i=0; i<t; i++)
    {
        if (lista[i].estado != 0 && dni == lista[i].dni)
        {
            index = i;
        }
        else
        {
            index = -1;
        }

    }
    return index;
}
void funBorrar(EPersona lista[],int t)
{
    int auxDNI;
    int index;
    char respuesta;

    printf("Ingrese el DNI a borrar:");
    scanf("%d",&auxDNI);
    index = buscarPorDni(lista,auxDNI,t);
    if (index == -1)
    {
        printf("El DNI ingresado es inexistente!!!\n");
    }
    else
    {
        mostrarPersona(lista[index]);
        printf("Esta seguro/a de borrar esta persona? s/n :");
        respuesta = getche();
        if (respuesta == 's')
        {
            lista[index].estado = 0;
            printf("\nLa persona a sido borrada\n");
        }
        else
        {
            printf("\nAccion cancelada por el usuario\n");
        }

    }
}

void funOrdenarporNombre(EPersona lista[], int t)
{
    int i, j;
    EPersona auxEPersona;

    for(i=0; i<t-1; i++)
    {
        if (lista[i].estado != 0 )
        {
            for(j=i+1; j<t; j++)
            {
                if (lista[j].estado != 0)
                {
                    if(stricmp(lista[i].nombre, lista[j].nombre)>0)
                    {
                        auxEPersona=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxEPersona;

                    }
                    else if(stricmp(lista[i].nombre, lista[j].nombre)==0)
                    {
                        if(lista[i].dni > lista[j].dni)
                        {
                            auxEPersona=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxEPersona;
                        }
                    }
                }

            }
        }

    }
}

void funGrafico(EPersona lista[], int t)
{
    int i, j;
    int max;
    int contador[3] = {0};
    contarEdad(lista, t, contador);
    max = obtenerMaximo(contador,3);
    for (i = max; i > 0; i--)
    {
        for (j = 0; j < 3; j++)
        {
            if (contador[j] >= i)
            {
                printf("\t  *");
            }
            else
            {
                printf("\t  ");
            }
        }
        putchar('\n');

    }
    printf("\t<18\t18/35\t>35\n");
}

void contarEdad (EPersona lista[], int t, int contador[])
{
    int i;

    for (i=0; i<t; i++)
    {
        if (lista[i].estado != 0)
        {
            if (lista[i].edad < 18)
            {
                contador[0] = contador [0] + 1;
            }
            else if(lista[i].edad >= 18 && lista[i].edad <= 35)
            {
                contador[1] = contador [1] +1;
            }
            else
            {
                contador[2] = contador [2] +1;
            }
        }

    }
}

int obtenerMaximo (int contador[], int t)
{
    int i, max=0;
    for (i=0; i<t; i++)
    {
        if (max == 0 || contador[i] > max)
        {
            max = contador[i];
        }
    }
    return max;
}
