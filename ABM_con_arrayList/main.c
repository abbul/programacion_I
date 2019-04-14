#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListModificada.h"
#include "clientes.h"

int main()
{
    ArrayList* lista=NULL;
    ArrayList* auxUno=NULL;
    ArrayList* auxCero=NULL;
    eCliente* auxCliente=NULL;
    int i=0,salida=1,aux,flag=0,flagCargar=1;

    lista = al_newArrayList();
    auxCero= al_newArrayList();
    auxUno= al_newArrayList();

    if(lista != NULL)
    {


        while(salida)
        {
            system("color 07");
            switch(menu())
            {
            case 1:
                system("cls");
                printf("ESTAS CARGANDO LA LISTA\n\n");

                if(flagCargar!=0)
                {
                    flagCargar= lee_archivo_cliente(lista);
                    system("color 02");
                }
                else
                {
                    printf("YA FUE CARGADA!!!");
                }
                getch();
                break;

            case 2:
                system("cls");
                printf("\t\tESTAS ORDENANDO\n\n");
                mostrar_clientes(lista);

                if(ordena_por_hora(lista) !=-1)
                {
                    printf("\nORDENADO CON EXITO!!");
                    system("color 02");
                }
                else
                {
                    printf("\nERROR AL ORDENAR");
                }
                getch();
                break;

            case 3:
                system("cls");
                printf("\t\tESTAS CREANDO 2 NUEVAS LISTAS\n\n");
                if(divide_lista(lista,auxUno,1) ==0 && divide_lista(lista,auxCero,0)==0)
                {
                    printf("CREADO CON EXITO!!");
                    system("color 02");
                }
                else
                {
                    printf("ERROR AL CREAR LISTAS");
                }
                getch();
                break;
            case 4:
                 system("cls");
                printf("\t\tESTAS RESOLVIENDO UNA TAREA\n\n");

                if(flag=busca_tarea(lista,flag)==1)
                {
                    system("color 04");
                }
                getch();
                break;
            case 5:
                system("cls");
                printf("\t\tESTAS GENERANDO LOS ARCHIVOS\n\n");
                if(generaArchivo(auxUno,"pAlta.csv",1)==0 && generaArchivo(auxCero,"pBaja.csv",0)==0)
                printf("SE GENERARON CON EXITO!!!");
                getch();
                break;
            case 6:
                system("color 4c");
                salida=0;
                break;
            }
        }
    }

    else
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }

    return 0;
}
