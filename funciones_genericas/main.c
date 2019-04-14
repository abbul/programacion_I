#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "otroFunciones.h"
#define X 7
#define C 7

int main()
{
    int salir=1;
    int auxPosicion;

    eDato clientes[X];
    eOtro alquileres[C];

    iniciaEstructura(clientes,X);
    iniciaEstructuraOtro(alquileres,C);
    cargaAutomatica(clientes,X);
    cargaAutomaticaAlquileres(alquileres,C);

    do
    {
        switch(menu())

        {
        case 1:
            auxPosicion= obtenerEspacioLibre(clientes,X);
            cargarEstructura(clientes,auxPosicion);

            getch();
            break;

        case 2:
            printf("Ingrese ID a modificar:");
            auxPosicion=buscarId(clientes,X);
            modificarEstructura(clientes,auxPosicion);
            getch();
            break;

        case 3:
            bajaEstructura(clientes,X);
            getch();
            break;

        case 4:
            auxPosicion=obtenerEspacioLibreOtro(alquileres,C);
            cargarAlquiler(alquileres,clientes,auxPosicion,X);
            getch();
            break;

        case 5:
            // auxPosicion=buscarContrato(clientes,C);
             bajaAlquiler(alquileres,C);
            getch();
            break;

        case 6:
            mostrarArrayEstrutura(clientes,X);
            // muestraTodo(clientes,alquileres,X,C);
             getch();
            break;
        case 7:
           salir=0;
            break;

        }


    }while(salir);

    return 0;
}
