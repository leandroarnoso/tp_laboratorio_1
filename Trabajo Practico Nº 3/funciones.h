#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char title[40];
    char genre[40];
    int duration;
    char description[500];
    int score;
    char linkImage[250];
    int isEmpty;

}sMovie;

void showMenu(char* menu);

int initMovieArray(sMovie* movieArray, int length);
void checkMovieArrayEmpty(sMovie* movieArray, int length, int* movieArrayEmpty);
int findMovieEmptyPlace(sMovie* movieArray, int length);
int findMovieByTitle(sMovie* movieArray, int length, char* titleAux);
void setMovie(sMovie* movieArray, int freePlaceIndex, char* titleAux, char* genreAux, int durationAux, char* descriptionAux, int scoreAux, char* linkImageAux);
void modifyMovie(sMovie* movieArray, int foundIndex);

int loadMovieFile(sMovie* arrayMovie, int length, char* fileName);
int saveMovieFile(sMovie* arrayMovie, int length, char* fileName);
void printMovieHtml(FILE *movieFile, sMovie movie);
int createMovieHtml(sMovie* arrayMovie, int length, char* fileName);

#endif // FUNCIONES_H_INCLUDED
