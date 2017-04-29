#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


/**
 * Obtiene una cadena y valida que sean solo letras
 * @param mensaje mensaje que muestra en pantalla
 * @param input
 * @return void
 */
void validarCadena(char mensaje[],char input[])
{
    int i=0,k, flag=0;
    char str[10];
    char error[]="error";
    do
    {
        flag=0;
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",&str);
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
 * @return void
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
            if(strlen(seguir)>8)
                printf("No se pueden ingresar mas de 8 digitos\n\n");

            numero=atoi(seguir);
            return numero;
        }
        else
            printf("El dato ingresado no es valido\n\n");
    }while (flag!=k || seguir>8);
}

/**
 * Permite el ingreso de los distintos datos de cada persona
 * @param EPersona lista[] pasa los datos de la estructura EPersona
 * @param cantidad pasa el largo del array de estructura
 * @return void
 */
void agregarPersona(EPersona lista[], int cantidad)
{
    int i,j,flag=0,auxiliarDni=1;

    i=obtenerEspacioLibre(lista, cantidad);

        validarCadena("ingrese nombre: ",lista[i].nombre);
        lista[i].edad=validarNumero("\nIngrese edad: ");
        while(lista[i].edad>100 || lista[i].edad==0)
            {
                printf("La edad ingresada no es valida\n");
                lista[i].edad=validarNumero("\nIngrese edad: ");
            }
        auxiliarDni=validarNumero("\nIngrese dni: ");

        for(j=0;j<cantidad;j++)
            {
              while (auxiliarDni==lista[j].dni)
                    {
                        if (auxiliarDni==0)
                            {
                                printf("El dni ingresado no es valido\n");
                                auxiliarDni=validarNumero("\nIngrese dni: ");
                                break;
                            }
                        printf("El dni ya fue ingresado\n");
                        auxiliarDni=validarNumero("\nIngrese dni: ");
                        break;
                    }
            }
        lista[i].dni=auxiliarDni;
        printf("\nLa persona fue agregada con exito!\n\n");
        lista[i].estado=1;
        flag=1;

        if(!flag)
            printf("No hay espacio suficiente\n");

        getch();
        system("cls");
}

/**
 * Muestra en pantalla el listado de personas agregadas
 * @param EPersona lista[] pasa los datos de la estructura EPersona
 * @param cantidad pasa el largo del array de estructura
 * @return void
 */
void mostrarPersona(EPersona lista[], int cantidad)
{
    int i;

    printf("Nombre\t\tEdad\t\tDNI\n");

    for(i=0;i<CANT;i++)
        {
            if(lista[i].estado==1)
                printf("%s\t\t%d\t\t%d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
}

/**
 * Obtiene el primer indice libre del array.
 * @param mensaje muestra el mensaje por pantalla
 * @param EPersona lista[] pasa los datos de la estructura EPersona
 * @param cantidad pasa el largo del array de estructura
 * @return void
 */
void borrarPersona(char mensaje[40], EPersona lista[], int cantidad)
{
    int dni,i;
    if(obtenerEspacioLibre(lista, cantidad==1))
        {
        mostrarPersona(lista, CANT);
        printf("\n%s", mensaje);
        scanf("%d",&dni);
        if(buscarPorDni(lista, dni, CANT)==-1)
            printf("El dni ingresado es incorrecto\n\n");
        else
            {
                i=buscarPorDni(lista, dni, CANT);
                lista[i].dni=0;
                lista[i].estado=0;
                printf("\nLa persona fue eliminada con exito!\n\n");
            }
        }
    else
        printf("No hay personas agregadas\n\n");

    getch();
    system("cls");
}

/**
 * Obtiene el primer indice libre del array.
 * @param EPersona lista[] pasa los datos de la estructura EPersona
 * @param cantidad pasa el largo del array de estructura
 * @return void
 */
void ordenarPersona(EPersona lista[], int cantidad)
{
    EPersona auxPersona;
    int i,j;

    for(i=0;i<cantidad-1;i++)
        {
            for(j=i+1;j<cantidad;j++)
            {
                if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    auxPersona=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxPersona;
                }
            if(strcmp(lista[i].nombre,lista[j].nombre)==0)
            {
                if(lista[i].edad>lista[j].edad)
                    {
                        auxPersona=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxPersona;
                    }
            }
        }
    }
    mostrarPersona(lista, CANT);
    getch();
    system("cls");
}

/**
 * Obtiene el primer indice libre del array.
 * @param EPersona lista[] pasa los datos de la estructura EPersona
 * @param cantidad pasa el largo del array de estructura
 * @return void
 */
void iniciarStruct(EPersona lista[], int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        lista[i].nombre['\0']=0;
        lista[i].edad=0;
        lista[i].estado=0;
        lista[i].dni=0;
    }
}

/**
 * Obtiene el primer indice libre del array.
 * @param EPersona lista[] pasa los datos de la estructura EPersona
 * @param cantidad pasa el largo del array de estructura
 * @return void
 */
void graficar(EPersona lista[], int cantidad)
{
   int valor[3];
   int i,j,menor=0,joven=0,adulto=0,max=0;

   for (i = 0; i < cantidad; i++)
   {
       if(lista[i].estado==1)
       {
            if(lista[i].edad<18 && lista[i].edad>0)
                menor++;

            if(lista[i].edad>=18 && lista[i].edad<=35)
                joven++;

            if(lista[i].edad>35)
                adulto++;
       }
   }
    valor[0]=menor;
    valor[1]=joven;
    valor[2]=adulto;

   for(i=0;i<3;i++)
        if (valor[i] > max)
            max = valor[i];

   for (i = max; i > 0; i--)
    {
      for (j = 0; j < 3; j++)
         if (valor[j] >= i)
            printf(" *\t");
         else
            printf("  \t");

      printf("\n");
    }
   printf("<18\t19-35\t>35\n\n");

        getch();
        system("cls");
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param EPersona lista[] pasa los datos de la estructura EPersona
 * @param dni el dni a ser buscado en el array.
 * @param cantidad el largo del array estructura
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 * @return void
 */
int buscarPorDni(EPersona lista[], int dni, int cantidad)
{
    int i;
     for(i=0;i<cantidad;i++)
    {
        if(dni==lista[i].dni)
        {
          return i;
          break;
        }

    }
    return -1;
}

/**
 * Obtiene el primer indice libre del array.
 * @param EPersona lista[] pasa los datos de la estructura EPersona
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 * @return void
 */
int obtenerEspacioLibre(EPersona lista[], int cantidad)
{
    int i;
    for(i=0;i < cantidad; i++)
    {
        if(lista[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}
