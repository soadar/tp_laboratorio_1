#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */


int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
    int retorno = -1;
    char buffer;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%c",&buffer);
            if(buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            printf("%s",mensajeError);
            reintentos--;
        }
        while(reintentos>=0);

    }
    return retorno;
}

int getCadena(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;

    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        fgets(bufferString,sizeof(bufferString),stdin);
        if( bufferString != NULL && esLetra(bufferString,strnlen(bufferString,sizeof(bufferString))-1) == 1 && strnlen(bufferString,sizeof(bufferString)) < longitud )
        {
            bufferString[strlen(bufferString)-1] = '\0';
            strcpy(pResultado,bufferString);
            retorno = 0;
            break;
        }
        else if (strnlen(bufferString,sizeof(bufferString)) > longitud)
        {
            printf("\nDemasiado largo\n");
            system("pause");
        }
        printf("%s",mensajeError);
    }
    return retorno;
}


int esLetra(char* cadena,int longitud)
{
    if(cadena != NULL && longitud > 0)
    {
        for(int i=0 ; cadena[i] != '\0' && i < longitud; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
            {
                return 0;
            }
        }
    }
    return 1;
}
