#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 100


/** \brief Solicita un numero entero al usuario y lo valida.
 *
 * \param input int* Se carga el numero ingresado.
 * \param message char* Es el mensaje mostrado pidiendo el ingreso del numero.
 * \param eMessage char* Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit int Limite inferior a validar.
 * \param hiLimit int Limite superior a validar.
 * \return int Retorna (0) si el numero ingresado no es valido - (1) si es valido.
 *
 */
int getInt(int* input, char* message, char* eMessage, int lowLimit, int hiLimit)
{
    int isValid = 0;
    int invalidDigit = 0;
    char auxInput[MAX_CHARACTERS];
    int auxInt;
    int length;
    int i;

    fflush(stdin);
    printf("%s", message);
    gets(auxInput);
    length = strlen(auxInput);

    for(i=0; i<length; i++)
    {
        if(i == 0 && !isdigit(auxInput[i]) && auxInput[i]!= '-')
        {   //Valida que en la primera posicion haya un digito o un signo menos
            invalidDigit = 1;
            break;
        }
        else if(i != 0 && !isdigit(auxInput[i]))
        {   //Valida que en el resto de la cadena solo haya digitos
            invalidDigit = 1;
            break;
        }
    }

    if(!invalidDigit)
    {
        auxInt = atoi(auxInput);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            puts(eMessage);
        }
        else
        {
            isValid = 1;
            *input = atoi(auxInput);
        }
    }
    else
    {
        puts(eMessage);
    }

    return isValid;
}//END getInt


/** \brief Solicita un caracter al usuario y lo valida.
 *
 * \param input char* Se carga el caracter ingresado.
 * \param message char* Es el mensaje mostrado pidiendo el ingreso del caracter.
 * \param eMessage char* Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit int Limite inferior a validar.
 * \param hiLimit int Limite superior a validar.
 * \return int Retorna (0) si el caracter ingresado no es valido - (1) si es valido.
 *
 */
int getChar(char* input, char* message, char* eMessage, char lowLimit, char hiLimit)
{
    int isValid = 0;
    char auxChar;

    fflush(stdin);
    printf("%s", message);
    auxChar = getche();

    lowLimit = tolower(lowLimit);
    hiLimit = tolower(hiLimit);
    auxChar = tolower(auxChar);
    if(auxChar < lowLimit || auxChar > hiLimit)
    {
        puts(eMessage);
    }
    else
    {
        isValid = 1;
        *input = auxChar;
    }

    return isValid;
}//END getChar


/** \brief Solicita una cadena con el nombre\s de una persona o lugar (depende del parametro mesage)
           y lo valida.
 *
 * \param input char* Se carga la cadena con el nombre.
 * \param message char* Es el mensaje mostrado pidiendo el ingreso de la cadena.
 * \param eMessage char* Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit int Longitud minima del
 * \param hiLimit int Longitud maxima del.
 * \return int Retorna (0) si la cadena no es valido[Tenga caracteres que no sean letras o tenga 2
 *             espacios seguidos - (1) si es valido.
 *
 */
int getName(char* input, char* message, char* eMessage, int lowLimit, int hiLimit)
{
    int isValid = 0;
    int invalidChar = 0;
    char auxInput[MAX_CHARACTERS];
    int length;
    int i;

    fflush(stdin);
    printf("%s", message);
    gets(auxInput);

    length = strlen(auxInput);
    for(i=0; i<length; i++)
    {
        if(i == 0 && (auxInput[i] < 'A' || auxInput[i] > 'Z') && (auxInput[i] < 'a' || auxInput[i] > 'z'))
        {   //Valida que el primer caracter sea una letra
            invalidChar = 1;
            break;
        }
        else if(i != 0 && (auxInput[i] != ' ' || (auxInput[i] == ' ' && auxInput[i-1] == ' ')) && (auxInput[i] < 'A' || auxInput[i] > 'Z') && (auxInput[i] < 'a' || auxInput[i] > 'z'))
        {   //Valida que los siguientes caracteres sean letras o espacios(no mas de uno entre letra y letra)
            invalidChar = 1;
            break;
        }
    }
    if(length < lowLimit || length > hiLimit || invalidChar)
    {
        puts(eMessage);
    }
    else
    {
        isValid = 1;
        strcpy(input, auxInput);
    }

    return isValid;
}//END getName
