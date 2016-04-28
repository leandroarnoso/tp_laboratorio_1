#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#define MAX_PEOPLE 20
#define MIN_ID 1000000
#define MAX_ID 99999999
#define MIN_LENGTH_NAME 2
#define MAX_LENGTH_NAME 50
#define MIN_AGE 1
#define MAX_AGE 99
#define ASCENDING_ORDER 1
#define INVALID_OPTION '0'
#define ADD_PERSON '1'
#define REMOVE_PERSON '2'
#define PRINT_LIST '3'
#define PRINT_BARS_GRAPHIC '4'
#define EXIT_PROGRAM '5'

typedef struct
{
    int id;
    char name[MAX_LENGTH_NAME];
    int age;
    int isEmpty;

}sPerson;

#endif //STRUCT_INCLUDED
