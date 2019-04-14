#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListModificada.h"
#include "clientes.h"
#include "bancos.h"
#include "pagos.h"

int agrega_capital (int cuentas[])
{
    int i,aux,auxMonto,flag=-1;

    printf("\t ESTAS AGREGANDO DINERO \n\n\n");

    printf("A Cual de las cuentas va a ingresar o egresar dinero? \n\n");

    printf("0.Cta Banesco   ****0068 -->  Bs%d \n",cuentas[0]);
    printf("1.Cta Banesco   ****0121 -->  Bs%d \n",cuentas[1]);
    printf("2.Cta Banesco   ****3212 -->  Bs%d  \n",cuentas[2]);
    printf("3.Cta Mercantil ****1290 -->  Bs%d \n\n",cuentas[3]);

    printf("OPCION: ");
    fflush(stdin);
    scanf("%d",&aux);
    aux=valida_int(aux,0,3);

    printf("Ingrese monto en BOLIVARES, Bs: ");
    scanf("%d",&auxMonto);

    for(i=0; i<4; i++)
    {
        if(aux==i)
        {
            cuentas[i]=cuentas[i]+auxMonto;
            flag=0;
            break;
        }
    }

    return flag;
}

ePago cargar_pago (ArrayList* lista, ArrayList* bancos, ArrayList* pagos,int cuentas[],int id)
{
    eBanco* auxBanco;
    ePago auxPago;
    ePago* aux;
    int posicion,i,flag=-1;
    char buffer[1240];

    printf("\nIngrese forma de compra \n");
    printf("1.Efectivo,   2.Transferencia,   3.MercadoPago,   4.Otros \n");
    printf("OPCION: ");
    scanf("%d",&auxPago.formaDePago);
    auxPago.formaDePago=valida_int(auxPago.formaDePago,1,4);

    if(auxPago.formaDePago==4)
    {
        printf("\nExplique por que la opcion OTRO \n");
        printf("OPCION: ");
        fflush(stdin);
        scanf("%s",&buffer);
    }

    do
    {
        mostrar_bancos(lista,bancos,id);
        printf("\n A cual de estas se le transfirio? \n");
        printf("OPCION: ");
        fflush(stdin);
        scanf("%d",&auxPago.cuentaReceptora);

        for(i=0; i<bancos->size; i++)
        {
            auxBanco= (eBanco*)bancos->get(bancos,i);

            if(auxPago.cuentaReceptora==i && auxBanco->idCliente==id)
            {
                flag=0;
            }
        }
    }
    while(flag==-1);


    printf("\nDesde cual cuenta bancaria? \n");
    printf("1.Banesco ****0068 ,  2.Banesco ****0121 , 3.Banesco  ***3212 , 4.Mercanil ****1290 \n");
    printf("OPCION: ");
    fflush(stdin);
    scanf("%d",&auxPago.cuentaEmisora);
    auxPago.cuentaEmisora=valida_int(auxPago.cuentaEmisora,1,4);


    printf("\nIngrese la cantidad de PESOS comprados \n");
    printf("OPCION:$ ");
    scanf("%d",&auxPago.cantidaComprada);
    auxPago.cantidaComprada=valida_int(auxPago.cantidaComprada,50,999999);

    cuentas[auxPago.cuentaEmisora-1]=cuentas[auxPago.cuentaEmisora-1]-auxPago.cantidaComprada;

    printf("\nIngrese Codigo de Operador. \n");
    printf("1.Astrid,   2.Alibell,   3.Aliuska,   4.Otro \n");
    printf("OPCION: ");
    scanf("%d",&auxPago.vendedor);
    auxPago.vendedor=valida_int(auxPago.vendedor,1,4);

    printf("\nIngrese Fecha de compra, formato(dia-mes-año) \n");
    printf("OPCION: ");
    scanf("%d",&auxPago.fechaVenta);
    auxPago.fechaVenta=valida_int(auxPago.fechaVenta,1,99);

    return auxPago;
}

ePago* nuevo_pago(ArrayList* lista, ArrayList* bancos, ArrayList* pagos,int cuentas[])
{
    ePago* returnAux;
    eCliente* auxCliente;
    eBanco* auxBanco;
    ePago aux;
    int posicion;

    printf("Ingrese ID cliente para registrar la compra: \n");
    printf("OPCION: ");
    scanf("%d",&aux.idCliente);

    posicion = buscar_id_cliente(lista,aux.idCliente);

    if(posicion!=-1)
    {
        auxCliente = (eCliente*) lista->get(lista,posicion);
        mostrar_un_cliente(auxCliente,1);
        mostrar_un_cliente(auxCliente,0);

        if(auxCliente->estado==1)
        {
            posicion = buscar_idCliente_en_bancos(bancos,aux.idCliente);

            if(posicion!=-1)
            {
                returnAux = (ePago*) malloc(sizeof(ePago));

                aux= cargar_pago(lista,bancos,pagos,cuentas,aux.idCliente);

                if(returnAux !=NULL)
                {
                    returnAux->idCliente = aux.idCliente;
                    returnAux->formaDePago = aux.formaDePago;
                    returnAux->cantidaComprada= aux.cantidaComprada;
                    returnAux->vendedor= aux.vendedor;
                    returnAux->fechaVenta =aux.fechaVenta;
                    printf("\t\t PAGO REGISTRADO CON EXITO!!!");
                }
            }
            else
            {
                printf(" \n \n CLIENTE NO TIENE CUENTAS VINCULADAS, DEBE VINCULARLE UNA PARA CONTINUAR");
            }

        }
        else
        {
            printf("\n\n DEBE ACTIVAR ESTE CLIENTE ANTES DE INGRESARLE UNA COMPRA");
        }
    }
    return returnAux;
}
