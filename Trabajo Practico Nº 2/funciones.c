#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"

#define BARS_QUANTITY 3

/** \brief Muestra por pantalla el menu principal.
 *
 */
void printMainMenu(void)
{
    system("cls");
    printf("1- Agregar persona\n"
           "2- Borrar persona\n"
           "3- Imprimir lista ordenada por  nombre\n"
           "4- Imprimir grafico de edades\n\n"
           "5- Salir\n");
}//END printMainMenu

/** \brief Inicializa el array people indicando que todas las posiciones estan vacias poniendo el flag (isEmpty)
 *         en TRUE(1) en todas las posiciones del array.
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del array.
 * \return int Return (0) si hay un Error [length invalido o recibe puntero NULL] - (1) si todo Ok.
 *
 */
int initPeople(sPerson* pPerson, int length)
{
    int isOk = 0;
    int i;

    if(pPerson != NULL && length > 0)
    {
        for(i=0; i<length; i++)
        {
            pPerson[i].isEmpty = 1;
        }
        isOk = 1;
    }

    return isOk;
}//End initPeople


/** \brief Verifica si el array people esta lleno.
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del array.
 * \return int Retorna (1) si esta lleno - (0) si no lo esta.
 *
 */
int checkArrayFull(sPerson* pPerson, int length)
{
    int isFull;
    int i;

    for(i=0; i<length; i++)
    {
        if(pPerson[i].isEmpty)
        {
            isFull = 0;
            break;
        }
    }

    return isFull;
}//END checkArrayFull


/** \brief Verifica si el array people esta vacio.
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del Array.
 * \return int Retorna (1) si esta vacio - (0) si no lo esta.
 *
 */
int checkArrayEmpty(sPerson* pPerson, int length)
{
    int isEmpty = 1;
    int i;

    for(i=0; i<length; i++)
    {
        if(!pPerson[i].isEmpty)
        {
            isEmpty = 0;
            break;
        }
    }

    return isEmpty;
}//END checkArrayEmpty


/** \brief Busca una persona por Id.
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del array.
 * \param id int Identificador de la persona a buscar.
 * \return sPerson* Retorna (Puntero NULL) si hay un Error [length invalido o recibe puntero NULL o no se encuentra la persona]
 *                  o (Puntero de la persona) si lo encuentra.
 *
 *
 */
sPerson* findPersonById(sPerson* pPerson, int length, int id)
{
    sPerson* auxPerson = NULL;
    int i;

    if(pPerson != NULL && length > 0)
    {
        for(i=0; i<length; i++)
        {
            if(pPerson[i].id == id && !pPerson[i].isEmpty)
            {
                auxPerson = pPerson + i;
                break;
            }
        }
    }

    return auxPerson;
}//END findPersonById


/** \brief Añade una persona al array people pasandole como datos los parametros recibidos.
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del array.
 * \param id int Identificador de la persona.
 * \param name[] char Nombre de la persona.
 * \param age int Edad de la persona.
 * \return int Retorna (0) si hay un Error [length invalido o recibe puntero NULL o no hay espacio libre] - (1) si todo Ok.
 *
 */
int addPerson(sPerson* pPerson, int length, int id, char name[], int age)
{
    int isOk = 0;
    int i;

    if(pPerson != NULL && length > 0)
    {
        for(i=0; i<length; i++)
        {
            if(pPerson[i].isEmpty)
            {
                pPerson[i].id = id;
                strcpy(pPerson[i].name, name);
                pPerson[i].age = age;
                pPerson[i].isEmpty = 0;
                isOk = 1;
                break;
            }
        }
    }

    return isOk;
}//END addPerson


/** \brief Borra una persona por Id poniendo el flag isEmpty en TRUE(1).
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del array.
 * \param id int Identificador de la persona a borrar.
 * \return int Retorna (0) si hay un Error [length invalido o recibe puntero NULL o no se encuentra la persona] - (1) si todo Ok.
 *
 */
int removePerson(sPerson* pPerson, int length, int id)
{
    int isOk = 0;
    sPerson* auxPerson;

    if(pPerson != NULL && length > 0)
    {
        auxPerson = findPersonById(pPerson, length, id);
        if(auxPerson != NULL)
        {
            auxPerson->isEmpty = 1;
            isOk = 1;
        }
    }

    return isOk;
}//END removePerson


/** \brief Ordena los elementos del array people por nombre de forma ascendente o descendente segun el parametro order.
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del array.
 * \param order int [1] indica ASCENDENTE - [0] indica DESCENDENTE.
 * \return int Retorna (0) si hay un Error [length invalido o order invalido or recibe puntero NULL] - (1) si todo Ok.
 *
 */
int sortPersonByName(sPerson* pPerson, int length, int order)
{
    sPerson auxPerson;
    int isOk = 0;
    int r;
    int i, j;

    if(pPerson != NULL && length > 0 && (order == 0 || order == 1))
    {
        for(i=0; i<length-1; i++)
        {
            if(pPerson[i].isEmpty)
            {
                continue;
            }
            for(j=i+1; j<length; j++)
            {
                if(pPerson[j].isEmpty)
                {
                    continue;
                }
                r = strcmp(pPerson[i].name, pPerson[j].name);
                if((order == 1 && r > 0) || (order == 0 && r < 0))
                {
                    auxPerson = pPerson[i];
                    pPerson[i] = pPerson[j];
                    pPerson[j] = auxPerson;
                }
            } //END for (j)
        }//END for (i)
        isOk = 1;
    }

    return isOk;
}//FIN sortPersonByName


/** \brief Muestra por pantalla en una tabla las personas en el array people.
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del array.
 * \return int Retorna (0) si hay un Error [length invalido o recibe puntero NULL] - (1) si todo Ok.
 *
 */
int printPerson(sPerson* pPerson, int length)
{
    int isOk = 0;
    int i;

    if(pPerson != NULL && length > 0)
    {
        printf("\n|   DNI    |            Nombre           | Edad |\n"
               "-------------------------------------------------\n");
        for(i=0; i<length; i++)
        {
            if(!pPerson[i].isEmpty)
                printf("| %8d | %-27s | %3d  |\n"
                       "-------------------------------------------------\n"
                       ,pPerson[i].id, pPerson[i].name, pPerson[i].age);
        }
        isOk = 1;
        }

    return isOk;
}//END printPerson


/** \brief Cuenta personas segun un criterio de edades y guarda esas cantidades en un array (peopleByRangeOfAges).
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del array.
 * \param pAges int* Puntero al array peopleByRangeOfAges.
 *
 */
void groupPeopleByAge(sPerson* pPerson, int length, int* pAges)
{
    int i;

    for(i=0; i<length; i++)
    {
        if(!pPerson[i].isEmpty && pPerson[i].age < 18)
        {
            pAges[0]++;
        }
        else if(!pPerson[i].isEmpty && pPerson[i].age > 18 && pPerson[i].age < 36)
        {
            pAges[1]++;
        }
        else if(!pPerson[i].isEmpty && pPerson[i].age > 35)
        {
            pAges[2]++;
        }
    }//END for

}//END agroupPersonByAge


/** \brief Muestra por pantalla un grafico de barras que representa las cantidades de personas segun su rango de edad
 *         (<18, entre 19-35, >35).
 *
 * \param pPerson sPerson* Puntero al array people.
 * \param length int Largo del array.
 * \return int Retorna (0) si hay Error [length invalido o recibe puntero NULL] - (1) si todo Ok
 *
 */
int printBarsGraphic(sPerson* pPerson, int length)
{
    int isOk = 0;
    int arrayPeopleByRangeOfAges[3] = {0, 0, 0};
    char bars[length][BARS_QUANTITY][4];
    int i, j;

    if(pPerson != NULL && length > 0)
    {
        groupPeopleByAge(pPerson, length, arrayPeopleByRangeOfAges);

        for(i=0; i<length; i++)
        {
            for(j=0; j<BARS_QUANTITY; j++)
            {
                if(i < arrayPeopleByRangeOfAges[j])
                {
                    strcpy(bars[i][j], "***");
                }
                else
                {
                    strcpy(bars[i][j], "   ");
                }
            }//END for (j)
        }//END for (i)

        printf("CANTIDAD DE  ^\n"
               "  PERSONAS   |\n");
        for(i=length; i>0; i--)
        {
            if(i%2 == 0)
            {
                printf("          %2d-+     %s      %s      %s\n"
                       , i, bars[i-1][0], bars[i-1][1], bars[i-1][2]);
            }
            else
            {
                printf("             |     %s      %s      %s\n"
                       , bars[i-1][0], bars[i-1][1], bars[i-1][2]);
            }
        }//END for
        printf("          ---+------+--------+--------+------->  EDAD\n"
               "            0|     <18     19-35     >35\n\n");

        isOk = 1;
    }//END if

    return isOk;
}//PrintBarsGraph


/** \brief Modifica la cadena de forma que toda la cadena queda en minuscula menos las primeras letras de cada palabra.
 *
 * \param pString char* Puntero al string a modificar
 * \param length int Largo del string.
 * \return int Retorna (0) si hay un Error [length invalido o recibe puntero NULL] - (1) si todo Ok.
 *
 */
int convertString(char* pString, int length)
{
    int isOk = 0;
    int i;

    if(pString != NULL && length > 0)
    {
        strlwr(pString);
        pString[0] = toupper(pString[0]);
        for(i=1; i<length; i++)
        {
            if(pString[i-1] == ' ')
            {
                pString[i] = toupper(pString[i]);
            }
        }
        isOk = 1;
    }

    return isOk;
}//END convertString
