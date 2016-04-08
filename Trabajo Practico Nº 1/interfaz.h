#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED


int mostrarMenu(int flagNumero1, int flagNumero2, int numero1, int numero2);

void mostrarSuma(int numero1, int numero2, int resultado);

void mostrarResta(int numero1, int numero2, int resultado);

void mostrarDivision(int numero1, int numero2, float resultado);

void mostrarMultiplicacion(int numero1, int numero2, int resultado);

void mostrarFactorial(int numero, long long int resultado);

void mostrarError(int error);

int pedirOpcion(int menu);

int pedirNumero(void);


#endif
