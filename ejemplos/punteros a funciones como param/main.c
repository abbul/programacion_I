#include <stdio.h>
#include <stdlib.h>

int funcion(int);
int otraFuncion(int);

int main()
{
    int (*pFunc[2]) (int);
    int i;

    int valor;
    (pFunc[0])=funcion;
    (pFunc[1]) = otraFuncion;

    for(i=0; i<2; i++)
    {
        valor = pFunc[i](5);
        printf("El valor es: %d\n", valor);
    }


   // printf("el valor luego de la llamada es: %d", valor);





   // printf("\nel valor luego de incrementar: %d", valor);
    return 0;
}




int funcion(int a)
{


    return (a+5);
}

int otraFuncion(int b)
{
    b++;
    return b;
}


/*
int funcion(int);
void llamaFuncion(int (*pFunc) (int));

int main()
{



   llamaFuncion(funcion);




    return 0;
}


void llamaFuncion(int (*pFunc) (int))
{
    int valor;

    valor = pFunc(5);

    printf("Valor en la funcion es: %d", valor);
}

int funcion(int a)
{
    printf("El valor de a es: %d\n", a);

    return (a+5);
}
*/
