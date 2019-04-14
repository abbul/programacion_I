#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    char descripcion[100];
    int prioridad;
    int horas;

} eCliente;

int divide_lista(ArrayList* lista,ArrayList* aux,int condicion);
int baja_logica_cliente(ArrayList*);
int menu(void);
int valida_int(int,int, int);
float valida_float(float,float, float);
char* valida_cadena(char[],int,int);
eCliente* nuevo_cliente(ArrayList*);
eCliente cargar_cliente(ArrayList*);
void mostrar_un_cliente(eCliente*); // INT es: condicion(1) los activos ó condicion(0) inactivos
void mostrar_clientes(ArrayList*); // INT es: condicion(1) los activos ó condicion(0) inactivos
int busca_tarea(ArrayList*,int); // busca el ID y retorna la posicion donde esta ó -1 sino existe
int lee_archivo_cliente(ArrayList* lista);
int ordena_por_hora(ArrayList*);

#endif // CLIENTES_H_INCLUDED
