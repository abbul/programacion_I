#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "funciones.h"
#include "ArrayList.h"
#define PERSONAL 0
#define FAMILIAR 1
#define COORPORATIVO 2

int main()
{
    ArrayList* clientes = al_newArrayList();
    ArrayList* abonos = al_newArrayList();
    char* mensaje;
    char contenido_mensaje[250];
    int buffer, respuesta;
    //eCliente *clientes = malloc(sizeof(eCliente)*10);

    leeArchivoCsv(clientes);
    cargarAbono(clientes,abonos);

    do
    {
        strcpy(mensaje,"Tipo abono\n\n PERSONAL->0 FAMILIAR->1 COORPORATIVO->2 \n");
        buffer = solicitaInt(mensaje,0,2);

        strcpy(mensaje,"Ingrese ID del cliente : \n");
        buffer = solicitaInt(mensaje,1,10);

        strcpy(mensaje,"Desea Ingresar otro Titulo?");
        respuesta= si_o_no(mensaje);

    }while(respuesta==1);

    // PARTE 3
    mostrar(clientes);

    // PARTE 4
    generaArchivoBin(abonos);
    generaArchivoCsv(abonos);


    return 0;
}

