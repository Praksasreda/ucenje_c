#include <stdio.h>
#include <stdlib.h>


typedef struct sklad{
    char ime[10];
    int *vrsta;
    int index;
    int velikost;
} s;

void init(s *sk,int velikost){
    sk -> index=0;
    sk -> vrsta = malloc(velikost * sizeof(int));
    sk -> velikost = velikost;
}


int isEmpty(s *sk){
    //vrne 0 ce ni prazen 
    // vrne 1 ce je prazen
    if (sk -> index ==0) return 1;
    else return 0;
}

int push(int x,s *sk){
    if (sk ->index == sk -> velikost) return 1;
    else {sk -> vrsta[sk ->index++] = x; return 0;}
}

int pop(s *sk){
    //vrne 1 kot napako
    //vrne vrednost in zmanjsa index
    if (isEmpty(sk)) return 1;
    else {
        return sk ->vrsta[--sk -> index];
    }
}

void izpisi(s *sk){
    for (int i=0;i<sk ->index;i++){
        printf("%3d",sk ->vrsta[i]);
    }
    printf("\n");
}
