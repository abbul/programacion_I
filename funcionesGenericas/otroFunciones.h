#ifndef OTROFUNCIONES_H_INCLUDED
#define OTROFUNCIONES_H_INCLUDED

typedef struct
{
    int estado, idCliente, equipo,tiempo,numeroContrato, tiempoReal;
}eOtro;

typedef struct
{
    int estado, idDeEdato, idDeEotro;
    char descripcion[50];
}eMixta;

void cargarAlquiler(eOtro listaOtro[],eDato listaDato[],int posicion, int tamDato);
int buscarContrato(eOtro lista[], int tam);
void bajaAlquiler(eOtro lista[],int tam);
void muestraTodo(eDato listaCliente[], eOtro listaAlquileres[], int X, int C);
void cargaAutomaticaAlquileres(eOtro lista[],int tam);
int obtenerEspacioLibreOtro (eOtro lista[], int tam);
void iniciaEstructuraOtro(eOtro lista[], int tam);
void mostrarEstruturaOtro(eOtro lista);
void mostrarArrayEstruturaOtro(eOtro lista[], int tam);
int buscaMayor(eOtro lista[], int tam)

#endif // OTROFUNCIONES_H_INCLUDED


/*    int aux[tamX];
    int i, j, otro=0, posicion;


    for(i=0;i<tamX;i++)
    {
        aux[i]=0;
    }

    for(i=0;i<tamX;i++)
    {
            for(j=0;j<tamC;j++)
            {
                if(listaCliente[i].id==listaAlquileres[j].idCliente)
                    {
                        aux[i]=aux[i]+1;
                    }
            }
    }

        for(i=0;i<tamX;i++)
        {
            if(aux[i]>otro)
            {
                otro=aux[i];
                posicion=i;
            }
        }

        printf("%s %s, alquilo: %d",listaCliente[posicion].nombre,listaCliente[posicion].apellido,otro);

        */
