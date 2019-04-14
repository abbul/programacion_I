#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void mostarAlumnoconMaterias(eAlumno listaAlumno[], eMateria listaMateria[], eInscripcion listaInscripcion[], int z, int x, int c)
{
    int i;
    int j;
    int k;

    for(i=0;i<z;i++)
    {
        printf("%s\n",listaAlumno[i].nombre);
        for(j=0;j<x;j++)
        {
              if(listaAlumno[i].legajo==listaInscripcion[j].legajo)
            {
                  for(k=0;k<c;k++)
                  {
                      if(listaInscripcion[j].idMateria==listaMateria[k].id)
                    {
                        printf("\t materia:%s \n",listaMateria[k].descripcion);
                        break;
                    }
                  }

            }
        }

    }

}

void mostarMateriaConCantidad(eMateria listaMateria[], eInscripcion listaInscripcion[], int x, int c)

{
    int i, j;
    int uno=0, dos=0, tres=0, cuatro=0, cinco=0;

    for(i=0;i<c;i++)
    {
         if(listaInscripcion[i].idMateria==1)
        {
            uno++;
        }
           if(listaInscripcion[i].idMateria==2)
        {
            dos++;
        }
            if(listaInscripcion[i].idMateria==3)
        {
            tres++;
        }
            if(listaInscripcion[i].idMateria==4)
        {
            cuatro++;
        }
            if(listaInscripcion[i].idMateria==5)
        {
            cinco++;
        }
    }

    printf(" \nProgamacion: %d \n Matematicas: %d \n Quimica: %d \n Fisica: %d \n Electronica: %d",uno,dos,tres,cuatro,cinco);
}

void maximoInscriptos(eMateria listaMateria[], eInscripcion listaInscripcion[], int x, int c)

{
     int i, j,acum=0;
    int uno=0, dos=0, tres=0, cuatro=0, cinco=0;

    for(i=0;i<c;i++)
    {
         if(listaInscripcion[i].idMateria==1)
        {
            uno++;
        }
           if(listaInscripcion[i].idMateria==2)
        {
            dos++;
        }
            if(listaInscripcion[i].idMateria==3)
        {
            tres++;
        }
            if(listaInscripcion[i].idMateria==4)
        {
            cuatro++;
        }
            if(listaInscripcion[i].idMateria==5)
        {
            cinco++;
        }
    }

        if(aum<uno)
        {
            acum=uno;
        }

    printf("%s:%d",listaMateria[i].descripcion,acum);
}
