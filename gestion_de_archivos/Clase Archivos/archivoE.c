#include <stdio.h>

#define ARCH	"c:\\Archivos\\bin.dat"
#define ESC 27

typedef struct
{
		char nombre[31];
		int edad;
} ePersona;

int main (void)
{
	FILE  *bin;
	ePersona per;
	system("pause");
	printf("\nSe va a generar por primera vez el archivo\n");
	if ((bin=fopen(ARCH,"w+b"))==NULL)
	{
		printf("El archivo no puede ser abierto");
		exit(1);
	}
	do
	{
		printf("\nIngrese el nombre: ");
		gets(per.nombre);
		printf("Ingrese la edad: ");
		scanf("%d",&per.edad);
		fflush(stdin);
		fwrite(&per,sizeof(ePersona),1,bin);
		printf("\nPresione ESC para terminar");
	}while((getche())!=ESC);

	fclose(bin);

	return 0;
}
