#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
   int aux;

    printf("%s",message);
   scanf("%d",&aux);
    if(aux>lowLimit && aux<hiLimit)
    {
        *input=aux;
        return 0;
    }

    printf("%s",eMessage);
    return -1;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float aux;

    printf("%s",message);
   scanf("%f",&aux);
    if(aux>lowLimit && aux<hiLimit)
    {
        *input=aux;
        return 0;
    }

    printf("%s",eMessage);
    return -1;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    char aux;

    printf("%c",message);
    fflush(stdin);
    scanf("%c",&aux);

    if(aux=='A' || aux=='B' || aux=='C')
    {
        *input=aux;
        return 0;
    }

    printf("%s",eMessage);
    return -1;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[50];
    int xy;

    printf("%s",message);
    fflush(stdin);
    scanf("%s",&aux);

    xy= strlen(aux);

    if(xy<50 && xy>2)
    {
        *input=aux;
        return 0;
    }

    printf("%s",eMessage);
    return -1;
}
