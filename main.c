/*
 *Programed by Dušan Slúka
 *xsluka00
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
 *function which returns Level int to main
 */
int getIntLevel(char *argv) {
  char *endptr;
  int i = strtol(argv, &endptr, 10);

  // here program checks if the int we want passes our requirements
  if (endptr[0] != '\0') {
    fprintf(stderr, "Parameter Level musi byt cele kladne cislo  \n");
    return 0;
  }
  if (i > 4 || i < 1) {
    fprintf(stderr, "Parameter Level sa ma nachadzat v rozmedzi od 1 - 4  \n");

    return 0;
  }

  return i;
}
/*
 *function which returns Level int to main
 */
int getIntParam(char *argv) {
  char *endptr;
  int i = strtol(argv, &endptr, 10);

  if (endptr[0] != '\0'){
    fprintf(stderr, "Parameter  musi byt cele kladne cislo  \n");
    return 0;
  }
  //TO DO
  if(i <= 0 ){
    fprintf(stderr, "Parameter  musi byt cele kladne cislo  \n");
    return 0;
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
  
  //printf("array1-%c\n",array1[i]);}
  // prejde kazdym prvkom char pola a porovna jednolive pozicie
  while (array1[i] == array2[i]) {
    if (array1[i] == '\0' && array2[i] == '\0') {
      response = true;
    }
    i++;
  }
  if(response == false){
    fprintf(stderr, "--stats sa nezhoduje  \n");
  }
  
  return response;
}
/*
 *this function checks if the password has small and capitall characters.
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
 *level 1 & based on param if the password contains numbers or special charcters
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

    for (int i = 0; row[i] != '\0'; i++) {
      if (row[i] >= '0' && row[i] <= '9') {
        number = true;
      }
      if (row[i] >= ' ' && row[i] <= '/' || row[i] >= ':' && row[i] <= '@' ||
          row[i] >= '[' && row[i] <= '`' || row[i] >= '{' && row[i] <= '~') {
        specialchar = true;
      }
    }
    if (checkLevel1(row) && number && specialchar) {
      result = true;
    }
  }

  return result;
}
/*
 *this function checks if the parameter has the right properties in security
 *level 1 & 2 & dosn t contain x same chrs in a row
 */
bool checkLevel3(char row[], int param) {
  int count = 0;
  bool result = true;

  for (int i = 0; row[i + 1] != '\0'; i++) {
    if (row[i] == row[i + 1] && count < param) {
      count++;
    }
    if (count >= (param - 1)) {
      result = false;
    }

    if (row[i] != row[i + 1]) {
      count = 0;
    }
  }

  if (checkLevel1(row) && checkLevel2(row, param) && result) {
    result = true;
  } else {
    result = false;
  }
  return result;
}
/*
 *this function checks if the parameter has the right properties in security
 *level 1 & 2 & 3 & dosnt contain substring of length param
 */
bool checkLevel4(char row[], int param) {
  bool result;
  int count = 1;
  //char actSubstring[param];

  //printf("----------level4-heslo>%s", row);
 
  for (int i = 0; row[i] != '\0'; i++) {
    //printf("I-row[%c]\n",row[i]);
    for (int j = i+1; row[j] != '\0'; j++) {
      //printf("J-row[%c]\n",row[j]);
      if (row[i] == row[j]) {
        int k = i + 1;
        int count = 1;
        int l = j + 1;
        while (row[k] == row[l] && count < param) {
         // printf("-----K---%d",k);
          count++;
          k++;
          l++;
        }
        if (count == param) {
          //printf("FALSE\n");
          result = false;
          return result;
        }
      }
    }
  }
 // printf("TRUE\n");
  if(checkLevel1(row) && checkLevel2(row,param)&&checkLevel3(row,param)){
   result = true; 
  }else{
    result = false;
  }
  
  return result;
}

void vypisStats(int shortestPass,double countChar,double countPass,int difChars){
  double avg = countChar/countPass;
  if(shortestPass == 101){
    shortestPass = 0;
  } 
  printf("Statistika:\n");
  printf("Ruznych znaku: %d\n",difChars);
  printf("Minimalni delka: %d\n",shortestPass);
  printf("Prumerna delka: %.1lf\n",avg);
}

int main(int argc, char *argv[]) {

  //Variables for parameters
  int level;
  int param;
  bool stats;

  //Variables Stats
  int shortestPass = 101;
  double countChar = 0;
  double countPass = 0;
 
  bool exists = false;
  char diffCharsarray[256];
  int difcharcounter = 0;
  
  //System variables
  bool bigger100 = true;
  // load params from argv
  if (argc > 2 && argc < 5) {
    
    if(argc == 4){
    stats = getBoolStats(argv[3]);
    if(stats == false){
      return 1;
      }
    } 
    
    level = getIntLevel(argv[1]);
    if(level == 0){
      return 1;
    }
    param = getIntParam(argv[2]);
    if(param == 0){
      return 2;
    }

  }else {
    fprintf(stderr,"Zly pocet parametrov \n");
    return 3;
  }

  char row[102];
  int counter = 0;
  //fprintf(stdout, "STARTED!");
  while (fgets(row, 102, stdin) != NULL) {
    int i = 0;
    while (row[i] != '\0') {
      if (row[i] == '\n') {
        if (i < 101){
          bigger100 = false;
          break;
        }
      }
      i++;
    }
    if (bigger100)
    {
      fprintf(stderr, "Chyba vstupnych parametrov, maximalna dlzka hesla je 100 znakov\n");
      return 5;
    }
    
    switch (level) {
    case 1:
      if (checkLevel1(row)) {
        //printf("heslo- %s splnuje lvl 1 param -%i\n", row, param);
        fprintf(stdout,"%s",row);
      }
      break;
    case 2:
      if (checkLevel2(row, param)) {
        fprintf(stdout,"%s",row);
        //printf("heslo- %s splnuje lvl 2 param -%i\n", row, param);
      }
      break;
    case 3:
      if (checkLevel3(row, param)) {
        fprintf(stdout,"%s",row);
        //printf("heslo- %s splnuje lvl 3 param -%i\n", row, param);
      }
      break;
    case 4:
      if (checkLevel4(row, param)) {
        fprintf(stdout,"%s",row);
        //printf("heslo- %s splnuje lvl 4 param -%i\n", row, param);
      }
      break;
    }
    if(stats){
      countPass++;
      //findes shortest password and counts all chars
      
      for(int i = 0; row[i] != '\n';i++){ 
        if(row[i+1] == '\n'){
          countChar += i+1;
        }           
        if(row[i+1] == '\n' && i <= shortestPass){
          shortestPass = i+1;
          
        }
         
      }
      //this section findes if the password contains new character whitch array dosbt contain
      for(int i = 0; row[i] != '\n';i++){
        for(int j = 0;j<difcharcounter;j++){
          if(row[i] == diffCharsarray[j]){
            exists = true;
          }
          
        }
        if(exists == false){
          diffCharsarray[difcharcounter] = row[i];
          difcharcounter++;
        }
        exists = false;
      }
     
        

    }
  }
  
  if(stats){
    vypisStats(shortestPass,countChar,countPass,difcharcounter);
  }

  return 0;
}