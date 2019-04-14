#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int estado, id , tarjetaCredito;
    char nombre[20], apellido[20], direccion[20];
}eDato;

typedef struct
{
    int estado, idCliente, marca,horaEntrada;
    char patente[10], marcaX[10];
}eOtro;


/** \brief muestra una menu de opciones
 * \param no recibe nada
 * \return retorna un int que es la opcion seleccionada
 */
int menu();


/** \brief valida un numero entre un menor y un mayor
 * \param numero es el numero a validar
 * \param minimoInt es el numero minimo a validar
 * \param maximoInt es el numero maximo a validar
 * \return retorna un int que es el numero ya validado
 */
int validaInt(int numero, int minimoInt, int maximoInt);


/** \brief valida un numero entre un menor y un mayor
 * \param numero es el numero a validar
 * \param minimoFloat es el numero minimo a validar
 * \param maximoFloat es el numero maximo a validar
 * \return retorna un Float que es el numero ya validado
 */
float validaFloat(float numero,float minimoFloat, float maximoFloat);


/** \brief valida el tamaño de una cadena
 * \param cadena es la cadena a validar
 * \param minimo es el numero minimo de debe tener la cadena
 * \param maximo es el numero maximo de debe tener la cadena
 * \return retorna un puntero a char con la cadena ya validada
 */
char* validaCadena(char cadena[],int minimo,int maximo);


/** \brief busca un espacio libre en una estructura eDato
 * \param listaDato es la estructura donde buscara el espacio libre
 * \param tamDato es el tamaño de la estructura
 * \return retorna un int que es la posicion libre
 */
int obtenerEspacioLibreDato(eDato listaDato[], int tamDato);


/** \brief busca un id en la estructura eDato
 * \param listaDato es la estructura donde buscara el id
 * \param tamDato es el tamaño de la estructura
 * \return retorna la posicion donde esta el id o -1 sino lo consigue
 */
int buscarIdDato(eDato listaDato[], int tamDato);


/** \brief busca una cadena en la estructura eDato
 * \param listaDato es la estructura donde buscara la cadena
 * \param tamDato es el tamaño de la estructura
 * \return retorna la posicion donde esta la cadena o -1 sino lo consigue
 */
int buscarCadenaDato(eDato listaDato[], int tamDato);


/** \brief libera los campos de la estructura eDato
 * \param listaDato es la estructura que se liberara
 * \param tamDato es el tamaño de la estructura
 * \return nada
 */
void iniciaEstructuraDato(eDato listaDato[], int tam);


/** \brief muestra los campos de la estructura eDato
 * \param listaDato es la estructura que se va a mostrar
 * \return nada
 */
void mostrarEstruturaDato(eDato listaDato);


/** \brief muestra los campos del array de estructura eDato
 * \param listaDato es el array de estructura que se va a mostrar
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void mostrarArrayEstruturaDato(eDato lista[], int tamDato);


/** \brief modifica los campos del array de estructura eDato
 * \param listaDato es el array de estructura que se va a modificar
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void modificarEstructuraDato(eDato listaDato[], int posicion);


/** \brief carga los campos del array de estructura eDato
 * \param listaDato es el array de estructura que se va a cargar
 * \param posicion es la ubicacion donde se cargara la array de la estructura
 * \return nada
 */
void cargarEstructuraDato(eDato listaDato[],int posicion);


/** \brief elimina los campos del array de estructura eDato
 * \param listaDato es el array de estructura que se va a eliminar
 * \param posicion es la ubicacion que se eliminara de la array de la estructura
 * \return nada
 */
void eliminarEstructuraDato(eDato listaDato[],int posicion);


/** \brief da de alta una posicion de la array de estructura eDato
 * \param listaDato es el array de estructura que se va a dar de alta
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void altaEstructuraDato(eDato listaDato[],int tam);


/** \brief se da de baja a una posicion del array de estructura eDato
 * \param listaDato es el array de estructura que se va a dar de baja
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void bajaEstructuraDato(eDato listaDato[],int tam);


/** \brief ordena la estructura array de estructura eOtro por doble criterio, 1ero Hora , 2do Patente
 * \param listaOtro es el array de estructura que se va a ordenar
 * \param tamOtro es el tamaño del array de la estructura
 * \return nada
 */
void ordenaEstructuraOtro(eOtro listaOtro[],int tamOtro);


/** \brief ordena la estructura eOtro y la muestra de forma paralela con la estructura eDato
 * \param listaOtro es el array de estructura que se va a ordenar ordenar
 * \param listaDato es el array de estructura que se va a mostrar
 * \param tamOtro es el tamaño del array de la estructura
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void mostar2estructuras(eDato listaDato[], eOtro listaOtro[],int tamDato, int tamOtro);


/** \brief carga de forma automatica el array de estructura eDato
 * \param listaDato es el array de estructura que se va a cargar automaticamente
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void cargaAutomaticaDato(eDato listaDato[],int tamDato);


/** \brief muestra una lista de todos los autos audi de la array de estructura eOtro
 * \param listaDato es el array de estructura que se va a mostrar
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void listarPorCadenaOtro(eDato listaDato[],eOtro listaOtro[],int tamDato, int tamOtro);


/** \brief carga la estructura array de estructura eOtro
 * \param listaOtro es el array de estructura que se va a cargar
 * \param listaDato es el array de estructura que se utiliza para comparar y validar algunos valores
 * \param tamOtro es el tamaño del array de la estructura que se va a cargar
 * \param tamDato es el tamaño del array de la estructura para comparar y validar algunos valores
 * \param posicion es la ubicacion donde se cargar la estructura eOtro
 * \return nada
 */
void cargarEstructuraOtro(eDato listaDato[], eOtro listaOtro[],int posicion, int tamDato, int tamOtro);



/** \brief busca una cadena en la estructura eOtro
 * \param listaOtro es el array de estructura donde se va a buscar
 * \param tamOtro es el tamaño del array de la estructura donde se va a buscar
 * \return un int, retorna la posicion o -1 sino la consigue
 */
int buscarCadenaOtro(eOtro listaOtro[], int tamOtro);


/** \brief busca un ID en la estructura eOtro
 * \param listaOtro es el array de estructura que se va a buscar
 * \param tamOtro es el tamaño del array de la estructura donde se va a buscar
 * \return retorna la posicion o -1 sino consigue el id
 */
int buscarIdOtro(eOtro listaOtro[], int tamOtro);


/** \brief le da de baja a un elemento en el array de estructura eOtro
 * \param listaOtro es el array de estructura que se va a dar de baja
 * \param listaDato es el array de estructura que se utiliza para comparar y validar algunos valores
 * \param tamOtro es el tamaño del array de la estructura que se va a dar de baja
 * \param tamDato es el tamaño del array de la estructura para comparar y validar algunos valores
 * \param listaGanancia es donde se guardara la ganancia cuando se le de baja al auto
 * \return nada
 */
int bajaEstructuraOtro(eDato listaDato[],eOtro listaOtro[],int tamDato, int tamOtro,int listaGanancia[]);


/** \brief carga la estructura array de estructura eOtro de forma automatica
 * \param listaOtro es el array de estructura que se va a cargar
 * \param tamOtro es el tamaño del array de la estructura que se va a cargar
 * \return nada
 */
void cargaAutomaticaOtro(eOtro listaOtro[],int tamOtro);


/** \brief obtiene un espacio libre en la estructura array de estructura eOtro
 * \param listaOtro es el array de estructura que se va a buscar el espacio
 * \param tamOtro es el tamaño del array de la estructura eOtro
 * \return devuelve la posicion buscada o -1 sino consiguio lugar
 */
int obtenerEspacioLibreOtro (eOtro listaOtro[], int tamOtro);


/** \brief inicia los campos de  la estructura array de estructura eOtro
 * \param listaOtro es el array de estructura que se va a iniciar
 * \param tamOtro es el tamaño del array de la estructura eOtro
 * \return nada
 */
void iniciaEstructuraOtro(eOtro listaOtro[], int tamOtro);


/** \brief muestra los campos de  la estructura eOtro
 * \param listaOtro es la estructura que va a mostrar
 * \return nada
 */
void mostrarEstruturaOtro(eOtro listaOtro);


/** \brief muestra los campos del array de estructura eOtro
 * \param listaOtro es el array de estructura que va a mostrar
 * \param tamOtro es el tamaño del array de la estructura eOtro
 * \return nada
 */
void mostrarArrayEstruturaOtro(eOtro listaOtro[], int tamOtro);

void mostrarTodo(eDato[],eOtro[],int,int,int[],int);

FILE* iniciaArchivo(FILE*,eDato[],eOtro[],int,int);

#endif // FUNCIONES_H_INCLUDED
