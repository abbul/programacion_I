
typedef struct
{
    int idDueno;
    char nombreApellido[40];
    char  dirrecion[40];
    int numeroTarjeta;
    int flagDeAltaCliente;

} Eclientes;

typedef struct
{
    char patente[40];
    char marca[40];
    int copiaIdDueno;
    int horaEntrada;
    int flagAltaAuto;

} Eauto;

/*
void inicializarCliente (Eclientes cliente[], int);
*/
