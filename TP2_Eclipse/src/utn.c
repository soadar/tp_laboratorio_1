/*
 * utn.c
 *
 *  Created on: 16 may. 2020
 *      Author: Soa
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

/**
 * \brief Solicita al usuario un caracter, luego de verificarlo, devuelve el valor ingresado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
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


/**
 * \brief Solicita una cadena al usuario, luego de verificar si solo contiene letras,devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int esCadena(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
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

/**
 * \brief Verifica si la cadena son solo letras
 * \param cadena Cadena de caracteres a ser analizada
 * \param tam tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
int esLetra(char* cadena,int tam)
{
    if(cadena != NULL && tam > 0)
    {
        for(int i=0 ; cadena[i] != '\0' && i < tam; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
            {
                return 0;
            }
        }
    }
    return -1;
}


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
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


/**
 * \brief Solicita un numero flotante al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
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
