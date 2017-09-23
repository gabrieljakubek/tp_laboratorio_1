#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{

    int dni;
    char nombre[50];
    int edad;
    int estado;

} EPersona;

/**
 * Carga la variable estado con 0
 * \param EPersona Se le pasa la estructura con la que se va a trabajar
 * \param Se le pasa la cantidad de estucturas disponibles
 * \return
 *
 */
void funcambiarEstadoyDNI(EPersona[],int);

/**
 * Genera un menu segun la informacion que se le pasa y entrega la opcion elegida
 * \param char texto Son los datos que se desean mostrar
 * \return Devuelve la opcion que se elige segun el texto
 */
int funmostrarMenu(char texto[]);

/**
 * Permite ingresar datos a la estructura
 * \param EPersona Se le pasa la estructura con la que se va a trabajar
 * \param int La cantidad de estucturas disponibles
 *
 */
int funAlta (EPersona[],int);

/**
 * Borra la persona buscada
 * \param EPersona Se le pasa la estructura con la que se va a trabajar.
 * \param int La cantidad de estructuras disponibles.
 *
 */
void funBorrar(EPersona lista[],int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * \param int La cantidad de estucturas disponibles.
 * @return el primer indice disponible.
 */
int funobtenerEspacioLibre(EPersona lista[], int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * \param  int La cantidad de estructuras disponibles
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int funbuscarPorDni(EPersona lista[], int dni, int);

/**
 * Funcion para mostrar los datos dentro de la estructura
 * \param se le pasa la estructura
 * \return void
 *
 */
void funmostrarPersona(EPersona);

/**
 * Funcion para mostrar todas las personas cargadas en la estructura
 * \param lista[] EPersona Estructura a usar
 * \param int Tamaño de la estructura
 *
 */
void funMostrarTodasPersonas(EPersona lista[], int);

/**
 * Ordena la lista por nombre
 * \param EPersona Se le pasa la estructura con la que se va a trabajar.
 * \param int La cantidad de estructuras disponibles.
 *
 */
void funOrdenarporNombre(EPersona lista[], int);

/**
 * Genera un grafico ordenado segun la edad
 * \param EPersona Se le pasa la estructura con la que se va a trabajar.
 * \param int La cantidad de estructuras disponibles.
 * \return void
 *
 */
void funGrafico(EPersona lista[], int);

/**
 * Cuenta la cantidad de una edad
 * \param EPersona Se le pasa la estructura con la que se va a trabajar.
 * \param int La cantidad de estructuras disponibles.
 * \param int contador Vector para almacenar los maximos de edades segun el rango <18, >18 && <=35 y >35
 *
 */
void funcontarEdad(EPersona lista[], int, int contador[]);

/**
 * Compara cual de los vectores tiene la mayor cantidad de edades
 * \param Vector a utilizar para obtener el maximo
 * \param La cantidad de vectores a comparar
 * \return Devuelve la cantidad más grande que tiene el vector
 *
 */
int funobtenerMaximo(int [], int );

/**
 * Chequea que lo ingresado en sea un numero y que sea positivo
 * \param int El numero ingresado
 * \return retorno Devuelve 0 si es un numero o 1 si no lo es
 *
 */
int funchequeoNumero(int);

/**
 * Chequea que lo ingresado en sean letras
 * \param char Las letras que se ingresaron
 * \return int Devuelve 0 si son solo letras o 1 si no lo son
 *
 */
int funchequeoLetras(char[50]);

/** \brief
 * Chequea que el DNI ingresado no este ya cargado
 * \param EPersona Se le pasa la estructura con la que se va a trabajar.
 * \param int t La cantidad de estructuras disponibles.
 * \param int El DNI ingresado
 * \return int Devuelve 0 si el DNI no esta cargado o 1 si ya esta cargado
 *
 */
int funchequeoDni (EPersona lista[], int t, int);
#endif // FUNCIONES_H_INCLUDED
