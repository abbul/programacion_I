#ifndef BANCOS_H_INCLUDED
#define BANCOS_H_INCLUDED

typedef struct
{
    int cedulaTitular;
    char nombreTitular[50];
    char apellidoTitular[50];
    int idCliente; // PK
    char nombreBanco[50];
    int numeroCuenta;

}eBanco;

int baja_logica_banco (ArrayList*,ArrayList*);
int lee_archivo_banco(ArrayList*);
int buscar_idCliente_en_bancos(ArrayList*,int); // busca el ID y retorna la posicion donde esta ó -1 sino existe
void modificar_banco(ArrayList*,ArrayList*);
void mostrar_bancos(ArrayList*, ArrayList*,int);
void mostrar_un_banco(eBanco* unBanco,int);
eBanco cargar_banco (ArrayList*);
eBanco* nuevo_banco(ArrayList*,ArrayList*);

#endif // BANCOS_H_INCLUDED
