#include <stdio.h>
#include <stdlib.h>
#define T 3
typedef struct
{
    int legajo;
    char nombre[30];
} eAlumno;

eAlumno* newAlumno(void);
eAlumno* newAlumnoParametros(int, char[]);
void mostrarAlumno(eAlumno*);
void liberarAlumno(eAlumno*);
int main()
{
   eAlumno* listaAlumnos[T];
   eAlumno* unAlumno;

   int leg;
   char nom[30];
   int i;

   for(i=0; i<T; i++)
   {
       printf("Ingrese legajo: ");
       scanf("%d", &leg);
       printf("Ingrese nombre: ");
       fflush(stdin);
       gets(nom);

       unAlumno = newAlumnoParametros(leg,nom);

       listaAlumnos[i] = unAlumno;

   }


   for(i=0; i<T; i++)
   {
       mostrarAlumno(listaAlumnos[i]);
   }


liberarAlumno(unAlumno);


   return 0;
}

eAlumno* newAlumno(void)
{
    eAlumno* pAlumno;


    pAlumno = (eAlumno*) malloc(sizeof(eAlumno));

    return pAlumno;
}

eAlumno* newAlumnoParametros(int legajo, char nombre[])
{
    eAlumno* alu;

    alu = newAlumno();

    alu->legajo=legajo;
    strcpy(alu->nombre,nombre);

    return alu;
}
void mostrarAlumno(eAlumno* this)
{
     printf("%d--%s\n", this->legajo, this->nombre);
}

void liberarAlumno(eAlumno* a)
{
    if(a!=NULL)
    {
        free(a);
    }
}
