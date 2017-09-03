#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Funcion de Ingreso de numero
 *
 * \return retorna Entrega el numero ingresado
 *
 */

float funIngreso ();

/** \brief Funcion suma
 *
 * \param primernum Es el primer numero que ingresa el usuario
 * \param segundonum Es el segundo numero ingresado por el usuario
 * \return resultado Devuelve el resultado de la suma
 *
 */

float funSumar(float primernum,float segundonum);

/** \brief Funcion resta
 *
 * \param primernum Es el primer numero que ingresa el usuario
 * \param segundonum Es el segundo numero ingresado por el usuario
 * \return resultado Devuelve el resultado de la resta
 *
 */

float funResta(float primernum,float segundonum);

/** \brief Funcion division
 *
 * \param primernum Es el primer numero que ingresa el usuario
 * \param segundonum Es el segundo numero ingresado por el usuario
 * \return resultado Devuelve el resultado de la division
 *
 */

float funDividir (float primernum,float segundonum);

/** \brief Funcion Multiplicacion
 *
 * \param primernum Es el primer numero que ingresa el usuario
 * \param segundonum Es el segundo numero ingresado por el usuario
 * \return resultado Devuelve el resultado de la multiplicacion
 *
 */

float funMultiplicaion (float primernum,float segundonum);

/** \brief Funcion validar cero
 *
 * \param primernum Es el primer numero que ingresa el usuario
 * \param segundonum Es el segundo numero ingresado por el usuario
 * \return respuesta Entrega [0] si alguno de los numeros es 0
 *
 */
float funValidarCero (float primernum,float segundonum);

/** \brief Funcion factorial
 *
 * \param primernum Es el primer numero que ingresa el usuario
 * \return respuesta Entrega el factorial del primer numero que ingreso el usuario
 *
 */
float funFactorial (float primernum);

/** \brief Funcion Validacion de Numero positivo
 *
 * \param num Es el numero a validar
 * \return retorno Devuelve 1 si es positivo sino 0
 *
 */
float funValidarPositivos (float num);

/** \brief Funcion Validacion de numero <= a 12
 *
 * \param num Es el numero a validar
 * \return retorno Devuelve 1 si es <= sino 0
 *
 */
float funValidarMenorIgualdoce(float num);

/** \brief  Funcion Validacion de numero con coma
 *
 * \param num Es el numero ingresado
 * \return retorno Devuelve 1 di es un numero entero sino 0
 *
 */
float funValidarComa (float num);
#endif // FUNCIONES_H_INCLUDED
