#include <stdio.h>

#define PI 3.141592
#define FALSE 0
#define TRUE !FALSE

/*
	Notas previas
	-------------

		Este archivo forma parte de un proyecto C, dependiendo del entorno de desarollo utilizado (IDE),
	utilizará un formato u otro para organizar los ficheros dentro del proyecto.
		Es posible compilar un archivo.c de forma independiente, pero el proyecto resulta más cómodo ya que
	sirve para guardar parámetros adicionales a la hora de compilar, comandos después de generar, dependencias, etc...

		Este proyecto está bajo control de código fuente (git en este caso), eso significa que se pueden realizar cambios
	libremente, realizando protecciones periódicas. Se mantiene un historial de cambios y está pensado para trabajar en equipo,
	con varias personas tocando los mismos ficheros a la vez.

        Antes de empezar, comentaré algunos conceptos previos que es interesante conocer, y dejaré enlaces adicionales
    por si se quiere leer más al respecto.

*/

/*

	Breve historia
	--------------

		En cuanto a la historia de C, fue el sustituto de los lenguajes A y B. C++ se supone
	que lo sustituye, pero en realidad está más en paralelo que como sustituto (C++ usa una filosofía basada en
	herencia y objetos, en lugar de orientar todo a procedimientos). Como sustitutos de C++ aparecieron lenguajes
	como Java y C#, que simplifican la gestión de memoria y la creación y destrucción de objetos. El sustituto real
	del lenguaje C y C++ sería D.

	https://es.wikipedia.org/wiki/C_(lenguaje_de_programaci%C3%B3n)
	https://es.wikipedia.org/wiki/C%2B%2B
	https://es.wikipedia.org/wiki/D_(lenguaje_de_programaci%C3%B3n)

*/

/*

	ANSI C
	------

		C es un lenguaje que tiene muchos años, y ha recibido algunas revisiones que afectan al cómo se utilizan diversas partes
    del lenguaje, desde la sintaxis a formas de organizar el código, recomendaciones sobre mejores prácticas, etc...
        Durante años hubo empresas como Borland o Microsoft que crearon librerías de funciones propias y que se hicieron populares
    porque eran los IDE de desarrollo más comunes en su época. El problema es que esas librerías no eran estándar y en muchos casos
    no se podían utilizar en otras plataformas que no fueran x86. Por ello, es bueno ceñirse a la especificación ANSI, lo que dará
    garantías a futuro sobre la compatibilidad del programa.
		Hay documentación por Internet que mezcla especificación ANSI con funciones no ANSI. Así mismo, hay gente que mezcla funciones
    de C con funciones de C++, y esto tampoco se debe hacer, ni está recomendado. Estos híbridos compilan porque sintácticamente son
    similares y ambos son "compatibles", pero es muy importante ser estricto sobre lo que se usa.
    Un ejemplo claro sería que en C el único comentario es multilínea, el comentario de C++ de una sola línea // no se debe usar.

*/

/*
	Arquitectura de 32 bits
	-----------------------

		Un procesador de 32 bits tendrá varios registros de este tamaño. En el caso de la arquitectura de pc x86, los
	registros se organizan de la siguiente manera:

	Registro acumulador:

	EAX (32 bits)
	___________________________
	|___________|______|______|

	Permite acceder a los registros compatibles con arquitecturas anteriores de 16 bits:

	Los 16 bits menos significativos son el registro AX:
	            |-----AX------|
	Que a su vez se divide en AH para los 8 bits másaltos y AL para los 8 bits más bajos:
	            |--AH--|--AL--|

	Esto mismo se puede realizar con el resto de registros del procesador EBX, ECX, EDX, EDI, ESI.

		Cuando se hicieron presentaciones para arquitecturas de 64 bits, ganó la propuesta de AMD, que es continuista, se
	crearon registros de 64 bits RAX, RBX, RCX, RDX, RSI, RDI que contienen a los registros de 32 bits de igual manera
	que como acabamos de ver. Esta arqutiectura se conoce como AMD64 ó x86_64.

*/

void arquitectura(void) {

}

/*
	Tipos de variables
	------------------
*/

/*
	Punteros
	--------
*/

/*
	Reserva de memoria
	------------------
*/


/*
	Funciones
	---------

	La función main es siempre el punto de entrada (inicio) de una aplicación escrita en C.
	En el caso del C que se usa con arduino, es la función loop(), que se ejecuta contínuamente.

	La estructura de una función es como sigue:

	TipoDeValorDevuelto NombreFuncion(TipoParametro NombreParametro1, TipoParametro NombreParametro2)

*/

int suma(int numeroA, int numeroB) {
    return numeroA + numeroB;
}

int ElevarA2(int y) {
    return y * y;
}

void Saluda(void) {
    printf("Hola!\n");
}

/*

void StringTest(void) {

    int numeros[10] = { 1, 3, 5, 7, 9 };

	//char letras[] = "Hola";
	char letras[50] = { 'H', 'o', 'l', 'a', '\0' };
	//letra = letra + 0x20;

	letras[3] = 'e';
	letras[3] = 98;
	letras[4] = 0;

	char * c = &letras[0];

	*c='B';

	for(int i=0; i<=4; i = i + 1) {
        numeros[i] = numeros[i] + 0x30;
    }

    printf ("Hola, esta es la letra que pedías: %s %s %d %ls\n", letras, c, numeros[2], numeros);
}

*/


/*

Ejemplo con pseudocodigo:

subproceso funcion bizzbuzz
para (i = 1; mientras i<=100; establece i = i + 1) {
    establecer print_number a verdadero;
    Si i es divisible por 3
        escribir "Bizz";
        establecer print_number a falso;
    Si i es divisible por 5
        escribir "Buzz";
        establecer print_number a falso;
    Si print_number es verdadero, escribir i;
    escribir una nueva línea;
}

*/

/*
void bizzbuzz(void){
    int i=0;
    int print_number=FALSE;

    for(i=1; i<=100; i++){
        print_number = TRUE;
        if(i % 3 == 0) {
            printf("Bizz");
            print_number=FALSE;
        } else {
            if(i % 5 == 0) {
                printf("Buzz");
                print_number=FALSE;
            }
        }
        if(print_number == TRUE) {
            printf("%d", i);
        }
        printf("\n");
    }
}
*/

/*

funcion calculadora {
    muestra mensaje "Calculadora v0.01";
    haz
        haz
            muestra mensaje "Indica la operación a realizar (+-*\): ";
            leer operacion;
        mientras operacion no sea '+' '-' '*' '/'
        muestra mensaje "Introduce un numero:"
        leer numero;
        muestra mensaje "Introduce otro numero:"
        leer numero2;
        si operacion es '/' y numero2 es 0
            mostrar mensaje "No se puede dividir entre 0!"
        sino
            dependiendo del valor de operacion:
                si es '+':
                    muestra numero + numero2;
                si es '-':
                    muestra numero - numero2;
                si es '*':
                    muestra numero * numero2;
                si es '/':
                    muestra numero / numero2;
                sino:
                    muestra mensaje "La operación no es válida";
        muestra mensaje "¿Deseas hacer otro cálculo? (s/n)";
        leer continuar;
    mientras continuar = 's';

}

*/



void calculadora(void) {
    int numero = 0;
    int numero2 = 0;
    char operacion = '\0';
    char continuar = 'n';

    printf("Calculadora v0.01\n");

    do {

        printf("\nIndica la operación a realizar (+-*/): ");
        do {
            scanf(" %c", &operacion);
        } while(operacion != '+' && operacion != '-' && operacion != '*' && operacion != '/');

        printf("\nIntroduce un numero: ");
        scanf("%d", &numero);
        printf("\nIntroduce otro numero: ");
        scanf("%d", &numero2);

        if((operacion == '/') && (numero2 == 0) ) {
            printf("\nNo se puede dividir entre 0!\n");
        }
        else
        {
            printf("\nResultado: ");
            switch(operacion) {
                case '+':
                    printf("%d", numero + numero2);
                    break;
                case '-':
                    printf("%d", numero - numero2);
                    break;
                case '*':
                    printf("%d", numero * numero2);
                    break;
                case '/':
                    //printf("%f", (double)numero / (double)numero2);
                    printf("%d", numero / numero2);
                    break;
                default:
                    printf("\nLa operación no es válida\n");
                    break;
            }
        }
        
        printf("\n");

        printf("\n¿Deseas hacer otro cálculo? (s/n) ");
        scanf(" %c", &continuar);

    } while(continuar == 's' || continuar == 'S');

}


/*
    funcion saludo1 
        muestra mensaje "saludo1";
        haz
            haz
                muestra mensaje "presiona un nuemero de 1 a 4";
                leer operacion;
                muestra mensaje "Introduce un numero:"
                leer numero;
        si el numero es 'n<4' 
                mostrar mensaje "No existe!"
            sino
                dependiendo del valor del numero:
                    si es '1':
                        muestra hola guap@;
                    si es '2':
                        muestra adios guap@";
                    si es '3':
                        muestra que tal?;
                    si es '4':
                        muestra la familia?;
                    sino:
                        muestra mensaje "La operación no es válida";
            muestra mensaje "¿Deseas seguir? (s/n)";
            leer continuar;
        mientras continuar = 's';


*/
int main(void) {
     saludo1(); 

return 0;
}
void saludo1 (void) {
    int numero = 0;
    
    char continuar = 'n';


    printf("saludo1");

    do {
        printf("\nIntroduce un numero: ");
        scanf("%d", &numero);
        
        if( numero>4 ) {
            printf("no existe");
        }
        else
        {
            printf("saludo: ");
            switch(numero) {
                case 1:
                    printf("\nhola guap@");
                    break;
                case 2:
                    printf("\nadios guap@");
                    break;
                case 3:
                    printf("\nque tal?");
                    break;
                case 4:
                
                    printf("\nla familia");
                    break;
                default:
                    printf("\nLa operación no es válida\n");
                    break;
            }
        }
        
        printf("\n");

        printf("\n¿Deseas seguir? (s/n) ");
        scanf(" %c", &continuar);

    } while(continuar == 's' || continuar == 'S');

}
