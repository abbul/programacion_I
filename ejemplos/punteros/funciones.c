#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void swap2 (int* punt1, int* punt2)
{
    int aux;

    aux= *punt1;
    *punt1= *punt2;
    *punt2 = aux;

}

void muestra(int* puntero[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
    printf("numero:%d\n",*(puntero+i));

    }
}
void carga(int* puntero[], int tam)
{
    int i;

     for(i=0;i<tam;i++)
    {
    printf("ingrese numero: ");
    scanf("%d",(puntero+i));

    }
}

void mostrarNotebook(eNotebook maquina)
{
    printf("marca:%s -- modelo:%s ---nucleo: %d -- ram:%d -- precio:%f \n",maquina.marca,maquina.procesador.modelo,maquina.procesador.nucleos,maquina.ram,maquina.precio);

}

void iniciaNotebook(eNotebook* maquina)
{
    strcpy(maquina->marca,"NADA");
    strcpy(maquina->procesador.modelo,"NADA");
    maquina->precio=0;
    maquina->ram=0;
    maquina->procesador.nucleos=0;
}

void cargarNotebook(eNotebook* maquina)
{
    printf("ingrese nombre: ");
    gets(maquina->marca);

    printf("ingrese ram: ");
    scanf("%d",&maquina->ram);

}


