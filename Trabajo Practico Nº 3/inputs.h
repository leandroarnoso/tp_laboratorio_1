#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED


char getChar(char* message);
char getChoice(char* message, char choice1, char choice2);
void getString(char* menssage, char* input);

int validateNumber(char* str);

int getNumberString(char* menssage, char* input);

int getValidInt(char* requestMessage, char* errorMessage, int* input, int lowLimit, int hiLimit);
int getValidString(char* requestMessage,char* errorMessage, char* input, int lowLimit, int hiLimit);


#endif // INPUTS_H_INCLUDED
