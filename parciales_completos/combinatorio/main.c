#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "funciones.h"
#include "ArrayList.h"
#define CANTIDAD 3

int main()
{
    int cantidad_de_atributos=0;
    int *num_atributo= &cantidad_de_atributos;
    int salida=0;
    int i;
    int respuesta;
    char* mensaje;
    char contenido_mensaje[250];
    char pru[250];
    eDato *atributos = malloc(sizeof(eDato)*10);
    ArrayList* lista = al_newArrayList();

    mensaje = contenido_mensaje;

    leeArchivoBinario(atributos,num_atributo);

    do
    {
        cargarDato(atributos,num_atributo);
        *num_atributo+=1;

        strcpy(contenido_mensaje,"Desea Ingresar otro Titulo?");
        respuesta= si_o_no(mensaje);

    }while(respuesta==1);

    showStruct(atributos,num_atributo);

   creaArchivoBinario(atributos,num_atributo);

    return 0;
}

