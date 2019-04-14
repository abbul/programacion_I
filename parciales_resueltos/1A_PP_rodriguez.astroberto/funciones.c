#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int menu()
{
    int opcion;
    system("cls");
    printf("\n***CLIENTES***\n\n\n");
    printf("1- Alta \n");
    printf("2- Modificacion \n");
    printf("3- Ingreso auto \n");
    printf("4- Egreso auto \n");
    printf("5- Listar \n");
    printf("6- Salir \n");
    printf("\n\nIngrese opcion: ");

    scanf("%d", &opcion);
    opcion=validaInt(opcion,1,6);

    return opcion;

}

int obtenerEspacioLibreDato(eDato listaDato[], int tamDato)
{
    int aux=-1;
    int flag=0;
    int i;

    for(i=0; i<tamDato; i++)
    {
        if(listaDato[i].estado!=1)
        {
            aux=i;
            flag=1;
            break;
        }
    }

    if(flag!=1)
    {
        printf(" \t No hay espacio libre \n");
    }

    return aux;
}

int buscarIdDato(eDato listaDato[], int tamDato)
{
    int aux=-1;
    int auxId;
    int i;

    scanf("%d",&auxId);

    for(i=0; i<tamDato; i++)
    {
        if(listaDato[i].id==auxId && listaDato[i].estado==1)
        {
            aux=i;
            break;
        }
    }

    if(aux==-1)
    {
        printf("No hay datos guardados con ese valor \n");
    }

    return aux;
}

int buscarCadenaDato(eDato listaDato[], int tamDato)
{
    int aux=-1;
    char auxCadena[50];
    int i;

    fflush(stdin);
    gets(auxCadena);

    for(i=0; i<tamDato; i++)
    {
        if(listaDato[i].nombre==auxCadena && listaDato[i].estado==1)

        {
            aux=i;
            break;
        }
    }

    if(aux==-1)
    {
        printf("No hay datos guardados con ese valor \n");
    }

    return aux;
}

int buscarPatenteOtro(eOtro listaOtro[], int tamOtro)
{
    int aux=-1;
    char auxCadena[50];
    int i;

    fflush(stdin);
    gets(auxCadena);

    for(i=0; i<tamOtro; i++)
    {
        if(listaOtro[i].patente==auxCadena && listaOtro[i].estado==1)

        {
            aux=i;
            break;
        }
    }

    return aux;
}

int validaInt(int numero,int minimoInt, int maximoInt)
{

    while(minimoInt>numero || numero>maximoInt)
    {
        printf("ERROR; Reingrese el dato: ");
        scanf("%d",&numero);
    }

    return numero;
}

float validaFloat(float numero,float minimoFloat, float maximoFloat)
{
    while(minimoFloat>numero || numero>maximoFloat)
    {
        printf("ERROR; Reingrese el dato: ");
        scanf("%f",&numero);
    }

    return numero;
}

char* validaCadena(char cadena[],int minimo,int maximo)
{
    char auxCadena[50];
    while(strlen(cadena)<minimo || strlen(cadena)>maximo)
    {
        printf("ERROR, reingrese cadena de caracteres:");
        fflush(stdin);
        gets(cadena);
    }

    strcpy(auxCadena,cadena);

    return auxCadena;
}

void iniciaEstructuraDato(eDato listaDato[], int tamDato)
{
    int i;
    for(i=0; i<tamDato; i++)
    {
        listaDato[i].estado=0;
        listaDato[i].id=0;
        listaDato[i].tarjetaCredito=0;
    }

    for(i=0; i<tamDato; i++)
    {
        strcpy(listaDato[i].nombre,"NADA");
        strcpy(listaDato[i].apellido,"NADA");
    }
}

void mostrarEstruturaDato(eDato listaDato)
{
    printf("\t ID:%d, %s %s TDC: %d\n",listaDato.id,listaDato.nombre,listaDato.apellido,listaDato.tarjetaCredito);
}

void mostrarArrayEstruturaDato(eDato listaDato[], int tamDato)
{
    int i;
    int aux=-1;
    eDato auxLista;

    for(i=0; i<tamDato; i++)
    {
        if(listaDato[i].estado==1)
        {
            auxLista=listaDato[i];
            mostrarEstruturaDato(auxLista);
            aux=1;
        }
    }

    if(aux==-1)
    {
        printf("\nNo hay nada para mostar\n");
    }
}

void modificarEstructuraDato(eDato listaDato[], int posicion)
{
    char respuesta;
    eDato auxLista;
    char buffer[200];

    if(posicion!=-1)

    {
        auxLista=listaDato[posicion];
        mostrarEstruturaDato(auxLista);

        printf("¿Desea modificar permanentemente este objeto? s/n \n");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta);

        if(respuesta=='S')
        {

            printf("Ingrese tarjeta de credito: ");
            scanf("%d",&listaDato[posicion].tarjetaCredito);
            listaDato[posicion].tarjetaCredito=validaInt(listaDato[posicion].tarjetaCredito,1,99999999);

            printf(" \t Modificacion Exitosa!!");
        }

        else
        {
            printf("Accion CANCELADA, no se modifico el objeto \n");
        }
    }
}

void cargarEstructuraDato(eDato listaDato[],int posicion)
{
    char buffer[200];
    if(posicion!=-1)
    {
        listaDato[posicion].id=posicion+1;

        printf("Ingrese tarjeta de credito: ");
        scanf("%d",&listaDato[posicion].tarjetaCredito);
        listaDato[posicion].tarjetaCredito=validaInt(listaDato[posicion].tarjetaCredito,10,99999999);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(buffer);
        strcpy(listaDato[posicion].nombre,validaCadena(buffer,2,20));

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(buffer);
        strcpy(listaDato[posicion].apellido,validaCadena(buffer,2,20));

        printf("Ingrese direccion: ");
        fflush(stdin);
        gets(buffer);
        strcpy(listaDato[posicion].direccion,validaCadena(buffer,2,20));

        listaDato[posicion].estado=1;

        printf("\t Carga Exitosa!!   Su ID es: %d",listaDato[posicion].id);
    }
}

void eliminarEstructuraDato(eDato listaDato[],int posicion)
{
    char respuesta;
    eDato auxLista;

    auxLista=listaDato[posicion];
    mostrarEstruturaDato(auxLista);

    printf("¿Desea eliminar permanentemente este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        listaDato[posicion].estado=-1;
        listaDato[posicion].id=0;
        listaDato[posicion].tarjetaCredito=0;
        strcpy(listaDato[posicion].nombre,"NADA");
        strcpy(listaDato[posicion].apellido,"NADA");
        printf("Dato eliminado \n");
    }
    else
    {
        printf("Accion CANCELADA, no se elimino el objeto \n");
    }

}
void altaEstructuraDato(eDato listaDato[], int tamDato)
{
    eDato auxLista;
    char respuesta;
    int aux;

    printf("Ingrese id a darle de alta\n");
    aux=buscarIdDato(listaDato,tamDato);
    auxLista=listaDato[aux];
    mostrarEstruturaDato(auxLista);

    printf("¿Desea darle de alta a este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        listaDato[aux].estado=1;
    }
    else
    {
        printf("Accion CANCELADA, no se dio de alta al objeto \n");
    }
}
void bajaEstructuraDato(eDato listaDato[],int tamDato)
{
    eDato auxLista;
    char respuesta;
    int aux;

    printf("Ingrese id a darle de baja\n");
    aux=buscarIdDato(listaDato,tamDato);

    if(aux!=-1)
    {
        auxLista=listaDato[aux];
        mostrarEstruturaDato(auxLista);

        printf("¿Desea darle de baja a este objeto? s/n \n");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta);

        if(respuesta=='S')
        {
            listaDato[aux].estado=0;
            printf("\t Baja exitosa!!! \n");
        }
        else
        {
            printf("Accion CANCELADA, no se dio de baja al objeto \n");
        }
    }
}

void ordenaEstructuraOtro(eOtro listaOtro[],int tamOtro)
{
    int i, j;
    eOtro auxlistaOtro;

    for(i=0; i<tamOtro-1; i++)
    {
        for(j=i+1; j<tamOtro; j++)
        {
            if(listaOtro[i].horaEntrada>listaOtro[j].horaEntrada)
            {
                auxlistaOtro=listaOtro[j];
                listaOtro[j]=listaOtro[i];
                listaOtro[i]=auxlistaOtro;
            }
            if( listaOtro[i].horaEntrada==listaOtro[j].horaEntrada && strcmpi(listaOtro[i].patente,listaOtro[j].patente)==1)
            {
                auxlistaOtro=listaOtro[j];
                listaOtro[j]=listaOtro[i];
                listaOtro[i]=auxlistaOtro;
            }
        }
    }
}

void mostar2estructuras(eDato listaDato[], eOtro listaOtro[],int tamDato, int tamOtro)
{
    int i,j;

    ordenaEstructuraOtro(listaOtro,tamOtro);

        for(i=0; i<tamOtro; i++)
        {
            for(j=0; j<tamDato; j++)
            {
                if(listaOtro[i].estado==1 && listaDato[j].id==listaOtro[i].idCliente && listaDato[j].estado==1)
                {
                printf("%s -- id:%d -- tdc:%d ",listaDato[j].nombre,listaDato[j].id,listaDato[j].tarjetaCredito);
                printf("hora:%d, patente:%s, marca: %s\n",listaOtro[i].horaEntrada,listaOtro[i].patente,listaOtro[i].marcaX);
                }
            }
        }

    /* for(i=0;i<tamOtro;i++)

     {
         if(listaOtro[i].marca==3)
         {
         for(j=0;j<tamDato;j++)
         {
             if(listaOtro[j].marca==listaOtro[j].marca)
         printf("%s",listaDato[i].nombre);
         }

         }


     }*/
}

void cargaAutomaticaDato(eDato listaDato[],int tamDato)
{
    int i;
    eDato aux[5]= {  {.estado=1,.id=1,.tarjetaCredito=456798,"Juan","Perez","Capital"},{1,2,345458,"Angel","Gomez","Mendoza"},{1,3,645878,"Zara","Prieto","Cordoba"},{1,4,907871,"Barbara","Rodriguez","Capital"},{1,5,458234,"Maria","Espinoza","Cordoba"} };

    for(i=0; i<5; i++)
    {
        listaDato[i]=aux[i];
    }
}

void cargarEstructuraOtro(eDato listaDato[],eOtro listaOtro[],int posicion, int tamDato, int tamOtro)
{
    char buffer[100];
    int aux, i, flag=-1;

    if(posicion!=-1)
    {
        do
        {
            printf("Ingrese ID de cliente: ");
            scanf("%d",&aux);

            for(i=0; i<tamDato; i++)
            {
                if(aux==listaDato[i].id)
                {
                    listaOtro[posicion].idCliente=aux;
                    flag=1;
                    break;
                }
            }

            if(flag==-1)
            {
                printf(" \t no hay cliente con ese id, REINGRESE ID!! \n");
            }
        }
        while(flag==-1);

        printf("Ingrese hora de entrada, formato 24hs: ");
        scanf("%d",&listaOtro[posicion].horaEntrada);
        listaOtro[posicion].horaEntrada=validaInt(listaOtro[posicion].horaEntrada,0,23);

        printf("elija marca de auto \n \t 1.ALPHA\t2.FERRARI\t3.AUDI\t4.Otros: ");
        scanf("%d",&listaOtro[posicion].marca);
        listaOtro[posicion].marca=validaInt(listaOtro[posicion].marca,1,4);

        if(listaOtro[posicion].marca==1)
            strcpy(listaOtro[posicion].marcaX,"ALPHA");

        if(listaOtro[posicion].marca==2)
            strcpy(listaOtro[posicion].marcaX,"FERRARI");

        if(listaOtro[posicion].marca==3)
            strcpy(listaOtro[posicion].marcaX,"AUDI");

        if(listaOtro[posicion].marca==4)
            strcpy(listaOtro[posicion].marcaX,"OTROS");

        do
        {
            aux=1;

            printf("Ingrese patente: ");
            fflush(stdin);
            gets(buffer);
            strcpy(buffer,validaCadena(buffer,3,6));

            for(i=0; i<tamOtro; i++)
            {
                if(strcmpi(listaOtro[i].patente,buffer)==0 )
                {
                    printf("ERROR, patente ya existe \n");
                    aux=0;
                    break;
                }
            }
        }while(aux==0);

        strcpy(listaOtro[posicion].patente,buffer);

        listaOtro[posicion].estado=1;
        printf("\tCarga de auto exitosa!!");
    }
}

int buscarIdOtro(eOtro listaOtro[], int tamOtro)
{
    int aux=-1;
    int auxId;
    int i;

    scanf("%d",&auxId);

    for(i=0; i<tamOtro; i++)
    {
        if(listaOtro[i].idCliente==auxId && listaOtro[i].estado==1)
        {
            aux=i;
            break;
        }
    }

    if(aux==-1)
    {
        printf("No hay datos guardados con ese valor \n");
    }

    return aux;
}

int bajaEstructuraOtro(eDato listaDato[],eOtro listaOtro[],int tamDato, int tamOtro, int listaGanancia[])
{
    char respuesta, auxPatente[10];
    int aux=-1, auxHora, total=0, i;

    printf("Ingrese Patente para egresar el auto: ");
    fflush(stdin);
    gets(auxPatente);

    for(i=0; i<tamOtro; i++)
    {
        if(strcmpi(auxPatente,listaOtro[i].patente)==0  && listaOtro[i].estado==1)
            aux=i;
    }

    if(aux!=-1)
    {
        printf("ID:%d , marca:%s , patente:%s \n",listaOtro[aux].idCliente,listaOtro[aux].marcaX,listaOtro[aux].patente);
        printf("¿Desea darle de baja a este objeto? s/n \n");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta);

        if(respuesta=='S')
        {
            printf("Su auto ingreso a las %dHs, Ingrese hora de salida: ",listaOtro[aux].horaEntrada);
            scanf("%d",&auxHora);
            auxHora=validaInt(auxHora,listaOtro[aux].horaEntrada+1,24);

            auxHora=auxHora-listaOtro[aux].horaEntrada;

            if(listaOtro[aux].marca==1)
            {
                total=auxHora*150;
                listaGanancia[0]+=total;

            }
            if(listaOtro[aux].marca==2)
            {
                total=auxHora*175;
                listaGanancia[1]+=total;
            }
            if(listaOtro[aux].marca==3)
            {
                total=auxHora*200;
                listaGanancia[2]+=total;
            }
            if(listaOtro[aux].marca==4)
            {
                total=auxHora*250;
                listaGanancia[3]+=total;
            }

            printf("\t Baja exitosa!!! \n");
            getch();

            system("cls");

            printf("\t\t SU TICKET: \n");

            for(i=0; i<tamOtro; i++)
            {
                if(listaOtro[aux].idCliente==listaDato[i].id && strcmpi(listaOtro[aux].patente,auxPatente)==0)
                {
                    printf(" \n\tNombre: %s %s   -- Direccion:%s \n",listaDato[i].nombre,listaDato[i].apellido,listaDato[i].direccion);
                    printf(" \tMarca: %s --   Patente: %s \n",listaOtro[aux].marcaX,listaOtro[aux].patente,listaOtro[aux].horaEntrada);
                    printf("\nTOTAL A PAGAR: $%d",total);

                    listaOtro[aux].estado=0;
                    strcpy(listaOtro[aux].patente,"NADA");
                    listaOtro[aux].horaEntrada=0;
                    listaOtro[aux].idCliente=0;
                    break;
                }
            }

        }
        else
        {
            printf("Accion CANCELADA, no se dio de baja al objeto \n");
        }
    }

    else
    {
        printf("ERROR, no hay autos con esa patente!! \n");
    }

    return total;
}

void cargaAutomaticaOtro(eOtro listaOtro[],int tamOtro)
{
    {
        int i;
        eOtro aux[]= { {.estado=1,.idCliente=1,.marca=2,.horaEntrada=5,"ASKA14","FERRARI"},{1,3,3,5,"HIO567","AUDI"},{1,3,4,5,"KOEWE3","OTROS"},{1,4,3,5,"QWE098","AUDI"},{1,5,1,5,"BUI560","ALPHA"} };

        for(i=0; i<5; i++)
        {
            listaOtro[i]=aux[i];
        }
    }

}

int obtenerEspacioLibreOtro (eOtro listaOtro[], int tamOtro)
{
    int aux=-1;
    int flag=0;
    int i;

    for(i=0; i<tamOtro; i++)
    {
        if(listaOtro[i].estado==0)
        {
            aux=i;
            flag=1;
            break;
        }
    }

    if(flag!=1)
    {
        printf(" \t No hay espacio libre \n");
    }

    return aux;
}

void iniciaEstructuraOtro(eOtro listaOtro[], int tamOtro)
{
    int i;
    for(i=0; i<tamOtro; i++)
    {
        listaOtro[i].estado=0;
        listaOtro[i].idCliente=0;
        listaOtro[i].horaEntrada=0;
    }

    /* for(i=0; i<tam; i++)
       {
           strcpy(lista[i].,"NADA");
       } */
}

void mostrarEstruturaOtro(eOtro listaOtro)
{
    printf("-> hora entrada: %d, patente: %s \n",listaOtro.idCliente,listaOtro.patente);
}

void mostrarArrayEstruturaOtro(eOtro listaOtro[], int tamOtro)
{
    int i;
    int aux=-1;
    eOtro auxLista;

    for(i=0; i<tamOtro; i++)
    {
        if(listaOtro[i].estado==1)
        {
            auxLista=listaOtro[i];
            mostrarEstruturaOtro(auxLista);
            aux=1;
        }
    }

    if(aux==-1)
    {
        printf("\nNo hay nada para mostar\n");
    }
}

void listarPorCadenaOtro(eDato listaDato[],eOtro listaOtro[],int tamDato, int tamOtro)
{
    int i,j;

        for(i=0; i<tamOtro; i++)
        {
            for(j=0; j<tamDato; j++)
            {
                if(listaOtro[i].marca==3 && listaOtro[i].estado==1 && listaDato[j].id==listaOtro[i].idCliente && listaDato[j].estado==1)
                {
                printf("%s -- id:%d -- tdc:%d ",listaDato[j].nombre,listaDato[j].id,listaDato[j].tarjetaCredito);
                printf("hora:%d, patente:%s \n",listaOtro[i].horaEntrada,listaOtro[i].patente);
                }
            }
        }
}

void mostrarTodo(eDato listaDato[],eOtro listaOtro[],int tamDato,int tamOtro,int ganancias[], int total)
{
            printf(" \tA. Lista de Dueños con sus autos \n \n");
            mostar2estructuras(listaDato,listaOtro,tamDato,tamOtro);
            getch();

            printf(" \n\tB. Todos los dueños con AUDI \n\n");
            listarPorCadenaOtro(listaDato,listaOtro,tamDato,tamOtro);
            getch();

            printf(" \n\tC. Recaudacion por Marca \n\n");
            printf("ALPHA-->$%d  FERRARI-->$%d  AUDI-->$%d  OTROS-->$%d \n\n",ganancias[0],ganancias[1],ganancias[2],ganancias[3]);
            getch();

            printf(" \n\tD. Recaudacion del total del estacionamiento \n");
            printf("\nTOTAL RECAUDACION: $%d",total);
            getch();
}

FILE* iniciaArchivo(FILE* archivo,eDato clientes[],eOtro autos[], int C, int A)
{
    if (( archivo= fopen("ListaDA.txt","rb+")) == NULL)
    {
        if ((archivo = fopen("ListaDA.txt","wb+")) == NULL)
        {
            printf("No se pudo abrir el archivo");
        }
        else
        {
             iniciaEstructuraDato(clientes,C);
            iniciaEstructuraOtro(autos,A);
            cargaAutomaticaDato(clientes,C);
            cargaAutomaticaOtro(autos,A);
        }
    }
    return archivo;
}
