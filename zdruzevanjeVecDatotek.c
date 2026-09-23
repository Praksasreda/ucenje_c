#include <stdio.h>
#include "pomoznaDat.h"
#include <string.h>
#include <limits.h>
int main(){
    char x[1024];
    printf("vnpsi besedilo :\n");
    fgets(x,sizeof(x),stdin);

    int len = strlen(x);
    sifriraj(x,len,"TEST");
    printf("%s\n",x);
    
    odsifriraj(x,len,"TEST");
    printf("%s\n",x);
    

}