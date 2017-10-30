#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i = 0;
    int j = 0;
    scanf("%d",&j);
    while(i < j){
         if(i % 2 != 0){
            printf("%d\n",i);
         } 
         i++;
    }
    return EXIT_SUCCESS;
}
