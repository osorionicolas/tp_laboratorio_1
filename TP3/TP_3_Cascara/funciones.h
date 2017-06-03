#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char titulo[30];
    char genero[20];
    int  duracion;
    char descripcion[500];
    int  puntaje;
    char linkImagen[400];

}EMovie;


FILE *pArch, *nuevo;

int validarNumero(char mensaje[]);
void validarCadena(char mensaje[], char input[], int);
void validarCadenaAlfa(char mensaje[], char input[], int);

void iniciarStructMovie(EMovie*);


int agregarPelicula(EMovie*);
void borrarPelicula(EMovie*);
void modificarPelicula(EMovie*);
int buscarPelicula(EMovie*);

void generarPagina(EMovie*);
void iniciarFileBinario(char*, char*);
void mostrarPelicula(EMovie*);


#endif // FUNCIONES_H_INCLUDED
