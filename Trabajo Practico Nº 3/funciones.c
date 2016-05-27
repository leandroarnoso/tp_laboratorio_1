#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "funciones.h"

/** \brief Muestra por pantalla un menu.
 *
 * \param menu Cadena de caracteres que contine el menu a mostrar.
 * \return void
 *
 */
void showMenu(char* menu)
{
     system("cls");
     printf(menu);

}


/** \brief Inicializa el array de peliculas indicando que todas las posiciones estan vacias poniendo el flag (isEmpty)
 *         en TRUE(1) en todas las posiciones del array.
 *
 * \param movieArray Es el array a inicializar.
 * \param length Indica la logitud del array.
 * \return Si hay un Error [length invalido o recibe puntero NULL] (0) - Si todo Ok (1).
 *
 */
int initMovieArray(sMovie* movieArray, int length)
{
    int isOk = 0;
    int i;

    if(movieArray != NULL && length > 0)
    {
        for(i=0; i<length; i++)
        {
            movieArray[i].isEmpty = 1;
        }
        isOk = 1;
    }

    return isOk;
} // End initMovieArray


/** \brief Comprueba si un array de peliculas esta vacio.
 *
 * \param planeArray Es el array que se va a comprobar.
 * \param arrayLength Indica la logitud del array.
 * \param movieArrayEmpty Puntero al flag que indica si el array esta vacio (1) o si al menos tiene una pelicula (0).
 * \return void
 *
 */
void checkMovieArrayEmpty(sMovie* movieArray, int length, int* movieArrayEmpty)
{
    int aux = 1;
    int i;

    for(i=0; i<length; i++)
    {
        if(!movieArray[i].isEmpty)
        {
            aux = 0;
            break;
        }
    }

    *movieArrayEmpty = aux;
} // END checkMovieArrayEmpty


/**
 * \brief Busca el primer lugar no utilizado en el array.
 *
 * \param movieArray Es el array en el cual buscar.
 * \param length Indica la logitud del array.
 * \return Si hay un Error [length invalido o recibe puntero NULL o no hay espacio libre] (-1) - Si hay espacio libre la posicion del mismo (i).
 *
 */
int findMovieEmptyPlace(sMovie* movieArray, int length)
{
    int index = -1;
    int i;

    if(movieArray != NULL && length > 0)
    {
        for(i=0; i<length; i++)
        {
            if(movieArray[i].isEmpty)
            {
                index = i;
                break;
            }
        }
    }

    return index;
} // END findMovieEmptyPlace


/**
 * \brief Busca la primer ocurrencia de una pelicula mediante su titulo.
 *
 * \param movieArray Es el array en el cual buscar.
 * \param length Indica la logitud del array.
 * \param titleAux Es el valor que se busca.
 * \return Si hay un Error [length invalido o recibe puntero NULL o no hay ocurrencia] (-1) - Si hay ocurrencia la posicion del mismo (i).
 *
 */
int findMovieByTitle(sMovie* movieArray, int length, char* titleAux)
{
    int index = -1;
    int i;

    if(movieArray != NULL && length > 0)
    {
        for(i=0; i<length; i++)
        {
            if(strcmp(movieArray[i].title, titleAux) == 0 && !movieArray[i].isEmpty)
            {
                index = i;
                break;
            }
        }
    }

    return index;
} // END findMovieByTitle


/**
 * \brief Carga los valores de una pelicula.
 *
 * \param movieArray Es el array de peliculas.
 * \param freePlaceIndex Indica la posicion a setear.
 * \param titleAux Titulo de la pelicula.
 * \param genreAux Genero de la pelicula.
 * \param durationAux Duracion de la pelicula.
 * \param descriptionAux Decripcion de la pelicula.
 * \param scoreAux Puntaje de la pelicula.
 * \param linkImageAux Link de la imagen de la pelicula.
 * \return void
 *
 */
void setMovie(sMovie* movieArray, int freePlaceIndex, char* titleAux, char* genreAux, int durationAux, char *descriptionAux, int scoreAux, char* linkImageAux)
{
    strcpy(movieArray[freePlaceIndex].title, titleAux);
    strcpy(movieArray[freePlaceIndex].genre, genreAux);
    movieArray[freePlaceIndex].duration = durationAux;
    strcpy(movieArray[freePlaceIndex].description, descriptionAux);
    movieArray[freePlaceIndex].score = scoreAux;
    strcpy(movieArray[freePlaceIndex].linkImage, linkImageAux);
    movieArray[freePlaceIndex].isEmpty = 0;

}


/**
 * \brief Muestra por pantalla un menu con los campos de una pelicula y modifica el campo elegido por el usuario pidiendo el nuevo dato a guardar.
 *
 * \param movieArray Es el array de peliculas.
 * \param foundIndex Indica la posicion de la pelicula a modificar.
 * \return void
 *
 */
void modifyMovie(sMovie* movieArray, int foundIndex)
{
    // variables auxiliares
    char genreAux[40];
    int durationAux;
    char descriptionAux[150];
    int scoreAux;
    char linkImageAux[250];
    //________________________________________________

    char option = 0;

    while(option != '6')
    {
        showMenu("\n------------  MODIFICAR  ------------\n\n"
                 "1- Genero \n2- Duracion \n3- Descripcion \n4- Puntaje\n5- Link de la Imagen\n\n6- REGRESAR AL MENU PRINCIPAL\n\n\n");
        option = getChar("\nIngrese la opcion: ");

        switch(option)
        {
            case '1': // GENERO
                if(!getValidString("\nIngrese el genero de la pelicula: ","El genero de la pelicula no debe exceder los 40 caracteres\n", genreAux, 2, 20))
                {
                    break;
                }
                strcpy(movieArray[foundIndex].genre, genreAux);
                getChar("\n\nGenero modificado. ENTER (para continuar)");

                break;

            case '2': // DURACION
                if(!getValidInt("\nIngrese la duracion de la pelicula: ","La duracion debe ser en minutos\n", &durationAux, 70, 240))
                {
                    break;
                }
                movieArray[foundIndex].duration = durationAux;
                getChar("\n\nDuracion modificada. ENTER (para continuar)");

                break;

            case '3': // DESCRIPCION
                if(!getValidString("\nIngrese la descripcion de la pelicula: ","La descripcion de la pelicula no debe exceder los 500 caracteres\n", descriptionAux, 1, 500))
                {
                    break;
                }
                strcpy(movieArray[foundIndex].description, descriptionAux);
                getChar("\n\nDescripcion modificada. ENTER (para continuar)");

                break;

            case '4': // PUNTAJE
                if(!getValidInt("\nIngrese el puntaje de la pelicula: ","El puntaje de la pelicula debe ser numerico\n", &scoreAux, 1, 100))
                {
                    break;
                }
                movieArray[foundIndex].score = scoreAux;
                getChar("\n\nPuntaje modificado. ENTER (para continuar)");

                break;

            case '5': // LINK IMAGEN
                if(!getValidString("\nIngrese el link de la imagen de la pelicula: ","El link no puede exceder los 250 caracteres\n", linkImageAux, 1, 250))
                {
                    break;
                }
                strcpy(movieArray[foundIndex].linkImage, linkImageAux);
                getChar("\n\nImagen modificada. ENTER (para continuar)");

        } // END SWITCH
    } // END WHILE

} // END modifyMovie




/** \brief Carga un array con los datos de un archivo binario.
 *
 * \param movieArray Es el array de peliculas.
 * \param length Indica la logitud del array.
 * \param fileName Nombre del archivo binario.
 * \return Si hay un Error [length invalido o recibe puntero NULL o no puede abrir el fichero] (0) - Si todo Ok (1).
 *
 */
int loadMovieFile(sMovie* movieArray, int length, char* fileName)
{
    int isOk = 0;
	FILE *movieFile;

	if(movieArray != NULL && length > 0)
    {
        movieFile = fopen(fileName, "rb");
        if(movieFile == NULL)
        {
            movieFile = fopen(fileName, "wb");
        }
        else
        {
            fread(movieArray, sizeof(sMovie), length, movieFile);
        }

        if(movieFile != NULL)
        {
            fclose(movieFile);
            isOk = 1;
        }
        else
        {
            getChar("------ ERROR ------\nNo se pudo abrir el fichero. ENTER (para continuar)");
        }
    }

	return isOk;
} // END loadMovieFile


/** \brief Guarda en un archivo binario los datos de un array.
 *
 * \param movieArray Es el array de peliculas.
 * \param length Indica la logitud del array.
 * \param fileName Nombre del archivo binario.
 * \return Si hay un Error [length invalido o recibe puntero NULL o no puede abrir el fichero] (0) - Si todo Ok (1).
 *
 */
int saveMovieFile(sMovie* movieArray, int length, char* fileName)
{
    int isOk = 0;
    FILE *movieFile;

    movieFile = fopen(fileName, "wb");
    if(movieFile != NULL && movieArray != NULL && length > 0)
    {
        fwrite(movieArray, sizeof(sMovie), length, movieFile);
        fclose(movieFile);
        isOk = 1;
        getChar("\nLas peliculas fueron guardadas con exito. ENTER (para continuar)\n");
    }
    else
    {
        getChar("\n------ ERROR -----\nNo se pudo abrir el fichero. ENTER (para continuar)\n");
    }

	return isOk;
} // END saveMovieFile


/** \brief Escribe en un archivo html los datos de una pelicula.
 *
 * \param movie Pelicula a escribir.
 * \param movieFile  Archivo en el que se escribe.
 * \return void
 *
 */
void printMovieHtml(FILE *movieFile, sMovie movie)
{
     //char linkImage[250] = "http://ia.mediaimdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg";

    fprintf(movieFile, "            <article class='col-md-4 article-intro'>\n"
                       "                <a href='#'>\n");
    fprintf(movieFile, "                    <img class='img-responsive img-rounded' src='%s' alt=''>\n", movie.linkImage);
    fprintf(movieFile, "                </a>\n"
                       "                <h3>\n"
                       "                    <a href='#'>%s</a>\n"
                       "                </h3>\n", movie.title);
    fprintf(movieFile, "                <ul>\n"
                       "                    <li>Genero: %s</li>\n"
                       "                    <li>Puntaje: %d / 100</li>\n"
                       "                    <li>Duracion: %d min</li>\n"
                       "                </ul>", movie.genre, movie.score, movie.duration);
    fprintf(movieFile, "                <p>%s</p>\n"
                       "            </article>\n", movie.description);

} // END printMovieHtml


/**
 *  \brief Crea un archivo html a partir de las peliculas de un array.
 *
 *  \param movieArray Es el array de peliculas.
 *  \param length Indica la logitud del array.
 *  \param fileName Nombre del archivo html generado.
 *  \return Si hay un Error [length invalido o recibe puntero NULL o no puede abrir el fichero] (0) - Si todo Ok (1).
 */
int createMovieHtml(sMovie* movieArray, int length, char* fileName)
{
    int isOk = 0;
    FILE *movieFile;
    int i;

    movieFile = fopen(fileName, "w");

    if(movieFile != NULL && movieArray != NULL && length > 0)
    {
        fprintf(movieFile, "<html lang='en'>\n"
                           "<head>\n"
                           "    <meta charset='utf-8'>\n"
                           "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
                           "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
                           "    <title>Lista peliculas</title>\n"
                           "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
                           "    <link href='css/custom.css' rel='stylesheet'>\n"
                           "</head>\n"
                           "<body>\n"
                           "    <div class='container'>\n"
                           "        <div class='row'>\n");
        for(i=0; i<length; i++)
        {
            if(!movieArray[i].isEmpty)
            {
                printMovieHtml(movieFile, movieArray[i]);
            }
        }
        fprintf(movieFile, "        </div>\n"
                           "    </div>\n"
                           "    <script src='js/jquery-1.11.3.min.js'></script>\n"
                           "    <script src='js/bootstrap.min.js'></script>\n"
                           "    <script src='js/ie10-viewport-bug-workaround.js'></script>\n"
                           "    <script src='js/holder.min.js'></script>"
                           "</body>\n"
                           "</html>");

        fclose(movieFile);
        isOk = 1;
        getChar("\nEl archivo html se ha generado con exito. ENTER (para continuar)\n");
    }

    if(!isOk)
    {
        getChar("\n------ ERROR -----\nNo se pudo generar el archivo html. ENTER (para continuar)\n");
    }

    return isOk;
} // END creatMovieHtml
