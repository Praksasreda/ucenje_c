#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OCEN 10
typedef struct el {
    int x;
    struct el *nasl;
} el;

el* vstavi(el *zac, int v){
    //malloc vrne pointer tipa void zato treba cast v el*
    el *nov = (el*) malloc(sizeof(el));
    nov -> x = v;
    nov -> nasl = zac;
    return nov;
}

int dolzina(el *zac){
    int stevec = 0;
    for (el *r = zac; r != NULL;r = r -> nasl){
        stevec++;
    }
    return stevec;
}

el* sprazni(el *zac){
    el *r = zac;
    while (r != NULL){
        el *naslednji = r -> nasl;
        free(r);
        r = naslednji;
    }
    return NULL;
}

typedef struct student{
    char *ime;
    int id;
    int stOCen; //st ocen vnesenih v ocene
    int ocene[MAX_OCEN];
    struct student *next;
} student;


student* dodajNaZacetek(student *s, student *nov){
    nov -> next = s;
    return nov;

}


student* ustvariStudenta(student *zac,char *ime,int id,int stOcen){
    student *nov = (student*) malloc(sizeof(student));
    nov -> ime = ime;
    nov -> id = id;
    nov -> stOCen = stOcen;
    nov -> next = zac;
    return nov; 
}

void izpisisStudenta(student *s){
    char ocene[50] = "{";
    char *p = ocene+1;
    for (int i =0; i < s->stOCen;i++){
        sprintf(p,"%d",s -> ocene[i]);
        p += (s->ocene[i== 10] ? 2 : 1);
        if (i < s -> stOCen-1){
            *p = ',';
            p++;
        }
    }
    strcat(p,"}");
    printf("ID : %d, ime %s ocene %s\n", s->id,s->ime,ocene);

}

void dodajOceno(student *s,int x){
    s -> ocene[s-> stOCen++] = x;

}

void izpisiSeznam(student *zac){
    for (student *r = zac; r != NULL;r = r ->next){
        printf("ime %s, id  %d,  ",r->ime,r -> id);
    }
}


int main(){
    student *zac = NULL;
    zac =  ustvariStudenta(zac,"Lojze",640003320,0);
    zac = ustvariStudenta(zac,"Tojze",640003320,0);
    zac =  ustvariStudenta(zac,"Bojze",640003320,0);
    dodajOceno(zac,5); 
    dodajOceno(zac,6); 
    dodajOceno(zac,7); 
    dodajOceno(zac,8); 
    izpisisStudenta(zac);
    
    izpisiSeznam(zac);
    /*
    el *zac = NULL;
    zac = vstavi(zac,5);
    zac = vstavi(zac,3);
    zac = vstavi(zac,1);
    zac = vstavi(zac,2);
    zac = vstavi(zac,3);
    zac = vstavi(zac,4);
    zac = vstavi(zac,5);
    for (el *r = zac; r != NULL;r = r ->nasl){
        printf("%d ",r->x);
    }
    
    el *r = zac;
    while (r != NULL){
        el *naslednji = r -> nasl;
        free(r);
        r = naslednji;
    }
    printf("%d\n",dolzina(zac));
    */


    return 0;
}