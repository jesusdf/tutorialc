#include <stdio.h>

#define PI 3.141592


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

int main(void)
{
/*
    Saluda();

    int a;
	int y = 3;
	int x = ElevarA2(y);

	printf("x vale %d e y vale %d. a vale %d.\n", x, y, a);
*/

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

	return 0;
}
