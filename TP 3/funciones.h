#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAMTIT 30 //Cantidad de caracteres para el Titulo
#define TAMGEN 30 //Cantidad de caracteres para el Genmero
#define TAMDESC 1000 //Cantidad de caracteres para la descripcion
#define TAMLINK 500 //Cantidad de caracteres para el Link
#define TAM 50 //Cantidad de estructuras a usar

typedef struct{
    int idPelicula;
    char titulo[TAMTIT];
    char genero[TAMGEN];
    int duracion;
    char descripcion[TAMDESC];
    int puntaje;
    char linkImagen[TAMLINK];
    int estado;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a serint agregarPelicula(EMovie movie); agregada al archivo
*  @param t la cantidad de estructuras
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int funAgregarPelicula(EMovie* movie, int t);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param t la cantidad de estructuras
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int funBorrarPelicula(EMovie* movie, int t);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombreHTML[] char destino donde se genera el archivo
 *  @param t la cantidad de estructuras
 *  @param nombre el nombre para el archivo.
 */
int funGenerarPagina(EMovie* movie, char nombreHTML[], int t);

/**
 * Permite modificar una pelicula del array
 * \param movie EMovie* array de peliculas
 * \param t int tamaño del array
 * \return int devuelve 1 si se modifico algun campo, 0 si no se modifico nada y -1 si no se encontro el ID
 *
 */
int funModificarPelicula(EMovie* movie, int t);

/**
 * Guarda las peliculas cargadas en un archivo
 * \param movie EMovie* array de peliculas
 * \param t int tamaño del array
 * \param destino[] char destino donde se guardara el archivo
 * \return int 0 si guardo las peliculas y 1 si no se pudo realizar la operacion
 *
 */
int funGuardar(EMovie* movie, int t, char destino[]);

/**
 * Carga del archivo las peliculas guardadas
 * \param movie EMovie* array de peliculas
 * \param destino[] char destino donde se encuentra el archivo
 * \return void
 *
 */
void funCargarArchivo(EMovie* movie, char destino[]);

/**
 * Cuenta cuantas peliculas fueron dadas de alta
 * \param movie EMovie* array de peliculas
 * \param t int tamaño del array
 * \return int
 *
 */
int funContAlta(EMovie* movie, int t);

/**
 * Inicia en todos los campos estado de la estructura en 0
 * \param movie EMovie* array de peliculas
 * \param t int tamaño del array
 * \return void
 *
 */
void funIniEstadoPelicula(EMovie* movie, int t);

/**
 * Muestra cada una de las peliculas que se le pasan
 * \param movie EMovie* array de peliculas con una posicion
 * \return void
 *
 */
void funMostrarPelicula(EMovie* movie);

/**
 * Genera un listado de las peliculas cargadas
 * \param movie EMovie* array de peliculas
 * \param t int tamaño del array
 * \return void
 *
 */
void funMostrarTodasPeliculas(EMovie* movie, int t);

/** \brief
 * Genera menu y permite ingresar una opcion
 * \param texto[] char array de caracters con los qué se genera el menu
 * \return int la opcion ingresada por el usuario
 *
 */
int funMostrarMenu(char texto[]);

/** \brief
 * Pausa la pantalla y luego la limpia
 * \return void
 *
 */
void funBorrarPantalla();

/**
 * Busca en el array de peliculas un ID
 * \param movie EMovie* array de peliculas
 * \param t int tamaño del array
 * \param id int ID de la pelicula a buscar
 * \return int
 *
 */
int funBuscarId(EMovie* movie,int t, int id);

/**
 * Cuenta la cantidad de caracteres que se ingresados no superen un tam especifico
 * \param campo[] char var donde se almacena la cadena de caracteres
 * \param tamaño int tamaño fijo de la variable a chequear
 * \return int 1 si se ingresaron mas caracteres de los establecidos
 *
 */
int funContarCaracteres(char campo[], int tamano);

/**
 * Chequea que el dato ingresado sea solo numeros positivos enteros
 * \param num[] char variable donde se guardan los datos
 * \return int 1 si no esta compuesto de numeros positivos o 0 si son numeros positivos
 *
 */
int funChequeoNumero(char num[]);

/**
 *  Obtiene el primer espacio disponible del array
 * \param movie EMovie*
 * \param t int tamaño del array
 * \return int retorna la posicion en la que se encuentra el espacio disponible
 *
 */
int funObtenerEspacioLibre(EMovie* movie, int t);
#endif // FUNCIONES_H_INCLUDED
