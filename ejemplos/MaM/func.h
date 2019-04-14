#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[20];
}eAlumno;

typedef struct{
    int id;
    char descripcion[20];
}eMateria;

typedef struct{
    int legajo;
    int idMateria;
}eInscripcion;

void mostarAlumnoconMaterias(eAlumno listaAlumno[], eMateria listaMateria[], eInscripcion listaInscripcion[], int z, int x, int c);
void mostarMateriaConCantidad(eMateria listaMateria[], eInscripcion listaInscripcion[], int x, int c);

#endif // FUNC_H_INCLUDED
