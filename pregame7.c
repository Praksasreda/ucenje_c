#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*Operacija)(int ,int);

int sestej(int a, int b){
    return a + b;
}
int odstej(int a, int b){
    return a - b;
}

int pomnozi(int a, int b){
    return a * b;
}

int delitev(int a, int b){
    return a / b;
}



Operacija ops[] = { sestej,odstej,pomnozi,delitev};
char simboli[] = {'+','-','*','/'};




//to je general struktura metode samo dodas paramtre in jih v return pravilno castas *(tip *)var ...
int primerjaj(const void *a, const  void *b){
    return *(int *)b  - *(int *)a; 
}


int main(){
   /*
   int tab[] = {1,2,3,4,5};
   int i = 3;
   printf("%d\n",i[tab]);
   char *niz = "To je dolg niz";
   char *p = strstr(niz,"dolg");
   printf("%c\n",*p);
   char *niz = "To je dolg niz";
   while (niz != NULL) {
    printf("%p - %s\n", niz, niz);
    //niz++;                    // premakni se za 1 naprej, da ne najdeš istega presledka
    niz = strstr(niz, " ");   // poišči naslednji presledek
}
char str[] = "abc:def:ghi";   // pozor: NE char*, ampak tabela
char *result = strtok(str, ":");   // prvi klic: niz + ločila
while (result != NULL) {
    printf("%s\n", result);
    result = strtok(NULL, ":");    // nadaljnji klici: NULL + ločila
}
// NEVARNO
char *preberiBesedo(void) {
    char *niz = malloc(100);
    scanf("%s", niz);
    return niz;    // kdo bo to sprostil?
}

// BOLJE
void preberiBesedo(char *beseda) {
    scanf("%s", beseda);   // klicatelj priskrbi pomnilnik
}
int x[7];
int *p = x;
    char vhod[] = "42,7,13,99,1,56,3";
    char *result = strtok(vhod,",");
    while (result != NULL){
        *p = atoi(result);
        p++;
        result = strtok(NULL,",");
    }

    qsort(x,7,sizeof(int),primerjaj);
    for (int *ptr = x;ptr < &x[7];ptr++){
        printf("%d ",*ptr);
    }
    printf("\n");
    
    typedef void urediFUnkcija(int *);
    //to je funkcija 
    urediFUnkcija uredi;
    //to je spremenljivka -> kazalec 
    urediFUnkcija *uredi;
    
    int (*compar)(const void *,const void *);
    
    typedef int (*Primerjalnik)(const void *,const void *);
    Primerjalnik c = primerjaj;
    //primerjalnik ni funkcija je ime za tip c je spremenljivka
    //c je kazalec ki drzi naslov neke funkcij
    //primerjalnik je kazalec 
    typedef int Celo;
    Celo c = 5;
    
    */

    int a = 5;
    int b = 3;
    for (int i = 0; i < sizeof(ops)/sizeof(ops[0]);i++){
        int rez = ops[i](a,b);
        printf("%d %c %d = %d\n",a,simboli[i],b,rez);
    }




}