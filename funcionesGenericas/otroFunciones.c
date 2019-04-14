#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "otroFunciones.h"

void cargarAlquiler(eOtro listaOtro[],eDato listaDato[],int posicion, int tamDato)
{
    char buffer[200];
    int aux, i, flag=-1;

    if(posicion!=-1)
    {
        do{
        printf("Ingrese ID de cliente: ");
        scanf("%d",&aux);

        for(i=0;i<tamDato;i++)
        {
                if(aux==listaDato[i].id)
                    {
                      listaOtro[posicion].idCliente=aux;
                      flag=1;
                      break;
                    }
        }

        if(flag==-1)
                 {
                     printf(" \t no hay cliente con ese id, REINGRESE ID!! \n");
                 }
        }while(flag==-1);


        listaOtro[posicion].idCliente=validaInt(listaOtro[posicion].idCliente,1,10);

        printf("Ingrese tiempo de alquiler en Horas: ");
        scanf("%d",&listaOtro[posicion].tiempo);
        listaOtro[posicion].tiempo=validaInt(listaOtro[posicion].tiempo,1,99);

        printf("elija el equipo a alquilar \n \t 1.AMOLADORA\t2.MEZCLARODA\t3.TALADRO:");
        scanf("%d",&listaOtro[posicion].equipo);
        listaOtro[posicion].equipo=validaInt(listaOtro[posicion].equipo,1,3);

        listaOtro[posicion].estado=1;
        listaOtro[posicion].numeroContrato=posicion+100;

        printf("Su numero de contrato es: %d ",listaOtro[posicion].numeroContrato);
    }
}

int buscarContrato(eOtro lista[], int tam)
{
    int aux=-1;
    int auxId;
    int i;

    scanf("%d",&auxId);

    for(i=0; i<tam; i++)
    {
        if(lista[i].numeroContrato==auxId && lista[i].estado==1)
        {
            aux=i;
            break;
        }
    }

    if(aux==-1)
    {
        printf("No hay datos guardados con ese valor \n");
    }

    return aux;
}

void bajaAlquiler(eOtro lista[],int tam)
{
    eOtro auxLista;
    char respuesta;
    int aux;

    printf("Ingrese contrato a darle de baja\n");
    aux=buscarContrato(lista,tam);

    if(aux!=-1)
    {
        auxLista=lista[aux];
        mostrarEstruturaOtro(auxLista);

        printf("¿Desea darle de baja a este objeto? s/n \n");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta);

        if(respuesta=='S')
        {
            lista[aux].estado=0;

            printf("ingrese tiempo real de alquiler\n");
            scanf("%d",&lista[aux].tiempoReal);
            lista[aux].tiempoReal=validaInt(lista[aux].tiempoReal,1,99);

            printf("\t Baja exitosa!!! \n");
        }
        else
        {
            printf("Accion CANCELADA, no se dio de baja al objeto \n");
        }
    }
}

void muestraTodo(eDato listaCliente[], eOtro listaAlquileres[], int tamX, int tamC)
{
    int i, aux;

        aux=buscaMayor(listaAlquileres,tamC);

        for(i=0;i<tamC;i++)
        {
                if(listaAlquileres[i].equipo==aux)
                {
                    printf("%d, cantidad: %d",listaAlquileres[i].idCliente,aux);
                }
        }



}

void cargaAutomaticaAlquileres(eOtro lista[],int tam)
{
    {
    int i;
    eOtro aux[]={  {.estado=1,.idCliente=1,.equipo=2,.tiempo=23,.numeroContrato=100,.tiempoReal=21},{1,2,2,23,101,21},{1,3,2,23,102,21},{1,4,1,23,103,25},{1,3,2,23,104,21} };

    for(i=0;i<5;i++)
    {
        lista[i]=aux[i];
    }
}

}

int obtenerEspacioLibreOtro (eOtro lista[], int tam)
{
    int aux=-1;
    int flag=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==-1)
        {
            aux=i;
            flag=1;
            break;
        }
    }

    if(flag!=1)
    {
        printf(" \t No hay espacio libre \n");
    }

    return aux;
}

void iniciaEstructuraOtro(eOtro lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=-1;
        lista[i].idCliente=0;
    }

 /* for(i=0; i<tam; i++)
    {
        strcpy(lista[i].,"NADA");
    } */
}

void mostrarEstruturaOtro(eOtro lista)
{
    printf("id:%d, equipo: %d \n",lista.idCliente,lista.equipo);
}

void mostrarArrayEstruturaOtro(eOtro lista[], int tam)
{
    int i;
    int aux=-1;
    eOtro auxLista;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            auxLista=lista[i];
            mostrarEstruturaOtro(auxLista);
            aux=1;
        }
    }

    if(aux==-1)
    {
        printf("\nNo hay nada para mostar\n");
    }
}

int buscaMayor(eOtro lista[], int tam)
{
    int i, mayor;

    mayor=lista[0].equipo;

    for(i=0;i<tam;i++)
    {
        if(lista[i].equipo>mayor)
        {
            mayor=lista[i].equipo;
        }
    }

    return mayor;
}
