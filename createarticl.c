#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

typedef char* str_t;

/* Tool for creating articles */

int
main(int argc, str_t *argv)
{
  str_t name;
  printf("Create a name for your article:\t");
  fgets(name, 255, stdin);
  name[strlen(name) - 1] = '\0';
  str_t cmd = "mkdir ";
  strcat(cmd, name);
  system(cmd);
  int len = strlen(cmd);
  for (int i = 0; i < len; i++)
    cmd[i] = '\0';
  strcat(cmd, "cd ");
  strcat(cmd, name);
  system(cmd);
  len = strlen(cmd);
  for (int i = 0; i < len; i++)
    cmd[i] = '\0';

  creat("main.txt", 777);
  FILE *f = fopen("main.txt", "r+");
  printf("Type in your name:\t");
  len = strlen(name);
  for (int i = 0; i < len; i++)
    name[i] = '\0';
  fgets(name, 255, stdin);
  name[len - 1] = '\0';
  struct tm tm = *localtime(time(NULL));
  fprintf(f, "Copyright (C)  %d  %s.\nPermission is granted to copy, distribute and/or modify this document\nunder the terms of the GNU Free Documentation License, Version 1.3\nor any later version published by the Free Software Foundation;\nwith no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.\nA copy of the license is included in the section entitled \"LICENSE.md\".", tm.tm_year + 1900, name);
  printf("Now write article and have fun editing our free encyclopedia ;)\n");
  system ("emacs main.txt");
  return 0;
}
