#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int respuesta;
    int x=0;
    int y=0;
    int menu1ok=0;
    int menu2ok=0;
    int calculos;
    int salida=0;
    int saltarPause=0;

    do
    {
        switch( menuIngreso(x, y) )
        {
        case 1 : /** Operando1 **/
            respuesta = utn_getNumero(&x,"\n\nIngrese primer operando, en el rango de -32768 a 32767: ","\nError, el rango es de -32768 a 32767\n\n",-32768,32767,0);
            if(respuesta == 0)
            {
                menu1ok=1;
                break;
            }
            break;
        case 2 : /** Operando2 **/
            respuesta = utn_getNumero(&y,"\n\nIngrese segundo operando, en el rango de -32768 a 32767: ","\nError, el rango es de -32768 a 32767\n\n",-32768,32767,2);
            if(respuesta == 0)
            {
                menu2ok=1;
                break;
            }
            break;
        case 3 : /** Calculos **/
            if ( menu1ok==1 && menu2ok==1 )
            {
                calculos=1;
                menuCalculos(x, y);
            }
            else if ( menu1ok==0 && menu2ok==1 )
            {
                printf("_____________________________________\n");
                printf("\nFalta ingresar el operando A\n");
                printf("_____________________________________\n\n");
            }
            else if ( menu1ok==1 && menu2ok==0 )
            {
                printf("_____________________________________\n");
                printf("\nFalta ingresar el operando B\n");
                printf("_____________________________________\n\n");
            }
            else
            {
                printf("_____________________________________\n");
                printf("\nAun no ha ingresado ningun dato\n");
                printf("_____________________________________\n\n");
            }

            break;
        case 4 :

            if ( calculos == 1 )
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
