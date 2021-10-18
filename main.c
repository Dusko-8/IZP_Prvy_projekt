#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *function which returns Level int to main
 */
int getIntLevel(char *argv) {
  char *endptr;
  int i = strtoul(argv, &endptr, 10);

  // here program checks if the int we want passes our requirements
  if (endptr[0] != '\0') {
    fprintf(stderr, "Parameter Level musi byt cele kladne cislo  \n");
    return -1;
  }
  if (i > 4 || i < 1) {
    fprintf(stderr, "Parameter Level sa ma nachadzat v rozmedzi od 1 - 4  \n");

    return -1;
  }

  return i;
}
/*
 *function which returns Level int to main
 */
int getIntParam(char *argv) {
  char *endptr;
  int i = strtoul(argv, &endptr, 10);

  if (endptr[0] != '\0' || i <= 0) {
    fprintf(stderr, "Parameter  musi byt cele kladne cislo  \n");
    return -1;
  }

  return i;
}
/*
 *returns truo or fals based on if the 3rd parameter was exactly -stats
 */
bool getBoolStats(char *array1) {
  int i;
  char array2[] = "--stats";
  bool response = false;
  printf("--a--%s\n", &array1[0]);
  i = 0;
  // prejde kazdym prvkom char pola a porovna jednolive pozicie
  while (array1[i] == array2[i] && response == 0) {
    if (array1[i] == '\0' || array2[i] == '\0') {
      response = true;
    }
    i++;
  }

  return response;
}

int main(int argc, char *argv[]) {
  printf("Number of arguments: %d\n", argc);

  int level;
  int param;
  bool stats;

  // nacitanie parametrov
  if (argc > 2 && argc < 5) {

    level = getIntLevel(argv[1]);
    param = getIntParam(argv[2]);
    stats = getBoolStats(argv[3]);

  } else {
    printf("Zly pocet parametrov \n");
  }
  
  printf("level- %d param- %d stats- %d \n", level, param, stats);

  
  
  
  
  
  /*char riadok[101];
  while (fgets(riadok, 101, stdin) != NULL) {
    printf("%s", riadok);
  }*/

  return 0;
}