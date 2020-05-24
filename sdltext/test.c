#include <stdio.h>

#include "sdltext.h"

char title[] =
"\
-----------------------\n\
-- Menu generico 1.0 --\n\
-----------------------\
";
char choice[] = "Seleccione una opcion:";

char menu[][LINE_MAX_LENGTH] = {
  "Decir hola",
  "Decir adios"
};

char submenu[][LINE_MAX_LENGTH] = {
  "En Español",
  "En Inglés",
  "En Alemán"
};

char messages[][LINE_MAX_LENGTH] = {
  "Hola.",
  "Adios.",
  "Hello.",
  "Goodbye.",
  "Hallo.",
  "Auf Wiedersehen."
};

int numero_saludos = (sizeof(menu) / LINE_MAX_LENGTH);
int saludo = 0;

int Submenu_Handler (int idioma)
{
  WriteLine (messages[(numero_saludos * idioma) + saludo]);
  return 0;
}

int Menu_Handler (int eleccion)
{
  saludo = eleccion;
  CreateMenu (title, choice, submenu, sizeof(submenu), &Submenu_Handler);
  return 0;
}

int main (void) {
  return CreateMenu (title, choice, menu, sizeof(menu), &Menu_Handler);
}

