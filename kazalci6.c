#include <stdio.h>
#include <stdlib.h>


struct kompleksno{
    int re,im;
};

typedef struct sklad {
    char ime[10];
    int vrsta[10];
} s;


int main(){

    /*
    int x = 5;
    int *p;
    p = &x;
    printf("%p = %d\n",p,*p);
    
    char a[10];
    if (a == &a[0]) printf("okei\n");
    else printf("ni panike\n");
    
    
    int t[] = {1,2,3,4,5};
    int *p = t;
    for (int i = 0; i < 5;i++){
        *p++ = i;
    }
    for (int i = 0;i< 5;i++){printf("%d\n",t[i]);}
    
    int *tp;
    
    tp = (int *) malloc (100 * sizeof(int));
    realloc(tp,50);
    free(tp);
    int a[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int *b = (int *)a; // enodim. tabela
    //potrebno zatko ker je poitner a oblike int (*)[3] potrebujemo pa samo int (*) zato pretvorba

    int i=1, j=2;
    printf("%d\n", a[i][j]);
    printf("%d\n", b[i*3+j]);
    */

    struct kompleksno w;
    w.re = 5;
    w.im = 1;

    struct kompleksno *z;
    z = (kompleksno*) malloc(sizeof(kompleksno));
    z++ ->re = 5;
    z ->im = 3;
    printf("%d,%d",z.re,z.im);
    free(z);
    





    return 0;
}