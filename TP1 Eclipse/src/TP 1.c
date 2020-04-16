#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



int main()
{
    int x=0;
    int y=0;
    int flagMenu1=0;
    int flagMenu2=0;
    int flagCalculos;
    int salida=0;
    int saltarPause=0;

    do
    {
        switch( menuIngreso(x, y) )
        {
        case 1 : /** Operando1 **/
            if(utn_getNumero(&x,"\nIngrese primer operando, en el rango de -32768 a 32767: ","\n________________________________\n\n El valor ingresado es incorrecto\n________________________________\n\n",-32768,32767,0) == 0)
            {
                flagMenu1=1;
                break;
            }
            break;

        case 2 : /** Operando2 **/
            if(utn_getNumero(&y,"\nIngrese segundo operando, en el rango de -32768 a 32767: ","\n________________________________\n\n El valor ingresado es incorrecto\n________________________________\n\n",-32768,32767,0) == 0)
            {
                flagMenu2=1;
                break;
            }
            break;

        case 3 :
            validarOperandos(&flagCalculos, flagMenu1, flagMenu2, x, y);
            break;

        case 4 :
            if ( flagCalculos == 1 )
            {
                menuResultados(x, y);
            }
            else
            {
                printf("_____________________________________\n");
                printf("\nAun no se realizaron las funciones matem\240ticas\n");
                printf("_____________________________________\n\n");
            }
            /** resultados **/
            break;

        case 5 :
            salida = 1;
            printf("_____________________________________\n");
            printf("\nSaliendo del programa...\n");
            printf("_____________________________________\n\n");
            break;
        default:
            printf("\nopci\242n inv\240lida...");
            system("pause>nul");
            saltarPause=1;
        }
        if (saltarPause!=1)
        {
            system("pause");
        }
        saltarPause=0;
    }
    while(salida == 0);
    return 0;
}
