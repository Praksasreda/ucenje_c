#include <stdio.h>
#include <stdlib.h>

void wc(char imedat[50]){
    FILE *f = fopen(imedat,"r");
    if (f == NULL){
        printf("Napaka pri branju datoteke\n");
        return ;
    }
    //potrebujem stevilo vrstic to je nekje v knjigi zapisani
    //nato besede se da s fscanf in znaki s fgetc ali nekaj takega
    //potrebno vec prehodov?
    int vrstic = 0;
    int besed = 0;
    int znakov = 0;

    char beseda[50];
    while (fscanf(f,"%s",beseda)== 1){
        //tukaj dobimo besede
        besed++;
    }
    rewind(f);
    char vrstica[50];
    while (fgets(vrstica,sizeof(vrstica),f) != NULL){
        vrstic++;
    }
    rewind(f);
    
    while(fgetc(f) != EOF){
        znakov++;
    }
    printf("vrstica %d, besed %d, znakov %d\n",vrstic,besed,znakov);
    fclose(f);
}

void wcEnaZanka(char imedat[50]){
    FILE *f = fopen(imedat,"r");
    if (f == NULL){
        printf("Napaka pri branju datoteke\n");
        return ;
    }
    int vrstic = 0;
    int besed = 0;
    int znakov = 0;
    
    int prejsniPresedek = 0;
    while (1){
        int znak = fgetc(f);
        if (znak == EOF){
            break;
        }
        if (znak == '\n') {
            vrstic++;
            if (!prejsniPresedek) besed++;
            prejsniPresedek = 1;
        }
        else if (znak == ' '){
            if (!prejsniPresedek) besed++;
                prejsniPresedek = 1;
            
        } 
        else prejsniPresedek = 0;
        znakov++;
    }


    printf("vrstica %d, besed %d, znakov %d\n",vrstic,besed,znakov);
    fclose(f);
}


int main(int argc, char *argv[]){
    if (argc<2){
        printf("Napacna uporaba programa:%s imedatoteke\n",argv[0]);
        return 1;
    }
    ;
    wc(argv[1]);
    wcEnaZanka(argv[1]);

}