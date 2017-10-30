#include <stdio.h>
#include <stdlib.h>

int power_of_two(int k);

int main(int argc, char *argv[]){
    
    int k = 0;
    int value = 0;
    value = power_of_two(k);
       printf("value is %d\n", value);
    return EXIT_SUCCESS;
}

int power_of_two(int k) {
    int value = 0;
    scanf("%d",&k);
    while (k % 2 == 0) {
          k = k/2;
    }
    if (k == 1){
       value = 1;
    } else {
       value = 0;
    }
    return value;
}


