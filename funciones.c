#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float funIngreso()
{
    float num;
    printf("Ingrese un numero: ");
    scanf("%f",&num);
    system("cls");
    return num;
}

float funSumar(float primernum,float segundonum)
{
    float resultado;
    resultado = primernum + segundonum;
    return resultado;
}

float funResta(float primernum,float segundonum)
{
    float resultado;
    resultado = primernum - segundonum;
    return resultado;
}

float funDividir (float primernum,float segundonum)
{
    float resultado;
    resultado = primernum / segundonum;
    return resultado;
}

float funMultiplicaion (float primernum,float segundonum)
{
    long double resultado;
    resultado = primernum * segundonum;
    return resultado;
}

float funFactorial (float primernum)
{
    int respuesta = 1;
    int cont;
    int validarpos;
    int validarmenorigualdoce;
    int validarcoma;
    validarcoma = funValidarComa(primernum);
    validarmenorigualdoce = funValidarMenorIgualdoce(primernum);
    validarpos = funValidarPositivos(primernum);
    if (validarcoma != 0 && validarmenorigualdoce != 0 && validarpos != 0)
    {
        for (cont = (int) primernum; cont > 1; cont--)
        {
            respuesta = respuesta * cont;
        }
    }
    else
    {
        respuesta = 0;
    }
    return respuesta;
}

float funValidarCero (float primernum,float segundonum)
{
    int respuesta =0;
    if (segundonum != 0)
    {
        respuesta  = 1;
    }
    return respuesta;
}

float funValidarPositivos (float num)
{
    int retorno = 0;
    if (num >= (float)0)
    {
        retorno = 1;
    }
    return retorno;
}

float funValidarMenorIgualdoce (float num)
{
    int retorno = 0;
    if (num <=12)
    {
        retorno = 1;
    }
    return retorno;
}

float funValidarComa (float num)
{
    int retorno;
    if (num - (int) num == 0)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}
