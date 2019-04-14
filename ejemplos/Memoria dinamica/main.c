#include <stdio.h>
#include <stdlib.h>
#define T 3
typedef struct
{
    int g;
    char a,c,b;
} a;
int main()
{
    int* p;
    int* auxP;
    int i;


    p= (int*) malloc(sizeof(int)*T);

    if(p!=NULL)
    {
        for(i=0; i<T; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", p+i);
        }

        for(i=0; i<T; i++)
        {
            printf("%d\n", *(p+i));
        }

        printf("Reasigno memoria\n");
        auxP = realloc(p,sizeof(int)*(T+2));
        if(auxP!=NULL)
        {
            p = auxP;

            for(i=T; i<T+2; i++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", p+i);
            }
            for(i=0; i<T+2; i++)
            {
                printf("%d\n", *(p+i));
            }

            auxP = realloc(p,sizeof(int)*(T-1));
            if(auxP!=NULL)
            {
                p = auxP;

                for(i=0; i<T-1; i++)
                {
                    printf("%d\n", *(p+i));
                }
            }


        }









    }
    else
    {
        printf("No hay memoria disponible");
    }





    return 0;
}
