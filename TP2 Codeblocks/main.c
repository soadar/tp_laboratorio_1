#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define TAM 9
#define TRUE 1
#define FALSE 0
#define TAMSEC 5 // cantidad de sectores en la empresa
#define MAXSALARIO 1000000.00 // Maximo salario a pagar
//#define IDINICIAL 1000


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

typedef struct
{
    int idS;
    char nombreSec[20];
} eSector;

int menuPrincipal();
int esLetra(char* cadena,int longitud);
int getCadena(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
void menuMod(Employee* list, int tam, int index, eSector* sectores, int tamsec);
int buscarEmpty(Employee* list, int len);
int preCarga(Employee* list, int tam, int check, eSector* sectores, int tamsec);
int initEmployees(Employee* list, int len);
int printEmployees(Employee* list, int length);
void preBaja(Employee* list, int tam, int check);
void prePrint(Employee* list, int tam, int check);
int removeEmployee(Employee* list, int len, int id);
int findEmployeeById(Employee* list, int len,int id);
void preBusqueda(Employee* list, int tam, int check, eSector* sectores, int tamsec);
int sortEmployees(Employee* list, int len, int order);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
void promedioYtotal (Employee* list, int tam, float* pTotalSalary, float* pPromedio, int* pPromUp);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
void listarSectores(eSector* sectores, int tamSec);
void harcodeoEmpleados(Employee* lista, int tam);


int main()
{
    int salida = 0;
    int cargaInicial = -2;
    int IdEmp = 1000;

    Employee list[TAM];
    eSector sectores[TAMSEC]= { {1, "sistemas"}, {2, "RRHH"}, {3, "Compras"}, {4, "Ventas"}, {5, "Contable"}};

    initEmployees(list,TAM);
    harcodeoEmpleados(list, TAM);

    do
    {
        cargaInicial = buscarEmpty(list, TAM) + IdEmp;
        system("cls");

        switch (menuPrincipal())
        {
        case 1: //alta
            if (preCarga(list, TAM, cargaInicial, sectores, TAMSEC))
            {
            IdEmp++;
            }
            //if carga == 0 // flag = 1
            break;
        case 2: //mod
            preBusqueda(list, TAM, cargaInicial, sectores, TAMSEC);
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
    return -2;
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
                printf("\n__________________Dando la baja del empleado:___________________\n\n");
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
    utn_getNumero(&resp, "\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 4\n", 1, 6, 3);
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
//                system("pause>nul");
            }
        }
        while(reintentos >= 0);
    }
    return -1;
}

int buscarEmpty(Employee* list, int len)
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

int preCarga(Employee* list, int tam, int check, eSector* sectores, int tamsec)
{
    char auxName[51];
    char auxApe[51];
    float auxSal;
    int auxSec;
    int auxCarga;

    if (check == -1)
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
//  listar sectores
        listarSectores(sectores, tamsec);
        utn_getNumero(&auxSec, "Ingrese nuevo sector: ", "\nError, sector incorrecto", 0, TAMSEC, 3);
        auxCarga=addEmployee(list, tam, check, auxName, auxApe, auxSal, auxSec);
        return auxCarga;
    }
    return -1;
}


void preBusqueda(Employee* list, int tam, int check, eSector* sectores, int tamsec)
{
    int index;
    int auxID;
    if (check == -2)
    {
        printf("\n\n*************************************\n");
        printf("*    La base de datos esta vacia    *\n");
        printf("*************************************\n\n");
        system("pause");


    }
    else
    {
        printf("\nIngrese ID del empleado: ");
        scanf("%d",&auxID);
        index = findEmployeeById(list, TAM, auxID);
        if (index >= 0)
        {
            menuMod(list, tam, index, sectores, TAMSEC);
        }
    }
}

void preBaja(Employee* list, int tam, int check)
{
    int auxID;
    if (check == -2)
    {
        printf("\n\n*************************************\n");
        printf("*    La base de datos esta vacia    *\n");
        printf("*************************************\n\n");
        system("pause");


    }
    else
    {
        printf("\nIngrese ID del empleado para la baja: ");
        scanf("%d",&auxID);
        removeEmployee(list, tam, auxID);
    }
}

void prePrint(Employee* list, int tam, int check)
{
    int resp;
    int criterio=0;
    float total;
    float promedio;
    int salaryUp;
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
            utn_getNumero(&criterio, "\n0) orden ascendente\n1) orden descendente\n", "\nError, ingreso incorrecto, debe ingresar 0 o 1\n", 0, 1, 3);
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

void menuMod(Employee* list, int tam, int index, eSector* sectores, int tamsec)
{
    int resp;
    printf("\n\n*************************************\n");
    printf("*        Modificacion de usuarios        *\n");
    printf("*************************************\n\n");
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
        printf("\nCarga Exitosa\n\n");
        system("pause");
        break;
    case 2 :
        printf("\nIngrese nuevo apellido: ");
        fflush(stdin);
        gets(list[index].lastName);
        printf("\nCarga Exitosa\n\n");
        system("pause");
        break;
    case 3 :
        utn_getNumeroFlotante(&list[index].salary, "\nIngrese nuevo salario: ", "\nError, salario demasiado alto\n", 0, MAXSALARIO, 3);
        printf("\nCarga Exitosa\n\n");
        system("pause");
        break;
    case 4:
        listarSectores(sectores, tamsec);
        utn_getNumero(&list[index].sector, "\nIngrese nuevo sector: ", "Error, sector incorrecto", 0, TAMSEC, 3);
        printf("\nCarga Exitosa\n\n");
        system("pause");
        break;
    }
}

void harcodeoEmpleados(Employee* lista, int tam)
{
    int id[10]= {100,200,300,400,500,600,700,800,900,1000};
    char nombre[10][30]= {"felipe", "miguel", "victor", "maria", "daniela", "daniel", "horacio", "dario", "sergia", "puma"};
    char apellido[10][30]= {"yerba", "azucar", "harina", "mayo", "coca", "queso", "manzana", "remera", "agua", "silla"};
    float salario[10]= {100.65, 2200.36, 874.8445, 15185.10, 5514.7, 4545.9, 6565.47, 9898.4, 74878.98, 999.99};
    int sector[10]= {1,2,4,6,5,6,7,8,9,1};
    int isEmpy[10]= {0,0,0,0,0,0,0,0,0,0};

    for (int i=0; i<tam; i++)
    {
        lista[i].id=id[i];
        strcpy(lista[i].name, nombre[i]);
        strcpy(lista[i].lastName, apellido[i]);
        lista[i].salary=salario[i];
        lista[i].sector=sector[i];
        lista[i].isEmpty=isEmpy[i];
    }
}

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

