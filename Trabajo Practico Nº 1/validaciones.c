#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "constantes.h"


/** \brief  Valida si la opcion recibida es un numero y aparecia en el menu para seleccionar.
            Devuelve 1 si es valido y 0 en caso contrario
 *
 * \param   menu Tipo de menu que se mostro al usuario para validar la opcion
 * \param   opcion Numero entero a validar
* \return  Devuelve 1 si es valido y 0 en caso contrario
 *
 */
int validarOpcion(int menu, int opcion)
{
    int opcionValida = 1;

    switch(menu)
    {
        case MENU_SIN_OPERANDOS:
            if(opcion!=INGRESAR_1ER_OPERANDO && opcion!=INGRESAR_2DO_OPERANDO && opcion!=SALIR)
            {
                opcionValida = 0;
            }
            break;

        case MENU_SOLO_1ER_OPERANDO:
            if(opcion!=INGRESAR_1ER_OPERANDO && opcion!=INGRESAR_2DO_OPERANDO && opcion!=FACTORIAL && opcion!=SALIR)
            {
                opcionValida = 0;
            }
            break;

        case MENU_AMBOS_OPERANDOS:
            if(opcion<1 || opcion>9)
            {
                opcionValida = 0;
            }
            break;

    }//FIN SWITCH

    return opcionValida;

}//FIN FUNCION


/** \brief  Recibe un string y valida si el string se puede pasar a entero. Retorna 1 si se puede y 0 en caso contrario
 *
 * \param   numero[] Cadena de caracteres a validar
 * \return  Retorna 1 si es valido y 0 en caso contrario
 *
 */
int validarNumeroEntero(char numero[MAXIMO_CARACTERES])
{
    int numeroValido = 1;
    int primeraEjecucionCiclo = 1;
    int i;

    i = 0;
    while(i<strlen(numero))
    {
        if(primeraEjecucionCiclo && !isdigit(numero[i]) && numero[i]!='-')
        {
            numeroValido = 0;
            break;
        }
        else if(!primeraEjecucionCiclo && !isdigit(numero[i]))
        {
            numeroValido = 0;
            break;
        }

        primeraEjecucionCiclo = 0;
        i++;

    }//FIN WHILE

    return numeroValido;

}//FIN FUNCION


/** \brief  Valida si el numero es distinto de cero. Devuelve 1 si es distinto y 0 en caso contrario
 *
 * \param   divisor Numero entero a validar
 * \return  Devuelve 1 si es distinto y 0 en caso contrario
 *
 */

int validarDivision(int divisor)
{
    int divisionValida = 1;

    if(divisor==0)
    {
        divisionValida = 0;
    }

    return divisionValida;

}//FIN FUNCION


/** \brief  Valida si se puede realizar el factorial de un numero. Devuelve 1 si es posible y 0 en caso contrario
 *
 * \param   factor Numero entero a validar
 * \return  Devuelve 1 si es valido el calculo y 0 en caso contrario
 *
 */
int validarFactorial(int factor)
{
    int factorialValido = 1;

    if(factor<0)
    {
        factorialValido = 0;
    }

    return factorialValido;

}//FIN FUNCION

