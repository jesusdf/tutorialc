#include <stdio.h>

#include "xytext/xytext.h"

char title[] =
"\
-----------------\n\
-- Agenda v1.0 --\n\
-----------------\
";
char choice[] = ">";

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
  for (int i = 0; i < numero; i++) {
    printf("%d ", Fibonacci(i));
  }
  printf("\n");
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
  printf ("Indica un numero: ");
  int numero = ReadNumber ();
  int resultado = 0;
  switch(option) {
    case 0: /* Fibonacci */
      CalcularFibonacci(numero);
      break;
    case 1: /* Factorial */
      resultado = CalcularFactorial(numero);
      printf ("Resultado: %d\n", resultado);
      break;
  }
  return 0;
}

int main (void) {
  return CreateMenu (title, choice, menu, sizeof(menu), &Menu_Handler);
}

