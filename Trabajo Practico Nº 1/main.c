/**************************************************************************************************

*PROGRAMA: Trabajo Practico Nº1 - Calculadora
*
*OBJETIVO:
    Ingresar 1 o 2 operandos (numeros enteros), seleccionar un calculo
    matematico (suma, resta, division, multiplicacion, factorial) y
    mostrar por pantalla el resultado.
*
*VERSION 1.0 del 07 de Abril de 2016
*AUTOR: Leandro Maximiliano Arnoso
*

***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"

#include "interfaz.h"
#include "validaciones.h"
#include "funciones.h"



int main(void)
{
    char seguir='s';
    int opcion;
    int numero1;
    int numero2;
    int flagNumero1 = 0;
    int flagNumero2 = 0;
    int menu;
    int resultado;
    float cociente;
    long long int resultadoFactorial;

    while(seguir=='s')
    {
        menu = mostrarMenu(flagNumero1, flagNumero2, numero1, numero2);
        opcion = pedirOpcion(menu);

        switch(opcion)
        {
            case OPCION_INVALIDA:
                mostrarError(ERROR_OPCION_INVALIDA);
                break;

            case INGRESAR_1ER_OPERANDO:
                numero1 = pedirNumero();
                flagNumero1 = 1;
                break;

            case INGRESAR_2DO_OPERANDO:
                numero2 = pedirNumero();
                flagNumero2 = 1;
                break;

            case SUMA:
                resultado = sumar(numero1, numero2);
                mostrarSuma(numero1, numero2, resultado);
                break;

            case RESTA:
                resultado = restar(numero1, numero2);
                mostrarResta(numero1, numero2, resultado);
                break;

            case DIVISION:
                if(validarDivision(numero2))
                {
                    cociente = dividir(numero1, numero2);
                    mostrarDivision(numero1, numero2, cociente);
                }
                else
                {
                    mostrarError(ERROR_DIVISION_POR_CERO);
                }
                break;

            case MULTIPLICACION:
                resultado = multiplicar(numero1, numero2);
                mostrarMultiplicacion(numero1, numero2, resultado);
                break;

            case FACTORIAL:

                if(validarFactorial(numero1))
                {
                    resultadoFactorial = factorial(numero1);
                    mostrarFactorial(numero1, resultadoFactorial);
                }
                else
                {
                    mostrarError(ERROR_FACTORIAL_NEGATIVO);
                }
                break;

            case CALCULAR_TODAS:
                resultado = sumar(numero1, numero2);
                mostrarSuma(numero1, numero2, resultado);

                resultado = restar(numero1, numero2);
                mostrarResta(numero1, numero2, resultado);

                if(validarDivision(numero2))
                {
                    cociente = dividir(numero1, numero2);
                    mostrarDivision(numero1, numero2, cociente);
                }
                else
                {
                    mostrarError(ERROR_DIVISION_POR_CERO);
                }

                resultado = multiplicar(numero1, numero2);
                mostrarMultiplicacion(numero1, numero2, resultado);

                if(validarFactorial(numero1))
                {
                    resultadoFactorial = factorial(numero1);
                    mostrarFactorial(numero1, resultadoFactorial);
                }
                else
                {
                    mostrarError(ERROR_FACTORIAL_NEGATIVO);
                }
                break;

            case SALIR:
                seguir = 'n';
                printf("Sayonara\n");
                break;

        }//FIN SWITCH

        if(opcion!=INGRESAR_1ER_OPERANDO && opcion!=INGRESAR_2DO_OPERANDO && opcion!=SALIR)
        //pausar el prog para ver los resultados y/o errores
        {
            system("pause");
        }

    }//FIN WHILE

    return 0;
}//FIN MAIN
