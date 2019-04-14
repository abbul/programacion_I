#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define X 5

int main()
{
    int opcion;
    char respuesta;
    int auxId;
    int i, j;
    int num;
    char seguir='s';
    int horaSalida;
    int pagar;
    int totalPagar;
    int acumGananciaAlpha=0,acumGananciaFerrari=0,acumGananciaAudi=0,acumGananciaOtros=0,acumulaGanancias=0;
    Eauto auxAutos;
    Eclientes cliente[X];
    Eauto autoDeCliente[X];


    /*for(i=0; i<X; i++)
    {
        cliente[i].flagDeAltaCliente=0;
        autoDeCliente[i].flagAltaAuto=0;
        cliente[i].idDueno=0;
        autoDeCliente[i].copiaIdDueno=0;
    }*/

    do
    {
        printf("\n\t 1. ALTAS \n\t 2. MODIFICACION \n\t 3. INGRESO DE AUTO \n\t 4. EGRESO DE AUTO \n\t 5. IMPRIMIR LISTA \n\t 6. SALIR \n");
        printf("Elija una opcion: ");
        scanf("%d",&num);

        switch(num)
        {
        case 1:

            for(i=0; i<X; i++)
            {
                if(cliente[i].flagDeAltaCliente==0)
                {
                    printf("Ingrese ID: \n");
                    scanf("%d",&cliente[i].idDueno);
                    printf("Ingrese Nombre y Apellido: \n");
                    fflush(stdin);
                    gets(cliente[i].nombreApellido);
                    printf("Ingrese  Dirrecion: \n");
                    fflush(stdin);
                    gets(cliente[i].dirrecion);
                    printf("Ingrese Numero de Tarjeta: \n");
                    scanf("%d",&cliente[i].numeroTarjeta);
                    cliente[i].flagDeAltaCliente=1;

                    printf("!!!!!!!!!!!ALTA CONFIRMADA!!!!!!!!!!!!! \n");
                    system("pause");
                    break;
                }

            }
            break;

        case 2:
        {
            printf("Ingrese el ID que desea modificarle la TDC \n");
            scanf("%d",&auxId);

            for(i=0; i<X; i++)
            {
                if(cliente[i].idDueno==auxId)
                {
                    printf("¿Desea confirmar la modificacion de la tarjeta? s/n  \n");
                    printf("%d \n %s \n  %s \n  %d ",cliente[i].idDueno,cliente[i].nombreApellido,cliente[i].dirrecion,cliente[i].numeroTarjeta);
                    respuesta = getche();

                    if(respuesta=='s')
                    {
                        printf("Ingrese el nuevo numero de tarjeta \n");
                        scanf("%d",&cliente[i].numeroTarjeta);
                        printf("Su nueva tarjeta es: %d ",cliente[i].numeroTarjeta);
                    }

                    else
                    {
                        printf("La modificacion fue cancelada por el usuario \n");
                    }
                }
            }
        }
        printf("!!!!!!!!!!!MODIFICACION CONFIRMADA!!!!!!!!!!!!! \n");
        system("pause");
        break;

        case 3:
            for(i=0; i<X; i++)
            {
                if(autoDeCliente[i].flagAltaAuto==0)
                {
                    printf("Ingrese patente: \n");
                    fflush(stdin);
                    gets(autoDeCliente[i].patente);

                    printf("Cual de estas marca es la de su auto, escribala \n");
                    printf("1.ALPHA, 2.FERRARI, 3.AUDI, 4.OTROS \n");
                    fflush(stdin);
                    gets(autoDeCliente[i].marca);

                    printf("Ingrese  ID: \n");
                    scanf("%d",&autoDeCliente[i].copiaIdDueno);

                    printf("Ingrese horario de entrada(formato 24hs): \n");
                    scanf("%d",&autoDeCliente[i].horaEntrada);

                    autoDeCliente[i].flagAltaAuto=1;

                    printf("!!!!!!!!!!!INGRESO CONFIRMADO!!!!!!!!!!!!! \n");
                    system("pause");

                    break;
                }

            }
            break;

        case 4:
        {

            printf("Ingrese el ID del auto para gestionar el egreso\n");
            scanf("%d",&auxId);

            for(i=0; i<X; i++)
            {
                if(cliente[i].idDueno==auxId)
                {
                    printf("Ingrese Hora de Salida para el Egreso \n");
                    scanf("%d",&horaSalida);
                    printf("¿Desea confirmar el egreso para este auto a las %d Horas ? s/n \n ",horaSalida);
                    printf("ID: %d \t Nombre y Apellido: %s \t  Patent: %s \t  Marca: %s \n",cliente[i].idDueno,cliente[i].nombreApellido,autoDeCliente[i].patente,autoDeCliente[i].marca);
                    respuesta = getch();

                    if(respuesta=='s')
                    {
                        pagar=horaSalida-autoDeCliente[i].horaEntrada;


                        if(strcmp(autoDeCliente[i].marca,"alpha")==0)
                        {
                            totalPagar=(pagar*150);
                            acumGananciaAlpha=acumGananciaAlpha+totalPagar;
                        }

                        if(strcmp(autoDeCliente[i].marca,"ferrari")==0)
                        {
                            totalPagar=(pagar*175);
                            acumGananciaFerrari=acumGananciaFerrari+totalPagar;
                        }
                        if(strcmp(autoDeCliente[i].marca,"audi")==0)
                        {
                            totalPagar=(pagar*200);
                            acumGananciaAudi=acumGananciaAudi+totalPagar;
                        }
                        if(strcmp(autoDeCliente[i].marca,"otros")==0)
                        {
                            totalPagar=(pagar*250);
                            acumGananciaOtros=acumGananciaOtros+totalPagar;
                        }

                        printf("!!!!!!!!!!!EGRESO CONFIRMADO!!!!!!!!!!!!! \n");
                        system("pause");
                        printf("Debe pagar un total de: $ %d \n",totalPagar);
                        auxId=0;
                    }

                    else
                    {
                        printf("el egreso fue cancelado por el usuario \n");
                    }
                }

                else
                {
                    printf("ERROR, el ID ingresao no pertenece a ningun cliente \n ");
                }
                break;
            }
        }
        break;

        case 5:
        {
            for(i=0; i<X-1; i++)
            {
                for(j=i+1; j<X; j++)
                {
                    if(strcmp(autoDeCliente[i].patente,autoDeCliente[j].patente)>0)
                    {
                        auxAutos = autoDeCliente[i];
                        autoDeCliente[i] = autoDeCliente[j];
                        autoDeCliente[j] = auxAutos;
                    }
                }
            }

            printf("Lista Ordenada por patente \n");

            for(i=0; i<X; i++)
            {
                printf("%s \t %s \n",autoDeCliente[i].patente,autoDeCliente[i].marca);
            }

            printf("Lista de Clientes con AUDI \n");

            for(i=0; i<X; i++)
            {
                if(strcmp(autoDeCliente[i].marca,"ferrari")==0)
                {
                    printf("%s \t %s \t %s \n",cliente[i].nombreApellido,autoDeCliente[i].patente,autoDeCliente[i].marca);
                }
            }

            printf("Ganancias por Auto");
            printf("Alpha: $ %d , Audi: $ %d , Ferrari: $ %d, Otros: $ %d",acumGananciaAlpha,acumGananciaAudi,acumGananciaFerrari,acumGananciaOtros);

            acumulaGanancias=acumGananciaAlpha+acumGananciaAudi+acumGananciaFerrari+acumGananciaOtros;
            printf("Ganancias del Estacionamiento: $ %d \n",acumulaGanancias);

        }
        break;

        case 6:
        {
            seguir='n';
        }
        break;
        }
    }
    while(seguir=='s');

}
