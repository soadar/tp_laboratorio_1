#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
#include "utn.h"

/** \brief reserva un espacio en memoria dinamica e inicializa las variables
 *
 * \return devuelve un espacio en memoria dinamica
 *
 */

Employee* employee_new()
{
    Employee* newEmp = (Employee*) malloc(sizeof(Employee));
    if (newEmp != NULL)
    {
        newEmp->id = 0;
        newEmp->nombre[0] = ' ';
        newEmp->horasTrabajadas = 0;
        newEmp->sueldo = 0;
    }
    return newEmp;
}

/** \brief reserva un espacio en memoria dinamica e inicializa las variables
 *
 * \param idStr id del usuario en formato texto
 * \param nombreStr nombre del usuario
 * \param horasTrabajadasStr horas trabajadas del usuario en formato texto
 * \param sueldoStr sueldo del usuario en formato texto
 * \return devuelve un espacio en memoria dinamica
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmp = employee_new();
    if (newEmp != NULL)
    {
        if (employee_setId (newEmp, atoi(idStr))
                || employee_setNombre (newEmp, nombreStr)
                || employee_setHorasTrabajadas (newEmp, atoi(horasTrabajadasStr))
                || employee_setSueldo (newEmp, atoi(sueldoStr)))
        {
            free(newEmp);
            newEmp=NULL;
        }
        newEmp->id = atoi(idStr);
        strcpy(newEmp->nombre, nombreStr);
        newEmp->horasTrabajadas = atoi(horasTrabajadasStr);
        newEmp->sueldo = atof(sueldoStr);
    }

    return newEmp;
}

/** \brief Muestra los datos de un empleado
 *
 * \param array del empleado
 * \return devuelve -1 en caso de error o 1 si esta todo ok
 *
 */
int mostrarPersona(Employee* list)
{
    int retorno = 1;
    if (list != NULL)
    {
        printf("%d   %10s    %d    %d\n",list->id, list->nombre, list->horasTrabajadas, list->sueldo);
        retorno = 0;
    }
    else
    {
        printf("Error al leer los datos\n");
        retorno = -1;
    }
    return retorno;
}

/** \brief seteo del ID
 *
 * \param this array del empleado
 * \param id valor a asignar
 * \return devuelve 0 si pudo asignar el valor, 1 caso contrario
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno = 1;
    if (this != NULL && id > 0)
    {
        this->id = id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 1;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief seteo del nombre
 *
 * \param this array del empleado
 * \param nombre valor a asignar
 * \return devuelve 0 si pudo asignar el valor, 1 caso contrario
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 1;

    if (this != NULL && nombre != NULL && strlen(nombre) >= 2 && strlen(nombre) <= 20)
    {
        strcpy(this->nombre, nombre);
        retorno=0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 1;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief seteo de las horas trabajadas
 *
 * \param this array del empleado
 * \param horasTrabajadas valor a asignar
 * \return devuelve 0 si pudo asignar el valor, 1 caso contrario
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 1;
    if (this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas= horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 1;
    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief seteo del sueldo
 *
 * \param this array del empleado
 * \param sueldo valor a asignar
 * \return devuelve 0 si pudo asignar el valor, 1 caso contrario
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 1;
    if (this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 1;
    if (this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief buscar un empleado por ID
 *
 * \param pArrayListEmployee puntero a LinkedList
 * \param id id a buscar
 * \return devuelve el index del empleado o -1 en sino fue encontrado
 *
 */

int employee_findById(LinkedList* pArrayListEmployee, int id)
{
    system("cls");
    Employee* auxEmp;
    int flag=-1;
    char resp;
    int tam = ll_len(pArrayListEmployee);
    for (int i=0; i < tam; i++)
    {
        auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
        if (auxEmp->id == id)
        {
            printf("\n_____________________________________________________________________________\n");
            printf("  ID           Nombre         horasTrabajadas        Salario     \n\n");
            printf(" %d   %10s       %d              %d\n",auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
            printf("_____________________________________________________________________________\n");
            printf("desea continuar con la midificacion? (s/n) : ");
            fflush(stdin);
            scanf("%c",&resp);
            if (resp == 's')
            {
                return i;
                break;
            }
            break;
        }
    }
    if (flag != 1)
    {
        printf("\nEl ID no coincide con ningun empleado\n");
        system("pause>nul");
    }
    return -1;
}

/** \brief menu para modificar empleado
 *
 * \param pArrayListEmployee puntero a LinkedList
 * \param  index del usuario a modificar
 *
 */

void menuMod(LinkedList* pArrayListEmployee, int index)
{
    Employee* auxEmp;
    auxEmp = (Employee*) ll_get(pArrayListEmployee, index);
    int resp;

    printf("\n\n*************************************\n");
    printf("*       Modificando empleado        *\n");
    printf("*************************************\n\n");
    printf("Que desea modificar?\n\n");
    printf("1) Nombre\n");
    printf("2) Horas trabajadas\n");
    printf("3) Sueldo\n");
    if (!utn_getNumero(&resp, "\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 4\n", 1, 4, 3))
    {
        switch (resp)
        {
        case 1 :
            if (!utn_getNombre(auxEmp->nombre, sizeof(auxEmp->nombre), "\nIngrese nuevo nombre: ", "\nError, debe ingresar solo letras", 3))
            {
                printf("\nCambio realizado con exito");
                break;
            }
            printf("\nOcurrio un error, reintente por favor");
            break;
        case 2:
            if (!utn_getNumero(&auxEmp->horasTrabajadas, "\nIngrese horas: ", "\nError, el maximo de horas permitidas es de 800 y como minimo 1 hora\n", 1, 800, 3))
            {
                printf("\nCambio realizado con exito");
                break;
            }
            printf("\nOcurrio un error, reintente por favor");
            break;
        case 3:
            if (!utn_getNumero(&auxEmp->sueldo, "\nIngrese nuevo sueldo: ", "\nError, el maximo de sueldo es de $1.000.000 y el minimo $8000\n", 8000, 1000000, 3))
            {
                printf("\nCambio realizado con exito");
                break;
            }
            printf("\nOcurrio un error, reintente por favor");
            break;
        }
    }
}


/** \brief lee el id del archivo binario nextId.bin, si no existe, devuelve el tamaño del puntero +1
 *
 * \param id id para asignar
 * \param pArrayListEmployee puntero a LinkedList
 * \return retorno 0 si pudo leer el archivo, -1 caso contrario
 *
 */

int nextId (int* id, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    *id = ll_len(pArrayListEmployee) + 1;
    FILE* pFile;
    pFile = fopen ("nextId.bin", "rb");
    if (pFile != NULL)
    {
        fread(id, sizeof(int), 1, pFile);
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

/** \brief actualiza el archivo nextId.bin
 *
 * \param id puntero del id
 * \return devuelve 0 si pudo guardar el archivo, -1 caso contrario
 *
 */
int updateId(int id)
{
    int retorno = -1;
    id++;
    FILE* pFile = fopen ("nextId.bin", "wb");
    if (pFile != NULL)
    {
        fwrite(&id, sizeof(int), 1, pFile);
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

/** \brief compara el id de dos empleados
 *
 * \param emp1 puntero a void
 * \param emp2 puntero a void
 * \return devuelve 0 si los ids son iguales, -1 si el empleado1 tiene un ID mayor al empleado2, 1 si el empleado1 tiene un ID menor al empleado2,
 *
 */
int ordenXId(void* emp1, void* emp2)
{
    int orden;
    Employee* empA = (Employee*) emp1;
    Employee* empB = (Employee*) emp2;
    if (empA->id == empB->id)
    {
        orden=0;
    }
    else if (empA->id > empB->id)
    {
        orden=-1;
    }
    else
    {
        orden=1;
    }
    return orden;
}

/** \brief compara el id de dos empleados
 *
 * \param emp1 puntero a void
 * \param emp2 puntero a void
 * \return devuelve 0 si los ids son iguales, -1 si el empleado1 tiene un ID mayor al empleado2, 1 si el empleado1 tiene un ID menor al empleado2,
 *
 */
int ordenXNombre(void* emp1, void* emp2)
{
    int orden;
    Employee* empA = (Employee*) emp1;
    Employee* empB = (Employee*) emp2;
    if (strcmp(empA->nombre, empB->nombre) == 0)
    {
        orden=0;
    }
    else if (strcmp(empA->nombre, empB->nombre) > 0)
    {
        orden=-1;
    }
    else
    {
        orden=1;
    }
    return orden;
}

/** \brief compara las horas trabajadas de dos empleados
 *
 * \param emp1 puntero a void
 * \param emp2 puntero a void
 * \return devuelve 0 si las horas son iguales, -1 si el empleado1 tiene mas horas que el empleado2, 1 si el empleado1 tiene menos horas que el empleado2,
 *
 */
int ordenXHoras(void* emp1, void* emp2)
{
    int orden;
    Employee* empA = (Employee*) emp1;
    Employee* empB = (Employee*) emp2;
    if (empA->horasTrabajadas == empB->horasTrabajadas)
    {
        orden=0;
    }
    else if (empA->horasTrabajadas > empB->horasTrabajadas)
    {
        orden=-1;
    }
    else
    {
        orden=1;
    }
    return orden;
}

/** \brief compara el sueldo de dos empleados
 *
 * \param emp1 puntero a void
 * \param emp2 puntero a void
 * \return devuelve 0 si los sueldos son iguales, -1 si el empleado1 tiene un sueldo mayor al empleado2, 1 si el empleado1 tiene un sueldo menor al empleado2,
 *
 */
int ordenXSueldo(void* emp1, void* emp2)
{
    int orden;
    Employee* empA = (Employee*) emp1;
    Employee* empB = (Employee*) emp2;
    if (empA->sueldo == empB->sueldo)
    {
        orden=0;
    }
    else if (empA->sueldo > empB->sueldo)
    {
        orden=-1;
    }
    else
    {
        orden=1;
    }
    return orden;
}
