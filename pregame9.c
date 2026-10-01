#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#define W 79
#define H 24



char znaki[] = {'$','#','&','/'};


int main(int argc, char *args[]){
    
    /*
    if (argc != 2){
        exit(1);
    }
    args[1] = "testnaDat.txt";
    FILE *d;
    if ((d = (fopen(args[1],"r")))==NULL){
        exit(2);
    }
    char trenutna[100];
    char najdaljsa[100]="";
    int stevec = 0;
    while(fscanf(d,"%99s",trenutna) == 1){
        stevec++;
        //if (strlen(najdaljsa)<strlen(trenutna))
        //   strcpy(najdaljsa,trenutna);
        
    }
    fclose(d);
    printf("najdaljsa beseda je %d\n",stevec);
    FILE *d;
    int tov,toi,tsid;
    int ov =0,oi=0,n =0;
    int stp;
    while (!feof(d)) {
        stp = fscanf(d, "%d %d %d\n", &tsid, &tov, &toi);
        if (stp != 3) { exit(1); }
        dodaj(tsid, tov, toi);
    }
    int a = 5;
    const int *p = &a;
    //lahko spreminjas vrednost in naslov samo ne smes
    //*p = 1;
    //lahko pa 
    //kaze na drug naslov in a  = 3;

    FILE *d;
    d = fopen("testnaDat.txt","r");
    char vrstica[N];
    int najdaljsa = 0;
    int trenutna = 0;

    while (!feof(d)){
        fgets(vrstica,N,d);
        trenutna += strlen(vrstica);
        
        if (vrstica[strlen(vrstica)-1]=='\n'){
            if (najdaljsa < trenutna) najdaljsa = trenutna;
            trenutna = 0;
        }
    }
    fclose(d);
    printf("%d %s",najdaljsa,vrstica);
    */

    
    //poitner na pointer za uporabo na 2d tabel mas tabelo pointerjev na posamezno tabelo
    //izracun prostora malloc(sizeof(pointer)) * stTabel + malloc(sizeof(array[0]))) pointer je 8B;
  
    srand(time(NULL));

    char **zaslon = malloc((H*sizeof(char*)));
    for (int i = 0; i < H;i++){
        *(zaslon+i) = malloc(W*sizeof(char));
    }

    for (int i = 0; i < H;i++){
        for (int j = 0; j < W;j++){
            zaslon[i][j]  = znaki[rand() % sizeof(znaki)];
        }
    }

    for (int i = 0; i < H;i++){
        for (int j = 0; j < W;j++){
            printf("%c",zaslon[i][j]);
        }
        free(zaslon[i]);
    }
    free(zaslon);
    printf("\n");


    return 0;
}