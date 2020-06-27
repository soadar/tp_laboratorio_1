#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


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
    int repetido;
    char buffer[4][100];
    Employee* auxEmp2;
    int tam = ll_len(pArrayListEmployee);
    //printf("Cantidad de empleados: %d\n",tam);
    while ( !feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
        if (cant == 4)
        {
            if (esNumerica(buffer[0], sizeof(buffer[0])))
            {
                //printf("%s %s %s %s\n",buffer[0],buffer[1],buffer[2],buffer[3]);
                auxEmp2 = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

                //
                for (int i=0; i<tam; i++)
                {
                    if(auxEmp2->id == atoi(buffer[0]))
                    {
                        repetido=1;
                        break;
                    }
                }
                //
                if (repetido != 1 && !ll_add(pArrayListEmployee, auxEmp2))
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
    if (repetido == 1)
    {
        printf("\nNo se cargaron los datos duplicados\n");
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
                //printf("id: %d\n", auxEmp->id);

                ll_add(pArrayListEmployee, auxEmp);

            }
        }
        return 0;
    }
    printf ("archivo corrupto");
    return 1;
}
