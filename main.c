#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//funkcia ktora dostane z argv char a vrati int s overenim pre level
int getIntLevel(char *argv){
    char *endptr;
    int i = strtoul(argv,&endptr,10);

    if(endptr[0] != '\0'){
      fprintf(stderr,"Parameter Level musi byt cele kladne cislo  \n");
      return -1;
    }
    if(i>4 || i<1){
      fprintf(stderr,"Parameter Level sa ma nachadzat v rozmedzi od 1 - 4  \n");

      return -1;
    }
    
    

    return i;
  }
//funkcia ktora dostane z argv char a vrati int s overenim pre param
int getIntParam(char *argv){
    char *endptr;
    int i = strtoul(argv,&endptr,10);

    if(endptr[0] != '\0' || i<=0){
      fprintf(stderr,"Parameter  musi byt cele kladne cislo  \n");
      return -1;
    }
    

    return i;
  }


/*int getCharParametre(char *argv){
    char *endptr;
    char str1[] = strtoul(argv,&endptr,10);
    char str2[] = "--stats";
    if (strcmpr(str1,str2)==0)
    {
      return 1;
    }
    
    return 0;
  }*/

int main(int argc, char *argv[])
{
  printf("Number of arguments: %d\n", argc);
 
  // inicializace promenne i 
 
  int i = 1;
  // prvni a dalsi podminky 
  /*while (argc > i)
  {
    // telo cyklu 
    printf("%d. argument: %s\n", i, argv[i]);
    // inkrementace 
    i = i + 1;
  }*/
  //inicializacia premennych pre parametre
  int level;
  int param;
  bool stats = false;

  //nacitanie parametrov
  if(argc > 2 && argc < 4){
    level = getIntLevel(argv[1]);
    param = getIntParam(argv[2]);

    /*if (getCharParametre(argv[3]))
    {
      bool stats = true;
    }*/
    
    

    /*if(argc == 3){
      stats = true;
    }*/
  }else{
    printf("Zly pocet parametrov \n");
  }
  printf("level- %d param- %d stats- %d \n",level,param,stats);
  
  



  char riadok[101];
  while (fgets(riadok,101,stdin)!= NULL)
  {
    printf("%s",riadok);
  }
  
  

 
  return 0;
}