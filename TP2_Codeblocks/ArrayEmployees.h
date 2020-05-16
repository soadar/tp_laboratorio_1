#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

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

#endif // ARRAYEMPLOYEES_H_INCLUDED

int menuPrincipal();
int buscarEmpty(Employee* list, int len);
int initEmployees(Employee* list, int len);
int printEmployees(Employee* list, int length);
void preBaja(Employee* list, int tam, int check);
void prePrint(Employee* list, int tam, int check);
void listarSectores(eSector* sectores, int tamSec);
int removeEmployee(Employee* list, int len, int id);
int findEmployeeById(Employee* list, int len,int id);
int sortEmployees(Employee* list, int len, int order);
void menuMod(Employee* list, int tam, int index, eSector* sectores, int tamsec);
int preCarga(Employee* list, int tam, int check, eSector* sectores, int tamsec);
void preBusqueda(Employee* list, int tam, int check, eSector* sectores, int tamsec);
void promedioYtotal (Employee* list, int tam, float* pTotalSalary, float* pPromedio, int* pPromUp);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
