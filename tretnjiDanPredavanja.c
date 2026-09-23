#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int vnosUporabnika(){
    char x[50];
    printf("Vnesi stevilko mesece (1-12): \n");
    fgets(x,sizeof(x),stdin);
    int mesec = atoi(x);

    return mesec;
    
}

void vrniDniVMesecu(int mesec){
    int steviloDni;
    switch(mesec){
        case 1: 
            steviloDni = 31;
            break;
        case 2:
            steviloDni = 28;
            break;
        case 3:
             steviloDni = 31;
             break;
        case 4: 
            steviloDni = 30;
            break;
        case 5: 
            steviloDni = 31;
            break;
        case 6:
            steviloDni = 30;
            break;
        
        case 7: 
            steviloDni = 31;
            break;
        case 8: 
            steviloDni = 31;
            break;
        
        case 9: 
            steviloDni = 30;  
            break;  
        case 10: 
            steviloDni = 31;
            break;
        
        case 11: 
            steviloDni = 30; break;

        default:
        steviloDni = 31; break;
    }
    printf("V %d. mesecu je  %d dni.\n",mesec,steviloDni);


}


void vecDimenzijskeTabele(){
    int a[3][3] = {{42,13,7},{15,8,3},{1,17,5}};
    int j = 0;
    for (int i = 0; i < 9; i++){
        printf("%d\n",*(a[0]+i));
    }
    //naslovi se racunajo na naslov(a[i][j] = N (zacetni naslov) + (i*sirina + j) * V kjer je  sirina st stolpcev in v velikost podatkovnega tipa)
}

void izpisiGraf(){
    char matrika[25][80] = {0};

    for (int i = 0; i < 80;i++){
        matrika[13][i] = '-';
    }
    for (int i = 0; i < 25;i++){
        matrika[i][40] = '|';
    }
    
    for (int i = 0; i < 25; i++){
        if (i == 13) continue;
        for (int j = 0; j <40;j++){
            matrika[i][j] = ' ';
        }
    }
        for (int i=0; i<79;i++){
            int x = 0 + i * (79-0) / 79;
            int y = sin(x);
            int j = 24 * (y-0)/(24-0);
            matrika[i][j] = '*';
        }

    

    for (int i = 1; i <= 2000;i++){
        
        printf("%c", *(matrika[0] +i ));
        
        if (i%80 == 0) printf("\n");

    }


}



int main(){
    //vrniDniVMesecu(vnosUporabnika());
    //vecDimenzijskeTabele();
    izpisiGraf();
    
    }