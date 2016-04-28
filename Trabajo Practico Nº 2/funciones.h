#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void printMainMenu(void);

int initPeople(sPerson* pPerson, int length);

int checkArrayFull(sPerson* pPerson, int length);

int checkArrayEmpty(sPerson* pPerson, int length);

sPerson* findPersonById(sPerson* pPerson, int length,int id);

int addPerson(sPerson* pPerson, int length, int id, char name[], int age);

int removePerson(sPerson* pPerson, int length, int id);

int sortPersonByName(sPerson* pPerson, int length, int order);

int printPerson(sPerson* pPerson, int length);

void groupPeopleByAge(sPerson* pPerson, int length, int* arrayOfAges);

int printBarsGraphic(sPerson* pPerson, int length);

int convertString(char* name, int length);

#endif //FUNCIONES_H_INCLUDED
