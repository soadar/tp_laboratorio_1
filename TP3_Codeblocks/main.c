#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
#include "utn.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/
Employee* new_Persona();
Employee* new_PersonaParam(int id, char* nombre, int horas, int sueldo);
Employee* new_PersonaParamTXT(char* id, char* nombre, char* horas, char* sueldo);

int mostrarPersona(Employee* list);
int mostrarPersonas (LinkedList* list);
int comprarEmpleadosID(void* emp1, void* emp2);

void menu( int* opcion);
int controller_showAsBinary(char* path, LinkedList* pArrayListEmployee);

int main()
{
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
            system("pause");
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
            system("pause");
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
