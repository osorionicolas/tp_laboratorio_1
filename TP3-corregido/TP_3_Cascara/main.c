#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"




int main()
{
    char seguir='s';
    int opcion=0;
    EMovie lista;
    iniciarStructMovie(&lista);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n\n");

        opcion=validarNumero("Ingrese opcion: ");

        switch(opcion)
        {
            case 1:
                {
                    if(agregarPelicula(&lista)==1)
                        {
                            printf("\nLa pelicula fue agregada con exito!\n\n");
                            getch();
                            system("cls");
                            break;
                        }
                    else
                    {
                        printf("La pelicula no pudo ser agregada\n\n");
                        break;
                    }
                }
            case 2:
                {
                    mostrarPelicula(&lista);
                    borrarPelicula(&lista);
                    break;
                }
            case 3:
                {
                    mostrarPelicula(&lista);
                    if(buscarPelicula(&lista))
                        modificarPelicula(&lista);

                    break;
                }
            case 4:
                {
                    generarPagina(&lista);
                    break;
                }
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
