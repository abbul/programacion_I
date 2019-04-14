#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "programadores.h"

 int menu(){
        int opcion;
        system("cls");
        printf("\n***Programadores***\n\n\n");
        printf("1- Alta Programador\n");
        printf("2- Modificacion Programador\n");
        printf("3- Baja Programador\n");
        printf("4- Listado Programadores\n");
        printf("5- Salir\n");
        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        return opcion;

    }

eProgramador iniciaEstructura(eProgramador lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].estado=0;
        lista[i].id=0;
    }

    for(i=0;i<tam;i++)
    {
        strcpy(lista[i].nombre,"NADA");
        strcpy(lista[i].categoria,"NADA");
    }

}

 void mostrarEstrutura(eProgramador lista)
{
        printf("%d %s  %d  %s\n",lista.id,lista.nombre,lista.sueldo,lista.categoria);
}

void mostrarArrayEstrutura(eProgramador lista[], int tam)
{
     int i;
    int aux=0;
    eProgramador auxLista;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
        auxLista=lista[i];
        mostrarEstrutura(auxLista);

        aux=1;
        }
    }
    if(aux==0)
    {
        printf("\nNo hay nada para mostar\n");
    }
}

eProgramador cargarEstructura(eProgramador lista[],int posicion)
{
    if(posicion!=-1)

    {
        printf("Ingrese id: ");
        scanf("%d",&lista[posicion].id);

        printf("Ingrese proyecto: ");
        scanf("%d",&lista[posicion].sueldo);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[posicion].nombre);

        printf("Ingrese categoria: ");
        fflush(stdin);
        gets(lista[posicion].categoria);

        lista[posicion].estado=1;
    }

}

int obtenerEspacioLibre(eProgramador lista[], int tam)
{
    int aux=-1, flag=0, i;

    for(i=0;i<tam;i++)
    {
            if(lista[i].estado==0)
            {
                aux=i;
                flag=1;
                break;
            }
    }

    if(flag==0)
            {
                printf("No hay espacio libre \n");
            }

    return aux;
}

void modificarEstructura(eProgramador lista[], int posicion)
{
    char respuesta;
    eProgramador auxLista;

    auxLista=lista[posicion];
    mostrarEstrutura(auxLista);

    printf("¿Desea modificar permanentemente este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        printf("Ingrese nuevo id:");
        scanf("%d",&lista[posicion].id);


        printf("Ingrese nuevo sueldo:");
        scanf("%d",&lista[posicion].sueldo);


        printf("Ingrese nuevo nombre:");
        fflush(stdin);
        gets(lista[posicion].nombre);

        printf("Ingrese categoria:");
        fflush(stdin);
        gets(lista[posicion].categoria);
    }

    else
    {
        printf("Accion CANCELADA, no se modifico el objeto \n");
    }

}

int buscarId(eProgramador lista[], int tam)
{
    int aux=-1;
    int auxId;
    int i;

    scanf("%d",&auxId);

    for(i=0; i<tam; i++)
    {
        if(lista[i].id==auxId && lista[i].estado==1)
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

void eliminarEstructura(eProgramador lista[],int posicion)
{
    char respuesta;
    eProgramador auxLista;

    auxLista=lista[posicion];
    mostrarEstrutura(auxLista);

    printf("¿Desea eliminar permanentemente este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        lista[posicion].estado=0;
        lista[posicion].id=0;
        lista[posicion].sueldo=0;
        strcpy(lista[posicion].nombre,"NADA");
        strcpy(lista[posicion].categoria,"NADA");
        printf("Dato eliminado \n");
    }
    else
    {
        printf("Accion CANCELADA, no se elimino el objeto \n");
    }

}
