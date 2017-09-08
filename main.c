#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    system("color 2");
    float operA;
    int flagA = 0;
    float operB;
    int flagB = 0;
    float suma;
    int flagSuma = 0;
    float resta;
    int flagResta = 0;
    float division;
    int flagDivision = 0;
    float multiplicacion;
    int flagMultiplicacion = 0;
    long long factorial;
    int flagFactorial = 0;
    int valdivision;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        if (flagA == 0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%.3f)\n",operA);
        }
        if (flagB == 0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.3f)\n",operB);
        }
        if (flagSuma == 0)
        {
            printf("3- Calcular la suma (A+B)\n");
        }
        else
        {
            printf("3- Calcular la suma (A+B) = %.3f\n",suma);
        }
        if (flagResta == 0)
        {
            printf("4- Calcular la resta (A-B)\n");
        }
        else
        {
            printf("4- Calcular la resta (A-B) = %.3f\n",resta);
        }
        if (flagDivision == 0)
        {
            printf("5- Calcular la division (A/B)\n");
        }
        else
        {
            printf("5- Calcular la division (A/B) = %.3f\n",division);
        }
        if (flagMultiplicacion == 0)
        {
            printf("6- Calcular la multiplicacion (A*B)\n");
        }
        else
        {
            printf("6- Calcular la multiplicacion (A*B) = %.3f\n",multiplicacion);
        }
        if (flagFactorial == 0)
        {
            printf("7- Calcular el factorial (A!)\n");
        }
        else
        {
            printf("7- Calcular el factorial (A!) = %d\n",factorial);
        }
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("Ingrese la opcion que desea usar: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            operA = funIngreso();
            flagA = 1;
            break;
        case 2:
            operB = funIngreso();
            flagB = 1;
            break;
        case 3:
            suma = funSumar(operA, operB);
            printf("La suma es de: %f\n", suma);
            flagSuma = 1;
            system("pause");
            system("cls");
            break;
        case 4:
            resta = funResta(operA, operB);
            printf("La resta es de: %f\n", resta);
            flagResta = 1;
            system("pause");
            system("cls");
            break;
        case 5:
            valdivision = funValidarCero(operA, operB);
            if (valdivision != 0)
            {
                division = funDividir(operA, operB);
                printf("La division es de: %.3f\n", division);
                flagDivision = 1;
                system("pause");
                system("cls");
            }
            else
            {
                printf("Error!!!! No se puede realizar la operacion \n");
                system("pause");
                system("cls");
            }
            break;
        case 6:
            multiplicacion = funMultiplicaion(operA, operB);
            printf("La multiplicacion es de: %3f\n", multiplicacion);
            flagMultiplicacion = 1;
            system("pause");
            system("cls");
            break;
        case 7:
            factorial= funFactorial(operA);
            if(factorial != 0)
            {
                printf("El factorial de %.f es de: %lli\n", operA,factorial);
                flagFactorial = 1;
                system("pause");
                system("cls");
            }
            else
            {
                printf("Error!!! No se puede sacar el factorialcon de ese numero! \n");
                system("pause");
                system("cls");
            }
            break;
        case 8:
            suma = funSumar(operA, operB);
            flagSuma = 1;
            printf("La suma es de: %f\n", suma);
            resta = funResta(operA, operB);
            flagResta = 1;
            printf("La resta es de: %f\n", resta);
            valdivision = funValidarCero(operA, operB);
            if (valdivision != 0)
            {
                division = funDividir(operA, operB);
                printf("La division es de: %.3f\n", division);
                flagDivision = 1;
            }
            else
            {
                printf("Error!!!! No se puede realizar la operacion \n");
            }
            multiplicacion = funMultiplicaion(operA, operB);
            printf("La multiplicacion es de: %f\n", multiplicacion);
            flagMultiplicacion = 1;
            factorial= funFactorial(operA);
            if(factorial != 0)
            {
                printf("El factorial de %.f es de: %lli\n", operA,factorial);
                flagFactorial = 1;
            }
            else
            {
                printf("Error!!! No se puede sacar el factorialcon de ese numero! \n");
            }
            system("pause");
            system("cls");
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
