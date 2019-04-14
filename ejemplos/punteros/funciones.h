#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char modelo[20];
    int nucleos;
}eProcesador;

typedef struct
{
    char marca[20];
    eProcesador procesador;
    int ram;
    float precio;
}eNotebook;

void swap2 (int* punt1, int* punt2);
void muestra(int* puntero[], int tam);
void carga(int* puntero[], int tam);
void mostrarNotebook(eNotebook note);
void iniciaNotebook(eNotebook* maquina);
void cargarNotebook(eNotebook* maquina);
void cargarAutomaticaNotebook();

#endif // FUNCIONES_H_INCLUDED
