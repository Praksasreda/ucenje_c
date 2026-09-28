#include <stdio.h>
typedef struct sklad{
    char ime[10];
    int vrsta[100];
    int index;
} s;

s sk = {.ime="test",.vrsta={1,2,3,4,5},.index=5};
struct sklad *sk;


void init(){
    sk.index=0;
}

void push(int x){}

int pop(){
    return;
}

int isEmpty(){
    return ;
}