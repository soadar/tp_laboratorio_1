#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define IDINICIAL 1000
#define TAM 20
#define TAMSEC 5 // cantidad de sectores en la empresa
#define MAXSALARIO 1000000.00 // Maximo salario a pagar
#define TRUE 1
#define FALSE 0

int main()
{
    int salida = 0;
    int IdEmp = IDINICIAL;
    int check=-2;

    Employee list[TAM];
    eSector sectores[TAMSEC]= { {1, "sistemas"}, {2, "RRHH"}, {3, "Compras"}, {4, "Ventas"}, {5, "Contable"}};
    initEmployees(list,TAM);

    do
    {
        system("cls");

        switch (menuPrincipal())
        {
        case 1:
            if (preCarga(list, TAM, IdEmp, sectores, TAMSEC) == 0){
                check=1;
                IdEmp++; }
            break;
        case 2:
            preBusqueda(list, TAM, check, sectores, TAMSEC);
            break;
        case 3:
            preBaja(list, TAM, check);
            break;
        case 4:
            prePrint(list, TAM, check);
            break;
        case 5:
            salida=1;
            printf("\n\nSaliendo del programa...\n\n\n");
            system("pause");
            break;
        }
    }
    while (salida == 0);
    return 0;
}
