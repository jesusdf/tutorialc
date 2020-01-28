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



