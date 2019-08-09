#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "claseArchivo.h"
#include "claseMostrar.h"
#include "claseNumero.h"
#include "claseObjeto.h"
#include "clasePersona.h"
#include "ArrayList.h"
#include "ClaseLeer.h"
#define CANTIDAD 10
#define CONSTANTE 15

int main()
{
    int salir=1;
    char* bufferPuntero;
    char buffer[100];
    ArrayList* listaDepersonas = al_newArrayList();
    ePersona* persona;

    // CARGAMOS EL PUNTERO
    bufferPuntero=&buffer;

    do
    {
        switch(menu())
        {
            case 1:
                altaPersona(listaDepersonas);
                getch();
                break;

            case 2:
                leerCadena("Ingrese DNI:",bufferPuntero,1,10);
                bajaPersona(listaDepersonas,buffer);
                getch();
                break;

            case 3:
                printf("Opcion 3:");
                getch();
                break;

            case 4:
                leerCadena("Ingrese DNI:",bufferPuntero,1,10);
                persona= buscarPorDNI(listaDepersonas,buffer);
                mostrarPersona(persona);
                getch();
                break;

            case 5:
                mostrarListaPersona(listaDepersonas);
                getch();
                break;

            case 6:
                printf("Opcion 6:");
                getch();
                break;
            case 9:
                printf("Hasta Luego!!!");
                getch();
                salir=0;
                break;
            default:
                printf("**** ERROR; Opcion Invalida ***");
                getch();
                break;
        }

    }while(salir != 0);

    return 0;
}
