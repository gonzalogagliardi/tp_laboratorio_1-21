/*
 * validaciones.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Principal
 */


#include "validaciones.h"

int validarCero(float numero1, float numero2)
{
    int retorno = 1;

    if(numero1 == 0 || numero2 == 0)
    {
        retorno = 0;
    }

    return retorno;
}
