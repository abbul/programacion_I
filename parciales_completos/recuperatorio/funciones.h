typedef struct
{
    int edad;
    int profesion;
    char nombre [20];
    int id;

}ePersona;

int generar_archivo_filtrado (ArrayList*);
int menu();
int filtra_lista(void*);
ePersona* constructor_ePersona (int);
int parsear_archivo (ArrayList*);
int mostrar_clientes (ArrayList*);

