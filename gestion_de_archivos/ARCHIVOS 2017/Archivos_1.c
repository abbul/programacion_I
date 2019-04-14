#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* miArchivo=NULL;

    char palabra[50]="por defecto";
    int numero=123;



    miArchivo = fopen("prueba.txt","w");//PATH

    fprintf(miArchivo,"%d",numero);

    fclose(miArchivo);



   miArchivo = fopen("prueba.txt","r");
    if(miArchivo==NULL)
    {
        printf("Archivo no encontrado!!!");
    }
    else
    {
       fgets(palabra,50,miArchivo);
       fclose(miArchivo);
       puts(palabra);
    }

}






