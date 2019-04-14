#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct
{
    int flag, id,datoInt1;
    char nombre[50],datoChar1[50],datoChar2[50];
}eDato;


int obtenerEspacioLibre(eDato lista[], int tam);
int buscarElementoInt(eDato lista[], int tam);
int buscarElementoCadena(eDato lista[], int tam);
int validaInt(int numero, int minimoInt, int maximoInt);
float validaFloat(float numero,float minimoFloat, float maximoFloat);
eDato iniciaEstructura(eDato lista[], int tam);
void mostrarEstrutura(eDato lista);
void mostrarArrayEstrutura(eDato lista[], int tam);
eDato modificarEstructura(eDato lista[], int posicion);
eDato cargarEstructura(eDato lista[],int posicion);
eDato eliminarEstructura(eDato lista[],int posicion);
eDato altaEstructura(eDato lista[],int tam);
eDato bajaEstructura(eDato lista[],int tam);
void ordenaEstructura(eDato lista[],int tam);

#endif // FUNCIONES_H_INCLUDED
