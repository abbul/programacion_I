#include <stdio.h>
#include <stdlib.h>
void prueba1();
void prueba2();

int main()
{
    //prueba1();
    prueba2();
    return 0;
}

void prueba1()
{
      FILE* miArchivo;


    char palabra[50];

    miArchivo = fopen("c:\\data\\prueba.txt","w");

    fprintf(miArchivo,"hola");

    fclose(miArchivo);

    miArchivo = fopen("c:\\data\\prueba.txt","r");

    fgets(palabra,50,miArchivo);

    puts(palabra);
}
void prueba2()
{
    FILE* miArchivo;
    int i;
    int numero;
    char lista[5];

    miArchivo = fopen("prueba.txt","w");

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

      fwrite(&numero,sizeof(int),1,miArchivo);


    }

    fclose(miArchivo);

    miArchivo = fopen("prueba.txt","r");
    i=0;
    while(!feof(miArchivo))
    {
      fread(&lista[i],sizeof(char),5,miArchivo);

        i++;
    }

    for(i=0; i<5; i++)
    {

        printf("%d\n",lista[i]);

    }

    fclose(miArchivo);
}
