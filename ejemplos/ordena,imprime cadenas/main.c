#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X 3

int validar(char cadena[]);
void mostrar(char cadena[][100], int tam);
void ordenaNombre(char cadena[][100], int tam);

int main()
{
    char nombre[X][100];
    char buffer[100];
    int i;

    for(i=0; i<X; i++)
    {
        printf("Ingrese nombre %d \n",i+1);
        gets(buffer);

        while(validar(buffer))
        {
            printf("REINGRESE nombre \n");
            gets(buffer);
        }
        strcpy(nombre[i],buffer);
    }

    mostrar(nombre,X);
    printf("________________\n");
    printf("________________\n");
    ordenaNombre(nombre,X);

    return 0;
}

int validar(char cadena[])
{
    int aux=1;

    if(strlen(cadena)>0 && strlen(cadena)<20)
    {
        aux=0;
    }

    return aux;
}

void mostrar(char cadena[][100], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%s\n",cadena[i]);
    }
}

void ordenaNombre(char cadena[][100], int tam)
{
    int i, j;
    char aux[50];
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(stricmp(cadena[i],cadena[j]) ==1)
            {
                strcpy(aux,cadena[j]);
                strcpy(cadena[j],cadena[i]);
                strcpy(cadena[i],aux);
            }
        }

    }

    mostrar(cadena,tam);
}
