#include <stdio.h>
/* Reader of articles in Zauropedia */
typedef char* str_t;
int 
main (int argc, char **argv)
{
  str_t path = argv[1];
  strcat(path, "/main.txt");
  FILE *f = fopen(path, "r");
  int c;
  while ((c = fgetc(f)) != EOF)
    {
      putchar(c);
    }
  putchar('\n');
  return 0;
}
