#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char total[50];
    char buffer[1000];
    char aux;

    printf("Ingrese nombre \n");
    fflush(stdin);
    scanf("%[^\n]",&buffer);

    while(strlen(buffer)>19 || strlen(buffer)<3)
    {
        printf("ERROR; Reingrese nombre \n");
        fflush(stdin);
        scanf("%[^\n]",&buffer);
    }

    strcpy(nombre,buffer);
    aux=nombre[0];
    aux= toupper(aux);
    nombre[0]=aux;

    printf("Ingrese apellido \n");
    fflush(stdin);
    scanf("%[^\n]",&buffer);

    while(strlen(buffer)>19 || strlen(buffer)<3)
    {
        printf("ERROR; Reingrese apellido \n");
        fflush(stdin);
        scanf("%[^\n]",&buffer);
    }

    strcpy(apellido,buffer);
    aux=apellido[0];
    aux= toupper(aux);
    apellido[0]=aux;

    strcat(total,apellido);
    strcat(total," ");
    strcat(total,nombre);

    printf("%s   %c\n",total);

    return 0;
}
