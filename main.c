#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float operA = 0;
    float operB = 0;
    float suma = 0;
    float resta = 0;
    float multiplicacion = 0;
    float division = 0;
    int factorial = 0;
    int valdivision;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.3f)\n",operA);
        printf("2- Ingresar 2do operando (B=%.3f)\n",operB);
        printf("3- Calcular la suma (A+B) = %.3f\n",suma);
        printf("4- Calcular la resta (A-B) = %.3f\n",resta);
        printf("5- Calcular la division (A/B) = %.3f\n",division);
        printf("6- Calcular la multiplicacion (A*B) = %.3f\n",multiplicacion);
        printf("7- Calcular el factorial (A!) = %d\n",factorial);
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("Ingrese la opcion que desea usar: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            operA = funIngreso();
            break;
        case 2:
            operB = funIngreso();
            break;
        case 3:
            suma = funSumar(operA, operB);
            printf("La suma es de: %f\n", suma);
            system("pause");
            system("cls");
            break;
        case 4:
            resta = funResta(operA, operB);
            printf("La resta es de: %f\n", resta);
            system("pause");
            system("cls");
            break;
        case 5:
            valdivision = funValidarCero(operA, operB);
            if (valdivision != 0)
            {
                division = funDividir(operA, operB);
                printf("La division es de: %.3f\n", division);
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
            system("pause");
            system("cls");
            break;
        case 7:
            factorial= funFactorial(operA);
            if(factorial != 0)
            {
                printf("El factorial de %.f es de: %d\n", operA,factorial);
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
            printf("La suma es de: %f\n", suma);
            resta = funResta(operA, operB);
            printf("La resta es de: %f\n", resta);
            valdivision = funValidarCero(operA, operB);
            if (valdivision != 0)
            {
                division = funDividir(operA, operB);
                printf("La division es de: %.3f\n", division);
            }
            else
            {
                printf("Error!!!! No se puede realizar la operacion \n");
            }
            multiplicacion = funMultiplicaion(operA, operB);
            printf("La multiplicacion es de: %f\n", multiplicacion);
            factorial= funFactorial(operA);
            if(factorial != 0)
            {
                printf("El factorial de %.f es de: %d\n", operA,factorial);
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
