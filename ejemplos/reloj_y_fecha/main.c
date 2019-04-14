#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <dos.h>

int main()
{
    SYSTEMTIME fecha;
    int stop = 0;
    char respuesta = 's';
    int min, seg;

    GetLocalTime(&fecha);
    printf("Hora: %02d:%02d:%02d\n", fecha.wHour, fecha.wMinute, fecha.wSecond);
    printf("fecha: %02d/%02d/%02d\n", fecha.wDay, fecha.wMonth, fecha.wYear);

    printf("MIN de la alarma: ");
    scanf("%d",&min);
    printf("SEG de la alarma: ");
    scanf("%d",&seg);

    do
    {
        GetLocalTime(&fecha);
        system("cls");
        printf("Hora: %02d:%02d:%02d\n", fecha.wHour, fecha.wMinute, fecha.wSecond);
        Sleep(1000);

        if(fecha.wMinute == min && fecha.wSecond == seg)
        {
            stop = 1;
        }
    }
    while(stop == 0);

    system("color FC");
    printf("\n\n ARRIBAAA!! \n Queres seguir durmiendo? ");
    getch();
    fflush(stdin);
    scanf("%c", &respuesta);
    Sleep(500);
    system("color CF");
    GetLocalTime(&fecha);
    Sleep(500);

    if(respuesta == 's')
    {
        system("color 07");
        printf("ingrese nuevo minuto de la alarma: ");
        scanf("%d", &min);
        printf("ingrese nuevo segundo de la alarma: ");
        scanf("%d", &seg);
    }

    stop = 0;
    do
    {
        GetLocalTime(&fecha);
        system("cls");
        printf("Hora: %02d:%02d:%02d\n", fecha.wHour, fecha.wMinute, fecha.wSecond);
        Sleep(1000);

        while(fecha.wMinute == min && fecha.wSecond >= seg && respuesta == 's')
        {
            system("color FC");
            GetLocalTime(&fecha);
            system("cls");
            printf("Hora: %02d:%02d:%02d\n", fecha.wHour, fecha.wMinute, fecha.wSecond);
            printf("\narriba pebetom");
            Sleep(500);
            system("color CF");
            GetLocalTime(&fecha);
            Sleep(500);
        }
    }
    while(stop == 0);

    return 0;
}
