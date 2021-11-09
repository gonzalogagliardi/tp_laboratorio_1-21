/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"


#define TAM 1000

int main()
{
	setbuf(stdout,NULL);

    char confirmar;
    char seguir;
    int id = 2000;
    Employee lista[TAM];
    int flag = 0;
    int menuOrd;

            if(!initEmployees(lista, TAM))
            {
               printf("Problemas al inicializar\n");
            }

                do{

                    switch(menu())
                    {

                    case 1:
                            if(!nuevoEmpleado(lista,TAM,&id))
                            {
                                printf("No se pudo cargar el empleado\n");

                            }
                            else{
                                printf("\nCarga exitosa!\n");
                            }
                            flag = 1;
                                break;
                    case 2:
                                if(flag == 0)
                                    {
                                        printf("Primero debe cargar un empleado\n");
                                    }
                                else{
                                            if(!modificarEmpleado(lista,TAM))
                                            {
                                            printf("\nNo se pudo realizar la modificacion.");
                                            }
                                    }

                                break;
                    case 3:
                            if(flag == 0)
                                    {
                                        printf("Primero debe cargar un empleado\n");
                                    }
                                else{

                                       if(!removeEmployee(lista, TAM))
                                        {
                                            printf("No se pudo realizar la baja.\n");
                                        }
                                }


                        break;
                    case 4:
                            if(flag == 0)
                            {
                                printf("Primero debe cargar un empleado\n");
                            }
                            else
                            {
                                menuOrd = menuOrdenamiento();

                                if(!printEmployeesOrder(lista,TAM,menuOrd))
                                {
                                printf("\nNo se pudo realizar la baja.");
                                }
                            }
                        break;
                    case 5:

                            printf("\nEsta seguro que quiere salir?: ");
                            fflush(stdin);
                            scanf("%c", &confirmar);
                            if(confirmar == 's')
                            {
                               seguir = 'n';
                            }
                            else
                            {
                                printf("\nVolivendo al menu..");

                            }


                            break;
                    default:
                        printf("Opcion invalida\n");
                        break;

                    }

                    system("pause");


                }while(seguir != 's');





        printf("\ndespues del while");


    return 0;
}
