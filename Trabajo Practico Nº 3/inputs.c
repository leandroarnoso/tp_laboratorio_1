#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado.
 *
 * \param message Es el mensaje a ser mostrado.
 * \return El caracter ingresado por el usuario.
 *
 */
char getChar(char* message)
{
    char aux;

    printf("%s", message);
    fflush(stdin);
    aux = getche();
    printf("\n");

    return aux;
}


/** \brief Solicita al usuario que elija entre 2 caracteres posibles y lo valida.
 *
 * \param message Es el mensaje a ser mostrado.
 * \param choice1 Primer caracter posible.
 * \param choice2 Segundo caracter posible.
 * \return El caracter ingresada por el usuario.
 *
 */
char getChoice(char* message, char choice1, char choice2)
{
    char aux = 0;

    while(aux != choice1 && aux != choice2)
    {
        aux = tolower(getChar(message));
    }

    return aux;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve.
 *
 * \param message Es el mensaje a ser mostrado.
 * \param input Array donde se cargará el texto ingresado.
 * \return void
 */
void getString(char* message, char* input)
{
    printf(message);
    fflush(stdin);
    gets(input);
}


/**
 * \brief Verifica si el valor recibido es numérico.
 *
 * \param str Array con la cadena a ser analizada.
 * \return (1) si es númerico - (0) si no lo es.
 *
 */
int validateNumber(char* str)
{
    int valid = 1;
    int i=0;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            valid = 0;
        }
        i++;
    }

    return valid;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve.
 *
 * \param message Es el mensaje a ser mostrado.
 * \param input Array donde se cargará el texto ingresado.
 * \return (1) si el texto contiene solo números - (0) si no.
 */
int getNumberString(char* message, char* input)
{
    int isNumber = 0;
    char aux[256];

    getString(message,aux);
    if(validateNumber(aux))
    {
        strcpy(input,aux);
        isNumber = 1;
    }

    return isNumber;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida.
 *
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato.
 * \param errorMessage Es el mensaje a ser mostrado en caso de error.
 * \return El número ingresado por el usuario.
 *
 */
int getValidInt(char* requestMessage, char* errorMessage, int* input, int lowLimit, int hiLimit)
{
    int isOk = 0;
    char auxStr[256];
    int auxInt;
    char answer = 's';

    while(1)
    {
        if (!getNumberString(requestMessage,auxStr))
        {
            printf ("%s\n", errorMessage);
            answer = getChoice("\nDesea reingresar el dato S/N?: ", 's', 'n');
            if(answer == 's')
            {
                continue;
            }
            else
            {
                break;
            }
        }

        auxInt = atoi(auxStr);
        if(auxInt<lowLimit || auxInt>hiLimit)
        {
            printf ("El numero debe ser mayor que %d y menor que %d.\n", lowLimit, hiLimit);
            answer = getChoice("\nDesea reingresar el dato S/N?: ", 's', 'n');
            if(answer == 's')
            {
                continue;
            }
        }
        break;
    }
    if(answer == 's')
    {
        *input = auxInt;
        isOk = 1;
    }

    return isOk;
}


/**
 * \brief Solicita un string.
 *
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato.
 * \param errorMessage Es el mensaje a ser mostrado en caso de error.
 * \param input Array donde se cargará el texto ingresado.
 * \return
 *
 */
int getValidString(char* requestMessage,char* errorMessage, char* input, int lowLimit, int hiLimit)
{
    int isOk = 0;
    int lengthString;
    char answer = 's';

    while(1)
    {
        getString(requestMessage, input);
        fflush(stdin);

        lengthString = strlen(input);
        if(lengthString < lowLimit || lengthString > hiLimit)
        {
            printf ("%s\n", errorMessage);
            answer = getChoice("\nDesea reingresar el dato S/N?: ", 's', 'n');
            if(answer == 's')
            {
                continue;
            }
        }
        break;
    }
    if(answer == 's')
    {
        isOk = 1;
    }

    return isOk;
}
