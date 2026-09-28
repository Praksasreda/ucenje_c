#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000000

void izpisiTabelo(int t[],int n){
    printf("[");
    for (int i = 0; i < n;i++){
        printf("%d%s",t[i], (i != n-1) ? ", " : "");
    }
    printf("]\n");
}

void urebiB(int t[],int n){
    for (int i = 0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if (t[j]> t[j+1]){
                /*
                int tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
                */
               /*
               t[j] = t[j] + t[j+1];
               t[j+1] = t[j] - t[j+1];
               t[j] = t[j] - t[j+1];
               */
              t[j] ^= t[j+1];
              t[j+1] ^= t[j];
              t[j] ^= t[j+1];
                //koristno veden  drugi in tretji pristop
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int tab[N];
    int n=0;
    for (int i=0;i<N;i++){
        int x = 1 + (rand()% 39);
        
        /*
        int nasel = 0;
        for (int j = 0; j < n;j++){
            if (tab[j] == x){
                nasel=1;
                break;
            }
        }
        if (nasel){
            i--; 
            continue;
            */
           
           tab[n++]=x;
        }
    
    clock_t start = clock();
    urebiB(tab,n);
    clock_t end = clock();
    double sekunde = (double)(end -start)/CLOCKS_PER_SEC;
    printf("Cas:  %f.2\n",sekunde);
    //izpisiTabelo(tab,n);
}
