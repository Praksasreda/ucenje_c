#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *args[]){
    int sekunde;
    int h,m,s;
    
    for (int i = 1; i < argc; i++){

        if (sscanf(args[i],"%d:%d:%d",&h,&m,&s) == 3){
            int skupaj = h * 3600 + m * 60 + s;

            printf("%s = %ds\n",args[i],skupaj);
        }

        else if (sscanf(args[i],"%d",&sekunde) == 1){
            int ur = sekunde / 3600;
            int minute = (sekunde % 3600) / 60;
            int sek = sekunde % 60;

            printf("%ds =  %02d:%02d:%02d\n",sekunde,ur,minute,sek);

        }
    }

    return 0;
}