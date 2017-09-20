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
void cambiarEstado(EPersona[],int);

/**
 * Genera un menu segun la informacion que se le pasa y entrega la opcion elegida
 * \param char texto Son los datos que se desean mostrar
 * \return Devuelve la opcion que se elige segun el texto
 */
int mostrarMenu(char texto[]);

/**
 * Permite ingresar datos a la estructura
 * \param EPersona Se le pasa la estructura con la que se va a trabajar
 * \param int La cantidad de estucturas disponibles
 *
 */
void funAlta (EPersona[],int);

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
int obtenerEspacioLibre(EPersona lista[], int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * \param  int La cantidad de estructuras disponibles
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int);

/**
 * Funcion para mostrar los datos dentro de la estructura
 * \param se le pasa la estructura
 * \return void
 *
 */
void mostrarPersona(EPersona);

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
void contarEdad (EPersona lista[], int, int contador[]);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int obtenerMaximo (int [], int );
#endif // FUNCIONES_H_INCLUDED
