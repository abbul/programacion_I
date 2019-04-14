#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int estado, id , dni;
    char nombre[50], apellido[50];
}eDato;


int menu();
int obtenerEspacioLibre(eDato lista[], int tam); // devuelve POSICION
int buscarId(eDato lista[], int tam);   // devuelve POSICION
int buscarNombre(eDato lista[], int tam);   // devuelve POSICION
int validaInt(int numero, int minimoInt, int maximoInt); // devuelve NUMERO ENTERO
float validaFloat(float numero,float minimoFloat, float maximoFloat); // devuelve NUMERO FLOAT
char* validaCadena(char cadena[],int minimo,int maximo); // devuelve NOMBRE
void iniciaEstructura(eDato lista[], int tam); //devuelve ESTRUCTURA
void mostrarEstrutura(eDato lista); // devuelve NADA
void mostrarArrayEstrutura(eDato lista[], int tam); // devuelve NADA
void modificarEstructura(eDato lista[], int posicion); // devuelve ESTRUCTURA
void cargarEstructura(eDato lista[],int posicion); //DEVUELVE ESTRUCTURA
void eliminarEstructura(eDato lista[],int posicion); //DEVUELVE ESTRUCTURA
void altaEstructura(eDato lista[],int tam); //DEVUELVE ESTRUCTURA
void bajaEstructura(eDato lista[],int tam); //DEVUELVE ESTRUCTURA
void ordenaEstructura(eDato lista[],int tam); //DEVUELVE NADA
void cargaAutomatica(eDato lista[],int tam);

#endif // FUNCIONES_H_INCLUDED
