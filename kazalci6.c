#include <stdio.h>

typedef struct sklad {
    char ime[10];
    int vrsta[10];
} s;


int main(){
    
    int x = 5;
    int *p;
    p = &x;
    printf("%p = %d\n",p,*p);

    char a[10];
    if (a == &a[0]) printf("okei");
    else printf("ni panike");
    printf("bao");
    return 0;
}