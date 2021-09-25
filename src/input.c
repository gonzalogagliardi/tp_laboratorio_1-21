/*
 * input.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Principal
 */


#include "input.h"





float get_Float(char* MSJ)
{
    float numero = 0;

    printf(MSJ);
    scanf("%f", &numero);

    return numero;
}
