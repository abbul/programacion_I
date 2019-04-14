#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    ePersona* persona;
    ArrayList* lista;
    ArrayList* nuevaLista; // lista filtrada
    int respuesta,i,salida=1;
    int flagOpcion1=-1,flagOpcion2=-1;

    persona = constructor_ePersona(1);
    lista = al_newArrayList();

    do
    {
        switch(menu())
        {

        case 1:
            if(flagOpcion1==-1)
            {
                flagOpcion1=parsear_archivo(lista);
                if(flagOpcion1==0)
                {
                    printf("\n\n DATOS LEIDOS CON EXITO!!\n\n ");

                }
                else
                {
                    printf("\n\n ERROR AL LEER EL ARCHIVO\n\n ");
                }
            }
            else
            {
                printf("\n\n  YA EL ARCHIVO FUE LEIDO ARTERIORMENTE \n\n  ");
            }
            getch();

            break;

        case 2:
            if( (nuevaLista = lista->filter(lista,filtra_lista)) !=NULL && flagOpcion1==0)
            {
                printf("\n \n LA LISTA FUE FILTRADA CON EXITO!!! \n \n");
                flagOpcion2=0;
                mostrar_clientes(nuevaLista);
            }
            else
            {
                printf("\n\n ERROR AL FILTRAR LISTA\n\n ");
            }
            getch();
            break;

        case 3:
            if(nuevaLista!=NULL && flagOpcion2==0)
            {
                if(generar_archivo_filtrado(nuevaLista) ==0)
                {
                    printf("\n\n ARCHIVO GENERADO CON EXITO!!!\n\n ");
                }
                else
                {
                    printf("\n\n ERROR AL GENERAR ARCHIVO!!!\n\n ");
                }
            }
            else
            {
                printf("\n\n ERROR AL GENERAR ARCHIVO!!! \n\n");
            }
            getch();
            break;

        case 4:
            salida=0;
            break;
        }

    }
    while(salida!=0);

    return 0;
}
