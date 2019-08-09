#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClaseLeer.h"
#include "claseNumero.h"


void leerCadena(char mensaje[], char* puntero, int min, int max)
{
    int flag;

    do{

        printf("%s",mensaje);
        fflush(stdin);
        scanf("%[^\n]", puntero);

        if( strlen(puntero) >= min && strlen(puntero)<=max )
        {
            flag=0;
        }else{
            flag=-1;
        }
    }while(flag == -1);

}

int leerInt()
{
    char cadena[100];
    int flag=-1;

    do{

        fflush(stdin);
        scanf("%[^\n]", cadena);
        validaInt(cadena);

        if(validaInt(cadena) == 0)
        {
            flag =0;

        }else{
            printf("ERROR; Solo debe contener INT");
        }


    }while(flag == -1);



    return cadena;
}

char* leerLetras()
{
    char cadena[100];
    char* salida;
    int flag=-1;

    do{

        fflush(stdin);
        scanf("%[^\n]", cadena);
        validaInt(cadena);

        if(validaInt(cadena) == 0)
        {
            flag =0;

        }else{
            printf("ERROR; Solo debe contener INT");
        }


    }while(flag == -1);

    salida = cadena;

    return salida;
}
