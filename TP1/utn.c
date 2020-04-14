#include <stdio.h>
#include <stdlib.h>

char menuIngreso(int x, int y)
{
    int respMenu1;

    system("cls");
    printf("\n\n1) Ingresar 1er operando (A=%d) ",x);
    printf("\n\n2) Ingresar 2do operando (B=%d) ",y);
    printf("\n\n3) Calcular todas las operaciones ");
    printf("\n\n4) Informar resultados ");
    printf("\n\n5) Exit\n\n");
    printf("Elija una opci\242n : ");
    fflush(stdin);
    scanf("%d",&respMenu1);
    return (respMenu1);
}

void menuCalculos(int x, int y)
{
    system("cls");
    printf("\n\n____________________________");
    printf("\na) Calcular la suma (%d + %d)",x,y);
    printf("\nb) Calcular la resta (%d - %d)",x,y);
    printf("\nc) Calcular la divisi\242n (%d / %d)",x,y);
    printf("\nd) Calcular la multiplicaci\242n (%d * %d)",x,y);
    printf("\ne) Calcular es factorial %d!", x);
    printf("\n____________________________\n\n");
}

void menuResultados(int x, int y)
{
    float bufferFloat;
    int bufferInt;
    int resultado;

    printf("\n____________________________\n");
    printf("\nEl resultado de (%d + %d) es : %d",x,y,suma(x,y));
    printf("\nEl resultado de (%d - %d) es : %d",x,y,resta(x,y));
    printf("\nEl resultado de (%d * %d) es : %d",x,y,multiplicacion(x,y));

    resultado = dividir(&bufferFloat, x, y);
    if (resultado == 0)
    {
        printf("\nEl resultado de (%d / %d) es : %.2f",x,y,bufferFloat);
    }
    else
    {
        printf("\nError\n");
    }

    resultado = factorial(&bufferInt, x);
    if (resultado == 0)
    {
        printf("\nEl factorial de %d  es : %d",x,bufferInt);
    }
    else
    {
        printf("\nError, ingreso invalido\n");
    }

    resultado = factorial(&bufferInt, y);
    if (resultado == 0)
    {
        printf("\nEl factorial de %d  es : %d",y,bufferInt);
    }
    else
    {
        printf("\nError, ingreso invalido\n");
    }
    printf("\n____________________________\n\n");
}

int suma(int x, int y)
{
    return x+y;
}

int resta(int x, int y)
{
    return x-y;
}

int multiplicacion(int x, int y)
{
    return x*y;
}

int dividir (float* pResultado, int numero1, int numero2)
{
    if (pResultado != NULL && numero2 != 0)
    {
        *pResultado = (float) numero1 / numero2;
        return 0;
    }
    return -1;
}

int factorial (int* pResultado, int numero)
{
    int bufferFact=1;

    if(pResultado != NULL && numero != NULL)
    {
        for (int cont = 1; cont <= numero; cont++ )
        {
            bufferFact = bufferFact * cont;
        }
        *pResultado = bufferFact;
        return 0;
    }
    return -1;
}

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
    int retorno = -1;
    char buffer;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("\n%s\n",mensaje);
            fflush(stdin);
            scanf("%c",&buffer);
            if(buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            printf("\n%s\n",mensajeError);
            reintentos--;
        }
        while(reintentos>=0);

    }
    return retorno;
}


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("\n%s\n",mensaje);
            fflush(stdin);
            scanf("%d",&bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s\n",mensajeError);
                reintentos--;
            }
        }
        while(reintentos >= 0);
    }
    return retorno;
}
