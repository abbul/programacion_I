#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* miArchivo;


    char palabra[50];

    miArchivo = fopen("prueba.txt","w");

    fprintf(miArchivo,"hola\na\ntodos");

    fclose(miArchivo);


    miArchivo = fopen("prueba.txt","r");
    while(!feof(miArchivo))
    {
        fgets(palabra,50,miArchivo);

        puts(palabra);
    }








}
