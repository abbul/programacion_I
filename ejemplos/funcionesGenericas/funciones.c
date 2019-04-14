#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int obtenerEspacioLibre(eDato lista[], int tam)
{
    int aux=-1;
    int flag=0;
    int i;

    for(i=0;i<tam;i++)
    {
            if(lista[i].flag==0)
            {
                aux=i;
                flag=1;
                break;
            }
    }

    if(flag==0)
            {
                printf("No hay espacio libre");
            }

    return aux;
}

int buscarElementoInt(eDato lista[], int tam)
{
    eDato auxLista;
    int aux=-1;
    int auxId;
    int i;

    printf("Ingrese ID a buscar \n");
    scanf("%d",&auxId);

    for(i=0;i<tam;i++)
    {
            if(lista[i].id==auxId)
            {
                aux=i;
                auxLista=lista[i];
                mostrarEstrutura(auxLista);
                break;
            }

            if(aux==-1)
            {
                    printf("No hay datos guardados con ese valor");
            }
    }

    return aux;
}

int buscarElementoCadena(eDato lista[], int tam)
{
    eDato auxLista;
    int aux=-1;
    char auxCadena[50];
    int i;

    printf("Ingrese CADENA a buscar \n");
    scanf("%s",&auxCadena);

    for(i=0;i<tam;i++)
    {
            if(lista[i].id==auxCadena)
            {
                aux=i;
                auxLista=lista[i];
                mostrarEstrutura(auxLista);
                break;
            }

            if(aux==-1)
            {
                    printf("No hay datos guardados con ese valor");
            }
    }

    return aux;
}

int validaInt(int numero,int minimoInt, int maximoInt)
{

    while(minimoInt>numero || numero>maximoInt)
    {
        printf("ERROR; Reingrese el dato: ");
        scanf("%d",&numero);
    }

    return numero;
}

float validaFloat(float numero,float minimoFloat, float maximoFloat)
{
    while(minimoFloat>numero || numero>maximoFloat)
    {
        printf("ERROR; Reingrese el dato: ");
        scanf("%f",&numero);
    }

    return numero;
}

eDato iniciaEstructura(eDato lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].flag=0;
        lista[i].id=0;
        lista[i].datoInt1=0;
    }

    for(i=0;i<tam;i++)
    {
        strcpy(lista[i].nombre,"NADA");
        strcpy(lista[i].datoChar1,"NADA");
        strcpy(lista[i].datoChar2,"NADA");
    }

}

void mostrarEstrutura(eDato lista)
{
        printf(" ID    INT 1    NOMBRE    CHAR 1     CHAR 2 \n");
        printf("%d--%d--%s--%s--%s \n",lista.id,lista.datoInt1,lista.nombre,lista.datoChar1,lista.datoChar2);
}

void mostrarArrayEstrutura(eDato lista[], int tam)
{
    int i;
    int aux=0;
    eDato auxLista;

    for(i=0;i<tam;i++)
    {
        if(lista[i].flag==1)
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

eDato modificarEstructura(eDato lista[], int posicion)
{
    char respuesta;

    printf("¿Desea modificar permanentemente este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        printf("flag actual: %d ,Ingrese nuevo int, flag: ",lista[posicion].flag);
        scanf("%d",&lista[posicion].flag);

        printf("id actual: %d ,Ingrese nuevo int, id: ",lista[posicion].id);
        scanf("%d",&lista[posicion].id);

        printf("Dato actual: %d ,Ingrese nuevo int: ",lista[posicion].datoInt1);
        scanf("%d",&lista[posicion].datoInt1);

        printf("nombre actual: %s ,Ingrese nuevo nombre: ",lista[posicion].nombre);
        fflush(stdin);
        gets(lista[posicion].nombre);

        printf("Dato actual: %s ,Ingrese nueva cadena, dato 1: ",lista[posicion].datoChar1);
        fflush(stdin);
        gets(lista[posicion].datoChar1);

        printf("Dato actual: %s ,Ingrese nueva cadena, dato 2: ",lista[posicion].datoChar2);
        fflush(stdin);
        gets(lista[posicion].datoChar2);
    }

    else{printf("Accion CANCELADA, no se modifico el objeto \n");}

}

eDato cargarEstructura(eDato lista[],int posicion)
{
    if(posicion!=-1)

    {
        printf("Ingrese int, flag: ");
        scanf("%d",&lista[posicion].flag);

        printf("Ingrese int, id: ");
        scanf("%d",&lista[posicion].id);
        lista[posicion].id=validaInt(lista[posicion].id,1,99);

        printf("Ingrese int, dato int 1: ");
        scanf("%d",&lista[posicion].datoInt1);
        lista[posicion].datoInt1=validaInt(lista[posicion].datoInt1,1,99);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[posicion].nombre);

        printf("Ingrese cadena, dato 1: ");
        fflush(stdin);
        gets(lista[posicion].datoChar1);

        printf("Ingrese cadena, dato 2: ");
        fflush(stdin);
        gets(lista[posicion].datoChar2);
    }
}

eDato eliminarEstructura(eDato lista[],int posicion)
{
    char respuesta;
    printf("¿Desea eliminar permanentemente este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        lista[posicion].flag=0;
        lista[posicion].id=0;
        lista[posicion].datoInt1=0;
        strcpy(lista[posicion].nombre,"NADA");
        strcpy(lista[posicion].datoChar1,"NADA");
        strcpy(lista[posicion ].datoChar2,"NADA");
    }
    else{printf("Accion CANCELADA, no se elimino el objeto \n");}

}
eDato altaEstructura(eDato lista[], int tam)
{
    eDato auxLista;
    char respuesta;
    int aux;

    printf("Ingrese id a darle de alta\n");
    aux=buscarElementoInt(lista,tam);
    auxLista=lista[aux];
    mostrarEstrutura(auxLista);

    printf("¿Desea darle de alta a este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        lista[aux].flag=1;
    }
    else
    {
            printf("Accion CANCELADA, no se dio de alta al objeto \n");
    }
}
eDato bajaEstructura(eDato lista[],int tam)
{
   eDato auxLista;
    char respuesta;
    int aux;

    printf("Ingrese id a darle de baja\n");
    aux=buscarElementoInt(lista,tam);
    auxLista=lista[aux];
    mostrarEstrutura(auxLista);

    printf("¿Desea darle de baja a este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        lista[aux].flag=0;
    }
    else
    {
            printf("Accion CANCELADA, no se dio de baja al objeto \n");
    }
}

void ordenaEstructura(eDato lista[],int tam)
{
    int i, j;

}
