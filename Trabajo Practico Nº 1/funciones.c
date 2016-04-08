

/** \brief  Recibe dos numeros enteros y retorna la suma entre ambos
 *
 * \param   numero1 Primer operando entero
 * \param   numero2 Segundo operando entero
 * \return  La suma entera entre ambos operandos
 *
 */
int sumar(int numero1, int numero2)
{
    return numero1 + numero2;

}//FIN FUNCION


/** \brief  Recibe dos numeros enteros y retorna la resta entre ambos
 *
 * \param   numero1 Primer operando entero
 * \param   numero2 Segundo operando entero
 * \return  La resta entera entre ambos operandos
 *
 */
int restar(int numero1, int numero2)
{
    return numero1 - numero2;

}//FIN FUNCION


/** \brief  Recibe dos numeros enteros y retorna la division entre ambos con decimales
 *
  * \param   numero1 Primer operando entero (dividendo)
 * \param   numero2 Segundo operando entero distinto de cero (divisor)
 * \return  La division entre ambos operandos con decimales
 *
 */
float dividir(int numero1, int numero2)
{
    return numero1 / (float)numero2;

}//FIN FUNCION


/** \brief  Recibe dos numeros enteros y retorna la multiplicacion entre ambos
 *
 * \param   numero1 Primer operando entero
 * \param   numero2 Segundo operando entero
 * \return  La multiplicacion entera entre ambos operandos
 *
 */
int multiplicar(int numero1, int numero2)
{
    return numero1 * numero2;

}//FIN FUNCION


/** \brief  Recibe un numero entero y retorna el facrtorial
 *
 * \param   numero Operando entero mayor o igual a cero
 * \return  El factorial del operando
 *
 */
long long int factorial(int numero)
{
    int i;
    long long int resultado = 1;

    for(i=numero; i>1; i--)
    {
        resultado = numero * factorial(numero-1);
    }

    return resultado;

}//FIN FUNCION
