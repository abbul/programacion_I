#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char descripcion[20];
}eProvincia;


typedef struct
{
    char nombre[30];
    int idProvincia;
}ePersona;

int main()
{
    eProvincia provincias[]={{1,"BS AS"},{2, "Entre Rios"},{3, "La Pampa"}};
    ePersona unaPersona={"Jose", 3};
    int i;

    printf("%s -- ", unaPersona.nombre);
    for(i=0; i<3; i++)
    {
        if(provincias[i].id==unaPersona.idProvincia)
        {
            printf("%s", provincias[i].descripcion);
            break;
        }
    }



    return 0;
}
