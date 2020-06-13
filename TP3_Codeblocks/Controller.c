#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* f;
    f = fopen (path, "r");
    if (f == NULL)
    {
        printf("ERROR");
        retorno = -1;
    }
    else
    {
        if ( !parser_EmployeeFromText(f, pArrayListEmployee) )
        {
            printf("\nSe cargo exitosamente la lista de empleados.\n");
            retorno = 0;
        }
    }
    fclose(f);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    f = fopen (path, "rb");
    if (f == NULL)
    {
        printf("ERROR");
        return -1;
    }
    if ( !parser_EmployeeFromBinary(f, pArrayListEmployee) )
    {
        printf("\nSe cargo exitosamente la lista de empleados.\n");
    }
    fclose(f);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id=0;
    char buffer[4][100];
    Employee* auxEmp = employee_new();

    nextId(&id, pArrayListEmployee);
    auxEmp->id = id;
    utn_getNombre(auxEmp->nombre, sizeof(auxEmp->nombre), "\ningrese nombre: ", "\nError, debe ingresar solo letras", 3);
    utn_getNumero(&auxEmp->horasTrabajadas, "\nIngrese horas trabajadas: ", "\nError, el maximo de horas a registrar es de 600", 1, 600, 3);
    utn_getNumero(&auxEmp->sueldo, "\nIngrese sueldo del empleado: ", "\nError, maximo sueldo es $1.000.000", 1, 1000000, 3);

    sprintf(buffer[0], "%d", auxEmp->id);
    strcpy(buffer[1], auxEmp->nombre);
    sprintf(buffer[2], "%d", auxEmp->horasTrabajadas);
    sprintf(buffer[3], "%d", auxEmp->sueldo);

    auxEmp = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

    if (!ll_add(pArrayListEmployee, auxEmp))
    {
        printf("\nCarga exitosa\n");
    }

    updateId(id);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    int id;
    int index;
    int tam = ll_len(pArrayListEmployee);
    if (tam > 0)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("\nIngrese ID del empleado: ");
        scanf("%d",&id);
        index = employee_findById(pArrayListEmployee, id);
        if (index > 0)
        {
            menuMod(pArrayListEmployee, index);
        }
    }
    else
    {
        printf("La base de datos esta vacia\n");
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    int id;
    int indexBaja;
    int tam = ll_len(pArrayListEmployee);
    if (tam > 0)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("-----------------------------------\n");
        printf("--------------Alerta---------------\n");
        printf("--Los cambios no se pueden deshacer--\n");
        printf("--------------Alerta---------------\n");
        printf("--------------Alerta---------------\n");
        printf("\nIngrese ID del empleado para la baja: ");
        scanf("%d",&id);
        indexBaja = employee_findById(pArrayListEmployee, id);
        if (indexBaja > 0)
        {
            if (!ll_remove(pArrayListEmployee,indexBaja))
            {
                printf("Baja exitosa");
            }
        }
    }
    else
    {
        printf("La base de datos esta vacia\n");
    }



    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;
    int flag=0;
    int tam = ll_len(pArrayListEmployee);
    if (tam > 0)
    {
        printf(" ID      nombre    horasTrabajadas    sueldo\n");
    }
    if (pArrayListEmployee != NULL)
    {
        for (int i=0; i < tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            if (auxEmp != NULL)
            {
                printf(" %d   %10s       %d              %d\n",auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
                flag = 1;
            }
        }
        if (flag != 1)
        {
            printf("No hay para listar\n");
        }
        return 0;
    }
    else
    {
        printf("No se pudo conseguir memoria\n");
        return -1;
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    //1 descendente
    int resp;
    int orden;
    if (pArrayListEmployee != NULL)
    {
        system("CLS");
        printf("************************************************\n");
        printf("*            Menu de ordenamiento              *\n");
        printf("************************************************\n");
        printf("\n1- Ordenar por ID");
        printf("\n2- Ordenar por nombre");
        printf("\n3- Ordenar por horas trabajadas");
        printf("\n4- Ordenar por sueldo");
        utn_getNumero(&resp, "\n\nIngrese una opcion: ", "\nError, ingreso algun valor incorrecto", 1, 4, 3);
        utn_getNumero(&orden, "\n1- Ascendente\n2- Descendente\n\nIngrese una opcion: ", "\nError, ingreso algun valor incorrecto", 1, 2, 3);
        if (resp > 0 && resp <5 && (orden == 1 || orden == 2))
        {
            switch (resp)
            {
            case 1:
                ll_sort(pArrayListEmployee, ordenXId, orden);
                break;
            case 2:
                ll_sort(pArrayListEmployee, ordenXNombre, orden);
                break;
            case 3:
                ll_sort(pArrayListEmployee, ordenXHoras, orden);
                break;
            case 4:
                ll_sort(pArrayListEmployee, ordenXSueldo, orden);
                break;
            }
        }
        else
        {
            printf("algun dato ingresado es incorrecto, vuelva a intentar");
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=1;
    Employee* auxEmp;
    FILE* f = fopen(path, "w" );
    int tam = ll_len(pArrayListEmployee);
    if (pArrayListEmployee != NULL && path != NULL)
    {
        if (f == NULL)
        {
            printf("Problemas al abrir el archivo\n");
            return -1;
        }
        else
        {
            for (int i=0; i < tam; i++)
            {
                auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                if (auxEmp != NULL)
                {
                    fprintf(f,"%d,%s,%d,%d\n",auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
                    retorno = 0;                }
            }
        }
    }
    fclose(f);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* auxEmp;
    FILE* f = fopen(path, "wb" );
    int tam = ll_len(pArrayListEmployee);
    if (pArrayListEmployee != NULL && path != NULL)
    {
        if (f == NULL)
        {
            printf("Problemas al abrir el archivo\n");
            return -1;
        }
        else
        {
            for (int i=0; i < tam; i++)
            {
                auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                if (auxEmp != NULL)
                {
                    fwrite(auxEmp, sizeof(Employee), 1, f);
                    retorno = 0;
                }
            }
        }
    }
    fclose(f);
    if (retorno == 0)
    {
        return retorno;
    }
    return 1;
}
