/*
 * getIO.h
 *
 *  Created on: 8 nov. 2021
 *      Author: Principal
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifndef GETIO_H_INCLUDED
#define GETIO_H_INCLUDED



#endif // GETIO_H_INCLUDED

int Validate_IntMinMax (char numero[], int min, int max);

/** \brief Pide un entero al usuario
 *
 * \param mensaje es el mensaje para pedir numero
 * \param El mensaje de error, en caso que lo haya.
 * \param min el minimo numero deseado
 * \param max el maximo deseado
 * \return retorna el entero
 */
int Get_IntMinMax (char message[], char errorMessage[], int min, int max);

int esSoloLetras(char str[]);

int getStringLetras(char mensaje[],char input[]);


/** \brief
 *
 * \param mensaje es el mensaje para pedir string
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 *
 */
void getString(char mensaje[],char input[]);


/** \brief Pide un flotante
 *
 * \param mensaje es el mesnaje para pedir numero
 * \param
 * \return el numero
 *
 */
float getFloat(char mensaje[]);

/** \brief Pide un entero
 *
 * \param mensaje es el mesnaje para pedir numero
 * \param
 * \return retorna el numero
 *
 */
int getInt(char mensaje[]);
