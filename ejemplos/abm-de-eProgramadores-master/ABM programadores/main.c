#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "programadores.h"
#define X 3


int main()
{
    int salir = 1;
    int posicion=-1;
    int aux, i, acum=0;

    eProyecto proyectos[]={ {.idProyecto=10,"ss gestion"} , {.idProyecto=11,"afip"} , {.idProyecto=12,"arba"} , {.idProyecto=13,"web"} };
    eProgProy ids[]={ {.idProyecto=11,.id=1,7} , {.idProyecto=13,.id=3,8} , {.idProyecto=10,.id=2,9} , {.idProyecto=13,.id=2,3} , {.idProyecto=10,.id=1,7} , {.idProyecto=12,.id=1,4} , {.idProyecto=11,.id=2,5} };
    eProgramador equipo[]= {  {1,"juan","junior",1,19999} , {2,"david","Semijunior",1,19999} , {3,"chistian","Senior",1,19999} ,  };

     int id;
    char nombre[20];
    char categoria[20];
    int estado;
    int sueldo;

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
        printf("Ingrese id a modificar:");
        aux=buscarId(equipo,X);
        if(aux!=-1){modificarEstructura(equipo,aux);}
        getch();

        break;
    case 3:
         system("cls");
        printf("Opcion3 \n");
        printf("Ingrese id a eliminar:");
        aux=buscarId(equipo,X);
        if(aux!=-1){eliminarEstructura(equipo,aux);}
        getch();

        break;

    case 4:
         system("cls");
        printf("Opcion4 \n");

        printf("ingrese id prog:");
        scanf("%d",&aux);
        acum=0;

            for(i=0;i<7;i++)
            {
                 if(ids[i].id==aux)
                 {
                     acum=acum +ids[i].horasTrabajadas;
                     printf("horas trabajas: %d \n",ids[i].horasTrabajadas);

                     if(ids[i].idProyecto==aux)
                     {

                     }

                 }
            }

            printf("des: %s\n",proyectos[i].descripcion);



             printf("total horas:%d",acum);
            getch();
        //mostrarArrayEstrutura(equipo,X);

        break;

    case 5:
      salir = 0;
        break;
        }

    }while(salir);
    return 0;
}

