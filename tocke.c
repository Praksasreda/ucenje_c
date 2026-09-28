#include <stdio.h>
#include <string.h>
#include <math.h>

#define DD 10
typedef struct tocke{
    char  ime[5];
    float x,y;
} to;

to  o[100];

int kolikoVrstic(char imedat[10]){
    int vrstic = 0;
    FILE *f = fopen(imedat,"r");
    if (f == NULL){
        printf("napaka pri branju datoteke");
        return 1;
    }
    char vrstica[50];
    while (fgets(vrstica,sizeof(vrstica),f) != NULL){
        vrstic++;
    }
    fclose(f);
    return vrstic;
}


void urebiBoddaljenost(to t[],int n){
    for (int i = 0;i<n;i++){
        //ideja je da za vsako izracunas oddaljenost nato pa primerjas 
        for (int j=0;j<n-i-1;j++){
            double pri1 = sqrtf((t[j].x*t[j].x) + (t[j].y*t[j].y));
            double pri2 = sqrtf((t[j+1].x*t[j+1].x) + (t[j+1].y*t[j+1].y));
            if (pri1 > pri2){
                to tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
                /*
                t[j] = t[j] + t[j+1];
               t[j+1] = t[j] - t[j+1];
               t[j] = t[j] - t[j+1];
               
            
                strcpy(tmp,t[j].ime);
                strcpy(t[j].ime,t[j+1].ime);
                strcpy(t[j+1].ime,tmp);
                */
               /*
               t[j] = t[j] + t[j+1];
               t[j+1] = t[j] - t[j+1];
               t[j] = t[j] - t[j+1];
               t[j].ime ^= t[j+1].ime;
               t[j+1].ime ^= t[j].ime;
               t[j].ime ^= t[j+1].ime;
               */
                //koristno veden  drugi in tretji pristop
            }
        }
    }
}


void urebiB(to t[],int n,int flag){
    for (int i = 0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            double pri1 = sqrtf((t[j].x*t[j].x) + (t[j].y*t[j].y));
            double pri2 = sqrtf((t[j+1].x*t[j+1].x) + (t[j+1].y*t[j+1].y));
            if ((flag && strcmp(t[j+1].ime,t[j].ime)<0) || (!flag && (pri1 > pri2))){
                
                    /*
                    char tmp[5];
                    strcpy(tmp,t[j].ime);
                    strcpy(t[j].ime,t[j+1].ime);
                    strcpy(t[j+1].ime,tmp);
                    */
                   to tmp = t[j];
                    t[j] = t[j+1];
                    t[j+1] = tmp;
                    

                }
                    
        
            }
                /*
                */
               /*
               t[j] = t[j] + t[j+1];
               t[j+1] = t[j] - t[j+1];
               t[j] = t[j] - t[j+1];
               t[j].ime ^= t[j+1].ime;
               t[j+1].ime ^= t[j].ime;
               t[j].ime ^= t[j+1].ime;
               */
                //koristno veden  drugi in tretji pristop
            }
        }
    




void preberiDatoteko(int velikostDat,char imedat[10]){
    FILE *f = fopen(imedat,"r");
    if (f == NULL){
        printf("napaka pri branju datoteke");
        return;
    }
    for (int i = 0;i < velikostDat;i++){
        char ime[5];
        float x,y;
        fscanf(f,"%s %f %f",ime, &x, &y);
        strncpy(o[i].ime,ime,sizeof(o[i].ime)-1);
        o[i].ime[sizeof(o[i].ime)-1] = '\0';
        o[i].x = x;
        o[i].y = y;
    }

        urebiB(o,velikostDat,1);
        for (int i = 0; i<velikostDat;i++){
            printf("%s %.2f %.2f\n",o[i].ime,o[i].x,o[i].y);
        }
        printf("\n");

        urebiB(o,velikostDat,0);
        for (int i = 0; i<velikostDat;i++){
            printf("%s %.2f %.2f\n",o[i].ime,o[i].x,o[i].y);
    }
    fclose(f);
}

int main(int argc, char *argv[]){
    if (argc< 2){
        printf("napacna uporaba programa. uporaba : %s ime_datoteke",argv[0]);
        return 1;
    }

    int dd = kolikoVrstic(argv[1]);
    preberiDatoteko(dd,argv[1]);

    return 0;
}