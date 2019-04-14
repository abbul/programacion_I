#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANTIDAD 3

typedef struct
{
    int id;
    char nombre[100];
    char sexo[10];
    int numeroTelefono;
    int importe;

} eCliente;

typedef struct
{
    int id;
    int tipo;
    int idCliente;
    int importeFinal;

} eAbono;

int* cargarDato(eCliente* atributos,int* posicion);
char* solicitaString(char* mensaje,int minimo,int maximo);
int solicitaInt(char* mensaje,int minimo,int maximo);
int validLength(char opcion[],int minimo,int maximo);
eCliente* newCliente();
eAbono* newAbono();
char* getNombre(eCliente* lista);
char* getImporte(eCliente* lista);
#endif // FUNCIONES_H_INCLUDED
