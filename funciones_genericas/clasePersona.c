#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "clasePersona.h"
#include "claseNumero.h"
#include "ArrayList.h"


void altaPersona(ArrayList* listaPersona)
{
    char* puntero;
    char id[100];
    char nombre[100];
    char apellido[100];
    char dni[100];
    ePersona* persona = (ePersona*) malloc(sizeof(ePersona));

    // CARGAMOS LOS DATOS
    puntero = &nombre;
    leerCadena("Ingrese Nombre: ",puntero,1,20);
    puntero = &apellido;
    leerCadena("Ingrese Apellido: ",puntero,1,20);
    puntero = &dni;
    leerCadena("Ingrese DNI: ",puntero,1,20);

    //OBTENEMOS LA CANTIDAD DE VALORES QUE HAY EN LA LISTA
    // LUEGO LOS CASTEAMOS A CHAR[], LO GUARDAMOS EN: id
    itoa(listaPersona->len(listaPersona),id,10);

    // PASAMOS LOS DATOS A UNA PERSONA
    strcpy(persona->id, id);
    strcpy(persona->nombre, nombre);
    strcpy(persona->apellido, apellido);
    strcpy(persona->dni, dni);

    // PASAMOS LA PERSONA A LA LISTA
    listaPersona->add(listaPersona,persona);

    printf("Alta Exitosa!!");
}

void bajaPersona(ArrayList* listaPersona,char* dni)
{
    ePersona* persona;
    int i;
    int posicion;

    persona = buscarPorDNI(listaPersona,dni);

    if(persona != NULL)
    {
       posicion = (int)persona->id;
       listaPersona->remove(listaPersona,posicion);

    }
    else
    {
        printf("ERROR; DNI no existe la lista");
    }
}

ePersona* buscarPorDNI(ArrayList* listaPersona, char* dni)
{
    ePersona* persona;
    int tamLista;
    int i;
    int flag=-1;

    if(listaPersona != NULL && dni != NULL)
    {

        tamLista = listaPersona->len(listaPersona);

        for(i=0;i<tamLista;i++)
        {
           persona = (ePersona*) listaPersona->get(listaPersona,i);

           if( strcmpi(persona->dni,dni) == 0 )
           {
               flag=0;
               break;
           }
        }

    }
    else
    {

        printf("ERROR; Valores en NULL ");
    }

    return (flag==0) ? persona : NULL;

}

int compararPersonas(ePersona* p1, ePersona* p2)
{
    int salida=-1;

    if(p1->dni == p2->dni )
    {
        salida =0;
    }

    return salida;

}

void mostrarPersona(ePersona* persona)
{
    if( persona != NULL)
    {
        printf("ID: %s -- NOMBRE: %s -- APELLIDO: %s -- DNI: %s\n",persona->id,persona->nombre,persona->apellido,persona->dni);
    }
    else{
         printf("\t\t ERROR; el objecto PERSONA es nulo");
    }

}

void mostrarListaPersona(ArrayList* listaPersona)
{
    ePersona* persona;
    int sizeLista;
    int i;

    if( listaPersona != NULL )
    {
        sizeLista = listaPersona->len(listaPersona);

        for(i = 0; i<sizeLista ; i++)
        {
            persona = (ePersona*) listaPersona->get(listaPersona,i);
            mostrarPersona(persona);
        }
    }
    else{
         printf("\t\t ERROR; list of object PERSONA is null");
    }

}
