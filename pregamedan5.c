#include <stdio.h>
#include <math.h>






typedef struct tocke {
    float x,y;
} t;

float izracunaj_razdaljo(t t1, t t2){
    float dx = t2.x - t1.x;
    float dy = t2.y - t1.y;

    return sqrtf((dx*dx)+(dy*dy));
}


int main(int argc, char *argv[]){
    t tocka1 = {.x=1.0,.y=2.0};
    t tocka2 = {.x=4.0,.y=6.0};
    float razdalja = izracunaj_razdaljo(tocka1,tocka2);
    printf("razdalja med tockama je %.2f\n",razdalja);
    return 0;
}