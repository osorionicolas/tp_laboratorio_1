/*******************************************************************
*Programa: Trabajo Practico N°1 - Calculadora
*
*Objetivo:
Realizar una calculadora con las distintas operaciones
*
*Autor:Nicolas Osorio  1-F
*
********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float num1, float num2);
float resta (float num1, float num2);
float multiplicacion (float num1, float num2);
float division (float num1, float num2);
float factorial (float num);
int getInt (char mensaje[]);
float getFloat (char mensaje[]);
char getChar(char mensaje[]);



int main()
{
    float oper1=0;     //OPERANDO NUMERO 1
    float oper2=0;     //OPERANDO NUMERO 2
    float resultado;   //RESULTADO DE LAS OPERACIONES
    char seguir='s'; //PARA COMENZAR EL MENU
    int opcion=0;    //OPCION ELEGIDA PARA EL MENU
    int flag=0;      //BANDERA PARA PEDIR QUE INGRESE EL PRIMER OPERANDO

    //Menu del programa
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",oper1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",oper2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!) \n(En caso de ser un numero decimal saca el factorial del entero)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        //Toma la opcion mediante la funcion getInt
        opcion=getInt("\nElija una opcion: ");

        //Valida que la opcion este entre las del menu
        while ((opcion != 1) && (opcion!=9) && (flag==0))
        {
            printf ("\naun no ingreso el primer operando\n");
            system("pause");
            system("cls");
            return main();
        }

        system ("cls");
        switch(opcion)
        {
            case 1:
                 {
                 flag=1;
                 oper1=getFloat("Ingrese el primer operando: ");
                 printf ("\n\n");
                 continue;
                 }
            case 2:
                 {
                 oper2=getFloat("ingrese el segundo operando: ");
                 printf ("\n\n");
                 continue;
                 }
            case 3:
                 {
                 resultado=suma(oper1,oper2);
                 printf("El resultado es: %.2f\n",resultado);
                 break;
                 }
            case 4:
                 {
                 resultado=resta(oper1,oper2);
                 printf("El resultado es: %.2f\n",resultado);
                 break;
                 }
            case 5:
                 {

                   if(oper2==0)
                    {
                        printf ("No se puede dividir por 0\n");

                    }
                    else
                        {
                            resultado=division(oper1,oper2);
                            printf("El resultado es: %.2f\n",resultado);
                        }

                    break;
                 }
            case 6:
                 {
                 resultado=multiplicacion(oper1,oper2);
                 printf("El resultado es: %.2f\n",resultado);
                 break;
                 }
            case 7:
                 {
                 resultado=factorial(oper1);
                 if (resultado==-1)
                 printf ("No se puede sacar el factorial de un numero menor a 0\n");
                 else
                 printf("El factorial del primer operando es %.0f\n",resultado);

                 break;
                }
            case 8:
                 {
                    printf("operando 1: %.2f, operando 2: %.2f\n\n",oper1,oper2);
                    //SUMA
                    resultado=suma(oper1,oper2);
                    printf("El resultado de la suma es: %.2f\n",resultado);

                    //RESTA
                    resultado=resta(oper1,oper2);
                    printf("El resultado de la resta es: %.2f\n",resultado);

                    //MULTIPLICACION
                    resultado=multiplicacion(oper1,oper2);
                    printf("El resultado de la multiplicacion es: %.2f\n",resultado);

                    //DIVISION
                    if(oper2==0)
                        {
                            printf ("No se puede dividir por 0\n");
                        }
                    else
                        {
                            resultado=division(oper1,oper2);
                            printf("El resultado de la division es: %.2f\n",resultado);
                        };

                    //FACTORIAL
                        resultado=factorial(oper1);
                    if (resultado==-1)
                        printf ("No se puede sacar el factorial de un numero menor a 0\n");
                    else
                        printf("El factorial del primer operando es %.0f\n",resultado);

                    break;
                }
            case 9:
                {
                    seguir = 'n';
                    break;
                }


            default:
                {
                    printf("Esa opcion no es valida\n\n");
                    system ("pause");
                    system("cls");
                    continue;
                }

        }

        seguir=getChar("\n\nDesea volver a hacer una operacion? s/n:  ");
        flag--;
        system("cls");
}
    return 0;
}
