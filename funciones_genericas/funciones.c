#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

 int menu()
 {
        int opcion;
        system("cls");
        printf("\n***CLIENTES***\n\n\n");
        printf("1- Alta \n");
        printf("2- Modificacion \n");
        printf("3- Baja \n");
        printf("4- Nuevo alquiler \n");
        printf("5- Fin alquiler \n");
        printf("6- Mostrar\n");
        printf("7- Salir\n");
        printf("\n\nIngrese opcion: ");

        scanf("%d", &opcion);
        opcion=validaInt(opcion,1,7);

        return opcion;

}

int obtenerEspacioLibre(eDato lista[], int tam)
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

int buscarId(eDato lista[], int tam)
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

int buscarNombre(eDato lista[], int tam)
{
    int aux=-1;
    char auxCadena[50];
    int i;

    scanf("%s",&auxCadena);

    for(i=0; i<tam; i++)
    {
        if(lista[i].nombre==auxCadena && lista[i].estado==1)
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

char* validaCadena(char cadena[],int minimo,int maximo)
{
    char auxCadena[100];
    while(strlen(cadena)<minimo || strlen(cadena)>maximo)
    {
        printf("ERROR, reingrese cadena de caracteres:");
        fflush(stdin);
        gets(cadena);
    }

    strcpy(auxCadena,cadena);

    return auxCadena;
}

void iniciaEstructura(eDato lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=-1;
        lista[i].id=0;
    }

    for(i=0; i<tam; i++)
    {
        strcpy(lista[i].nombre,"NADA");
        strcpy(lista[i].apellido,"NADA");
    }
}

void mostrarEstrutura(eDato lista)
{
    printf("id:%d, dni: %d, nombre: %s, apellido:%s \n",lista.id,lista.dni,lista.nombre,lista.apellido);
}

void mostrarArrayEstrutura(eDato lista[], int tam)
{
    int i;
    int aux=-1;
    eDato auxLista;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            auxLista=lista[i];
            mostrarEstrutura(auxLista);
            aux=1;
        }
    }

    if(aux==-1)
    {
        printf("\nNo hay nada para mostar\n");
    }
}

void modificarEstructura(eDato lista[], int posicion)
{
    char respuesta;
    eDato auxLista;
    char buffer[200];

    if(posicion!=-1)

    {
       auxLista=lista[posicion];
    mostrarEstrutura(auxLista);

    printf("¿Desea modificar permanentemente este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {

        printf("Ingrese nuevo nombre: ");
        fflush(stdin);
        gets(buffer);
        strcpy(lista[posicion].nombre,validaCadena(buffer,2,20));

        printf("Ingrese nuevo apellido: ");
        fflush(stdin);
        gets(buffer);
        strcpy(lista[posicion].apellido,validaCadena(buffer,2,20));
    }

    else
    {
        printf("Accion CANCELADA, no se modifico el objeto \n");
    }

    }



}

void cargarEstructura(eDato lista[],int posicion)
{
    char buffer[200];
    if(posicion!=-1)
    {
        lista[posicion].id=posicion+1;

        printf("Ingrese dni: ");
        scanf("%d",&lista[posicion].dni);
        lista[posicion].dni=validaInt(lista[posicion].dni,1,99999999);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(buffer);
        strcpy(lista[posicion].nombre,validaCadena(buffer,2,20));

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(buffer);
        strcpy(lista[posicion].apellido,validaCadena(buffer,2,20));

        lista[posicion].estado=1;
    }
}

void eliminarEstructura(eDato lista[],int posicion)
{
    char respuesta;
    eDato auxLista;

    auxLista=lista[posicion];
    mostrarEstrutura(auxLista);

    printf("¿Desea eliminar permanentemente este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        lista[posicion].estado=-1;
        lista[posicion].id=0;
        lista[posicion].dni=0;
        strcpy(lista[posicion].nombre,"NADA");
        strcpy(lista[posicion].apellido,"NADA");
        printf("Dato eliminado \n");
    }
    else
    {
        printf("Accion CANCELADA, no se elimino el objeto \n");
    }

}
void altaEstructura(eDato lista[], int tam)
{
    eDato auxLista;
    char respuesta;
    int aux;

    printf("Ingrese id a darle de alta\n");
    aux=buscarId(lista,tam);
    auxLista=lista[aux];
    mostrarEstrutura(auxLista);

    printf("¿Desea darle de alta a este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        lista[aux].estado=1;
    }
    else
    {
        printf("Accion CANCELADA, no se dio de alta al objeto \n");
    }
}
void bajaEstructura(eDato lista[],int tam)
{
    eDato auxLista;
    char respuesta;
    int aux;

    printf("Ingrese id a darle de baja\n");
    aux=buscarId(lista,tam);

    if(aux!=-1)
    {
        auxLista=lista[aux];
        mostrarEstrutura(auxLista);

        printf("¿Desea darle de baja a este objeto? s/n \n");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta);

        if(respuesta=='S')
        {
            lista[aux].estado=0;
            printf("\t Baja exitosa!!! \n");
        }
        else
        {
            printf("Accion CANCELADA, no se dio de baja al objeto \n");
        }
    }
}

void ordenaEstructura(eDato lista[],int tam)
{
    int i, j;
    eDato auxLista;

    for(i=0;i<tam-1;i++)
    {
            for(j=i+1;j<tam;j++)
            {
                if(strcmpi(lista[i].nombre,lista[j].nombre)==1)
                {
                    auxLista=lista[j];
                    lista[j]=lista[i];
                    lista[i]=auxLista;
                }
                if( strcmpi(lista[i].nombre,lista[j].nombre)==0 && lista[i].id > lista[j].id)
                {
                    auxLista=lista[j];
                    lista[j]=lista[i];
                    lista[i]=auxLista;
                }
            }
    }

    mostrarArrayEstrutura(lista,tam);
}

void cargaAutomatica(eDato lista[],int tam)
{
    int i;
    eDato aux[5]={  {.estado=1,.id=1,.dni=012,"Juan","Perez"},{1,2,345,"Angel","Gomez",},{1,3,678,"Zara","Prieto"},{1,4,901,"Barbara","Rodriguez"},{1,5,234,"Maria","Espinoza"} };

    for(i=0;i<5;i++)
    {
        lista[i]=aux[i];
    }
}

