#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100 

typedef struct bes {
    char beseda[MAX];
    struct bes *nasl; // kazalec na naslednji element seznama
    struct bes *naslCrka;
} beseda;

typedef int fIsci(beseda *,char *);

beseda * ustvariBesedo(beseda *zac,char *vhodna){
    beseda * nov = (beseda *) malloc(sizeof(beseda));
    strcpy(nov -> beseda,vhodna);
    nov -> nasl = zac;
    nov -> naslCrka = NULL;
    return nov;
}
//preuredit da vraca vec vrednosti. 1 ce ni ujemanja 0 ce je arg1 manjse od arg2  -1 ce je arg2 vecje od arg1

int obstaja(beseda *zac, char *iskana){
    beseda *r = zac;
    while (r != NULL){
        beseda *naslednji = r -> nasl;
        if (strcmp(r->beseda,iskana)== 0) return 1 ;
        r = naslednji;
    }
    return 0;
}

beseda * vstaviUrejeno(beseda *zac, char *iskana){
    // prazen seznam ali nova beseda pride pred prvo: nov element postane glava
    if (zac == NULL || strcmp(iskana, zac->beseda) < 0){
        return ustvariBesedo(zac, iskana);
    }

    // prejsnji element
    beseda *tmp = zac; 
    beseda *r = zac;
    // trenutni element
    while (r != NULL){
        int primerjava = strcmp(r->beseda, iskana);
        if (primerjava == 0) return zac; //duplikat
        if (primerjava > 0){
            //beseda v listu je vecja torej iskana mora it pred njo
            // na prejsni element se doda naslov novega
            tmp->nasl = ustvariBesedo(r, iskana);
            //vrne zacetek ker nismo spremninjal zacetka
            return zac;
        }
        tmp = r;
        r = r->nasl;
    }
    //dodam na konec
    tmp->nasl = ustvariBesedo(NULL, iskana);
    return zac;
}




beseda * preberiDatoteko(char *imeDat,beseda *zac){
    FILE *f = fopen(imeDat,"r");
    if (f == NULL){
        printf("napaka pri branju datoteke");
        return NULL ; //vrne NULL ce je napaka 
    }
    char brano[MAX];
    beseda *temp = zac;
    while (fscanf(f, "%99[a-zA-Z]%*[^a-zA-Z]",brano)==1){
        //tukaj sedaj obdelava 
        int dolzina = strlen(brano)+1;

        for (int i = 0; i < dolzina;i++){
            brano[i] = tolower(brano[i]);
        }
        //tukaj lahko direkt 
        temp = vstaviUrejeno(temp,brano);
    }

    fclose(f);
    return temp;
}

int poisci(beseda *zac,char *word){
    int stevec = 0;
    for (beseda *r = zac; r != NULL;r = r ->nasl){
        int primerjava = strcmp(r->beseda,word);
        if (primerjava == 0) return stevec;
        stevec++;
    }
    return -1;
}

int povprecnoIskanje(fIsci *isci,beseda *zac){
    int stBesed = 0;
    int steviloKorakov = 0;
    for (beseda *r = zac; r != NULL; r = r ->nasl){
        stBesed++;
        steviloKorakov += isci(zac,r->beseda);
    }
    return (int) (steviloKorakov/stBesed);
}

void dopolniSeznam(beseda *zac){
    //kazalec na zacetkui hrani prvo crko 
    beseda *prvaCrke = zac;
    for (beseda *r = zac; r != NULL; r = r->nasl){
        r->naslCrka = NULL;
        if (r->beseda[0] != prvaCrke->beseda[0]){
            //ce se beseda ne ujema s prvo crko  zacetka potem je nova 
            //spremenis prva crka na da kaze na r torej prejsno
            prvaCrke->naslCrka = r;
            prvaCrke = r;
        }
    }
}

int poisciHitreje(beseda *zac,char *word){
    if (zac == NULL) return -1;
    int stevec = 0;
    beseda *r = zac;
    //ideja je da prvo prides do crke potem pa isces znotraj skupine
    while (r->beseda[0] < word[0] && r->naslCrka != NULL){
        r = r->naslCrka;
        //steje korako do prave skupine
        stevec++;
    }
    //ce ni besede vrni -1
    if (r->beseda[0] != word[0]) return -1;
    

    while (r != NULL && r->beseda[0] == word[0]){
        int primerjava = strcmp(r->beseda,word);
        if (primerjava == 0) return stevec;
        //smo ze mimo
        if (primerjava > 0) break;

        r = r->nasl;
        //stejemo znotraj skupine
        stevec++;
    }
    return -1;
}

void pocistiSeznam(beseda *zac){
    while (zac != NULL){
        beseda *naslednji = zac->nasl;
        free(zac);
        zac = naslednji;
    }
}

void izpisiBesede(beseda *zac){
    for (beseda *r = zac; r != NULL;r = r ->nasl){
        printf("%s ", r->beseda);
    }
    printf("\n");
}


int main(){
    char imeDat[] = "slovenija.txt";
    beseda *zac = NULL;
    zac = preberiDatoteko(imeDat,zac);
    dopolniSeznam(zac);
    izpisiBesede(zac);

    printf("PI1: %d\n", povprecnoIskanje(poisci, zac));
    printf("PI1: %d\n", povprecnoIskanje(poisciHitreje, zac));

    
    while(1) {    
    char trb[MAX];
    scanf("%s", trb);
    printf("%d\n", poisci(zac, trb));
    printf("%d\n", poisciHitreje(zac, trb));
    }

    pocistiSeznam(zac);
    zac = NULL;
}