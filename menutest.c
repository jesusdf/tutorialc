#include <stdio.h>
#include <string.h>

#define USE_SDL 1

#ifdef USE_SDL
#include "sdltext/sdltext.h"
#else
#include "xytext/xytext.h"
#endif

char title[] =
"\
----------------------\n\
-- Matemáticas v1.0 --\n\
----------------------\
";
char choice[] = "Seleccione una opción:";

char menu[][LINE_MAX_LENGTH] = {
  "Calcular fibonacci",
  "Calcular factorial"
};

int Fibonacci(int numero) {
  if (numero <= 1) {
    return numero;
  } else {
    return (Fibonacci(numero - 1) + Fibonacci(numero - 2));
  }
}

void CalcularFibonacci (int numero) {
  char msg[1000]="";
  char parcial[100]="";
  int len = 0;
  for (int i = 0; i < numero; i++) {
    len = snprintf(parcial, sizeof(parcial), "%d ", Fibonacci(i));
    if (len > 0)
    {
      strncat(msg, parcial, sizeof(msg));
    }
  }
  WriteLine (msg);
}

int CalcularFactorial(int numero) {
  if (numero <= 0) {
    return 1;
  } else {
    return (numero * CalcularFactorial(numero - 1));
  }
}

int Menu_Handler (int option)
{
  Write ("Indica un numero: ");
  int numero = ReadNumber ();
  int resultado = 0;
  char msg[1000] = "";
  switch(option) {
    case 0: /* Fibonacci */
      CalcularFibonacci(numero);
      break;
    case 1: /* Factorial */
      resultado = CalcularFactorial(numero);
      snprintf (msg, sizeof(msg), "Resultado: %d\n", resultado);
      WriteLine (msg);
      break;
  }
  return 0;
}

int main (void) {
  return CreateMenu (title, choice, menu, sizeof(menu), &Menu_Handler);
}

