/*
 * ArrayEmployees.h
 *
 *  Created on: 8 nov. 2021
 *      Author: Principal
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief menu principal
 * \return  Retorna la opcion elegida del menu
 *
 */
int menu ();


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* lista, int len);


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployees(Employee* lista, int len, int id, char name[], char lastName[], float salary, int sector);

int nuevoEmpleado(Employee* lista, int len, int* id);

/** \brief busca empeleado inicializado
 *
 * \param lista de empleados
 * \param tamaño
 * \return 1 todoOk - 0 error
 *
 */
int findFree(Employee* lista, int let);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* lista, int len);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortEmployees(Employee* lista, int len, int order);


/** \brief imprime todos los empleados y pregunta en que orden
 *
 * \param tamaño
 * \param order - orden en que se imprime ascendente o descendente
 * \return retorna 1 si todoOK - 0 si hay error
 *
 */
int printEmployeesOrder(Employee lista[], int len,int order);


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*/
void printEmployee(Employee lista);


int printEmployees(Employee lista[],int len);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* lista, int len, int id);


/** \brief Menu de las opciones de modifacion
 *
 * \param tamaño de la lista
 * \param indice representa un id
 * \return retorna la opcion elegida
 */
int menuModificar(Employee lista[],int len, int indice);


/** \brief Modifica los datos la lista de empleados
 *
 * \param tamaño de la misma
 * \param indice representa un id
 * \return 1 todoOk - 0 error
 */
int modificarEmpleado(Employee lista[], int len);


/** \brief menu de ordenamiento de la lista
 * \return la opcion seleccionada del menu
 *
 */
int menuOrdenamiento();


/** \brief Informes de salario
 *
 * \param lista de empleados
 * \param tamaño
 * \return 1 si todoOk - 0 si hay error
 *
 */

int informesSueldo(Employee lista[], int len);
