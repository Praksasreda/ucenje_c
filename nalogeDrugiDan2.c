#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *args[]){
    char besede[100][50];
    int index = 0;

    while (index < 100){
        char temp[50];
        printf("vnesite besedo : \n");
        fgets(temp,50,stdin);

        if (strcmp(temp,"EOF\n") == 0){
            break;
        }
        
        strcpy(besede[index++],temp); 
        
        if (index == 99){
            break;
        }
        
    }
    for (int i = 0; i < 20;i++){
        printf("-");
    }
    printf("\n");
    for (int i = index-1; i  >=0; i--){
        printf("%d. %s",i+1,besede[i]);
    }
}