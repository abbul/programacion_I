#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo, categoria;
    char descripcion[20];
    float precio;
} eProducto;

eProducto* newProducto(int,int,char[],float);

int main()
{
    char codigo[500], descripcion[500], categoria[500],precio[500];
    eProducto* producto;
    eProducto* lista[51];

    int cont=0;

    FILE * pFile;

    pFile = fopen ("productos.csv", "r");
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", codigo, descripcion, categoria,precio);
    while(!feof(pFile))
    {

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", codigo, descripcion, categoria,precio);

        producto = newProducto(atoi(codigo),atoi(categoria), descripcion, atof(precio));


        lista[cont]=producto;
        cont++;
    }

    for(cont=0; cont<51; cont++)
    {
        if(lista[cont]->categoria==1)
            printf("%d - %s - %d - %.2f\n", lista[cont]->codigo, lista[cont]->descripcion, lista[cont]->categoria,lista[cont]->precio);
    }



    fclose(pFile);

    return(0);
}
eProducto* newProducto(int codigo,int cat,char des[],float precio)
{
    eProducto* p;

    p=(eProducto*) malloc(sizeof(eProducto));

    p->codigo = codigo;
    p->categoria = cat;
    strcpy(p->descripcion,des);
    p->precio = precio;

    return p;
}
