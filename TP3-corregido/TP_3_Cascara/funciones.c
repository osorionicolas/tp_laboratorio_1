#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

/**
 * Inicia la estructura lista
 * @param Emovie *lista pasa los datos de la estructura Emovie
 * @return void
 */
void iniciarStructMovie(EMovie *lista)
{
        lista->titulo['\0']=0;
        lista->genero['\0']=0;
        lista->descripcion['\0']=0;
        lista->linkImagen['\0']=0;
        lista->duracion=0;
        lista->puntaje=0;
}


/**
 *  Agrega una pelicula al archivo binario
 *  @param lista la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *lista)
{
    char tituloAux[30];
    iniciarFileBinario("bin.dat","ab+");
    validarCadenaAlfa("Ingrese titulo de la pelicula: ",tituloAux,30);
    rewind(pArch);
    while(!feof(pArch))
    {
        fread(&lista,sizeof(EMovie),1,pArch);
        if(strcmp(tituloAux,lista->titulo)==0)
        {
            printf("La pelicula ya existe en la base de datos\n\n");
            return main();
        }
    }
    strcpy(lista->titulo,tituloAux);
    validarCadena("Ingrese genero: ",lista->genero,20);
    do
    {
        lista->duracion=validarNumero("Ingrese duracion: ");
    }while(lista->duracion<=0);
    validarCadenaAlfa("Ingrese descripcion: ",lista->descripcion,500);
    do
    {
        lista->puntaje=validarNumero("Ingrese puntaje de la pelicula (1-10): ");
            if(lista->puntaje<1 || lista->puntaje>10)
                printf("El puntaje es erroneo\n");
    }while(lista->puntaje<1 || lista->puntaje>10);

    validarCadenaAlfa("Link de imagen: ",lista->linkImagen,400);
    fwrite(&lista,sizeof(EMovie),1,pArch);
    fclose(pArch);
    return 1;
}

/**
 *  Borra una pelicula del archivo binario
 *  @param lista la estructura a ser eliminada al archivo
 *  @return void
 */
void borrarPelicula(EMovie *lista)
{
    char respuesta;
    char titulo[30];
    iniciarFileBinario("bin.dat","rb+");
    validarCadenaAlfa("Ingrese titulo de la pelicula: ",titulo,30);
    rewind(pArch);
    while(!feof(pArch))
    {

        fread(&lista,sizeof(EMovie),1,pArch);

        if(strcmp(titulo,lista->titulo)==0)
        {
            printf("\n\n%s\n%s\n%d\n%d\n%s\n",lista->titulo,lista->genero,lista->duracion,lista->puntaje,lista->descripcion);
            break;
        }
        else if(feof(pArch))
        {
                printf("La pelicula no se encuentra en la base de datos\n");
                getch();
                system("cls");
                return main();
        }

    }

    printf("\n\nDesea eliminar la pelicula? (s/n): ");
    respuesta=getche();
    getch();
    if(respuesta=='s')
    {
    nuevo=fopen("nuevo.dat","wb");
    if (nuevo==NULL)
    {
        perror("nuevo.dat");
        exit(1);
    }

        rewind(pArch);
        while(!feof(pArch))
        {
            fread(&lista,sizeof(EMovie),1,pArch);

            if(!feof(pArch))
                {
                    if(strcmp(titulo,lista->titulo)!=0)
                    {
                        fflush(stdin);
                        fwrite(&lista,sizeof(EMovie),1,nuevo);
                    }
                }
        if(feof(pArch))
                break;
        }


    printf("\nLa pelicula fue eliminada con exito!\n\n");
    }
    else
        {
            getch();
            system ("cls");
            return;
        }
    fclose(pArch);
    fclose(nuevo);
    remove("bin.dat");
    rename("nuevo.dat","bin.dat");

    getch();
    system("cls");

}

/**
 *  Busca en el archivo binario la estructura de la pelicula ingresada
 *  @param lista puntero estructura
 *  @return retorna 1 o 0 de acuerdo a si se encontro la pelicula o no
 */
int buscarPelicula(EMovie *lista)
{
    char respuesta;
    char titulo[30];
    iniciarFileBinario("bin.dat","rb+");
    validarCadenaAlfa("Ingrese titulo de la pelicula: ",titulo,30);
    rewind(pArch);
    while(!feof(pArch))
    {

        fread(&lista,sizeof(EMovie),1,pArch);
        if(strcmp(titulo,lista->titulo)==0)
        {
            printf("\n\n%s\n%s\n%d\n%d\n%s\n",lista->titulo,lista->genero,lista->duracion,lista->puntaje,lista->descripcion);
            return 1;
        }
        else if(feof(pArch))
        {
                printf("La pelicula no se encuentra en la base de datos\n");
                getch();
                break;
        }
    }
        system("cls");
        return 0;
}


/**
 *  Modifica una pelicula del archivo binario
 *  @param lista la estructura a ser modificada al archivo
 *  @return void
 */
void modificarPelicula(EMovie *lista)
{
    char respuesta;
    int opcion;

    printf("\n\nDesea modificar la pelicula? (s/n): ");
    respuesta=getche();
    getch();
    if(respuesta=='s')
    {
        printf("\nElija el campo a modificar:\n"
        "1-Titulo\n"
        "2-Genero\n"
        "3-Duracion\n"
        "4-Descripcion\n"
        "5-Puntaje\n"
        "6-Link de imagen\n");
    opcion=validarNumero("Ingrese opcion: ");

    switch(opcion)
    {
        case 1:
        {
            validarCadena("\n\nIngrese nuevo titulo: ", lista->titulo,30);
            break;
        }
        case 2:
        {
            validarCadena("\n\nIngrese nuevo genero: ", lista->genero,20);
            break;
        }
        case 3:
        {
            do{
                lista->duracion=validarNumero("Ingrese duracion de la pelicula: ");
            }while(lista->duracion<=0);
            break;
        }
        case 4:
        {
            validarCadenaAlfa("Ingrese nueva descripcion: ", lista->descripcion,500);
            break;
        }
        case 5:
        {
            do{
                lista->puntaje=validarNumero("Ingrese puntaje de la pelicula: ");
                if(lista->puntaje<1 || lista->puntaje>10)
                    printf("El puntaje es erroneo\n");
            }while(lista->puntaje<1 || lista->puntaje>10);
            break;
        }
        case 6:
        {
            validarCadenaAlfa("Ingrese nueva url de imagen: ", lista->linkImagen,400);
            break;
        }
        default:
            {
                printf("La opcion elegida no es valida\n");
                break;
            }
    }

    fseek(pArch,(-1)*sizeof(EMovie),SEEK_CUR);
    fflush(stdin);
    fwrite(&lista,sizeof(EMovie),1,pArch);
    printf("Actualizacion exitosa!\n\n");
    getch();
    system("cls");
    fclose(pArch);
    }
    else
        system ("cls");
        return;
}


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @return void
 */
 void generarPagina(EMovie *lista)
 {
    FILE *pHtml;
    char cadena1[300];
    char cadena2[30];
    char cadena3[30];
    char cadena4[25];
    char cadena5[25];
    char cadena6[25];
    char cadena7[20];

    sprintf(cadena1,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");
    sprintf(cadena2,"alt=''></a><h3><a href='#'>");
    sprintf(cadena3,"</a></h3><ul><li>Género: ");
    sprintf(cadena4,"</li><li>Puntaje: ");
    sprintf(cadena5,"</li><li>Duración: ");
    sprintf(cadena6,"</li></ul><p>");
    sprintf(cadena7,"</p></article>");

    iniciarFileBinario("bin.dat","rb");

    if((pHtml=fopen("peliculas.html" , "w"))==NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        exit(1);
    }
    else
    {
        rewind(pArch);
        while(!feof(pArch))
        {
        fread(&lista,sizeof(EMovie),1,pArch);
        if(!feof(pArch))
        {
        fprintf(pHtml,cadena1);
        fprintf(pHtml,lista->linkImagen);
        fprintf(pHtml,cadena2);
        fprintf(pHtml,lista->titulo);
        fprintf(pHtml,cadena3);
        fprintf(pHtml,lista->genero);
        fprintf(pHtml,cadena4);
        fprintf(pHtml, "%d", lista->puntaje);
        fprintf(pHtml,cadena5);
        fprintf(pHtml, "%d", lista->duracion);
        fprintf(pHtml,cadena6);
        fprintf(pHtml,lista->descripcion);
        fprintf(pHtml,cadena7);
        }
        }
        printf("El archivo fue generado con exito\n\n");
    }

     fclose(pHtml);
     fclose(pArch);
 }


/**
 *  Genera abre el archivo binario
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param modo el modo en que se abre el archivo
 */
void iniciarFileBinario(char *nombre, char *modo)
{
    int var;
    if((pArch=fopen(nombre , modo))==NULL)
    {
        perror("bin.dat");
        printf("\nEl archivo no puede ser abierto");
        exit(1);
    }
}


/**
 * Muestra en pantalla el listado de peliculas agregadas
 * @param EMovie[] pasa los datos de la estructura EMovie
 * @return void
 */
void mostrarPelicula(EMovie *lista)
{

    iniciarFileBinario("bin.dat","rb");
    while(!feof(pArch))
    {
        fread(&lista,sizeof(EMovie),1,pArch);
        if(!feof(pArch))
            printf("\n%s\n%s\n%d\n%d\n%s\n\n",lista->titulo,lista->genero,lista->duracion,lista->puntaje,lista->descripcion);
    }
fclose(pArch);
}




                        /**< VALIDACIONES */



/**
* Obtiene una cadena y valida que sean alfanumerica
* @param mensaje mensaje que muestra en pantalla
* @param input cadena ingresada por el usuario que se valida
* @param largoCadena largo correspondiente a la cadena
* @return void
*/
void validarCadenaAlfa(char mensaje[],char input[], int largoCadena)
{
    int i=0,k, flag=0;
    char str[largoCadena];
    do
    {
        flag=0;
        printf("%s",mensaje);
        fflush(stdin);
        gets(str);
        if(strlen(str)>largoCadena)
            strcpy(str[largoCadena],'\0');

        k=strlen(str);
        for(i=0;i<k;i++)
        {
            if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i]>=0 && str[i]<=9) && (flag==0))
                    flag=1;

                    i++;
        }
            if(flag==0)
                strcpy(input,str);

            else
                printf("El nombre ingresado no es valido\n\n");

    }while (flag!=0);
}

/**
* Obtiene una cadena y valida que sean solo letras
* @param mensaje mensaje que muestra en pantalla
* @param input cadena ingresada por el usuario que se valida
* @param largoCadena largo correspondiente a la cadena
* @return void
*/
void validarCadena(char mensaje[],char input[], int largoCadena)
{
    int i=0,k, flag=0;
    char str[largoCadena];
    do
    {
        flag=0;
        printf("%s",mensaje);
        fflush(stdin);
        gets(str);
        if(strlen(str)>largoCadena)
            strcpy(str[largoCadena],'\0');

        k=strlen(str);
        for(i=0;i<k;i++)
        {
            if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (flag==0))
                    flag=1;

                    i++;
        }
            if(flag==0)
                strcpy(input,str);

            else
                printf("El nombre ingresado no es valido\n\n");

}while (flag!=0);
}

/**
 * Obtiene una cadena, valida que sea solamente numero y lo transforma
 * @param mensaje mensaje que muestra en pantalla
 * @return el numero validado
 */
int validarNumero(char mensaje[])
{
    int numero,i,k,flag=0;
    char seguir[10];
    do
    {
        flag=0;
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",&seguir);
        k=strlen(seguir);
        for(i=0;i<k;i++)
        {
            if(isdigit(seguir[i]))
                flag++;
        }
        if(flag==k)
        {
            numero=atoi(seguir);
            return numero;
        }
        else
            printf("El dato ingresado no es valido\n\n");
    }while (flag!=k);
}

