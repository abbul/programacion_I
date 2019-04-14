#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "funciones.h"
#include "ArrayList.h"
#define CANTIDAD 3

void showStruct(eDato* atributos, int* posicion)
{
    int buffer,i;

     buffer= *posicion;

       for(i=0;i<buffer;i++)
    {
         printf("\n\n Titulo: %s ,,  Variable: %s ,, Cantidad: %d \n\n",(atributos+i)->titulo,(atributos+i)->variable,(atributos+i)->cantidad_variables);
    }
}

int si_o_no (char* mensaje)
{
    int salida,flag;
    char var[250];
    char* puntero;

    puntero = var;

    do
    {
        flag=1;
        printf("\n %s \n",mensaje);
        fflush(stdin);
        gets(puntero);

        if(strlen(puntero)==1)
        {
            if( isdigit(puntero[0]) )
            {
                system("cls");
                printf("ERROR; Solo ingresar letras.");
                getch();
                flag=0;
            }
            else
            {
                if( strcmpi(puntero,"s")==0)
                {
                    salida=1;
                }
                else if( strcmpi(puntero,"n")==0 )
                {
                    salida=0;
                }
                else
                {
                    system("cls");
                    printf("ERROR; Solo con S o N");
                    getch();
                    flag=0;
                }
            }
        }
        else
        {
            system("cls");
            printf("ERROR; Responda solo con una letra--> S ó N");
            getch();
            flag=0;
        }
    }
    while(flag==0);

    return salida;
}

void inicia_eDato(eDato* atributos)
{
    int i,j;
    for(i=0; i<CANTIDAD; i++)
    {
        strcpy( (atributos+i)->titulo,"NADA" );
        atributos->cantidad_variables=0;

        for(j=0; j<CANTIDAD; j++)
        {
            strcpy( (atributos+i)->variable[j],"NADA");
        }
    }
}

int creaEspacio(eDato* atributos)
{
    eDato* aux=NULL;
    int salida=0;

    if(atributos==NULL)
    {
        atributos= malloc(sizeof(eDato));
        inicia_eDato(atributos);
        salida=1;
    }

    else
    {
        aux= (eDato*) realloc(atributos,sizeof(eDato)*10);
        if(aux!=NULL)
        {
            atributos=aux;
            salida=1;
        }
    }

    return salida;
}

int* cargarDato(eDato* atributos,int* posicion)
{
    char mensaje[250];
    int buffer;

    buffer= *posicion;

    strcpy(mensaje,"Ingrese Titulo: ");
    strcpy( (atributos+buffer)->titulo,solicitaString(mensaje,1,100));

    strcpy(mensaje,"Ingrese variable: ");
    strcpy((atributos+buffer)->variable,solicitaString(mensaje,1,100));

    strcpy(mensaje,"Ingrese Cantidad: ");
    (atributos+buffer)->cantidad_variables= solicitaInt(mensaje,1,100);

    return posicion;
}

char* solicitaString(char* mensaje,int minimo,int maximo)
{
    int salida, i;
    char var[250];
    char* puntero;

    puntero = var;

    do
    {
        salida=1;
        printf("\n %s \n",mensaje);
        fflush(stdin);
        gets(puntero);

        if(strlen(puntero)>=minimo && strlen(puntero)<=maximo)
        {
            for(i=0; i<strlen(puntero); i++)
            {
                if( isdigit(puntero[i]) )
                {
                    system("cls");
                    printf("ERROR; Solo ingresar letras.");
                    getch();
                    salida=0;
                    break;
                }
            }
        }
        else
        {
            system("cls");
            printf("ERROR; Excede la cantidad de caracteres.");
            getch();
            salida=0;
        }
    }
    while(salida==0);

    return puntero;
}

int combinatorio(eDato* atributos)
{
    int i=0,contador=0;

    for(i=0; i<CANTIDAD; i++)
    {
        if( (atributos+i)->cantidad_variables >0 )
        {
            contador++;
        }
    }
    return contador;
}

int solicitaInt(char* mensaje,int minimo,int maximo)
{
    int salida, i,buffer;
    char var[250];
    char* puntero;

    puntero = var;

    do
    {
        salida=1;
        printf("\n %s \n",mensaje);
        fflush(stdin);
        gets(puntero);

        for(i=0; i<strlen(puntero); i++)
        {
            if( !isdigit(puntero[i]))
            {
                system("cls");
                printf("ERROR; Solo ingresar numeros enteros.");
                getch();
                salida=0;
                break;
            }
        }

        if(salida==1)
        {
            buffer= atoi(puntero);

            if(minimo>buffer && buffer>maximo)
            {
                salida=0;
            }
        }
    }
    while(salida==0);

    return buffer;
}

void setTitulo(eDato *atributos, int *num_atributo, char titulo[100])
{
    int j,posicion;

    posicion= num_atributo;

    j= (atributos+posicion)->cantidad_variables;

    strcpy( (atributos+posicion)->titulo,titulo);


}

void setVariable(eDato *atributos, int *num_atributo, char variable[100])
{
    int j,posicion;

    posicion= num_atributo;
    j= (atributos+posicion)->cantidad_variables;

    strcpy( (atributos+posicion)->variable[j],variable);
    atributos->cantidad_variables++;

}

int validLength(char opcion[],int minimo,int maximo)
{
    int salida=0;

    if( strlen(opcion)>minimo &&  strlen(opcion)<maximo)
    {
        salida=1;
    }

    return salida;
}

int creaArchivoBinario(eDato* atributos, int* posicion)
{
    FILE* archivo;
    int i=0, buffer;

    buffer= *posicion;

    archivo= fopen("prueba.bin","wb");

    if(archivo==NULL)
    {
        printf("ERROR al generar archivo!!!!!");
        getch();
    }

    else
    {
        for(i=0; i<buffer; i++)
        {
            fseek(archivo, 0L, SEEK_END);
            fflush(stdin);
            fwrite(&atributos[i], sizeof(eDato), 1, archivo);

        }
    }

    fclose(archivo);
}

int* leeArchivoBinario(eDato* atributos, int* posicion)
{
    FILE* archivo;
    eDato auxlista;
    int i=0,cantidad;

    archivo= fopen("prueba.bin","rb");

    if(archivo==NULL)
    {
        archivo= fopen("prueba.bin","wb");

        if(archivo==NULL)
        {
            printf("ERROR en archivo!!!!!");
            getch();
        }
    }

    else
    {
        rewind(archivo);
        i=0;
        while(!feof(archivo))
        {
            fflush(stdin);
            cantidad= fread(&atributos[i], sizeof(eDato), 1, archivo);
            //lista[i]=auxlista;
            i++;
            if(cantidad!=1)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro");
					break;
                }
            }
        }

        *posicion=(*posicion)+(i-1);
    }
    fclose(archivo);
}


void prueba()
{
    printf("\n\n---->PASOOO<----\n\n");
    getch();
}
