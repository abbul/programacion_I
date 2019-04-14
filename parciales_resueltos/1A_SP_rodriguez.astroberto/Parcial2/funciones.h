
typedef struct
{
    char nombre[50];
    char correo [50];

}eClientes;

int parsear_y_comparar_archivo(ArrayList* lista,ArrayList* listaNegra);
int menu ();
int parsear_archivo (ArrayList*);
int depurar_lista (ArrayList*,ArrayList*,ArrayList*);
int mostrar_clientes (ArrayList*);
eClientes* constructor_eCliente (int);
