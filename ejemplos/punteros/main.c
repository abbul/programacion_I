#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define X 3

int main()
{
   eNotebook lista;

   cargarNotebook(&lista);
   mostrarNotebook(lista);

    return 0;
}

