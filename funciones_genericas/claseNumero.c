#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "claseNumero.h"

int validaInt(char* cadena)
{
    int i;
    int flag = 0;
    int size;
    int buffer;

    size = strlen(cadena);

    for(i=0; i<size; i++)
    {
        buffer=-1;

        buffer = *(cadena+i);

        if( buffer == -1 )
        {
            flag = -1;
            break;
        }
    }

    return flag;
}

int validaRangoInt(int numero,int minimoInt, int maximoInt)
{
    int salida=0;

    if( numero>=minimoInt && numero<=maximoInt)
    {
        salida=1;
        return salida;
    }

    return salida;
}

int validaRangoFloat(float numero,float minimoFloat, float maximoFloat)
{
    int salida=0;

    if( numero > minimoFloat && numero < maximoFloat )
    {
        salida=1;
    }

    return salida;
}

int buscaMayor(int arregloInt[], int tam)
{
    int i, mayor;

    mayor=arregloInt[0];

    for(i=0;i<tam;i++)
    {
        if(arregloInt[i] > mayor)
        {
            mayor=arregloInt[i];
        }
    }

    return mayor;
}

int buscaPosicionDelMayor(int arregloInt[], int tam)
{
    int i, mayor, posicion;

    mayor=arregloInt[0];
    posicion=0;

    for(i=0;i<tam;i++)
    {
        if(arregloInt[i] > mayor)
        {
            mayor=arregloInt[i];
            posicion=i;
        }
    }

    return posicion;
}
