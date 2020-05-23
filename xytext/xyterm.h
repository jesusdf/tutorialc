/*
 * Terminal functions (clear, position, read, write, etc...)
 */

#ifndef XYTERM_H
#define XYTERM_H 1

#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true !false
#define LINE_MAX_LENGTH 81

#ifdef _WIN32
  #define Clear() system("cls")
#else
  #define Clear() printf("\033[H\033[J")
#endif

int ReadNumber () {
  char *end;
  char buffer[LINE_MAX_LENGTH];

  if (fgets (buffer, sizeof(buffer), stdin)) {
    fflush(stdin);
    return strtol (buffer, &end, 10);
  } else {
    return 0;
  }
}

void WriteLine(char *text)
{
  printf ("%s\n", text);
}

void Pause() {
  fgetc(stdin);
}

#endif