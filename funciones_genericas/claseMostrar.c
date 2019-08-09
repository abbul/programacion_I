#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "claseMostrar.h"

int menu()
{
    int opcion;
    int flag;

    system("cls");
    printf("\n***MENU PRINCIPAL***\n\n\n");
    printf("1- ALTA Cliente \n");
    printf("2- BAJA Cliente \n");
    printf("3- MODIFICAR Cliente \n");
    printf("4- MOSTRAR Cliente \n");
    printf("5- MOSTRAR Lista Cliente \n");
    printf("6- Comprar Comida \n");
    printf("7- Eliminar Comida \n");
    printf("8- Mostrar Compra \n");
    printf("9- Salir\n");
    printf("\n\nIngrese opcion: ");

    scanf("%d", &opcion);

    flag=validaRangoInt(opcion,1,7);

    return (flag == 1) ? opcion : 0;
}

int menuDos()
{
    int opcion;
    system("cls");
    printf("\n***MENU DOS***\n\n\n");
    printf("1- Alta \n");
    printf("2- Modificacion \n");
    printf("3- Baja \n");
    printf("4- Nuevo alquiler \n");
    printf("5- Fin alquiler \n");
    printf("6- Mostrar\n");
    printf("7- Salir\n");
    printf("\n\nIngrese opcion: ");

    scanf("%d", &opcion);
    opcion=validaInt(opcion,1,7);

    return opcion;

}

int menuTres()
{
    int opcion;
    system("cls");
    printf("\n***MENU TRES***\n\n\n");
    printf("1- Alta \n");
    printf("2- Modificacion \n");
    printf("3- Baja \n");
    printf("4- Nuevo alquiler \n");
    printf("5- Fin alquiler \n");
    printf("6- Mostrar\n");
    printf("7- Salir\n");
    printf("\n\nIngrese opcion: ");

    scanf("%d", &opcion);
    opcion=validaInt(opcion,1,7);

    return opcion;

}
