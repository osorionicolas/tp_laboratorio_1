#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANT 30

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

void agregarPersona(EPersona[], int);
void mostrarPersona(EPersona[], int);
void borrarPersona(char mensaje[40],EPersona[], int);
void ordenarPersona(EPersona[], int);
void iniciarStruct(EPersona[], int);
void graficar(EPersona[], int);
int validarNumero(char mensaje[]);
void validarCadena(char mensaje[], char input[]);
int buscarPorDni(EPersona lista[], int dni, int cantidad);
int obtenerEspacioLibre(EPersona lista[], int cantidad);

#endif // FUNCIONES_H_INCLUDED
