#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


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


int main()
{
    char seguir='s';
    int opcion=0;
    int i;

    EPersona lista [CANT];
    iniciarStruct(lista, CANT);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        opcion=validarNumero("Ingrese una opcion: ");
        printf("\n");

        switch(opcion)
        {
            case 1:
                {
                    agregarPersona(lista, CANT);
                    break;
                }
            case 2:
                {
                    borrarPersona("Ingrese el dni de la persona a borrar: ",lista, CANT);
                    break;
                }
            case 3:
                {
                    ordenarPersona(lista, CANT);
                    break;
                }
            case 4:
                {
                    graficar(lista,CANT);
                    break;
                }
            case 5:
                seguir = 'n';
                break;
            default:
                {
                    printf("El numero ingresado no es valido\n");
                    break;
                }
        }
    }
    return 0;
}
