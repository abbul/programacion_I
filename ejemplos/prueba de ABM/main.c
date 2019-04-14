#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define X 3

typedef struct{
    int id;
    char nombre[20];
    char categoria[20];
    int proyecto;
    int estado;
}
eProgramador;

//a = Senior
//b = SemiSenior
//c = Junior

int menu();
eProgramador iniciaEstructura(eProgramador lista[], int tam);
void mostrarEstrutura(eProgramador lista);
void mostrarArrayEstrutura(eProgramador lista[], int tam);
eProgramador cargarEstructura(eProgramador lista[],int posicion);
int obtenerEspacioLibre(eProgramador lista[], int tam);
int buscarPorElemento(eProgramador lista[], int tam);

int main()
{
    eProgramador equipo[X];
    int salir = 1;
    int posicion=-1;

    iniciaEstructura(equipo,X);

    do{
        switch(menu()){

    case 1:
        system("cls");
        printf("Opcion1 \n");
        posicion=obtenerEspacioLibre(equipo,X);
        cargarEstructura(equipo,posicion);
        getch();

        break;

    case 2:
         system("cls");
        printf("Opcion2 \n");
        getch();


        break;
    case 3:
         system("cls");
        printf("Opcion3 \n");
        getch();

        break;

    case 4:
         system("cls");
        printf("Opcion4 \n");
        mostrarArrayEstrutura(equipo,X);
        getch();
        break;



    case 5:
      salir = 0;



        break;

        }

    }while(salir);
    return 0;
}

    int menu(){
        int opcion;
        system("cls");
        printf("\n***Programadores***\n\n\n");
        printf("1- Alta Programador\n");
        printf("2- Modificacion Programador\n");
        printf("3- Baja Programador\n");
        printf("4- Listado Programadores\n");
        printf("5- Salir\n");
        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        return opcion;

    }

eProgramador iniciaEstructura(eProgramador lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].estado=0;
        lista[i].id=0;
        lista[i].proyecto=0;
    }

    for(i=0;i<tam;i++)
    {
        strcpy(lista[i].nombre,"NADA");
        strcpy(lista[i].categoria,"NADA");
    }

}

 void mostrarEstrutura(eProgramador lista)
{
        printf("%d \n",lista.id);
        printf("%d \n",lista.proyecto);
        printf("%s \n",lista.nombre);
        printf("%s \n",lista.categoria);
}

void mostrarArrayEstrutura(eProgramador lista[], int tam)
{
     int i;
    int aux=0;
    eProgramador auxLista;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
        auxLista=lista[i];
        mostrarEstrutura(auxLista);

        aux=1;
        }
    }
    if(aux==0)
    {
        printf("\nNo hay nada para mostar\n");
    }
}

eProgramador cargarEstructura(eProgramador lista[],int posicion)
{
    if(posicion!=-1)

    {
        printf("Ingrese id: ");
        scanf("%d",&lista[posicion].id);

        printf("Ingrese proyecto: ");
        scanf("%d",&lista[posicion].proyecto);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[posicion].nombre);

        printf("Ingrese categoria: ");
        fflush(stdin);
        gets(lista[posicion].categoria);

        lista[posicion].estado=1;
    }

}

int obtenerEspacioLibre(eProgramador lista[], int tam)
{
    int aux=-1, flag=0, i;

    for(i=0;i<tam;i++)
    {
            if(lista[i].estado==0)
            {
                aux=i;
                flag=1;
                break;
            }
    }

    if(flag==0)
            {
                printf("No hay espacio libre \n");
            }

    return aux;
}

int buscarPorElemento(eProgramador lista[], int tam)
{
    int aux=-1;
    int i;
    int auxId;

    printf("Ingrese ID a buscar");
    scanf("%d",&auxId);

    for(i=0;i<tam;i++)
    {
            if(lista[i].id==auxId && lista[i].estado==1)
            {
                aux=i;
                break;
            }

            if(aux==-1)
            {
                    printf("No hay datos guardados con ese valor");
            }
    }

    return aux;
}
