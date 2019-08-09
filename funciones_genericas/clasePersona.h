#ifndef CLASEPERSONA_H_INCLUDED
#define CLASEPERSONA_H_INCLUDED

#include "ArrayList.h"

typedef struct
{
    char id[100];
    char estado[100];
    char tipo[100];
    char nombre[100];
    char apellido[100];
    char dni[100];

}ePersona;

void altaPersona(ArrayList* listaPersona);
void bajaPersona(ArrayList* listaPersona,char* dni);
ePersona* buscarPorDNI(ArrayList* listaPersona, char* dni);
int compararPersonas(ePersona* p1, ePersona* p2);
void mostrarPersona(ePersona* persona);


#endif // CLASEPERSONA_H_INCLUDED
