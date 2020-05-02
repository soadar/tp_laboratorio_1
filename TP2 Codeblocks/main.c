#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2
#define TRUE 1
#define FALSE 0
#define SECTORES 10 // cantidad de sectores en la empresa
#define MAXSALARIO 1000000.00 // Maximo salario a pagar

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

int menuPrincipal();

int buscarEmpy(Employee* list, int len);
int preCarga(Employee* list, int tam);
int initEmployees(Employee* list, int len);
int printEmployees(Employee* list, int length);
void preBaja(Employee* list, int tam, int check);
void menuMod(Employee* list, int tam, int index);
void prePrint(Employee* list, int tam, int check);
int removeEmployee(Employee* list, int len, int id);
int findEmployeeById(Employee* list, int len,int id);
void preBusqueda(Employee* list, int tam, int check);
int sortEmployees(Employee* list, int len, int order);
void promedioYtotal (Employee* list, int tam, float* pTotalSalary, float* pPromedio, int* pPromUp);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int main()
{
    int salida=0;
    int cargaInicial=-1;
    Employee list[TAM];

    initEmployees(list,TAM);

    do
    {
        system("cls");
        switch (menuPrincipal())
        {
        case 1: //alta
            cargaInicial = preCarga(list, TAM);
            break;
        case 2: //mod
            preBusqueda(list, TAM, cargaInicial);
            break;
        case 3://baja
            preBaja(list, TAM, cargaInicial);
            break;
        case 4: //print
            prePrint(list, TAM, cargaInicial);
            break;
        case 5:
            salida=1;
            printf("Saliendo...");
            break;
        case 6:
            cargaInicial=initEmployees(list,TAM)+1;
            system("pause");
            break;
        }
    }
    while (salida == 0);

    return 0;
}

/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
//r = initEmployees(arrayEmployees, ELEMENTS);
//Para indicar que todas las posiciones del array están vacías,  esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
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
// r = addEmployee(arrayEmployees, ELEMENTS,id,name,lastName,salary,sector);
//Agrega en un array de empleados existente los valores recibidos como parámetro en la primer posición libre.
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    if( list != NULL && name != NULL && lastName != NULL && len >= 0 && len < 1000)
    {
        strcpy (list[id].name, name);
        strcpy (list[id].lastName, lastName);
        list[id].salary=salary;
        list[id].sector=sector;
        list[id].isEmpty=FALSE;
        list[id].id=id;
        printf("\nCarga Exitosa\n\n");
        system("pause");
        return 0;
    }
    else
    {
        printf("\nError, la carga no pudo realizarse.\n");
        system("pause");
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
//int index = findEmployeeById(arrayEmployees, ELEMENTS,9);
//Busca un empleado recibiendo como parámetro de búsqueda su Id.
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
//r = removeEmployee(arrayEmployees, ELEMENTS,20);
//Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
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
                printf("\n__________________Dando de baja al empleado:___________________\n\n");
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
//Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
//r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);
int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmpleado;
    for (int i=0; i<len-1; i++)
    {
        for (int j=i+1; j<len; j++)
        {
            if (list[i].sector > list[j].sector && order == 0)
            {
                auxEmpleado = list[i];
                list[i]=list[j];
                list[j]=auxEmpleado;
            }
            else if (list[i].sector < list[j].sector && order == 1)
            {
                auxEmpleado = list[i];
                list[i]=list[j];
                list[j]=auxEmpleado;
            }
            else if (order == 0 && list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName ) > 0 )
            {
                auxEmpleado = list[i];
                list[i]=list[j];
                list[j]=auxEmpleado;
            }
            else if (order == 1 && list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName ) < 0 )
            {
                auxEmpleado = list[i];
                list[i]=list[j];
                list[j]=auxEmpleado;
            }
        }
    }
    return 0;
}


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
//r = printEmployees(arrayEmployees, ELEMENTS);
//Imprime el array de empleados de forma encolumnada.
int printEmployees(Employee* list, int length)
{
//    int vectorVacio=0;
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

int menuPrincipal()
{
    int resp;
    printf("\n\n1) Alta \n");
    printf("2) Modificar \n");
    printf("3) Baja \n");
    printf("4) Informar \n");
    utn_getNumero(&resp, "\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 4", 1, 6, 0);
    return resp;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, float minimo,float maximo,int reintentos)
{
    int retorno = -1;
    float bufferFloat;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%f",&bufferFloat);
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }
        while(reintentos >= 0);
    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("\n%s",mensaje);
            fflush(stdin);
            scanf("%d",&bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                return 0;
            }
            else
            {
                printf("\n%s",mensajeError);
                reintentos--;
                system("pause>nul");
            }
        }
        while(reintentos >= 0);
    }
    return -1;
}

void menuMod(Employee* list, int tam, int index)
{
    int resp;
    printf("\nQue desea modificar?\n\n");
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
        break;
    case 2 :
        printf("\nIngrese nuevo apellido: ");
        fflush(stdin);
        gets(list[index].lastName);
        break;
    case 3 :
        utn_getNumeroFlotante(&list[index].salary, "\nIngrese nuevo salario: ", "\nError, salario demasiado alto\n", 0, MAXSALARIO, 3);
        break;
    case 4:
        utn_getNumero(&list[index].sector, "\nIngrese nuevo sector: ", "Error, sector incorrecto", 0, SECTORES, 3);
        break;
    }
}

int buscarEmpy(Employee* list, int len)
{
    for (int i=0; i < len; i++)
    {
        if (list[i].isEmpty==TRUE)
        {
            return i;
        }
    }
    return -1;
}

int preCarga(Employee* list, int tam)
{
    char auxName[51];
    char auxApe[51];
    float auxSal;
    int auxSec;
    int auxID;
    int auxCarga;

    auxID = buscarEmpy(list, tam);

    if (auxID >= 0 && auxID < tam)
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
        utn_getNumero(&auxSec, "Ingrese nuevo sector: ", "\nError, sector incorrecto", 0, SECTORES, 3);

        auxCarga=addEmployee(list, tam, auxID, auxName, auxApe, auxSal, auxSec);

        return auxCarga;
    }
    else
    {
        printf("\nError, La base de datos esta completa\n");
        system("pause>nul");
    }
    return -1;
}


void preBusqueda(Employee* list, int tam, int check)
{
    int index;
    int auxID;
    if (check == 0)
    {
        printf("\nIngrese ID del empleado: ");
        scanf("%d",&auxID);
        index = findEmployeeById(list, TAM, auxID);
        if (index >= 0)
        {
            menuMod(list, tam, index);
        }
    }
    else
    {
        printf("\n\n*************************************\n");
        printf("*    La base de datos esta vacia    *\n");
        printf("*************************************\n\n");
        system("pause");
    }
}


void preBaja(Employee* list, int tam, int check)
{
    int auxID;
    if (check == 0)
    {
        printf("\nIngrese ID del empleado para la baja: ");
        scanf("%d",&auxID);
        removeEmployee(list, tam, auxID);
    }
    else
    {
        printf("\n\n*************************************\n");
        printf("*    La base de datos esta vacia    *\n");
        printf("*************************************\n\n");
        system("pause");
    }
}

void prePrint(Employee* list, int tam, int check)
{
    int resp;
    int criterio=0;
    float total;
    float promedio;
    int salaryUp;
    if (check == 0)
    {
        printf("\n1) Listado de los empleados ordenados alfabéticamente por Apellido y Sector.");
        printf("\n2) Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n");
        utn_getNumero(&resp, "\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar 0 o 1\n", 1, 2, 3);
        if (resp == 1)
        {
            printf("\n0) orden ascendente\n1) orden descendente\n\n");
            scanf("%d",&criterio);
            sortEmployees(list, tam, criterio);
            printEmployees(list, tam);
        }
        else if (resp == 2)
        {
            promedioYtotal(list, tam, &total, &promedio, &salaryUp);
            printf("\nTotal     Promedio       promedioMayor\n\n");
            printf("%7.2f     %7.2f         %d\n\n", total, promedio, salaryUp);
            system("pause>nul");
        }
    }
    else
    {
        printf("\n\n*************************************\n");
        printf("*    La base de datos esta vacia    *\n");
        printf("*************************************\n\n");
        system("pause");
    }
}

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
