#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    eAlumno alumnos[]={{1, "Jose"}, {3, "Pakita"}, {4, "Juan"}, {7, "Luis"}, {10, "Ana"}, {9, "Silvia"}, {8, "Maria"}, {15, "Sofia"}, {18, "Martin"}, {11, "Dalia"}};
    eMateria materias[]={{1, "Progamacion"}, {2, "Matematicas"},{3, "Quimica"}, {4, "Fisica"}, {5, "Electronica"}};
    eInscripcion inscripciones[]={{1,2}, {1,3}, {3,2}, {4,4}, {3,5}, {3,1}, {4,1}, {1,1}, {8,1}, {9,3}, {10,2}, {10,5}, {10, 3}, {8, 1}, {1,2}};

    // mostarAlumnoconMaterias(alumnos,materias,inscripciones,10,5,15);

    mostarMateriaConCantidad(materias,inscripciones,5,15);


    return 0;
}
