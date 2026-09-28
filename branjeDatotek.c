#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preberiDatoteko(char imedat[50]){
    //imedat[strcspn(imedat,"\n")]="\0";
    FILE *f = fopen(imedat,"r");
    if (f == NULL){
        printf("napaka pri branju datoteke\n");
        return ;
    }
    int vsotaOcen = 0;
    int stevecOcen = 0;

    int maxOcena = 0;
    char maxIme[50], maxPriimek[50];

    char ime[50], priimek[50];
    int ocene;
    while (fscanf(f,"%s %s %d",ime,priimek,&ocene) == 3){
        vsotaOcen+= ocene;
        stevecOcen++;
        if (ocene > maxOcena){
            maxOcena = ocene;
            strcpy(maxIme,ime);
            strcpy(maxPriimek,priimek);
        }
    }
    printf("Povprecna ocena : %.2f\n",1.0 * vsotaOcen / stevecOcen);
    printf("Student s najvisjo oceno : %s %s %d \n",maxIme,maxPriimek,maxOcena);
    fclose(f);
}


void preberiTemperature(char imedat[50]){
    //vzorec dan temperatura  int float
    FILE  *f = fopen(imedat,"r");
    if (f == NULL){
        printf("Napaka pri branju datoteke\n");
        return;
    }
    //imamo vzorec uporabi s fscanf
    int dan;
    float temp;

    int stevecToplih = 0;
    FILE *t = fopen("topli.txt","w");
    if (t == NULL){
        printf("Napaka pri branju datoteke\n");
        fclose(t);
        return;
    }



    //kaj rabimo naredit je novo datoteko kjer so dnevi samo nad 25
    while(fscanf(f,"%d %f",&dan,&temp)== 2){
        if (temp > 25.0){
            fprintf(t,"%d %.2f\n",dan, temp);
            stevecToplih++;
        }
    }
    printf("Stevilo toplih dni je : %d\n",stevecToplih);
    fclose(f);
}




int main(int argc, char *argv[]){
    /*
    FILE *f = fopen("podatki.txt","r");
    //obvezna koda da ne vrne seg faulta 
    if (f == NULL){
        printf("Napaka pri branju\n");
        fclose(f);
        return 1;
    }
    
    char vrstica[256];
    while (fgets(vrstica,sizeof(vrstica),f)!=NULL){
        printf("%s",vrstica);
    }
    fclose(f);
    */
    if (argc < 2){
        printf("Uporaba programa : %s ime_datoteke\n", argv[0]);
        return 1;
    }
    //preberiDatoteko(argv[1]);
    preberiTemperature(argv[1]);
    return 0;
}