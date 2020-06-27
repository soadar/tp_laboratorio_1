/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"

int main(void)
{
    startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort
    system("pause>nul");

    int option = 0;
    int check = 2;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        menu(&option);
        switch(option)
        {
        case 1:
            check = controller_loadFromText("data.csv",listaEmpleados);
            system("pause>nul");
            break;
        case 2:
            check = controller_loadFromBinary("data.bin",listaEmpleados);
            system("pause>nul");
            break;
        case 3:
            if (check == 2)
            {
                printf("\n\n*****************************************\n");
                printf("*   Debe cargar una base para comenzar  *\n");
                printf("*****************************************\n\n");
            }
            else
            {
                controller_addEmployee(listaEmpleados);
            }
            system("pause>nul");
            break;
        case 4:
            if (check == 2)
            {
                printf("\n\n*****************************************\n");
                printf("*   Debe cargar una base para comenzar  *\n");
                printf("*****************************************\n\n");
            }
            else
            {
                controller_editEmployee(listaEmpleados);
            }
            system("pause>nul");
            break;
        case 5:
            if (check == 2)
            {
                printf("\n\n*****************************************\n");
                printf("*   Debe cargar una base para comenzar  *\n");
                printf("*****************************************\n\n");
            }
            else
            {
                controller_removeEmployee(listaEmpleados);
            }
            system("pause>nul");
            break;
        case 6:
            if (check == 2)
            {
                printf("\n\n*****************************************\n");
                printf("*   Debe cargar una base para comenzar  *\n");
                printf("*****************************************\n\n");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
            }
            system("pause>nul");
            break;
        case 7:
            if (check == 2)
            {
                printf("\n\n*****************************************\n");
                printf("*   Debe cargar una base para comenzar  *\n");
                printf("*****************************************\n\n");
            }
            else
            {
                controller_sortEmployee(listaEmpleados);
            }
        case 8:
            if (check == 2)
            {
                printf("\n\n*****************************************\n");
                printf("*   Debe cargar una base para comenzar  *\n");
                printf("*****************************************\n\n");
            }
            else
            {
                if (!controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("\nSe guardo exitosamente el archivo\n");
                }
                else
                {
                    printf("\nNo se pudo guardar el archivo\n");
                }
            }
            system("pause>nul");
            break;
        case 9:
            if (check == 2)
            {
                printf("\n\n*****************************************\n");
                printf("*   Debe cargar una base para comenzar  *\n");
                printf("*****************************************\n\n");
            }
            else
            {
                if (!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("\nSe guardo exitosamente el archivo\n");
                }
                else
                {
                    printf("\nNo se pudo guardar el archivo\n");
                }
            }
            system("pause>nul");
            break;
        }
    }
    while(option != 10);
    printf("\n\nSaliendo del programa...");
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

void menu( int* opcion)
{
    system("cls");
    printf("************************************************\n");
    printf("*                Menu principal                *\n");
    printf("************************************************\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    utn_getNumero(opcion, "\nIngrese una opcion: ", "Error, debe ingresar de 1 a 10", 1, 10, 3);
}
