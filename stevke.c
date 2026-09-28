#include <stdio.h>
#include <string.h>

void prestej(char niz[], int pojavitve[]){
    for (int i = 0; niz[i] != '\0'; i++){
        if (niz[i] >= '0' && niz[i] <= '9'){
            pojavitve[niz[i] - '0']++;
        }
    }
}

int main(){
    int pojavitve[10] = {0};
    char vrstica[100];

    printf("vnesite stevilke: \n");
    while (fgets(vrstica,sizeof(vrstica),stdin)!= NULL){
        if ((vrstica[0]) == '\n')break;
        prestej(vrstica,pojavitve);
    }
    
    for (int i = 0; i < 10; i++){
        if (i == 9) printf("%d=%d\n", i, pojavitve[i]);
        else printf("%d=%d,", i, pojavitve[i]);
    }

    return 0;

}