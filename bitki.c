#include <stdio.h>
#include <stdlib.h>

void izpisiStevilo(int vhod){    
}

int main(int argc, char *argv[]){

    if (argc < 2){
        printf("uporaba programa %s stevilka (0-8)\n",argv[0]);
        return 1;
    }
    /*
    int vsota = 0;
    int biti; 
    int stevec =0;
    int kolikoJiprizgati= atoi(argv[1]);
    biti = (1<<kolikoJiprizgati)-1;

    for (int i = 0; i<8-kolikoJiprizgati+1;i++){
    int stevilo = biti<<i;
    vsota+=stevilo;
    stevec++;
    //potrebno pognati s ukazom gcc -std=c2x
    // je na verziji c23
    printf("%08b = %d\n",stevilo,stevilo);
}
printf("i=%s, n=%d,vsota=%d\n",argv[1],stevec,vsota);
    */


    int vsota = 0;
    int stevecNajdenih =0;
    int kolikoJihprizgati= atoi(argv[1]);
    
   for (int i = 0; i < 256;i++){
        int stevec = 0;
        
        for (int j = 0; j < 8;j++){
            if ((i & (1 << j)) != 0) stevec++;
        }
        if (stevec == kolikoJihprizgati){
            printf("%08b = %d\n",i,i);
            vsota+= i;
            stevecNajdenih++;
        }
   }
   printf("i=%s, n=%d,vsota=%d\n",argv[1],stevecNajdenih,vsota);

}