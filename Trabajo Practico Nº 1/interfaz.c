#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"

#include "validaciones.h"


/** \brief  Muestra por pantalla un menu de opciones y retorna el tipo de menu que se esta mostrando
 *
 * \param   flagNumero1 Indica si existe numero1 para mostrar
 * \param   flagNumero2 Indica si existe numero2 para mostrar
 * \param   numero1 Numero entero a mostrar en el menu
 * \param   numero2 Otro numero entero a mostrar en el menu
 * \return  Devuelve el tipo de menu que se esta mostrando
 *
 */
int mostrarMenu(int flagNumero1, int flagNumero2, int numero1, int numero2)
{
    int menu = MENU_SIN_OPERANDOS;

    system("cls");
    fflush(stdin);

    printf("   -----CALCULADORA-----\n\n");

    if(flagNumero1)    //printf de la primera opcion segun se haya ingresado el primer operando o no
    {
        printf("1- Ingresar 1er operando (A=%d)\n", numero1);
    }
    else
    {
        printf("1- Ingresar 1er operando (A=' ')\n");
    }

    if(flagNumero2)   //Idem anterior pero con el segundo operando
    {
        printf("2- Ingresar 2do operando (B=%d)\n", numero2);
    }
    else
    {
        printf("2- Ingresar 2do operando (B=' ')\n");
    }

    if(flagNumero1 && flagNumero2)
    {
        menu = MENU_AMBOS_OPERANDOS;
        printf("3- Calcular la suma (A+B)\n"
               "4- Calcular la resta (A-B)\n"
               "5- Calcular la division (A/B)\n"
               "6- Calcular la multiplicacion (A*B)\n"
               "7- Calcular el factorial (A!)\n"
               "8- Calcular todas las operacione\n");
    }
    else if(flagNumero1)
    {
        menu = MENU_SOLO_1ER_OPERANDO;
        printf("7- Calcular el factorial (A!)\n");
    }

    printf("9- Salir\n\n");

    return menu;

}//FIN FUNCION


/** \brief  Recibe tres numeros enteros y los muestra por pantalla con un mensaje
 *
 * \param   numero1 Numero que representa el 1er operando que hay que mostrar
 * \param   numero2 Numero que representa el 2do operando que hay que mostrar
 * \param   resultado Numero que representa el resultado a mostrar
 *
 */
void mostrarSuma(int numero1, int numero2, int resultado)
{
    printf("SUMA:\n%d + %d = %d\n\n", numero1, numero2, resultado);

}//FIN FUNCION


/** \brief  Recibe tres numeros enteros y los muestra por pantalla con un mensajee
 *
 * \param   numero1 Numero que representa el 1er operando que hay que mostrar
 * \param   numero2 Numero que representa el 2do operando que hay que mostrar
 * \param   resultado Numero que representa el resultado a mostrar
 *
 */
void mostrarResta(int numero1, int numero2, int resultado)
{
    printf("RESTA:\n%d - %d = %d\n\n", numero1, numero2, resultado);

}//FIN FUNCION


/** \brief  Recibe tres numeros enteros y los muestra por pantalla con un mensaje
 *
 * \param   numero1 Numero que representa el 1er operando que hay que mostrar
 * \param   numero2 Numero que representa el 2do operando que hay que mostrar
 * \param   resultado Numero que representa el resultado a mostrar
 *
 */
void mostrarDivision(int numero1, int numero2, float resultado)
{
    printf("DIVISION:\n%d / %d = %.2f\n\n", numero1, numero2, resultado);

}//FIN FUNCION


/** \brief  Recibe tres numeros enteros y los muestra por pantalla con un mensaje
 *
 * \param   numero1 Numero que representa el 1er operando que hay que mostrar
 * \param   numero2 Numero que representa el 2do operando que hay que mostrar
 * \param   resultado Numero que representa el resultado a mostrar
 *
 */
void mostrarMultiplicacion(int numero1, int numero2, int resultado)
{
    printf("MULTIPLICACION:\n%d * %d = %d\n\n", numero1, numero2, resultado);

}//FIN FUNCION


/** \brief  Recibe dos numeros enteros y los muestra por pantalla con un mensaje
 *
 * \param   numero Numero al que se le calculo el factorial que hay que mostrar
 * \param   resultado Numero que representa el resultado a mostrar
 *
 */
void mostrarFactorial(int numero, long long int resultado)
{
    printf("FACTORIAL:\n%d! = %lld\n\n", numero, resultado);

}//FIN FUNCION


/** \brief  Muestra por pantalla un mensaje de error
 *
 * \param   error Tipo de error que indica que mensaje mostrar
 *
 */
void mostrarError(int error)
{
    switch(error)
    {
        case ERROR_OPCION_INVALIDA:
            printf("\n----ERROR----\nUsted ingreso una opcion no valida.\n\n");
            break;

        case ERROR_NUMERO_INVALIDO:
            printf("\n----ERROR----\nUsted no ingreso un numero entero.\n\n");
            break;

        case ERROR_DIVISION_POR_CERO:
            printf("DIVISION:\n----ERROR MATEMATICO----\nNo se puede dividir por cero(0).\n\n");
            break;

        case ERROR_FACTORIAL_NEGATIVO:
            printf("FACTORIAL:\n----ERROR MATEMATICO----\nNo existe el factorial de un numero negativo.\n\n");
            break;

    }//FIN SWITCH

}//FIN FUNCION


/** \brief  Solicita una opcion al usuario y la valida. Devuelve la opcion ingresada si es valida o -1 en caso contrario
 *
 * \param   menu Es el tipo de menu que se le mostro al usuario para validar la opcion
 * \return  La opcion ingresada por el usuario si es valida o -1 en caso contrario
 *
 */
int pedirOpcion(int menu)
{
    char opcionAux[MAXIMO_CARACTERES];
    int opcion;

    printf("Ingrese una opcion: ");
    scanf("%s", opcionAux);

    if(!validarNumeroEntero(opcionAux) )
    {
        opcion = OPCION_INVALIDA;
    }
    else
    {
        opcion = atoi(opcionAux);

        if(!validarOpcion(menu, opcion))
        {
            opcion = OPCION_INVALIDA;
        }
    }

    printf("\n\n-----------------------\n\n");

    return opcion;

}//FIN FUNCION


/** \brief  Solicita un numero entero al usuario, lo valida y devuelve
 *
 * \return  El numero ingresado por el usuario validado
 *
 */
int pedirNumero()
{
    char numeroAux[MAXIMO_CARACTERES];
    int numero;
    int esNumero;

    do
    {
        system("cls");
        fflush(stdin);
        printf("Ingrese un numero entero: ");
        scanf("%s", &numeroAux);

        esNumero = validarNumeroEntero(numeroAux);
        if(!esNumero)
        {
            mostrarError(ERROR_NUMERO_INVALIDO);
            system("pause");
        }

    }while(!esNumero);

    numero = atoi(numeroAux);

    return numero;

}//FIN FUNCION
