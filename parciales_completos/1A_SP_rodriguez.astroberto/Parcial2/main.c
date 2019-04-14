#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    int salir = 0, auxInt;

    ArrayList* lista=NULL;
    ArrayList* listaNegra=NULL;
    ArrayList* listaNueva=NULL;
    eClientes* auxCliente=NULL;

    do
    {
        switch (menu())
        {
        case 1:
            system("cls");
            lista = al_newArrayList();
            auxInt=parsear_archivo(lista);

            if(auxInt==0)
            {
                printf(" \n\n LEIDO CON EXITO!!");
            }
            else
            {
                printf(" \n\n NO SE ENCONTRO EL ARCHIVO");
            }
            getch();
            break;
        case 2:
            system("cls");
            listaNegra = al_newArrayList();
            auxInt=parsear_y_comparar_archivo(lista,listaNegra);

            if(auxInt==0)
            {
                printf("LEIDO CON EXITO!!");
            }
            if(auxInt==1)
            {
                printf(" \n\n  NO SE ENCONTRO EL ARCHIVO");
            }
            if(auxInt==-1)
            {
                printf(" \n\n  ANTES DEBE CARGAR LA LISTA DE DESTINATARIOS");
            }
            getch();

            break;
        case 3:
            system("cls");
             listaNueva = al_newArrayList();
            auxInt= depurar_lista(lista,listaNegra,listaNueva);
            if(auxInt==0)
            {
                printf("ARCHIVO DEPURADO CON EXITO!!");
            }
            else
            {
                printf("\n\n ERROR AL DEPURAR");
            }
            getch();
            break;

        case 4:
            system("cls");
            auxInt= mostrar_clientes(listaNueva);
            if(auxInt==0)
            {
                printf(" \n\n MOSTRADO CON EXITO!!");
            }
            else
            {
                printf("\n\n NO HAY NADA PARA MOSTRAR");
            }
            getch();
            break;
        case 5:
            salir = 1;
            break;
        }
    }
    while(salir==0);

    return 0;
}

