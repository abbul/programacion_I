#include <stdio.h>
#include <stdlib.h>

void grafica(char texto[], int tam);

int main()
{
    int a,b,c;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    grafica("entre 10 y 18 \n",a);
    grafica("entre 18 y 30 \n",b);
    grafica("entre 30 y 45 \n",c);

    return 0;
}

void grafica(char texto[],int tam)
{
    int i;


    for(i=0;i<tam;i++)
    {
        printf("*");
    }
    printf("\n%s",texto);
}
