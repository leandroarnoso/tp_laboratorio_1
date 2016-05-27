/**************************************************************************************************

*PROGRAMA: Trabajo Practico Nº3
*
*OBJETIVO:
        Definir una estructura “movie” con los datos de una pelicula:
            • Título
            • Género
            • Duración
            • Descripción
            • Puntaje
            • Link de imagen
        Realizar un programa que permita agregar, borrar y modificar peliculas en un archivo binario
        mediante un menú:
            1. Agregar película
            2. Modificar pelicula
            3. Borrar película
            4. Generar página web
            5. Salir
        La opción 4, listará las peliculas pero no por pantalla, sino generando un archivo html.
        Crear una función que reciba un array de estructuras movie y el nombre del archivo html de
        salida, y se encargue de generarlo.
*
*VERSION 1.0 del 27 de Mayo de 2016
*AUTOR: Leandro Maximiliano Arnoso
*

***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "funciones.h"

#define MAX_MOVIES 200
#define FILE_HTML "MOVIE LIST.html"
#define FILE_BIN "data.bin"
#define ADD '1'
#define MODIFY '2'
#define DELETE '3'
#define CREATE_HTML '4'
#define SAVE '5'
#define ESC 27


int main()
{
    // arrays de peliculas
    sMovie movieArray[MAX_MOVIES];
    initMovieArray(movieArray, MAX_MOVIES);
    //________________________________________________

    // variables auxiliares
    char titleAux[40];
    char genreAux[40];
    int durationAux;
    char descriptionAux[500];
    int scoreAux;
    char linkImageAux[250];
    //________________________________________________

    char option = 0;
    char answer = 0;
    int movieArrayEmpty;
    int freePlaceIndex;
    int foundIndex;

    loadMovieFile(movieArray, MAX_MOVIES, FILE_BIN);
	checkMovieArrayEmpty(movieArray ,MAX_MOVIES, &movieArrayEmpty);

    while(option != ESC)
    {
        showMenu("\n------------  ABM PELICULAS  ------------\n\n"
                 "1- Agregar pelicula\n2- Modificar Pelicula\n3- Borrar pelicula\n4- Generar pagina web\n5- Guardar\n\nESC- Salir\n");
        option = getChar("\nIngrese la opcion: ");

        switch(option)
        {
            case ADD:  // ALTA PELICULA
                freePlaceIndex = findMovieEmptyPlace(movieArray, MAX_MOVIES);
                if(freePlaceIndex == -1)
                {
                    getChar("\n\nNO QUEDAN LUGARES LIBRES!!!\n\n\nENTER (para continuar)");
                    break;
                }

                if(!getValidString("\nIngrese el titulo de la pelicula: ","El titulo de la pelicula no debe exceder los 40 caracteres\n", titleAux, 1, 40))
                {
                    break;
                }
                if(findMovieByTitle(movieArray, MAX_MOVIES, titleAux) != -1)
                {
                    getChar("\n\nLA PELICULA YA EXISTE!!!\n\n\nENTER (para continuar)");
                    break;
                }

                if(!getValidString("\nIngrese el genero de la pelicula: ","El genero de la pelicula no debe exceder los 40 caracteres\n", genreAux, 1, 40))
                {
                    break;
                }
                if(!getValidInt("\nIngrese la duracion de la pelicula: ","La duracion debe ser en minutos\n", &durationAux, 70, 240))
                {
                    break;
                }
                if(!getValidString("\nIngrese la descripcion de la pelicula: ","La descripcion de la pelicula no debe exceder los 150 caracteres\n", descriptionAux, 1, 500))
                {
                    break;
                }
                if(!getValidInt("\nIngrese el puntaje de la pelicula: ","El puntaje de la pelicula debe ser numerico\n", &scoreAux, 1, 100))
                {
                    break;
                }
                if(!getValidString("\nIngrese el link de la imagen de la pelicula: ","El link no puede exceder los 250 caracteres\n", linkImageAux, 1, 250))
                {
                    break;
                }

                setMovie(movieArray, freePlaceIndex, titleAux, genreAux, durationAux, descriptionAux, scoreAux, linkImageAux);
                movieArrayEmpty = 0;
                getChar("\n\nLa pelicula se ha agregado con exito. ENTER (para continuar)");

                break;

            case MODIFY:  // MODIFICAR PELICULA
                if(movieArrayEmpty)
                {
                    getChar("\n\nNO HAY NINGUNA PELICULA EN EL ABM\n\n\nENTER (para continuar)");
                    break;
                }

                if(!getValidString("\nIngrese el titulo de la pelicula: ","El titulo de la pelicula no debe exceder los 40 caracteres\n", titleAux, 1, 40))
                {
                    break;
                }
                foundIndex = findMovieByTitle(movieArray, MAX_MOVIES, titleAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA LA PELICULA DE TITULO: %s\n", titleAux);
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                modifyMovie(movieArray, foundIndex);

                break;

            case DELETE:  // BAJA PELICULA
                if(movieArrayEmpty)
                {
                    getChar("\n\nNO HAY NINGUNA PELICULA EN EL ABM\n\n\nENTER (para continuar)");
                    break;
                }

                if(!getValidString("\nIngrese el titulo de la pelicula: ","El titulo de la pelicula no debe exceder los 40 caracteres\n", titleAux, 1, 40))
                {
                    break;
                }
                foundIndex = findMovieByTitle(movieArray, MAX_MOVIES, titleAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA LA PELICULA DE TITULO: %s\n", titleAux);
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                movieArray[foundIndex].isEmpty = 1;
                checkMovieArrayEmpty(movieArray,MAX_MOVIES,&movieArrayEmpty);
                getChar("\n\nLa pelicula se ha dado de baja con exito. ENTER (para continuar)");

                break;

            case CREATE_HTML:  // CREAR HTML
                if(movieArrayEmpty)
                {
                    getChar("\n\nNO HAY NINGUNA PELICULA EN EL ABM\n\n\nENTER (para continuar)");
                    break;
                }

                createMovieHtml(movieArray, MAX_MOVIES, FILE_HTML);

                break;

            case SAVE:
                saveMovieFile(movieArray, MAX_MOVIES, FILE_BIN);

                break;

            case ESC:
                answer = getChoice("\nDesea guardar los cambios S/N?: ", 's', 'n');
                if(answer == 's')
                {
                    saveMovieFile(movieArray, MAX_MOVIES, FILE_BIN);
                }
                printf("\nSayonara\n\n");
        }
    }

    return 0;
}
