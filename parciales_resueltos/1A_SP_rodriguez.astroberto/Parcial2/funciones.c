#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

int parsear_y_comparar_archivo(ArrayList* lista,ArrayList* listaNegra)
{
    FILE* archivo;
    eClientes* auxClientes;
    eClientes* aux;
    char auxNombre[50],auxCorreo[50],nombreArchivo[50];
    int i,salida=-1,flag=0;

    if(lista!=NULL && listaNegra!=NULL)
    {
        printf("ingrese el nombre del archivo: ");
        fflush(stdin);
        gets(nombreArchivo);

        strcpy(nombreArchivo,"black_list.csv"); //SOLO PARA PROBAR MAS RAPIDO EL CODIGO; LUEGO COMENTAR!!!

        archivo = fopen(nombreArchivo,"r");

        if(archivo!=NULL)
        {
            printf(" \n\n CARGANDO, se esta leyendo el archivo... \n\n ");

            while(!feof(archivo))
            {
                flag=0;
                fflush(stdin);
                fscanf(archivo,"%[^,],%s\n",auxNombre,auxCorreo);

                auxClientes =constructor_eCliente(1);

                strcpy(auxClientes->nombre,auxNombre);
                strcpy(auxClientes->correo,auxCorreo);

                for(i=0; i<lista->len(lista); i++)
                {
                    aux= (eClientes*) lista->get(lista,i);

                    if( strcmpi(aux->correo,auxClientes->correo) == 0 )
                    {
                        listaNegra->add(listaNegra,aux);
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                {
                    listaNegra->add(listaNegra,auxClientes);
                }

                salida=0;
            }
        }
        else
        {
            salida=1;
        }
    }

    return salida;
}

int mostrar_clientes (ArrayList* lista)
{
    eClientes* auxCliente;
    int salida=-1,i;

    if(lista!=NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            auxCliente= (eClientes*) lista->get(lista,i);
            printf("NOMBRE: %s  , CORREO: %s \n",auxCliente->nombre,auxCliente->correo);
            salida=0;
        }
    }

    return salida;
}

int menu()
{
    int respuesta;

    system("cls");

    printf("1- Cargar Destinatarios.\n");
    printf("2- Cargar Lista Negra.\n");
    printf("3- Depurar.\n");
    printf("4- Listar\n");
    printf("5- Salir\n");
    printf("Respuesta : ");

    scanf("%d",&respuesta);

    return respuesta;
}

int parsear_archivo (ArrayList* lista)
{
    FILE* archivo;
    char nombreArchivo[200], auxNombre[200], auxCorreo[200];
    int salida=-1;

    eClientes* auxClientes;

    printf("Ingrese el nombre del archivo: ");
    fflush(stdin);
    gets(nombreArchivo);

    strcpy(nombreArchivo,"destinatarios.csv"); //SOLO PARA PROBAR MAS RAPIDO EL CODIGO; LUEGO COMENTAR!!!

    archivo = fopen(nombreArchivo,"r");

    if(archivo!=NULL)
    {
        while(!feof(archivo))
        {
            fflush(stdin);
            fscanf(archivo,"%[^,],%s\n",auxNombre,auxCorreo);

            auxClientes= constructor_eCliente(1);

            strcpy(auxClientes->nombre,auxNombre);
            strcpy(auxClientes->correo,auxCorreo);

            lista->add(lista,auxClientes);
            salida=0;
        }

    }

    return salida;
}

int depurar_lista (ArrayList* lista,ArrayList* listaNegra,ArrayList* listaNueva)
{
    int i,tam,salida=-1;
    eClientes* cliente;
    eClientes* clienteNegro;

    if(listaNegra!=NULL && listaNueva!=NULL && lista!=NULL)
    {
        printf("\n\n CARGANDO, se estan comparando los datos... \n\n");

        tam= lista->len(lista);

        for(i=0; i<tam; i++)
        {
            cliente = (eClientes*) lista->get(lista,i);

            if(lista->contains(listaNegra,cliente) ==0)
            {
                lista->add(listaNueva,cliente);
                salida=0;
            }
        }
    }

    return salida;
}

eClientes* constructor_eCliente (int cantidad)
{
    eClientes* aux;

    aux = (eClientes*)malloc(sizeof(eClientes)* cantidad);

    return aux;
}
