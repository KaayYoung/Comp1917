#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i = 0;
    int n = 0;
    scanf("%d", &n);
    while (n > 0){
       while (i < n) {
           printf("*");
        i++;
       }
       printf("\n");
       n--;
       i = 0;
    }
    return EXIT_SUCCESS;
}
