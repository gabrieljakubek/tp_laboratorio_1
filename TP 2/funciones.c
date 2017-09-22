#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void funcambiarEstado(EPersona lista[],int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        lista[i].estado = 0;
    }
}

int funmostrarMenu(char texto[])
{
    int opcion = 0;
    printf(texto);
    scanf("%d",&opcion);
    return opcion;
}

void funmostrarPersona(EPersona lista)
{
    printf("%d--%s--%d\n", lista.dni,lista.nombre,lista.edad);
}
int funobtenerEspacioLibre(EPersona lista[], int t)
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
    int index, auxInt;
    index = funobtenerEspacioLibre(lista,t);
    if (index != -1)
    {
        printf("Ingrese el DNI: ");
        scanf("%d", &lista[index].dni);
        auxInt = funchequeoNumero(lista[index].dni);
        while (auxInt != 0)
        {
            printf("Reingrese el DNI: ");
            scanf("%d", &lista[index].dni);
            auxInt = funchequeoNumero(lista[index].dni);
        }
        auxInt = funchequeoDni(lista,t,lista[index].dni);
        while (auxInt != 0)
        {
            printf("El DNI ya figura en la lista");
            break;
        }
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(lista[index].nombre);
        auxInt = funchequeoLetras(lista[index].nombre);
        while (auxInt != 0)
        {
            printf("Reingrese un nombre sin numeros: ");
            fflush(stdin);
            gets(lista[index].nombre);
            auxInt = funchequeoLetras(lista[index].nombre);
        }
        printf("Ingrese la edad: ");
        scanf("%d", &lista[index].edad);
        auxInt = funchequeoNumero(lista[index].edad);
        while (auxInt != 0)
        {
            printf("Reingrese la edad: ");
            scanf("%d", &lista[index].edad);
            auxInt = funchequeoNumero(lista[index].edad);
        }
        lista[index].estado = 1;
    }
    else
    {
        printf("No hay mas espacio para ingresar personas.\n");
    }
    system("pause");
    system("cls");
}

int funbuscarPorDni(EPersona lista[], int dni, int t)
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
    index = funbuscarPorDni(lista,auxDNI,t);
    if (index == -1)
    {
        printf("El DNI ingresado es inexistente!!!\n");
    }
    else
    {
        funmostrarPersona(lista[index]);
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
    system("pause");
    system("cls");
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
                    if(strcmp(lista[i].nombre, lista[j].nombre)>0)
                    {
                        auxEPersona=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxEPersona;

                    }
                    else if(strcmp(lista[i].nombre, lista[j].nombre)==0)
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
    funcontarEdad(lista, t, contador);
    max = funobtenerMaximo(contador,3);
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
    printf("\t<18\t18/35\t>35 \n");
    system("pause");
    system("cls");
}

void funcontarEdad(EPersona lista[], int t, int contador[])
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

int funobtenerMaximo(int contador[], int t)
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

int funchequeoNumero(int num)
{
    int i = 0, cont;
    int flag = 0;
    char buffer[20];
    itoa(num,buffer,10);
    cont = strlen(buffer);
    while (i<cont &&  flag == 0)
    {
        if(isdigit(buffer[i])!=0)
        {
            i++;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}

int funchequeoLetras(char letras[50])
{
    int i = 0, cont;
    int flag = 0;
    cont = strlen(letras);
    while (i<cont && flag == 0)
    {
        if (isalpha(letras[i]) != 0)
        {
            i++;
        }
        else
        {
            flag = 1;
        }

    }
    return flag;
}

int funchequeoDni(EPersona lista[], int T, int dni)
{

    int i;
    int flag = 0;
    for (i=0; i<T; i++)
    {
        if (dni == lista[i].dni)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

