#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListModificada.h"
#include "clientes.h"
#include "bancos.h"
#include "pagos.h"

int baja_logica_banco (ArrayList* lista,ArrayList* bancos)
{
    char respuesta;
    int i,posicion,auxId;
    eBanco* auxBanco;

    printf("Ingese ID para darle de BAJA a una de sus cuentas \n");
    printf("OPCION: ");
    scanf("%d",&auxId);
    posicion=buscar_idCliente_en_bancos(bancos,auxId);

    if(posicion!=-1)
    {
        mostrar_bancos(lista,bancos,auxId);
        printf("\n\n Ingrese numero de IDENTIFICADOR BANCARIO a eliminar? \n");
        printf("OPCION: ");
        scanf("%d",&posicion);

        for(i=0; i<bancos->size; i++)
        {
            auxBanco= (eBanco*)bancos->get(bancos,i);

            if(posicion==i && auxBanco->idCliente==auxId)
            {
                printf("¿Desea darle de BAJA a esta Cuenta? s/n \n");
                fflush(stdin);
                scanf("%c",&respuesta);
                respuesta=toupper(respuesta);

                if(respuesta=='S')
                {
                    auxBanco->cedulaTitular=0; // HASTA AHORA EL BANCO NO TIENE ESTADO
                    lista->set(bancos,posicion,auxBanco);
                    printf(" \t Cuenta Bancaria ELIMINADA!!!! \n");
                    break;
                }
                else
                {
                    printf("Accion CANCELADA, no se elimino el Banco");
                    break;
                }
            }
        }
    }

    return posicion;
}

int lee_archivo_banco(ArrayList* banco)
{
    FILE* archivo=NULL;
    eBanco* returnAux;
    eBanco* auxBanco;
    char auxCedulaTitular[100];
    char auxNombreTitular[100];
    char auxApellidoTitular[100];
    char auxIdCliente[100];
    char auxNombreBanco[100];
    char auxNumeroCuenta[100];

    archivo = fopen("dataBanco.csv", "r");

    if(archivo != NULL && banco != NULL)
    {
        while(!feof(archivo))
        {
            fscanf(archivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", auxIdCliente, auxNombreTitular, auxApellidoTitular, auxCedulaTitular, auxNombreBanco, auxNumeroCuenta);
            returnAux = (eBanco*) malloc(sizeof(eBanco));
            if(feof(archivo))
            {
                break;
            }

            else if(returnAux !=NULL)
            {
                returnAux->idCliente = atoi(auxIdCliente);
                strcpy(returnAux->nombreTitular, auxNombreTitular);
                strcpy(returnAux->apellidoTitular, auxApellidoTitular);
                returnAux->cedulaTitular= atoi(auxCedulaTitular);
                strcpy(returnAux->nombreBanco, auxNombreBanco);
                returnAux->numeroCuenta = atoi(auxNumeroCuenta);

                banco->add(banco, returnAux);
            }
        }
    }
    else
    {
        printf("ERROR; No se pudo abrir el archivo");
        exit(1);
    }

    fclose(archivo);

    return 0;
}

int buscar_idCliente_en_bancos(ArrayList* bancos,int id)
{
    int aux=-1;
    int i;
    eBanco* auxBanco;

    for(i=0; i<bancos->size; i++)
    {
        auxBanco= (eBanco*) bancos->get(bancos,i);

        if(auxBanco->idCliente == id)
        {
            aux=i;
            break;
        }
    }
    return aux;
}

void modificar_banco(ArrayList* lista,ArrayList* bancos)
{
    eBanco auxBanco;
    eBanco* auxLista;
    char buffer[200];
    char respuesta;
    int posicion,aux,auxId,i,flag=-1;

    printf("Ingrese ID cliente para modificar Banco:");
    scanf("%d",&auxId);

    posicion= buscar_idCliente_en_bancos(bancos,auxId);

    if(posicion!=-1)
    {
        mostrar_bancos(lista,bancos,auxId);

        printf("Ingrese IDENTIFICADOR BANCARIO a Modificar? \n");
        printf(" o sino quiere modificar ninguno ingrese cualquier numero distinto \n");
        fflush(stdin);
        scanf("%d",&aux);

        for(i=0; i<bancos->size; i++)
        {
            auxLista= (eBanco*)bancos->get(bancos,i);

            if(aux==i && auxLista->idCliente==auxId)
            {
                auxBanco= cargar_banco(bancos);
                auxLista->idCliente= auxId;
                auxLista->numeroCuenta= auxBanco.numeroCuenta;
                auxLista->cedulaTitular = auxBanco.cedulaTitular;
                strcpy(auxLista->nombreBanco,auxBanco.nombreBanco);
                strcpy(auxLista->nombreTitular,auxBanco.nombreTitular);
                strcpy(auxLista->apellidoTitular,auxBanco.apellidoTitular);
                bancos->set(bancos,posicion,auxLista);
                flag=0;
                break;
            }
        }
        if(flag==-1)
        {
            printf("MODIFICACION CANCELADA!!!");
        }
        printf("MODIFICACION EXITOSA!!!");
    }
}

void mostrar_bancos(ArrayList* lista, ArrayList* bancos,int idCliente) // impreme todos los bancos que tengl el ID q se le pasa
{
    int i, posicion,flag=0;
    eBanco* aux=NULL;
    eCliente* auxCliente;

    posicion=buscar_id_cliente(lista,idCliente);
    auxCliente= (eCliente*) lista->get(lista,posicion);

    if(posicion!=-1)
    {
        printf("ID:%d -> %s %s \n\n",auxCliente->id,auxCliente->nombre,auxCliente->apellido);
        printf("Tiene estos bancos asociados: \n\n");

        for(i=0; i<bancos->size; i++)
        {
            aux = (eBanco*) bancos->get(bancos,i);

            if(aux->idCliente==idCliente)
            {
                mostrar_un_banco(aux,i);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay nada para mostrar");
        }
    }

}

void mostrar_un_banco(eBanco* unBanco, int identificador) // solo imprime el banco con la condicion q envies 1 ó 0
{
    printf("-------------------------------------------------------\n");
    printf("IDENTIFICADOR BANCARIO: %d \n",identificador);
    printf("\n ID: %d, %s %s, CI TITULAR: %d \n",unBanco->idCliente,unBanco->nombreTitular,unBanco->apellidoTitular,unBanco->cedulaTitular);
    printf("Nombre del Banco: %s, Numero de Cuenta: %d \n",unBanco->nombreBanco,unBanco->numeroCuenta);
    printf("-------------------------------------------------------\n");
}

eBanco* nuevo_banco(ArrayList* lista,ArrayList* bancos)
{
    eBanco* returnAux;
    eCliente* auxCliente;
    eBanco aux;
    int posicion,auxId;

    if(bancos!=NULL && lista!=NULL)
    {
        printf("Ingrese ID a vincular:");
        scanf("%d",&auxId);
        posicion =buscar_id_cliente(lista,auxId);

        if(posicion!=-1)
        {
            auxCliente= lista->get(lista,posicion);
            mostrar_un_cliente(auxCliente,1);
            mostrar_un_cliente(auxCliente,0);
            returnAux = (eBanco*) malloc(sizeof(eBanco));

            if(returnAux !=NULL)
            {
                aux= cargar_banco(bancos);

                returnAux->idCliente= auxId;
                returnAux->numeroCuenta= aux.numeroCuenta;
                returnAux->cedulaTitular = aux.cedulaTitular;
                strcpy(returnAux->nombreBanco,aux.nombreBanco);
                strcpy(returnAux->nombreTitular,aux.nombreTitular);
                strcpy(returnAux->apellidoTitular,aux.apellidoTitular);
            }
        }
    }

    return returnAux;

}

eBanco cargar_banco (ArrayList* bancos)
{
    eBanco auxBanco;

    printf("Ingrese Apellido Titular: ");
    fflush(stdin);
    gets(auxBanco.apellidoTitular);
    strcpy(auxBanco.apellidoTitular,valida_cadena(auxBanco.apellidoTitular,2,20));

    printf("Ingrese Nombre Titular: ");
    fflush(stdin);
    gets(auxBanco.nombreTitular);
    strcpy(auxBanco.nombreTitular,valida_cadena(auxBanco.nombreTitular,2,20));

    printf("Ingrese Cedula Titular: ");
    scanf("%d",&auxBanco.cedulaTitular);
    auxBanco.cedulaTitular=valida_int(auxBanco.cedulaTitular,50,99999999);

    printf("Ingrese Nombre Banco: ");
    fflush(stdin);
    gets(auxBanco.nombreBanco);
    strcpy(auxBanco.nombreBanco,valida_cadena(auxBanco.nombreBanco,2,20));

    printf("Ingrese Numero de cuenta: ");
    scanf("%d",&auxBanco.numeroCuenta);
    auxBanco.numeroCuenta=valida_int(auxBanco.numeroCuenta,10,99999999);

    return auxBanco;
}
