#include <stdio.h>
int main(int argc, char *argv[])
{
  printf("Number of arguments: %d\n", argc);
 
  /* inicializace promenne i */
  int i = 1;
  /* prvni a dalsi podminky */
  while (argc > i)
  {
    /* telo cyklu */
    printf("%d. argument: %s\n", i, argv[i]);
    /* inkrementace */
    i = i + 1;
  }
 
  return 0;
}