#include <stdio.h>
/*int is_alpha(char c){
     if (!((c >= 'a' && c<='z')  || (c >= 'A' && c<='Z'))){ return 1;}
        else{return 0;}
     

}
int is_name(char s[]){

    for (int i = 0; s[i] < count; i++)
    {
        /* code 
    }
    
}*/

double avg(double a[],double size){
    double sucet = 0;

    for (int i = 0; i < size; i++)
    {
        sucet += a[i];
    }
    
    
    return sucet/size;
}
int main(int argc, char const *argv[])
{

    double a[]={1.0,2.0,3.0};
     
    printf("Avg is> %g",avg(a,3));

    /*char name[101],surname[101];

    printf("Name:");
    scanf("%100s",name);

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!((name[i] >= 'a' && name[i]<='z')  || (name[i] >= 'A' && name[i]<='Z')))
        {
            fprintf(stderr,"Invalid name\n");
        }
        
    }
    


    printf("Surname:");
    scanf("%100s",surname);
    
    
    for (int i = 0; surname[i] != '\0'; i++)
    {
        if (!((surname[i] >= 'a' && surname[i]<='z')  || (surname[i] >= 'A' && surname[i]<='Z')))
        {
            fprintf(stderr,"Invalid surname\n");
        }
        
    }

    printf("Name> %s; Surname>%s\n",name,surname);*/


    return 0;
}
