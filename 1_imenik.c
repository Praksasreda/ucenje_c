#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pomnilnik = 0;

typedef struct { 
    //kazalci treba bo -> uporabit
    char *ime;  
    char *priimek;  
    char *telefon;
} oseba;

int preberiKolikoVrstic(char *imedat){
    //dodaj basic struktura za branje
    FILE *f = fopen(imedat,"r");
    if (f == NULL){
        printf("napaka pri branju datoteke");
        return 0;
    }
    //potrebno branje samo ene vrstice
    char brano[100];
    fgets(brano,sizeof(brano),f);
    fclose(f);
    return atoi(brano);
}

int primerjajPriimek(const void *a, const void *b){
    //void ne ve tipa tukaj ga castas  v pointer na osebo da lahko klices atribute
    oseba *oseba1 = (oseba*)a;
    oseba *oseba2 = (oseba*)b;
    
    return strcmp(oseba1 -> priimek, oseba2 -> priimek);
}



//metoda ki prebere datoteka in dodaja kazalce temp oseb v osebe dejanske vrednosti se pa shranijo v temp nekje v pomnilniku
void beriVrstico(char *imedat,oseba *osebe,int stVrstic){
    
    FILE *f = fopen(imedat,"r");
    if (f == NULL){
        printf("napaka pri branju datoteke");
        return ; //vrne NULL ce je napaka 
    }
    
    //potreben preskok prve vrstice¸
    oseba temp;
    char vrstica[100];
    fgets(vrstica,sizeof(vrstica),f);
    for (int i = 0;i < stVrstic;i++){
        //tukaj se sedaj dela na 
        fgets(vrstica,sizeof(vrstica),f);
        //dobimo vrstico shranimo gor lahko damo
        char *result;
        result = strtok(vrstica,":");
        //tukaj ze odreze ime
        int stAtrb = 0;
        while (result !=NULL){
            switch (stAtrb)
            {
                //problem sami pointerji so v structu rabis alloc prostor
                case 0:
                    temp.ime = malloc(strlen(result)+1);
                    pomnilnik += strlen(result)+1;
                    strcpy(temp.ime,result);
                    stAtrb++;
                    break;
                case 1:
                    temp.priimek = malloc(strlen(result)+1);
                    pomnilnik += strlen(result)+1;
                    strcpy(temp.priimek,result);    
                    stAtrb++;
                    break;
                case 2:
                    temp.telefon = malloc(strlen(result)+1);
                    result[strcspn(result,"\n")]='\0';
                    pomnilnik += strlen(result)+1;
                    strcpy(temp.telefon,result);
                    break;
            }
            result = strtok(NULL,":");
        }
        *osebe = temp;
        osebe++;
    }    
    fclose(f);
}


int main(){
    char imedat[] = "osebe.txt";
    int stVrstic = preberiKolikoVrstic(imedat);

    if (stVrstic==0) {printf("Napaka pri branju\n"); return 1;} 
    //osebe je pointer na obmocje ker se shranjeni pointerji na samomicne osebe
    // v to obmocje se pisejo temp iz beriVrstico
    oseba *osebe = malloc(stVrstic* sizeof(oseba));
    beriVrstico(imedat,osebe,stVrstic);

    //sedaj imamo v osebe shranjene vse vnose iz datoteke samo sortiranje je poterbno
    qsort(osebe,stVrstic,sizeof(oseba),primerjajPriimek);
    for (int i =0; i < stVrstic;i++){
        printf("%s %s %s\n", osebe[i].ime, osebe[i].priimek, osebe[i].telefon);
    }

    for(int i=0;i<stVrstic;i++){
        free(osebe[i].ime);
        free(osebe[i].priimek);
        free(osebe[i].telefon);
    }
    pomnilnik+= stVrstic * sizeof(oseba);
    printf("Podatkovna struktura zaseda %d Bajtov\n",pomnilnik);
    free(osebe);
}
