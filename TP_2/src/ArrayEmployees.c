/*
 * ArrayEmployees.c
 *
 *  Created on: 8 nov. 2021
 *      Author: Principal
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getIO.h"
#include "ArrayEmployees.h"

int initEmployees(Employee* lista, int len)
{
    int retorno = -1;

    if( lista != NULL && len > 0)
    {
        retorno = 0;
        for(int i=0; i < len; i++)
        {
            lista[i].isEmpty = 1;
        }

    }

    return retorno;
}


int menu ()
{

int opcion;

    system("cls");

    printf("*** Menu Empleados *** \n\n");
    printf("1-Alta Empleados\n");
    printf("2-Modificar Empleados\n");
    printf("3-Baja Empleados\n");
    printf("4-Informes Empleados\n");
    printf("5-Salir\n");
    opcion = Get_IntMinMax("\nIngrese una opcion: ","\nError. Ingrese una opcion: ",1,5);


    return opcion;
}
int findEmployeeById(Employee* lista, int len, int id)
{
    int indice= -1;

     for(int i=0; i < len; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }

    return indice;

}


int findFree(Employee* lista, int len)
{
    int indice = -1;

    if(lista != NULL && len > 0)
    {
     for(int i=0; i < len; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;

}


int addEmployees(Employee* lista, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int todoOk = -1;
    int indice;

        if(lista != NULL && len > 0 && name != NULL && lastName != NULL && salary > 0 && sector > 0)
        {
            indice = findFree(lista,len);
            lista[indice].id = id;
            lista[indice].salary = salary;
            lista[indice].isEmpty = 0;
            lista[indice].sector = sector;
            strcpy(lista[indice].name, name);
            strcpy(lista[indice].lastName, lastName);
            todoOk = 1; //Ver si por esto da error

        }
        return todoOk;
}

int nuevoEmpleado(Employee* lista, int len, int* id)
{
    int todoOk = -1;
    int indice;
    int auxiliarId;
    Employee auxiliarEmployee;

        if(lista != NULL && len > 0 )
        {
            indice = findFree(lista,len);
            if(indice != -1)
            {
                printf("    *** Alta Empleado ***\n");
                printf("-----------------------------\n");
                auxiliarId = *id;
                (*id)++;

                getStringLetras("\nIngrese el nombre: ", auxiliarEmployee.name);
                getStringLetras("\nIngrese el apellido: ", auxiliarEmployee.lastName);
                auxiliarEmployee.salary = getFloat("\nIngrese el salario: ");
                auxiliarEmployee.sector = Get_IntMinMax("\nIngrese el sector (1 a 15): ", "\nError. Reingrese un sector valido: ",0,15);

                todoOk = addEmployees(lista,len,auxiliarId,auxiliarEmployee.name,auxiliarEmployee.lastName,auxiliarEmployee.salary,auxiliarEmployee.sector);

                if(todoOk == -1)
                {
                    printf("Error al cargar empleado.");
                }
                else
                {
                    printf("Empleado cargado con exito!!\n");
                }
            }
            else
            {
                printf("No hay espacio para cargar empleados.");
            }
        }


    return todoOk;
}

int removeEmployee(Employee* lista, int len)
{
    int retorno = 0;
    int id;
    int indice;
    char confirma;

        if (lista != NULL && len > 0)
        {
                system("cls");
                printf("     *** Baja Empleado ***\n");
                printEmployees(lista,len);
                printf("\nIngrese id: ");
                scanf("%d", &id);

                indice = findEmployeeById(lista,len,id);
                if(indice == -1)
                {
                    printf("\nEl id: %d no esta registrado.", id);
                }
                else
                {
                       printEmployee(lista[indice]);
                       getStringLetras("\nConfirma la baja? s/n: ", &confirma);

                        if(confirma == 's')
                        {
                            lista[indice].isEmpty = 1;
                            retorno = 1;
                        }
                        else
                        {
                            printf("Baja cancelada por el usuario\n");
                        }

                }
        }



    return retorno;
}

void printEmployee(Employee lista)
{
    printf("   %d       %-10s           %-10s         $%.2f        %d  \n", lista.id,lista.name, lista.lastName, lista.salary, lista.sector);
}


int printEmployeesOrder(Employee lista[],int len, int order)
{
    int retorno = 0;

        if(lista != NULL && len > 0)
        {

            //order = menuOrdenamiento();
            sortEmployees(lista,len,order);

            if(order != -1)
            {
            system("cls");
            printf("                      *** Lista de Empleados ***                      \n");
            printf("--------------------------------------------------------------------------\n");
            printf("   ID         Nombre               Apellido          Salario        Sector  \n");
            printf("--------------------------------------------------------------------------\n");


               for(int i=0; i < len; i++)
                {

                    if(!lista[i].isEmpty)
                    {
                        printEmployee(lista[i]);
                    }

                }

            }
            else{
                informesSueldo(lista,len);
            }

            retorno = 1;
        }

    return retorno;
}

int printEmployees(Employee lista[],int len)
{
    int retorno = 0;

        if(lista != NULL && len > 0)
        {




            system("cls");
            printf("                      *** Lista de Empleados ***                      \n");
            printf("--------------------------------------------------------------------------\n");
            printf("   ID         Nombre               Apellido          Salario        Sector  \n");
            printf("--------------------------------------------------------------------------\n");


               for(int i=0; i < len; i++)
                {

                    if(!lista[i].isEmpty)
                    {
                        printEmployee(lista[i]);
                    }

                }




            retorno = 1;
        }

    return retorno;
}

int menuModificar(Employee lista[],int len, int indice)
{
    int opcion = 0;
    system("cls");
    printf("     *** Modificar Empleado ***\n");
    printf("-----------------------------------\n");
    printf("Para confirmar una modificacion ingrese 's'.\n\n");
    printf("\n Nombre: %s   \n Apellido: %s   \n Salario: $%.2f   \n Sector: %d \n\n", lista[indice].name, lista[indice].lastName, lista[indice].salary, lista[indice].sector);
    printf("1- Modificar Nombre\n");
    printf("2- Modificar Apeliido\n");
    printf("3- Modificar Salario\n");
    printf("4- Modificar Sector\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int modificarEmpleado(Employee lista[], int len)
{


    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char quit;
    Employee auxEmployee;
    if (lista != NULL && len > 0)
    {
        system("cls");
        printf("   *** Modificar Empleado *** \n\n");
        printf("----------------------------------\n");
        printEmployees(lista,len);
        printf("Ingrese id del empleado a modificar: ");
        scanf("%d", &id);

        indice = findEmployeeById(lista, len, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado.\n", id);
        }
        else
        {
            do
            {
                switch ( menuModificar(lista, len, indice) )
                {
                case 1:
                    printf("\nModificar nombre: ");
                    fflush(stdin);
                    gets(auxEmployee.name);
                    printf("\nConfirma cambio de nombre?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(lista[indice].name, auxEmployee.name);
                    }
                    else
                    {
                        printf("Modificacion cancelada\n");
                    }
                    break;
                case 2:
                    printf("\nModificar apellido: ");
                    fflush(stdin);
                    gets(auxEmployee.lastName);
                    printf("\nConfirma cambio de apellido?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(lista[indice].lastName, auxEmployee.lastName);
                    }
                    else
                    {
                        printf("\nModificacion cancelada\n");
                    }
                    break;
                case 3:
                     printf("Modificar Salario: ");
                    scanf("%f", &auxEmployee.salary);
                    printf("\nConfirma cambio de Salario?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].salary = auxEmployee.salary;
                    }
                    else
                    {
                        printf("Modificacion cancelada\n");
                    }
                    break;
                    /////

                case 4:
                    printf("Modificar Sector: ");
                    scanf("%d", &auxEmployee.sector);
                    printf("\nConfirma cambio de Sector?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].sector = auxEmployee.sector;
                    }
                    else
                    {
                        printf("Modificacion cancelada\n");
                    }
                    break;

                case 10:
                    printf("\nEsta seguro que quiere salir?: ");
                    fflush(stdin);
                    scanf("%c", &quit);
                    quit = toupper(quit);
                    if (quit == 'S')
                    {
                        seguir = 'n';
                    }
                    else
                    {
                        break;
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                }

            }
            while(seguir == 's');

            todoOk = 1;

        }
    }
    return todoOk;


}


int sortEmployees(Employee* lista, int len, int order)
{
    int todoOk = -1;
    Employee auxEmployee;

        if(lista != NULL && len > 0)
        {

            for(int i=0; i < len ; i++)
            {
                for(int j= i+1; j < len; j++)
                {
                    if(order)//Asc
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)>0 || (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].sector>lista[j].sector))
                        {
                            auxEmployee = lista[i];
                            lista[i] = lista[j];
                            lista[j] = auxEmployee;
                        }
                    }
                    else{//desc

                        if(strcmp(lista[i].lastName,lista[j].lastName)<0 || (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].sector<lista[j].sector))
                        {
                            auxEmployee = lista[i];
                            lista[i] = lista[j];
                            lista[j] = auxEmployee;
                        }

                    }
                }
            }

            todoOk = 0;
        }










    return todoOk;
}


int menuOrdenamiento()
{
    int retorno;
    int opcion;

     system("cls");
     printf("1_ Ordenar Empleados ascendente\n");
     printf("2_ Ordenar Empleados descendente\n");
     printf("3_ Mostrar informes de salario.\n");
     opcion = Get_IntMinMax("\nSelecciona una opcion: ","Error. Selecciona una opcion : ",1,3);

     switch(opcion)
     {
     case 1:
        retorno = 0;
        break;

     case 2:
        retorno = 1;
        break;

     case 3:
         retorno = -1;

        break;
     }

     return retorno;
}






int informesSueldo(Employee lista[], int len)
{
    int retorno = 0;
    float promSalario;
    float AcumuladorSalario = 0;
    int contadorEmpelados = 0;
    int contSalarioPromMayor = 0;
    int flag = 1;

            if( lista != NULL && len > 0 )
            {
                for( int i = 0; i< len; i++)
                {
                    if(lista[i].isEmpty == 0)
                    {
                        AcumuladorSalario += lista[i].salary;
                        contadorEmpelados++;
                    }
                }


            if(contadorEmpelados != 0)
            {
                promSalario = (float) AcumuladorSalario / contadorEmpelados;
            }

            for(int i=0; i<len; i++)
            {
                if(lista[i].isEmpty == 0&& lista[i].salary > promSalario)
                {
                    contSalarioPromMayor++;
                }
            }
            retorno = 1;
            flag = 0;
            }

            if(flag == 0)
            {
                printf("\n\n*El total de los salarios es %.2f\n",AcumuladorSalario);
                printf("**El promedio de los salarios es %2.f\n", promSalario);
                printf("***La cantidad de empleados que superan el sueldo promedio es %d\n\n", contSalarioPromMayor);
            }
            else{
                printf("No se pudo la informacion.");
            }


    return retorno;
}
