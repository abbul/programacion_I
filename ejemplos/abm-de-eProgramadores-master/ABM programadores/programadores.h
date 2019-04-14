#ifndef PROGRAMADORES_H_INCLUDED
#define PROGRAMADORES_H_INCLUDED

typedef struct{

    int idProyecto;
    char descripcion[100];
}
eProyecto;

typedef struct{

  int idProyecto;
  int id;
  int horasTrabajadas;
}
eProgProy;

typedef struct{

    int id;
    char nombre[20];
    char categoria[20];
    int estado;
    int sueldo;
}
eProgramador;

//a = Senior
//b = SemiSenior
//c = Junior

int menu();
eProgramador iniciaEstructura(eProgramador lista[], int tam);
void mostrarEstrutura(eProgramador lista);
void mostrarArrayEstrutura(eProgramador lista[], int tam);
eProgramador cargarEstructura(eProgramador lista[],int posicion);
int obtenerEspacioLibre(eProgramador lista[], int tam);

void modificarEstructura(eProgramador lista[], int posicion);
int buscarId(eProgramador lista[], int tam);
void eliminarEstructura(eProgramador lista[],int posicion);

#endif // PROGRAMADORES_H_INCLUDED
