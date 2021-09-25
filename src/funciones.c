/*
 * funciones.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Principal
 */


#include "funciones.h"
#include "validaciones.h"

void suma(float x, float y, float* pSuma)
{


    *pSuma = x + y;


}

void resta(float x, float y, float* pResta)
{


    *pResta = x - y;


}

void multiplicacion(float x, float y, float* pMultiplicacion)
{


    *pMultiplicacion = x * y;


}

int division(float x, float y, float* pDividir)
{
    int retorno = 0;

    /* if(validarCero(primerNumero, segundoNumero))
     {
        HACER LAS OPERACIONES CON PUNTERO AL RESULTADO, DEVOLVER 1 o 0
     }*/

        if(validarCero(x, y))
        {
            *pDividir = x / y;
            retorno = 1;
        }

    return retorno;
}

int factorial(float num, float* pFactorial)
{
     *pFactorial = 1;

    int retorno = 0;

    if(num >= 0)
    {
        for(int i=2; i <= num; i++)
        {
            *pFactorial *= i;

        }
        retorno = 1;
    }


    return retorno;
}


int factorial2(float num, float* pFactorial2)
{
     *pFactorial2 = 1;

    int retorno = 0;

    if(num >= 0)
    {
        for(int i=2; i <= num; i++)
        {
            *pFactorial2 *= i;

        }
        retorno = 1;
    }


    return retorno;
}




