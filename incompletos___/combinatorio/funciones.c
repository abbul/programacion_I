#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "funciones.h"
#include "ArrayList.h"
#define CANTIDAD 3

void showStruct(eCliente* atributos, int* posicion)
{
    int buffer,i;

    buffer= *posicion;

    for(i=0; i<buffer; i++)
    {
        printf("\n\n nombre: %s ,,  sexo: %s ,, Cantidad: %d \n\n",(atributos+i)->nombre,(atributos+i)->sexo,(atributos+i)->id);
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

void inicia_eCliente(eCliente* atributos)
{
    int i,j;
    for(i=0; i<CANTIDAD; i++)
    {
        strcpy( (atributos+i)->nombre,"N" );
        atributos->id=0;

        for(j=0; j<CANTIDAD; j++)
        {
            strcpy( (atributos+i)->sexo,"N");
        }
    }
}

int creaEspacio(eCliente* atributos)
{
    eCliente* aux=NULL;
    int salida=0;

    if(atributos==NULL)
    {
        atributos= malloc(sizeof(eCliente));
        inicia_eCliente(atributos);
        salida=1;
    }

    else
    {
        aux= (eCliente*) realloc(atributos,sizeof(eCliente)*10);
        if(aux!=NULL)
        {
            atributos=aux;
            salida=1;
        }
    }

    return salida;
}

int* cargarDato(eCliente* atributos,int* posicion)
{
    char mensaje[250];
    int buffer;

    buffer= *posicion;

    strcpy(mensaje,"Ingrese nombre: ");
    strcpy( (atributos+buffer)->nombre,solicitaString(mensaje,1,100));

    strcpy(mensaje,"Ingrese sexo: ");
    strcpy((atributos+buffer)->sexo,solicitaString(mensaje,1,100));

    strcpy(mensaje,"Ingrese Cantidad: ");
    (atributos+buffer)->id= solicitaInt(mensaje,1,100);

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

int combinatorio(eCliente* atributos)
{
    int i=0,contador=0;

    for(i=0; i<CANTIDAD; i++)
    {
        if( (atributos+i)->id >0 )
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

void setnombre(eCliente *atributos, int *num_atributo, char nombre[100])
{
    int j,posicion;

    posicion= num_atributo;

    j= (atributos+posicion)->id;

    strcpy( (atributos+posicion)->nombre,nombre);


}

void setsexo(eCliente *atributos, int *num_atributo, char sexo[100])
{
    int j,posicion;

    posicion= num_atributo;
    j= (atributos+posicion)->id;

    strcpy( (atributos+posicion)->sexo,sexo);
    atributos->id++;

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

int creaArchivoBinario(eCliente* atributos, int* posicion)
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
            fwrite(&atributos[i], sizeof(eCliente), 1, archivo);

        }
    }

    fclose(archivo);
}

int* leeArchivoBinario(eCliente* atributos, int* posicion)
{
    FILE* archivo;
    eCliente auxlista;
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
            cantidad= fread(&atributos[i], sizeof(eCliente), 1, archivo);
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

void leeArchivoCsv(ArrayList* this)
{
    FILE* archivo;
    char id[200];
    char nombre[200];
    char sexo[200];
    char numeroTelefono[200];
    char importe[200];
    char name_archivo[200];
    int contador=0, id_int,telefono_int, importe_int;
    char contenido_mensaje[250];
    char* mensaje=contenido_mensaje;
    eCliente* lista;
    eCliente aux;

    strcpy(mensaje,"Ingrese nombre del archivo: \n");
    strcpy( name_archivo,solicitaString(mensaje,1,50));

    archivo = fopen("clientes.csv","r");

    fscanf(archivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,sexo, numeroTelefono, importe);

    while(!feof(archivo))
    {
        fscanf(archivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,sexo, numeroTelefono, importe);

        lista = newCliente();

        id_int =atoi(id);
        telefono_int =atoi(numeroTelefono);
        importe_int =atoi(importe);

        aux.id=id_int;
        strcpy( aux.nombre,nombre);
        strcpy( aux.sexo,sexo);
        aux.numeroTelefono= telefono_int;
        aux.importe=importe_int;

        lista->id=aux.id;
        strcpy( lista->nombre,aux.nombre);
        strcpy( lista->sexo,aux.sexo);
        lista->numeroTelefono= aux.numeroTelefono;
        lista->importe=aux.importe;

        this->add(this, lista);
    }

    fclose(archivo);

}

void generaArchivoBin(ArrayList* this)
{
    FILE* archivo;
    eAbono* lista = newAbono();
    int i=0, buffer;

    archivo= fopen("abonos.bin","wb");

    if(archivo==NULL)
    {
        printf("ERROR al generar archivo!!!!!");
        getch();
    }

    else
    {
        for(i=0; i<this->len(this); i++)
        {
            lista = this->get(this, i);
            fseek(archivo, 0L, SEEK_END);
            fflush(stdin);
            fwrite(&lista, sizeof(eAbono), 1, archivo);
        }
    }

    fclose(archivo);

}

void generaArchivoCsv(ArrayList* this)
{
    eAbono* lista = newAbono();
    FILE* f;
    f= fopen("abonos.bin","wb");
    int i;

    if(this != NULL && lista != NULL)
    {
        if(f != NULL)
        {
            rewind(f);
            fprintf(f, "ID,TIPO,ID_CLIENTE,IMPORTE_FINAL\n");
            for(i=0; i<this->len(this); i++)
            {
                lista = this->get(this, i);
                fprintf(f, "%d,%d,%d,%d\n", lista->id, lista->tipo, lista->idCliente, lista->importeFinal);
            }
        }
    }
}

eCliente* newCliente()
{
    eCliente* aux = (eCliente*) malloc(sizeof(eCliente));

    return aux;
}

eAbono* newAbono()
{
    eAbono* aux = (eAbono*) malloc(sizeof(eAbono));

    return aux;
}

void mostrarUno(ArrayList* this)
{
    int i;
    eCliente* lista = newCliente();

    if(this != NULL && lista != NULL)
    {
        system("cls");
        if(this->isEmpty(this) == 1)
        {
            printf("La lista esta vacia.\n");
        }
        else
        {
            printf("Id Nombre              NumeroTelefono Importe       \n\n");
            for(i=0; i<this->len(this); i++)
            {
                lista = (eCliente*)this->get(this, i);
                mostrarUno(lista);
            }
        }
        printf("\n\n");

    }
}

void mostrar(ArrayList* this)
{
    eCliente* lista = newCliente();
    int i;

     for(i=0; i<this->len(this); i++)
    {
        lista = (eCliente*)this->get(this, i);
        printf("%d -- %s \n",lista->id,lista->nombre);
    }
}

void ordenar(ArrayList* this)
{
    this->sort(this,compararAbonos,1);

    printf("lista ordenada!!\n\n");
    system("pause");
}

int validar_num(char* opcion)
{
    int i, flag = 0, size;

    size = strlen(opcion);

    for(i=0; i<size; i++)
    {
        if(*(opcion+i) < 48  || *(opcion+i) > 57)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}
