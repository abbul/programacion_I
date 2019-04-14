#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListModificada.h"
#include "clientes.h"

int generaArchivo(ArrayList* lista, char nombrearchivo[],int condicion)
{
    FILE* archivo;
    eCliente* aux;
    int i,salida=-1;

    archivo =fopen(nombrearchivo,"w");
    if(archivo!=NULL)
    {
        for(i=0; i<lista->size; i++)
        {
            aux= (eCliente*) lista->get(lista,i);

            if(aux->prioridad==condicion)
            {
                fprintf(archivo,"%d,%s,%d\n",aux->prioridad,aux->descripcion,aux->horas);
                salida=0;
            }

        }
    }

    return salida;
}

int divide_lista(ArrayList* lista,ArrayList* aux,int condicion)
{
    eCliente* auxDato;
    int salida=-1,i;

    if(lista!=NULL && aux!=NULL && (condicion==1 || condicion ==0))
    {
        for(i=0; i<lista->size; i++)
        {
            auxDato = (eCliente*) lista->get(lista,i);

            if(auxDato->prioridad==condicion)
            {
                aux->add(aux,auxDato);
                salida=0;
            }
        }
    }

    return salida;
}

int menu(void)
{
    int opcion;

    system("cls");
    printf("1. Cargar lista de tareas \n");
    printf("2. Ordenar \n");
    printf("3. Particionar por prioridad \n");
    printf("4. Resolver tarea \n");
    printf("5. Generar \n");
    printf("6. Salir \n");


    printf("\n\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int ordena_por_hora(ArrayList* lista)
{
    int salida=-1, i,j;
    eCliente* aux1;
    eCliente* aux2;
    eCliente* auxBurbuja;

    if(lista != NULL)
    {
        salida=1;
        for(i=0; i<lista->size-1; i++)
        {
            aux1= (eCliente*) lista->get(lista,i);

            for(j=i+1; j<lista->size; j++)
            {
                aux2= (eCliente*) lista->get(lista,j);

                if(aux1->horas > aux2->horas)
                {
                    auxBurbuja = aux1;
                    aux1= aux2;
                    aux2 = auxBurbuja;

                    lista->set(lista,i,aux1);
                    lista->set(lista,j,aux2);
                    salida=0;
                }
            }
        }

    }
    return salida;
}

int valida_int(int numero,int minimoInt, int maximoInt)
{

    while(minimoInt>numero || numero>maximoInt)
    {
        printf("ERROR; Reingrese el numero: ");
        scanf("%d",&numero);
    }

    return numero;
}

float valida_float(float numero,float minimoFloat, float maximoFloat)
{
    while(minimoFloat>numero || numero>maximoFloat)
    {
        printf("ERROR; Reingrese el numero: ");
        scanf("%f",&numero);
    }

    return numero;
}

char* valida_cadena(char cadena[],int minimo,int maximo)
{
    char auxCadena[100];
    while(strlen(cadena)<minimo || strlen(cadena)>maximo)
    {
        printf("ERROR, reingrese de forma correcta:");
        fflush(stdin);
        gets(cadena);
    }

    strcpy(auxCadena,cadena);

    return auxCadena;
}

eCliente* nuevo_cliente(ArrayList* lista)
{
    eCliente* returnAux;
    eCliente aux;

    returnAux = (eCliente*) malloc(sizeof(eCliente));

    //aux= cargar_cliente(lista);

    if(returnAux !=NULL)
    {
        returnAux->horas = aux.horas;
        returnAux->prioridad = aux.prioridad;
        strcpy(returnAux->descripcion,aux.descripcion);
    }

    return returnAux;
}

void mostrar_un_cliente(eCliente* returnAux) // solo imprime el cliente con la condicion q envies 1 ó 0
{
    printf("descripcion: %s, prioridad: %d, Horas: %d \n",returnAux->descripcion,returnAux->prioridad,returnAux->horas);
}

void mostrar_clientes(ArrayList* lista)
{
    int i, flag=0;
    eCliente* aux=NULL;

    for(i=0; i<lista->size; i++)
    {
        aux = (eCliente*) lista->get(lista,i);
        mostrar_un_cliente(aux);
        flag=1;
    }
    if(flag==0)
    {
        printf("No hay nada para mostrar");
    }
}

int busca_tarea(ArrayList* lista,int flag) // solo busca el id y lo retorna la posicion
{
    int aux,i,menosHoras=500;
    eCliente* auxCliente;

    printf(" \n 1.%d \n",lista->size);
    getchar();

    if(flag==1 && lista!=NULL)
    {
        for(i=0; i<lista->size; i++)
        {
            auxCliente= (eCliente*) lista->get(lista,i);

            if(auxCliente->horas < menosHoras && auxCliente->prioridad==0)
            {
                menosHoras=auxCliente->horas;
                aux=i;
                flag=1;
                printf(" \n 2.%d \n",lista->size);
                getchar();
            }
        }
    }

    else
    {
        for(i=0; i<lista->size; i++)
        {
            auxCliente= (eCliente*) lista->get(lista,i);

            if(auxCliente->horas < menosHoras && auxCliente->prioridad==1)
            {
                menosHoras=auxCliente->horas;
                aux=i;
                flag=1;
            }
        }
    }

    printf("SE RESOLVIO LA SIGUIENTE TAREA: \n");
    auxCliente= (eCliente*) lista->pop(lista,aux);
    contract(lista,aux);
    mostrar_un_cliente(auxCliente);

    return flag;
}

int lee_archivo_cliente(ArrayList* lista)
{
    FILE* archivo=NULL;
    eCliente* returnAux;
    eCliente* auxCliente;
    char auxDescripcion[50];
    char auxPrioridad[50];
    char auxHoras[50];
    int salida=-1;

    archivo = fopen("data.csv","r");

    if(archivo!= NULL && lista != NULL)
    {
        while(!feof(archivo))
        {
            fflush(stdin);
            fscanf(archivo,"%[^,],%[^,],%s\n",auxPrioridad,auxDescripcion,auxHoras);

            returnAux = (eCliente*) malloc(sizeof(eCliente));
            if(feof(archivo))
            {
                break;
            }

            else
            {
                if(returnAux!=NULL)
                {
                    strcpy(returnAux->descripcion,auxDescripcion);
                    returnAux->prioridad = atoi(auxPrioridad);
                    returnAux->horas = atoi(auxHoras);

                    lista->add(lista,returnAux);
                    salida=0;
                }
            }
        }
    }
    else
    {
        printf("ERROR; No se pudo abrir el archivo");
        exit(1);
    }

    mostrar_clientes(lista);

    fclose(archivo);

    return salida;
}

int baja_logica_cliente(ArrayList* lista)
{
    char respuesta;
    int i,posicion,auxId;
    eCliente* auxLista;

    printf("Ingese ID a darle de BAJA:");
    scanf("%d",&auxId);
//    posicion=buscar_id_cliente(lista,auxId);

    if(posicion!=-1)
    {
        auxLista =(eCliente*) lista->get(lista,posicion);

        if(auxLista->prioridad==1)
        {
            mostrar_un_cliente(auxLista);
            printf("¿Desea darle de BAJA a este cliente? s/n \n");
            fflush(stdin);
            scanf("%c",&respuesta);
            respuesta=toupper(respuesta);

            if(respuesta=='S')
            {
                auxLista->prioridad=0;
                lista->set(lista,posicion,auxLista);
                printf(" \t Cliente ELIMINADO!!!! \n");
            }
            else
            {
                printf("Accion CANCELADA, no se elimino el objeto \n");
            }
        }

        else
        {
            printf("ERROR, este ID ya esta dado de baja");
        }
    }
}
