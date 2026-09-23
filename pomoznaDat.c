#include <stdio.h>
#include <string.h>

char kljuc[] = "TEST";

void sifriraj(char besedilo[],int len, char kljuc[]){
    for (int i = 0; i < len;i++){
        besedilo[i] = besedilo[i] ^ kljuc[i % strlen(kljuc)];
    }
}


void odsifriraj(char besedilo[],int len, char kljuc[]){
    for (int i = 0; i < len;i++){
        besedilo[i] = besedilo[i] ^ kljuc[i % strlen(kljuc)];
    }
}