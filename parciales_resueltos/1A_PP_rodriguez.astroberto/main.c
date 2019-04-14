#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define C 7
#define A 7

int main()
{
    int salir=1, i, auxPosicion, totalRecaudacion=0, gananciaMarca[]={0,0,0,0};
    eDato clientes[C];
    eOtro autos[A];

    iniciaEstructuraDato(clientes,C);
    iniciaEstructuraOtro(autos,A);
    cargaAutomaticaDato(clientes,C);
    cargaAutomaticaOtro(autos,A);

    do
    {
        switch(menu())
        {
        case 1:
            auxPosicion= obtenerEspacioLibreDato(clientes,C);
            cargarEstructuraDato(clientes,auxPosicion);
            getch();
            break;

        case 2:
            printf("Ingrese ID a modificar:");
            auxPosicion=buscarIdDato(clientes,C);
            modificarEstructuraDato(clientes,auxPosicion);
            getch();
            break;

        case 3:
            auxPosicion=obtenerEspacioLibreOtro(autos,A);
            cargarEstructuraOtro(clientes,autos,auxPosicion,C,A);
            getch();
            break;

        case 4:
            totalRecaudacion+=bajaEstructuraOtro(clientes,autos,C,A,gananciaMarca);
            getch();
            break;

        case 5:
            system("cls");
            mostrarTodo(clientes,autos,C,A,gananciaMarca,totalRecaudacion);
            break;

        case 6:
            salir=0;
            break;
        }
    }while(salir);

    return 0;
}
