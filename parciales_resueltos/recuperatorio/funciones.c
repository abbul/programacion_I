#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

int generar_archivo_filtrado (ArrayList* nuevaLista)
{
    FILE* archivo;
    ePersona* auxPersona;
    int salida=-1,i;

    archivo = fopen("out.csv","w");

    if(archivo!=NULL)
    {
        for(i=0; i<nuevaLista->len(nuevaLista);i++)
        {
            auxPersona= (ePersona*) nuevaLista->get(nuevaLista,i);
            fprintf(archivo,"%d,%s,%d,%d \n",auxPersona->id,auxPersona->nombre,auxPersona->edad,auxPersona->profesion);
        }

            salida=0;

         fclose(archivo);
    }


    return salida;
}

int menu()
{
    int respuesta;

    system("cls");

    printf("1- Cargar lista.\n");
    printf("2- Filtrar lista.\n");
    printf("3- Generar archivo con la lista filtrada.\n");
    printf("4- Salir\n");
    printf("Respuesta : ");

    scanf("%d",&respuesta);

    return respuesta;
}

int filtra_lista(void* empleado)
{
    int salida = 1;
    ePersona* aux;

    if(empleado != NULL)
    {
        aux = empleado;
        if(aux->edad > 30 && aux->profesion==4)
        {
            salida = 0;
        }
    }

    return salida;
}

ePersona* constructor_ePersona (int cantidad)
{
    ePersona* aux;

    aux = (ePersona*)malloc(sizeof(ePersona)* cantidad);

    return aux;
}

int parsear_archivo (ArrayList* lista)
{
    FILE* archivo;
    char nombreArchivo[200], auxNombre[200], auxProfesion[20],auxId[20],auxEdad[20];
    int salida=-1;

    ePersona* auxPersona;

    printf("Ingrese el nombre del archivo: ");
    fflush(stdin);
    gets(nombreArchivo);

    strcpy(nombreArchivo,"data.csv"); //SOLO PARA PROBAR MAS RAPIDO EL CODIGO; LUEGO COMENTAR!!!

    archivo = fopen(nombreArchivo,"r");

    if(archivo!=NULL)
    {

       // fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]",auxId,auxNombre,auxEdad,auxProfesion);

        while(!feof(archivo))
        {


            fflush(stdin);
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]",auxId,auxNombre,auxEdad,auxProfesion);

            auxPersona= constructor_ePersona(1);

            auxPersona->id= atoi(auxId);
            auxPersona->edad=atoi(auxEdad);
            auxPersona->profesion=atoi(auxProfesion);
            strcpy(auxPersona->nombre,auxNombre);


            lista->add(lista,auxPersona);

            salida=0;
        }
    }

    return salida;
}

int mostrar_clientes (ArrayList* lista)
{
    ePersona* auxCliente;
    int salida=-1,i;

    if(lista!=NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            auxCliente= (ePersona*) lista->get(lista,i);
            printf("NOMBRE: %s  , Edad: %d ID : %d Profesion:%d\n",auxCliente->nombre,auxCliente->edad,auxCliente->id,auxCliente->profesion);
            salida=0;
        }
    }

    return salida;
}
