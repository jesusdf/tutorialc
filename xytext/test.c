#include <stdio.h>

#include "xytext.h"

char title[] =
"\
-----------------------\n\
-- Menu generico 1.0 --\n\
-----------------------\
";
char choice[] = "Seleccione una opcion";

char menu[][LINE_MAX_LENGTH] = {
  "Decir hola",
  "Decir adios"
};

char messages[][LINE_MAX_LENGTH] = {
  "Hola.",
  "Adios."
};

int Menu_Handler (int option)
{
  WriteLine (messages[option]);
  return 0;
}

int main (void) {
  return CreateMenu (title, choice, menu, sizeof(menu), &Menu_Handler);
}

