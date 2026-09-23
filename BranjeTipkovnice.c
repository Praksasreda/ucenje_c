#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    /*
    printf("Vnesi neko stevilo :\n");
    int vnos;
    scanf("%d",&vnos);
    
    printf("Vnesi eno besedo : \n");
    char x[30];
    
    fgets(x,30,stdin);
    
    
    //printf("%d\n",vnos);
    printf("%s\n",x);
    return 0;
    int starost;
    printf("Vpisi strost ");
    scanf("%d",&starost);
    
    char ime[20];
    printf("vpisi svoje ime ");
    scanf("%s",ime);
    
    printf("vpisal si %s in da si %d star\n",ime,starost);
    
    
    */
   int maxDolzina=0;
   char najdaljse[1000];

   while (1){
        char temp[1000];
        fgets(temp,1000,stdin);
        printf("%lu\n",strlen(temp));
        if (strcmp(temp,"\n") == 0) break;
        if (strlen(temp)> maxDolzina){
            strcpy(najdaljse,temp);
            maxDolzina = strlen(temp);
        }
   }

   printf("najdaljsi niz je %s",najdaljse);


}