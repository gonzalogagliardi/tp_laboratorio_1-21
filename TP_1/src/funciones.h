/*
 * funciones.h
 *
 *  Created on: 24 sep. 2021
 *      Author: Principal
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
 * @fn void suma(float, float, float*)
 * @brief
 *
 * @param x Primer valor ingresado a sumarse
 * @param y segundo valor ingresado a sumarse
 * @param pSuma es el puntero que devuelve el resultado
 */
void suma(float x, float y, float* pSuma);



/**
 * @fn void resta(float, float, float*)
 * @brief
 *
 * @param x Primer valor ingresado a restar
 * @param y  segundo valor ingresado a restar
 * @param pResta es el puntero que devuelve el resultado
 */
void resta(float x, float y, float* pResta);



/**
 * @fn void multiplicacion(float, float, float*)
 * @brief
 *
 * @param x  Primer valor ingresado a multiplicar
 * @param y  Segundo valor ingresado a multiplicar
 * @param pMultiplicacion es el puntero que devuelve el resultado
 */
void multiplicacion(float x, float y, float* pMultiplicacion);



/**
 * @fn int division(float, float, float*)
 * @brief
 *
 * @param x Primer valor ingresado a dividir
 * @param y Segundo valor ingresado a dividir
 * @param pDividir es el puntero que devuelve el resultado
 * @return
 */
int division(float x, float y, float* pDividir);



/**
 * @fn int factorial(float, float*)
 * @brief
 *
 * @param num valor recibdo para realizar el factorial
 * @param pFactorial puntero que devuelve el resultado
 * @return
 */
int factorial(float num, float* pFactorial);



/**
 * @fn int factorial2(float, float*)
 * @brief
 *
 * @param num valor recibdo para realizar el factorial
 * @param pFactorial2 puntero que devuelve el resultado
 * @return
 */
int factorial2(float num, float* pFactorial2);

#endif /* FUNCIONES_H_ */
