/*
 * ArrayEmployees.c
 *
 *  Created on: 16 may. 2020
 *      Author: Soa
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0
#define MAXSALARIO 1000000.00 // Maximo salario a pagar
#define TAMSEC 5 // cantidad de sectores en la empresa
#define TAM 20


/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
    if(list!= NULL && len >= 0 && len < 1000)
    {
        for (int i=0; i < len; i++)
        {
            list[i].isEmpty=TRUE;
        }
        return 0;
    }
    return -1;
}


/** \brief add in a existing list of employees the values received as parameters
 *      in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int indice;
    Employee auxList;
    indice = buscarEmpty(list, len);
    if( list != NULL && name != NULL && lastName != NULL && len >= 0 && len < 1000)
    {
        strcpy (auxList.name, name);
        strcpy (auxList.lastName, lastName);
        auxList.salary=salary;
        auxList.sector=sector;
        auxList.isEmpty=FALSE;
        auxList.id=id;

        list[indice]=auxList;
        printf("\nCarga Exitosa\n");
        system("pause>nul");
        return 0;
    }
    else
    {
        printf("\nError, la carga no pudo realizarse.\n");
        system("pause>nul");
    }
    return -1;
}


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id)
{
    system("cls");
    if( list != NULL && len > 0 && len < 1000)
    {
        for (int i=0; i < len; i++)
        {
            if (list[i].id == id)
            {
                printf("\n_____________________________________________________________________________\n");
                printf("  ID           Nombre         Apellido        Salario     Sector\n\n");
                printf("  %03d    %12s    %12s         %8.2f     %2d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
                printf("_____________________________________________________________________________\n");
                return i;
            }
        }
        printf("\nEl ID no coincide con ningun empleado\n");
        system("pause>nul");
    }
    return -1;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    char resp;
    if( list != NULL && len >= 0 && len < 1000)
    {
        for (int i=0; i < len; i++)
        {
            if (list[i].id == id)
            {
                system ("cls");
                printf("\n_______________________________________________________________\n");
                printf("\n_______________________Baja de empleado________________________\n\n");
                printf("\nID           Nombre         Apellido        Salario     Sector\n\n");
                printf("%03d    %12s    %12s         %8.2f     %2d\n", list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
                printf("\n_______________________________________________________________\n");
                printf("\n\nEsta seguro de eliminar al empleado s/n? : ");
                fflush(stdin);
                scanf("%c",&resp);
                if (resp == 's')
                {
                    list[i].isEmpty=TRUE;
                    printf("\n\nSe elimino al empleado\n\n");
                    system("pause>nul");
                }
                else
                {
                    printf("\nSe cancelo la baja del empleado\n\n");
                    system("pause>nul");
                }
                return 0;
            }
        }
        printf("\nEl ID no coincide con ningun empleado\n");
        system("pause>nul");
    }
    return -1;
}


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmpleado;

    if ( list != NULL && len > 0 )
    {
        if (order == 1)
        {
            for (int i=0; i<len-1; i++)
            {
                for (int j=i+1; j<len; j++)
                {
                    if (list[i].sector > list[j].sector)
                    {
                        auxEmpleado = list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                    else if (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName ) > 0)
                    {
                        auxEmpleado = list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                }
            }
        }
        else
        {
            for (int i=0; i<len-1; i++)
            {
                for (int j=i+1; j<len; j++)
                {
                    if (list[i].sector < list[j].sector)
                    {
                        auxEmpleado = list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                    else if (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName ) < 0)
                    {
                        auxEmpleado = list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                }
            }
        }
        return 0;
    }
    return -1;
}


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length)
{
    system("CLS");
    printf("\nID           Nombre         Apellido        Salario     Sector\n\n");
    for (int i=0; i < length; i++)
    {
        if (list[i].isEmpty==FALSE)
        {
            printf("%03d    %12s    %12s         %8.2f     %2d\n", list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    system("pause>nul");
    return 0;
}


/** \brief busca el primer lugar vacio en la array
 *
 * \param list Employee*
 * \param length tamaño de empleados
 * \return retorna el index del vector si encuentra un lugar vacio, si no encuentra nada devuelve -1
 *
 */
int buscarEmpty(Employee* list, int length)
{
    for (int i=0; i < length; i++)
    {
        if (list[i].isEmpty==TRUE)
        {
            return i;
        }
    }
    return -1;
}


/** \brief realiza un chequeo antes de la carga del empleado
 *
 * \param list Employee*
 * \param tam tamaño de empleados
 * \param id a asignar
 * \param list eSector*
 * \param tamsec tamaño de sectores
 * \return retorna el index del vector si encuentra un lugar vacio, si no encuentra nada devuelve -1
 *
 */
int preCarga(Employee* list, int tam, int id, eSector* sectores, int tamsec)
{
    char auxName[51];
    char auxApe[51];
    float auxSal;
    int auxSec;
    int auxCarga;
    int index;

    index = buscarEmpty(list,tam);

    if (index == -1)
    {
        printf("\nError, La base de datos esta completa\n");
        system("pause>nul");
    }
    else
    {
        system("CLS");
        printf("\n\n*************************************\n");
        printf("*           Alta de usuario         *\n");
        printf("*************************************\n\n");
        printf("\nIngrese Nombre: ");
        fflush(stdin);
        gets(auxName);
        printf("\nIngrese Apellido: ");
        fflush(stdin);
        gets(auxApe);
        utn_getNumeroFlotante(&auxSal, "\nIngrese nuevo salario: ", "\nError, salario demasiado alto\n", 0, MAXSALARIO, 3);
        listarSectores(sectores, tamsec);
        utn_getNumero(&auxSec, "Ingrese nuevo sector: ", "\nError, sector incorrecto", 0, TAMSEC, 3);
        auxCarga=addEmployee(list, tam, id, auxName, auxApe, auxSal, auxSec);
        return auxCarga;
    }
    return -1;
}


/** \brief realiza un chequeo antes de la busqueda del empleado
 *
 * \param list Employee*
 * \param tam tamaño de empleados
 * \param check bandera para saber si se realizo una primera carga
 * \param sectores eSector*
 * \param tamsec tamaño de sectores
 * \return retorna el index del vector si encuentra un lugar vacio, si no encuentra nada devuelve -1
 *
 */
void preBusqueda(Employee* list, int tam, int check, eSector* sectores, int tamsec)
{
    int index;
    int auxID;
    system("CLS");
    if (check == -2)
    {
        printf("\n\n*************************************\n");
        printf("*    La base de datos esta vacia    *\n");
        printf("*************************************\n\n");
        system("pause");


    }
    else
    {
        printf("\n\n************************************************\n");
        printf("*              Modificar empleado              *\n");
        printf("************************************************\n");
        printf("\nIngrese ID del empleado: ");
        scanf("%d",&auxID);
        index = findEmployeeById(list, TAM, auxID);
        if (index >= 0)
        {
            menuMod(list, tam, index, sectores, TAMSEC);
        }
    }
}


/** \brief realiza un chequeo antes de la baja del empleado
 *
 * \param list Employee*
 * \param tam tamaño de empleados
 * \param check bandera para saber si se realizo una primera carga
 *
 */
void preBaja(Employee* list, int tam, int check)
{
    int auxID;
    system("CLS");
    if (check == -2)
    {
        printf("\n\n*************************************\n");
        printf("*    La base de datos esta vacia    *\n");
        printf("*************************************\n\n");
        system("pause");


    }
    else
    {
        printf("\n\n************************************************\n");
        printf("*                Baja empleado                 *\n");
        printf("************************************************\n");
        printf("\nIngrese ID del empleado para la baja: ");
        scanf("%d",&auxID);
        removeEmployee(list, tam, auxID);
    }
}

/** \brief realiza un chequeo antes de listar los empleados
 *
 * \param list Employee*
 * \param tam tamaño de empleados
 * \param check bandera para saber si se realizo una primera carga
 *
 */
void prePrint(Employee* list, int tam, int check)
{
    int resp;
    int criterio=0;
    float total;
    float promedio;
    int salaryUp;
    system("CLS");
    if (check == -2)
    {
        printf("\n\n*************************************\n");
        printf("*    La base de datos esta vacia    *\n");
        printf("*************************************\n\n");
        system("pause");
    }
    else
    {

        printf("\n1) Listado de los empleados ordenados alfabeticamente por Apellido y Sector.");
        printf("\n2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio. \n");
        utn_getNumero(&resp, "\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar 1 o 2\n", 1, 2, 3);
        if (resp == 1)
        {
            utn_getNumero(&criterio, "\n1) orden ascendente\n0) orden descendente\n", "\nError, ingreso incorrecto, debe ingresar 0 o 1\n", 0, 1, 3);
            sortEmployees(list, tam, criterio);
            printEmployees(list, tam);
        }
        else if (resp == 2)
        {
            promedioYtotal(list, tam, &total, &promedio, &salaryUp);
            printf("\nTotal         Promedio      promedioMayor\n\n");
            printf("%7.2f     %7.2f         %d\n\n", total, promedio, salaryUp);
            system("pause>nul");
        }
    }
}

/** \brief realiza el promedio de los sueldos, el total y los empleados que superan el promedio
 *
 * \param list Employee*
 * \param tam tamaño de empleados
 * \param pTotalSalary del empleado buscado
 * \param pPromedio eSector*
 * \param pPromUp tamaño de sectores
 * \return retorna el index del vector si encuentra un lugar vacio, si no encuentra nada devuelve -1
 *
 */
void promedioYtotal (Employee* list, int tam, float* pTotalSalary, float* pPromedio, int* pPromUp)
{
    int cont=0;
    int contProm=0;
    float totalSalary;
    float promedio;
    for (int i=0; i < tam; i++)
    {
        if (list[i].isEmpty==FALSE)
        {
            totalSalary = totalSalary + list[i].salary;
            cont++;
        }
    }
    promedio = (float) totalSalary / cont;

    *pTotalSalary = totalSalary;
    *pPromedio = promedio;

    for (int i=0; i < tam; i++)
    {
        if (list[i].isEmpty==FALSE && list[i].salary > promedio )
        {
            contProm++;
        }
    }
    *pPromUp = contProm;
}


/** \brief menu para modificar nombre, apellido, salario o sector del emplados
 *
 * \param list Employee*
 * \param tam tamaño de empleados
 * \param index del empleado buscado
 * \param sectores eSector*
 * \param tamsec tamaño de sectores
 * \return retorna el index del vector si encuentra un lugar vacio, si no encuentra nada devuelve -1
 *
 */
void menuMod(Employee* list, int tam, int index, eSector* sectores, int tamsec)
{
    int resp;
    printf("\n\n*************************************\n");
    printf("*       Modificando empleado        *\n");
    printf("*************************************\n\n");
    printf("Que desea modificar?\n\n");
    printf("1) Nombre\n");
    printf("2) Apellido\n");
    printf("3) Salario\n");
    printf("4) Sector\n");
    utn_getNumero(&resp, "\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 4\n", 1, 4, 3);
    switch (resp)
    {
    case 1 :
        printf("\nIngrese nuevo nombre: ");
        fflush(stdin);
        gets(list[index].name);
        printf("\nCarga Exitosa\n\n");
        system("pause>nul");
        break;
    case 2 :
        printf("\nIngrese nuevo apellido: ");
        fflush(stdin);
        gets(list[index].lastName);
        printf("\nCarga Exitosa\n\n");
        system("pause>nul");
        break;
    case 3 :
        utn_getNumeroFlotante(&list[index].salary, "\nIngrese nuevo salario: ", "\nError, salario demasiado alto\n", 0, MAXSALARIO, 3);
        printf("\nCarga Exitosa\n\n");
        system("pause>nul");
        break;
    case 4:
        listarSectores(sectores, tamsec);
        utn_getNumero(&list[index].sector, "\nIngrese nuevo sector: ", "Error, sector incorrecto", 0, TAMSEC, 3);
        printf("\nCarga Exitosa\n\n");
        system("pause>nul");
        break;
    }
}

/** \brief harcodea una lista de empleados para pruebas
 *
 * \param list Employee*
 * \param tam tamaño de empleados
 *
 */

/** \brief imprime en pantalla el listado de sectores
 *
 * \param sectores eSector*
 * \param tamSec tamaño de sectores
 * \param check bandera para saber si se realizo una primera carga
 *
 */
void listarSectores (eSector* sectores, int tamSec)
{
    system("CLS");
    printf("\n\n*************************************\n");
    printf("*        Listado de sectores        *\n");
    printf("*************************************\n\n");
    printf("  id      descripcion");

    for (int i=0; i < tamSec; i++ )
    {
        printf("\n  %d     %10s",sectores[i].idS, sectores[i].nombreSec);

    }
    printf("\n");
}


/** \brief menu principal para manejo de empleados
 *
 * \return resp devuelve la opcion elegida
 *
 */
int menuPrincipal()
{
    int resp;
    printf("\n\n************************************************\n");
    printf("*                Menu principal                *\n");
    printf("************************************************\n");
    printf("\n\n1) Alta \n");
    printf("2) Modificar \n");
    printf("3) Baja \n");
    printf("4) Informar \n");
    printf("5) Salir \n");
    utn_getNumero(&resp, "\nIngrese una opcion: ", "Error, debe ingresar una opcion entre 1 y 4", 1, 5, 3);
    return resp;
}
