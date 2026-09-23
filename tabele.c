#include <stdio.h>
#include <string.h>

int main(){
    /*
    char niz[10] = "test";
    for (int i = 0; i < 10; i++){
        if (strcmp((niz +i),"\0") == 0){
            printf("   bao\n");
            break;
        }
        printf("%c",*(niz + i));
    }
    int meseci[]  = {31,31,31,31,3,13,13,13,13,13,13};
    int d2[4096] = {0};
    
    for (int i = 0;i < 4;i++ ){
        //    printf("%d\t", *(d2 + i));
    }
    printf("\n");
    */
    while (1){
        char niz[100];

        printf("vnesi novo besedo : \n");
        fgets(niz,100,stdin);

        if (strcmp(niz,"\n")== 0){ 
            printf("izhod iz programa....\n");
            break;}

        for (int i = 0; i < strlen(niz)/2;i++){
            char temp = niz[strlen(niz)-1-i];
            niz[strlen(niz)-1-i] = niz[i];
            niz[i] = temp;
        }
        
        printf("%s\n",niz);
        
    }

    return 0;
}