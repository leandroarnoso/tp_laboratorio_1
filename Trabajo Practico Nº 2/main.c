/**************************************************************************************************

*PROGRAMA: Trabajo Practico Nº2
*
*OBJETIVO:
        Definir una estructura que represente una persona, con los campos nombre, edad, dni y un
        flag de estado.
        Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el
        siguiente:
        1. Agregar una persona
        2. Borrar una persona
        3. Imprimir lista ordenada por nombre
        4. Imprimir gráfico de edades
        Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.
        El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
        • Menores de 18
        • De 19 a 35
        • Mayores de 35.
        En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo.
*
*VERSION 1.0 del 28 de Abril de 2016
*AUTOR: Leandro Maximiliano Arnoso
*

***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "inputs.h"
#include "funciones.h"


int main()
{
    sPerson arrayPeople[MAX_PEOPLE];
    sPerson* pPerson;
    int id;
    char name[MAX_LENGTH_NAME];
    int age;
    int arrayEmpty = 1;       //flag que indica (1) si la lista de personas esta vacia - (0) si al menos hay una persona
    int arrayFull = 0;        //flag que indica (1) si la lista de personas esta lleno - (0) si al menos hay un espacio vacio
    int validInput;           //guarda (1) si se pudo guardar el ingreso de algun dato solicitado - (0) si no se pudo
    int removeComplete;       //guarda (1) si se pudo borrar a una persona - (0) si no se pudo
    char follow = 's';
    char option;

    initPeople(arrayPeople, MAX_PEOPLE);
    do
    {
        printMainMenu();
        option = INVALID_OPTION;
        validInput = getChar(&option, "\nPresione la tecla de la opcion a la que desea acceder: ",
                             "\n\nERROR, Opcion no valida.\nPor favor intentelo nuevamente.", ADD_PERSON, EXIT_PROGRAM);
        printf("\n--------------------------------------------------------\n\n");

        switch(option)
        {
            case ADD_PERSON:
                if(!arrayFull)
                {
                    validInput = getInt(&id, "Ingrese el DNI de la persona: ",
                                        "ERROR, el DNI esta fuera de rango [1.000.000 - 99.999.999].\nPor favor, intentelo nuevamente.\n",
                                        MIN_ID, MAX_ID);
                    while(!validInput)
                    {
                        validInput = getInt(&id, "Ingrese el DNI de la persona: ",
                                            "ERROR, el DNI esta fuera de rango [1.000.000 - 99.999.999].\nPor favor, intentelo nuevamente.\n",
                                            MIN_ID, MAX_ID);
                    }
                    pPerson = findPersonById(arrayPeople, MAX_PEOPLE, id);
                    if(pPerson != NULL)
                    {
                        printf("\nLa persona con DNI %d ya existe.\n\n", id);
                        break;
                    }

                    validInput = getName(name, "\nIngrese el nombre o los de la persona: ",
                                         "ERROR, nombre no valido [2 - 50 LETRAS].\nPor favor, intentelo nuevamente.\n",
                                         MIN_LENGTH_NAME, MAX_LENGTH_NAME);
                    while(!validInput)
                    {
                        validInput = getName(name, "Ingrese el nombre o los nombres de la persona: ",
                                             "ERROR, nombre no valido [2 - 50 LETRAS].\nPor favor, intentelo nuevamente.\n",
                                             MIN_LENGTH_NAME, MAX_LENGTH_NAME);
                    }
                    convertString(name, MAX_LENGTH_NAME);

                    validInput = getInt(&age, "\nIngrese la edad de la persona: ",
                                        "ERROR, edad fuera de rango[1 - 99].\nPor favor, intentelo nuevamente.\n", MIN_AGE, MAX_AGE);
                    while(!validInput)
                    {
                        validInput = getInt(&age, "Ingrese la edad de la persona: ",
                                            "ERROR, edad fuera de rango [1 - 99].\nPor favor, intentelo nuevamente.\n", MIN_AGE, MAX_AGE);
                    }

                    addPerson(arrayPeople, MAX_PEOPLE, id, name, age);
                    printf("\nLa persona ha sido agregada con exito a la lista.\n\n");
                    arrayEmpty = 0;
                    arrayFull = checkArrayFull(arrayPeople, MAX_PEOPLE);
                }
                else
                {
                    printf("\nNo se puede agregar a otra persona debido a que la lista de personas\n"
                           "esta llena.\n\n");
                }
                break;

            case REMOVE_PERSON:
                if(!arrayEmpty)
                {
                    validInput = getInt(&id, "Ingrese el DNI de la persona que desea borrar: ",
                                        "ERROR, DNI fuera de rango [1.000.000 - 99.999.999].\nPor favor, intentelo nuevamente.\n",
                                        MIN_ID, MAX_ID);
                    while(!validInput)
                    {
                        validInput = getInt(&id, "Ingrese el DNI de la persona que desea borrar: ",
                                            "ERROR, DNI fuera de rango [1.000.000 - 99.999.999].\nPor favor, intentelo nuevamente.\n",
                                             MIN_ID, MAX_ID);
                    }

                    removeComplete = removePerson(arrayPeople, MAX_PEOPLE, id);

                    if(removeComplete)
                    {
                        printf("\nLa persona ha sido borrada con exito de la lista.\n\n");
                        arrayFull = 0;
                        arrayEmpty = checkArrayEmpty(arrayPeople, MAX_PEOPLE);
                    }
                    else
                    {
                        printf("\nNo existe la persona con el DNI %d.\n\n", id);
                    }
                }
                else
                {
                    printf("\nLa lista de personas esta vacia.\n\n");
                }
                break;

            case PRINT_LIST:
                if(!arrayEmpty)
                {
                    sortPersonByName(arrayPeople, MAX_PEOPLE, ASCENDING_ORDER);
                    printPerson(arrayPeople, MAX_PEOPLE);
                }
                else
                {
                    printf("\nLa lista de personas esta vacia.\n\n");
                }
                break;

            case PRINT_BARS_GRAPHIC:
                if(!arrayEmpty)
                {
                    printBarsGraphic(arrayPeople, MAX_PEOPLE);
                }
                else
                {
                    printf("\nLa lista de personas esta vacia.\n\n");
                }
                break;

            case EXIT_PROGRAM:
                follow = 'n';
                puts("SAYONARA");
                break;
        }//END switch
        if(follow=='s')
        {
            system("pause");
        }
    }while(follow=='s');

    return 0;
}//END main
