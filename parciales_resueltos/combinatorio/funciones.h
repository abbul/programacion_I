#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANTIDAD 3

typedef struct
{

    char titulo[100];
    char variable[100];
    int cantidad_variables;

} eDato;

int* cargarDato(eDato* atributos,int* posicion);
char* solicitaString(char* mensaje,int minimo,int maximo);
int solicitaInt(char* mensaje,int minimo,int maximo);
int validLength(char opcion[],int minimo,int maximo);

#endif // FUNCIONES_H_INCLUDED
