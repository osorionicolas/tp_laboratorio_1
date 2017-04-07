#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
* \brief Suma dos numeros ingresados en la funcion principal
* \param num1 Se carga el primero operando
* \param num2 Se carga el segundo operando
* \return Resultado de la suma
*/
float suma (float num1, float num2);

/**
* \brief Resta dos numeros ingresados en la funcion principal
* \param num1 Se carga el primero operando
* \param num2 Se carga el segundo operando
* \return Resultado de la resta
*/
float resta (float num1, float num2);

/**
* \brief Multiplica dos numeros ingresados en la funcion principal
* \param num1 Se carga el primero operando
* \param num2 Se carga el segundo operando
* \return Resultado de la multiplicacion
*/
float multiplicacion (float num1, float num2);

/**
* \brief Divide dos numeros ingresados en la funcion principal
* \param num1 Se carga el primero operando
* \param num2 Se carga el segundo operando
* \return Resultado de la division
*/
float division (float num1, float num2);

/**
* \brief Saca el factorial de un numero ingresado en la funcion principal
* \param num Se carga el numero del cual se va a sacar el factorial
* \return Se muestra el factorial
*/
float factorial (float num);

/**
* \brief Toma un numero entero
* \param mensaje Muestra el mensaje en pantalla que se le carga en la funcion principal
* \return El numero entero que toma
*/
int getInt (char mensaje[]);

/**
* \brief Toma un numero flotante / decimal
* \param mensaje Muestra el mensaje en pantalla que se le carga en la funcion principal
* \return El numero flotante que toma
*/
float getFloat (char mensaje[]);

/**
* \brief Toma una letra para que el usuario pueda seguir en el programa
* \param mensaje Muestra el mensaje en pantalla que se le carga en la funcion principal
* \return La respuesta del usuario
*/
char getChar(char mensaje[]);

#endif // FUNCIONES_H_INCLUDED
