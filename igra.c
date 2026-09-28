#include <stdio.h>

void izpisiPlosco(char plosca[7][7]) {
    printf("\n    ");
    for (int j = 0; j < 7; j++)
            printf("%2d ", j + 1);
    printf("\n");
 
    for (int i = 0; i < 7; i++) {
        printf("%3d  ", i + 1);
         for (int j = 0; j < 7; j++)
                printf("%c  ", plosca[i][j]);
        printf("\n");
    }
    printf("\n");
}

int preveriZmago(char plosca[7][7], char krogec){
    //vodoravna logika
    for (int i = 0; i < 7;i++){
        int stevec = 0;
        for (int j = 0; j < 7;j++){
            if (plosca[i][j] == krogec){
                stevec++;
            }
            else stevec = 0;
            if (stevec==4) return 1;

        }
    }
    for (int i = 0; i < 7;i++){
        int stevec = 0;
        for (int j = 0; j < 7;j++){
            if (plosca[j][i] == krogec) stevec++;
            if (stevec == 4) return 1;
        }
    }
    return 0;
}

void pocistiVnos(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main(){
    char plosca[7][7];
      for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
                plosca[i][j] = '.';

    char krogci[2] = {'X','O'};
    int zasedenaPolja = 0;
    int naPotezi = 0;
    int napake[2] = {0,0};
    int vrhovi[7] = {0};

    while (1){
        izpisiPlosco(plosca);
        printf("vnesi vrstico stolpce _ _ igralec %c: \n",krogci[naPotezi]);
        int vrstica, stolpec;
        int prebrano = scanf("%d %d", &vrstica,&stolpec);

        int veljavno = 1;
        if (prebrano != 2){
            pocistiVnos();
            veljavno = 0;
        }
        else if (vrstica < 1 || vrstica > 7 || stolpec < 1 || stolpec > 7 ){
            printf("Neveljavna poteza (%d,%d)",vrstica,stolpec);
            veljavno = 0;
        }
        else if (plosca[vrstica-1][stolpec-1] != '.'){
            printf("Polje je ze zasedeno (%d,%d)",vrstica,stolpec);
            veljavno = 0;
        }
        
        if (veljavno == 0){
            napake[naPotezi]++;
            if (napake[naPotezi]>=3){
                printf("igralec %c je naredil prevec napak in izgubi\n",krogci[naPotezi]);
                printf("zmaga igralec %c",krogci[1 - naPotezi]);
                break;
            }
            continue;
        }
        plosca[vrstica-1][stolpec-1] = krogci[naPotezi];
        vrhovi[vrstica-1]++;
        zasedenaPolja++;

        if (preveriZmago(plosca,krogci[naPotezi])==1){
            printf("zmagal je igralec %c;\n",krogci[naPotezi]);
            izpisiPlosco(plosca);
            break;  
        }

        if (zasedenaPolja == 49){
            printf("polna plosca noben ne zmaga");
            izpisiPlosco(plosca);
            break;
        }
        naPotezi = 1 - naPotezi;

    }
    return 0;
 
}