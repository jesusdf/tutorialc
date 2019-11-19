/*
 * Menu handler functions
 */

#ifndef XYMENU_H
#define XYMENU_H 1

int CreateMenu (char *title, char *choice, char menu[][LINE_MAX_LENGTH], int size, int (*handler)(int)) {
  const int count = (size / LINE_MAX_LENGTH);
  int option = 0;
  int ret = 0;

  while (true) {
    
    Clear();

    printf ("%s\n\n", title);
    for (int i=0; i < count; printf ("\t%d) %s\n", i, menu[i++]));
    printf ("\t%d) Exit\n", count + 1);

    do {
      printf ("\n%s: ", choice);
      option = ReadNumber ();
    } while (option < 1 || option > count + 1);

    printf ("\n");

    if (option == count + 1)
      return 0;

    ret = handler (option - 1);
    if (ret != 0)
      return ret;

    Pause ();

  }
}

#endif