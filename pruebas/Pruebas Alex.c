// Hola mundo
/*
#include <stdio.h>
int main () {
 // he usado printf que es para imprimir algo en pantalla  
 //hemos añadido un salto de linea con la expresion \n
    printf ("hola mundosss. \n");

    system ("pause"); 
    return 0;

}




// Voy a realizar pruebas con variables
    // las variables siempre se deben declarar
    // Existen varios tipos d variables
    //Como se le da valor a una variable: 
        //ponemos el nombre un = y el valor que le queremos asignar.ç
             //Tipos:
             // Entero: se declara ponien "int" y el nombre de la variable, despues el nombre asignado. despues ;.
                // son los numeros sin decimales
                //el limite avarca de -32768 a 32767. 2^16

    
             //Flotante: se declara ponien "float" y el nombre de la variable. despues ; .
                // son los numeros con decimales
                //tambien se puede usar con numeros enteros, pero las float ocupan 32 bits y las enteras 16.
                //el limite avarca de +-. 2^32
             //Doble: se declara ponien "double" y el nombre de la variable. despues ; .
                // son los numeros con decimales y enteros
                //el limite avarca de 2^64
            //Char: se declara ponien "char" y el nombre de la variable. despues ; .
                // son los caracteres com Z, y, u ,b...
                // char entiende los numeros como letras, la simbologia del caracter "aspid"
// En un mismo printf se pueden colocar varias variables.


/*
#include <stdio.h> 
int main () {
int x; // 8, 9, 15..
float y; // 8.5 10.65...
double y2; //2^64
char z;
x = 5;
y= 10.5;
y2=20.9;
z= 'a';

printf ("valor de x: %i.\n", x);
printf ("valor de y: %f.\n", y);
printf ("valor de y2: %f.\n", y2);
printf ("valor de z: %c.\n", z);
 
printf ("valor de x: %i.\nvalor de y: %f.\n ", x, y); // varias varibles en una linea.
system ("pause"); 

return 0;


}
*/

// Macros, Asignacion de valores y Operacione. Operaciones con Variables.
// la macros se declaran con el include. Con la "#define".
    // Se usa para darle un valor a lo que tu as definido, por ejemplo en la "Nota 1.1".
/*
#include <stdio.h> 
#define PI 3.1416 // Nota1.1- cada vez que salga PI en el codigo se entendera que es 3.1416.
int main (){
float x;
    x= PI;
    printf ("el valor de x es: %f.\n",x);
 
system ("pause"); 

return 0;
*/
/*
#include <stdio.h>

int main (){

int y;
printf ("Introduce un valor para y: ");
scanf ("%i" ,&y);// &y, siempre que queramos introducir el valor de una variable se usa &. scanf se usa para leer lo que tu escribes en el teclado.
printf ("el valor de y es: %i. \n" ,y);
system ("pause");
return 0;

}
*/
/*
#include <stdio.h>
#define PI 3.1416 // Nota1.1- cada vez que salga PI en el codigo se entendera que es 3.1416.
int main (){
float x;
    x= PI;
int y;
printf ("Introduce un valor para y: ");
scanf ("%i" ,&y);// &y, siempre que queramos introducir el valor de una variable se usa &. scanf se usa para leer lo que tu escribes en el teclado.
printf ("el valor de y es: %i. \n" ,y);

x= x * y; // Ahora se realizara una operacion despues de lo anterior. 

printf ("el nuevo valor de x es: %f. \n", x);

system ("pause");
return 0;

}
*/







/*

// los enteros los podemos declarar cada uno por su lado 
        //int x;
        //int y;
// O de forma conjunta, separandolo por una coma
        //int x,y,z;


#include <stdio.h>
#include <math.h> // la libreria de las matematicas.

int main () {
    int x, y;
    x = 10;
    y = 2;
    
// operaciones Basicas
    //x = x + y; // la forma mas practica de realizar esto es escribir:
    x+= y;
    printf ("el valor de x+y es: %i .\n", x);

    x= x - y;
    printf ("el valor de x-y es: %i .\n", x);

    x= x * y;
    printf ("el valor de x*y es: %i .\n", x);
   
    x= x / y;
    printf ("el valor de x/y es: %i .\n", x);

    //x= x % y;
    //printf ("el valor de x resto y es: %i .\n", x); // resto es el resultado de la division entre un numero y otro. por si acaso...

    x = pow (y,x); // elevar un numero a otro, vamos a poner como comentario la operacion de resto.
    printf ("el valor de y elevado a x es: %i .\n", x);
    
    x= sqrt (x);// raiz cuadrada de X.
    printf ("el valor de la raiz cuadrada de x es: %i .\n", x);

// operadores de incremento, no es mas que sumar o disminuir una unidad.
    x++; // esto lo que hace es que incremente en una unidad. en este caso a x
    printf ("el valor de x++ es: %i .\n", x);
x--; // esto lo que hace es que disminulle en una unidad. en este caso a x
    printf ("el valor de x-- es: %i .\n", x);

system ("pause");
return 0;

}

*/


/*
// Ordenamiento por metodo Burbuja

//Problema 1
   // Intercambiar los valores de dos numeros enteros introducidos por teclado.

#include <stdio.h>// no se usa a nivel profesional, ya que no es nada eficiente

int main () {
    int x, y, aux;
    
        printf ("el valor de x es: ");
        scanf("%i", &x);

        printf ("el valor de y es: ");
        scanf("%i", &y);

    aux = x;
    x = y;
    y = aux;

        printf ("el valor de x es: %i .\n" ,x);
        printf ("el valor de y es: %i .\n" ,y);


system ("pause");
return 0;    
}


*/


// Bloque 2: Estucturas Selectivas.
    //Es la forma que se tiene de hacer que se ejecuten ciertas lineas de codigo en funcion de una condicion.
    //La Estructura selectiva siempre comienza por "if".
    //Para asignar un valor colocamos "=", pero para decir que algo es igual que "=="
    //Si no se cunple y deseamos que se haga otra cosa usamos " else"


/*
#include <stdio.h>

int main (){

    int x;

    x = 5;

    if (x == 4) // existen otros comparadores como: "<",">=",">", ">=","!=" 
        {
            printf("el valor de x es 5 . \n");
        }
    
    else
        {
            printf("el valor de x no es 5 . \n");    
        }
    
system("pause");
return 0;

}
*/





/*
// Bloque 2.2: Ampliacion de estructuras selectivas
// Ejercicio 1º:
        // Realizar un programa que lea de la entrada estandar(monitor) un numero entero positivo y
        // que escriba en la salida estandar si es par o impar


#include <stdio.h>

int main (){

// Ejercicio 1º:
        // Realizar un programa que lea de la entrada estandar(monitor) un numero entero positivo y
        // que escriba en la salida estandar si es par o impar

        int x, y;

        printf ("introduzca un numero:");
        scanf("%i" , &x);

        y = x % 2;

        if(y == 0) {
            printf ("el numero  %i es par . \n" , x);
        }

        else {
            printf ("el numero %i es impar. \n ", x);

        }

system ("pause");
return 0;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
// Ejercicio 2º:
        //realizar un programa que lea tres numeros enteros positivos distintos e imprima el mayor 
        // y el menor de los tres. Intentar que el programa realice el menor numero de comparaciones posible.
/*
#include <stdio.h>

int main (){ 
    int x, y, z, max, min;

printf ("introduce el valor para x: ");
        scanf ("%i", &x);

        printf ("introduce el valor para y: ");
        scanf ("%i", &y);

        printf ("introduce el valor para z: ");
        scanf ("%i", &z);

        if (x > y){

            if (x > z){
                max = x;
            }
            else {
                max = z;
            }
        } 
        else {

            if (y > z){
                max = y;
            }
            else {
                max = z;
            } 
            
        }

printf ("el mayor de los tres es: %i . \n" ,max);

system ("pause");
return 0;
}

*/
/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Condiciones Multiples y Ejercicio: 
// hacer un programa que diga si un numero insertado por teclado se encuentra entre 1 o 10 o si no lo esta.

#include <stdio.h>

int main (){

 int x;

    printf ("inroduce un numero: ");
    scanf ("%i" ,&x);
 
    /*if (x >=1 && x <=10){ // && significa Y, o que las dos condiciones se tienen cumplir y entonces entra el programa.
    printf("el numero %i esta entre 1 y 10 .\n",x);
 }

if (x >=1 || x <=10){ // || significa O,  conque  una de las dos condiciones se cumpla, entonces entra el programa.
    printf("el numero %i esta entre 1 y 10 .\n",x);
 }
    else {
    printf ("el numero %i NO esta entre 1 y 10.\n", x);
}


    system ("pause");
    return 0;

}

*/
/*
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Estructuras iterativas While y For
// Escribe un programa que lea dos numeros y muestre por pantalla todos los numeros
//comprendidos estre esos numeros dados.
// existen varios tipos de bucles while y for.

#include <stdio.h> 

int main () {

int x, y, i; // i equivale a un contador, puede ser j, k, etc.

    printf("introducir un numero");
    scanf ("%i", &x);
    printf("intruduce un numero mayor que el anterior:");
    scanf("%i", &y);
//bucle For.
// este tiene varias partes:
                   // inicializar el contador: i=x + 1
                   // la condicion: i<y
                   // el incremento: i++
    for(i=x + 1 ; i<y ; i++){
            printf ("%i, ", i);
    }
printf("\n");
// blucle while:
// este solo lleva 1 condicion.
i=x+1;
while (i<y){
    printf("%i, ",i);
    i++;
}
printf("\n");

system ("pause");
return 0;

}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ejercicio For y while
//Realiza un programa que imprima la suma de los nmeros pares entre dos y mil.
// for
/*
#include <stdio.h>
int main(){
    int i;
    float suma;
    suma= 0;

    for (i = 2 ; i  <= 2000 ; i += 2){
        suma += 1;
    }

printf("el resultado de la suma es : %f.\n", suma);

system ("pause");
return 0;
}

// while
#include <stdio.h>
int main(){

int x, y, i;
float suma;

printf("intruduce de cuantos numeros quieres calcular la media: ");
scanf("%i",&x);
    i=0;
    suma = 0;

    while (i < x) {
        printf(" intruduce el numero %i, ", i+1);
        scanf ("%i", &y);
        suma += y;
        i++;
    }
    
suma = suma / x;
printf("el resultado de la media es: %f. \n", suma);

system ("pause");
return 0;
}

*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bucles anidados y Ejercicio Cronometro.
// Hacer tablas de multiplicar  del 1 al 9.
// funcion sleep
// if y else
/*
#include <stdio.h>

int main()
{
    int i, j;                     // primero declaramos contadores
    for(i=1;i<=9;i++){            // primero empieza en primer blucle
         for(j=1;j<=10;j++){      // se ejecuta el segundo bucle dentro del primero hasta llegar a 10
        
             printf("%i x %i = %i.\n", i,j,i*j);


         }// cuando termine el segundo bucle vuelve al primero y se repite.   
      printf("\n"); // o usar  
      //system("pause");  

    }

system ("pause");
return 0;

}
*/
// hacer un cronometro que consiste cuando se pulse la tecla espacio.
#include <stdio.h>
#include <windows.h> // para la funcion sleep.

int main()
{
   
system ("pause");
return 0;

}







