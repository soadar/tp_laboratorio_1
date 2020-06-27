#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

int mostrarPersona(Employee* list);
int mostrarPersonas (LinkedList* list);

void menu( int* opcion);
void menuMod(LinkedList* pArrayListEmployee, int index);

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

Employee* new_PersonaParamTXT(char* id, char* nombre, char* horas, char* sueldo);

void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED

int employee_findById(LinkedList* pArrayListEmployee, int id);

int comprarEmpleadosID(void* emp1, void* emp2);

int nextId (int* id, LinkedList* pArrayListEmployee);
int updateId(int id);
int ordenXId(void* emp1, void* emp2);
int ordenXNombre(void* emp1, void* emp2);
int ordenXHoras(void* emp1, void* emp2);
int ordenXSueldo(void* emp1, void* emp2);
