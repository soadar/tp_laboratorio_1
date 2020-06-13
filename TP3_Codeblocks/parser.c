#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cant;
    int flag;
    char buffer[4][100];
    Employee* auxEmp2;
    while ( !feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
        if (cant == 4)
        {
            if (esNumerica(buffer[0], sizeof(buffer[0])))
            {
                auxEmp2 = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

                if (!ll_add(pArrayListEmployee, auxEmp2))
                {
                    flag = 1;
                }
            }
        }
        else
        {
            break;
        }
    }
    if (flag==1)
    {
        return 0;
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;
    int cant;
    if (pFile != NULL)
    {
        while (!feof(pFile))
        {
            auxEmp = employee_new();
            cant = fread(auxEmp, sizeof(Employee), 1, pFile);
            if (cant == 1)
            {
                //printf("%d  %s  %d  %d\n",auxEmp->id,auxEmp->nombre,auxEmp->horasTrabajadas,auxEmp->sueldo);
                ll_add(pArrayListEmployee, auxEmp);
            }
        }
        return 0;
    }
    printf ("archivo corrupto");
    return 1;
}
