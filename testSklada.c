#include <stdio.h>
#include "sklad.h"
#include <stdlib.h>

int main(){

    //zdj se rabi dobit koliko skladov bomo delali
    int stSkladov,velikostSkladov;
    printf("vnesite stevilo skladov\n");
    scanf("%d",&stSkladov);
    
    printf("vnesite velikost skladov\n");
    scanf("%d",&velikostSkladov);
    
    //sedaj mamo pomnilniski prostor z st skladov prostora
    s *skladi = malloc(stSkladov * sizeof(s));

    //zapolnemo zgornji prostor s dejanskimi structi 
    for (int i = 0; i < stSkladov;i++){
        init(&skladi[i],velikostSkladov);
    }
    
    int ukaz;
    printf("0 - konec programa\n");
    printf("1 - dodaj element na sklad\n");
    printf("2 - briši element s sklada\n");
    printf("3 - izpiši vsebino sklada\n");
    printf("4 - izberi sklad (%d,%d)\n",0,stSkladov-1);
    printf("5 - izpiši vsebino vseh skladov\n");
    int izbrani = 0;
    printf("trenutno izbrani sklad je %d\n",izbrani);
    


    //v metodah se klice (skladi+izbrani) zato ker v sklad.c metode kot argumente prejemajo pointerje, ti pa potrebujejo dejansko naslove zato se samo poda skladi (ker tabela je sama po sebi kazalec in mu pristevas kateri indeks naredi se s *sk = dejanski naslov )
    
    do {
        printf("---Vnesite stevilko ukaza : ---\n");
        scanf("%d",&ukaz);
        switch(ukaz){
            case 1:
                printf("vnesi stevilo: \n");
                int x;
                scanf("%d",&x);
                if (push(x,(skladi+izbrani)) == 1) printf("napaka s vnosom: poln sklad\n");
                break;

            case 2:
                if (isEmpty((skladi+izbrani)) == 1) printf("napaka : prazen sklad\n");
                else printf("odstranjeno iz sklada : %d\n",pop((skladi+izbrani)));
                break;

            case 3:
                printf("izpis vsebine sklada st %d\n",izbrani);
                izpisi((skladi+izbrani));
                break;

            case 0:
                printf("Izhod....\n");
                break;

            case 4 :
                printf("vnesite index sklada : (%d,%d)\n",0,stSkladov-1);
                scanf("%d",&izbrani);
                break;
            case 5: 
                printf("izpis vseh skladov\n");
                for(int i = 0;i < stSkladov;i++){
                    printf("sklad %d",i);
                    izpisi((skladi+i));
                }
                break;
            } 
         } while (ukaz != 0);

         for (int i = 0; i < stSkladov;i++){
            free(skladi[i].vrsta);
            //znotraj init je se alloc prostor za arraye
        }
         free(skladi);
         return 0;
}