/*
 * menu.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Principal
 */
#include <conio.h>
#include <stdio.h>
#include "menu.h"
#include "funciones.h"
#include "input.h"


void menuUsuario()
{
    float x = 0;
    float y = 0;
    char seguir = 's';
    int flagX = 0;
    int seCalculo = 0;

    float operacionDividir;
    int factorialresul;
    int factorialresul2;
    float pDividir;
    float pSuma;
    float pResta;
    float pMultiplicacion;
    float pFactorial;
    float pFactorial2;


    do{

        switch(menu())
        {
            case 1:
                if(flagX == 0)
                {
                   x =  get_Float("\nIngrese el primer numero: ");
                        printf("\nPRIMER NUMERO CARGADO CON EXITO!!\n");
                    flagX++;
                    system("pause");//Para que limpie la pantalla
                }

                    break;

            case 2:
                if(flagX == 1)
                {
                   y =  get_Float("\nIngrese el segundo numero: ");
                   printf("\nSEGUNDO NUMERO CARGADO CON EXITO!!\n");
                    flagX++;
                    system("pause");//Para que limpie la pantalla
                }
                else
                {
                    printf("\nError. Debe ingresar el primer numero.\n");
                }
            break;

            case 3:
                if(flagX == 2)
                {


                      suma(x, y, &pSuma);
                      resta( x, y, &pResta);
                      multiplicacion( x, y, &pMultiplicacion);

                      operacionDividir = division( x, y, &pDividir);

                      factorialresul = factorial( x,  &pFactorial);
                      factorialresul2 = factorial2( y, &pFactorial2);


                    flagX++;
                    seCalculo = 1;
                 printf("Realizando operaciones..\n");
                 system("pause");
                }
                else
                {
                    printf("\nError. Antes de calcular las operaciones debe ingresar los numeros.\n");
                }


            break;

            case 4:
            		if(seCalculo)
            		{
                     printf("x = %.2f --------------- y = %.2f", x, y);
                     printf("\n     La suma es: %.2f ", pSuma);
                     printf("\n     La resta es: %.2f", pResta);
                     printf("\n     La multiplicacion es: %.2f", pMultiplicacion);


                     if(operacionDividir)
                        {
                            printf("\n     La division es: %.2f", pDividir);
                        }
                        else
                        {
                            printf("\n     Error. No es posible dividir por 0.");
                        }

                        if(factorialresul)
                        {
                             printf("\n     El factorial de x es: %.2f", pFactorial);
                        }
                        else
                        {
                            printf("No se pudo realizar el factorial de x.");
                        }

                        if(factorialresul2)
                        {
                             printf("\n     El factorial de y es: %.2f", pFactorial2);
                        }
                        else
                        {
                            printf("     No se pudo realizar el factorial de y.");
                        }


            			flagX = 0;
            			seCalculo = 0;
            			system("pause");
            			}
            		else
            		{
            			printf("\nAntes de ver los resultados tiene que calcular las operaciones\n");
            			system("pause");
            		}
            		break;
            case 5:

                printf("Saliendo de la calculadora.. Adios.\n");
                seguir = 'n';
            break;

            default:
                printf("Opcion incorrecta.. Ingrese una opcion correcta\n");
            break;
        }


        //system("pause");


    }while(seguir == 's');

}


int menu()
{
    int opcion;


        printf("\t");
        printf("\n\n\n**Menu de opciones**\n\n");
        printf("\n1. Ingrese el primer operando: ");
        printf("\n2. Ingrese el segundo operando: ");
        printf("\n3. Calcular todas las operaciones.");
        printf("\n4. Ver resultados.");
        printf("\n5. Salir.");
        printf("\n\nIndique opcion: ");
        //__fpurge(stdin);
        fflush(stdin);
        scanf("%d",&opcion);

        return opcion;
}


