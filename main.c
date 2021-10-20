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
 *returns truo or fals based on if the 3rd parameter was exactly --stats
 */
bool getBoolStats(char *array1) {
  int i = 0;
  char array2[] = "--stats";
  bool response = false;

  // prejde kazdym prvkom char pola a porovna jednolive pozicie
  while (array1[i] == array2[i] && response == 0) {
    if (array1[i] == '\0' || array2[i] == '\0') {
      response = true;
    }
    i++;
  }

  return response;
}
/*
 *this function checks if the parameter has the right properties in security
 *level1
 */
bool checkLevel1(char row[]) {
  int counter = 0;
  bool small = false;
  bool capital = false;
  bool result = false;
  // check if the password contains small and capitall lathers
  while (row[counter] != '\0') {
    if (row[counter] >= 'a' && row[counter] <= 'z') {
      small = true;
    } else if (row[counter] >= 'A' && row[counter] <= 'Z') {
      capital = true;
    }
    counter++;
  }

  if (small && capital) {
    return result = true;
  }
  return result;
}
/*
 *this function checks if the parameter has the right properties in security
 *level 1 & 2
 */
bool checkLevel2(char row[], int param) {
  bool result = false;
  bool number = false;
  bool specialchar = false;

  if (param == 2 || param == 1) {
    if (checkLevel1(row) == true) {
      result = true;
    }
  }

  if (param == 3) {
    for (int i = 0; row[i] != '\0'; i++) {
      if (row[i] >= '0' && row[i] <= '9') {
        number = true;
      }
    }
    if (checkLevel1(row) && number) {
      result = true;
    }
  }

  if (param >= 4) {
    //printf("---------%s\n", row);
    for (int i = 0; row[i] != '\0'; i++) {
      if (row[i] >= '0' && row[i] <= '9') {
        number = true;
      }
      if (row[i] >= ' ' && row[i] <= '/' ||
          row[i] >= ':' && row[i] <= '@' ||
          row[i] >= '[' && row[i] <= '`' ||
          row[i] >= '{' && row[i] <= '~') {
        specialchar = true;
      }
    }
    /*printf("level 1-%s\n", checkLevel1(row) ? "true" : "false");
    printf("cislo 2-%s\n", number ? "true" : "false");
    printf("special 3-%s\n", specialchar ? "true" : "false");*/
    if (checkLevel1(row) && number && specialchar) {
      result = true;
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  printf("------------------------------------\n");
  printf("Number of arguments: %d\n", argc);

  int level = 2;
  int param = 8;
  bool stats;

  // nacitanie parametrov
  /*if (argc > 2 && argc < 5) {

    //level = getIntLevel(argv[1]);
    //param = getIntParam(argv[2]);
    //stats = getBoolStats(argv[3]);

  } else {
    printf("Zly pocet parametrov \n");
  }*/

  printf("level- %d param- %d stats- %d \n", level, param, stats);
  printf("------------------------------------\n");
  char row[101];
  int counter = 0;

  while (fgets(row, 101, stdin) != NULL) {

    switch (level) {
    case 1:
      if (checkLevel1(row)) {
        printf("heslo ma velke aj male znaky-%s\n", row);
      }
      break;
    case 2:
      if (checkLevel2(row, param)) {
        printf("heslo- %s splnuje lvl 2 param -%i\n", row, param);
      }
      break;

    default:
      break;
    }
  }

  return 0;
}