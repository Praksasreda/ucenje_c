#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 50

int main(){
    srand(time(NULL));    
    int rangi[10] = {0};
    for (int i = 0; i <N;i++){
        int x = 1 + (rand()% 100);

        rangi[(x-1)/10]++;
    }

    int max = 0;
    for (int i = 0; i < 10;i++){
        if (rangi[i] > max) max = rangi[i];
    }


    //krogic  izpisi
    for (int kopija = max; kopija >= 1;kopija--){
        for (int j = 0; j < 10;j++){
            if (rangi[j] >= kopija) printf("  %s    ","o");
            else printf("%7s"," ");
            }

        printf("\n");
    }


    for (int i = 0; i < 70;i++){
        printf("-");
    }
    printf("\n");


    //izpis 1-10 11-20....
    for (int i=1;i<101;i+=10){
        printf("%3d-%2d ",i,i+9);
    }
    printf("\n");


    //debug 
    for (int i = 0; i < 10;i++){
        //printf("%3d = %3d,",i,rangi[i]);
    }   
    printf("\n");
    

}