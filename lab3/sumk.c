#include <stdio.h>
#include <stdlib.h>

#define UPPER_LIMIT 15

int main(int argc,char* argv[]) {

    int num = 1;
    while (num <= UPPER_LIMIT) {
         int sum = num * (num + 1) / 2;
         printf("%2d %4d\n", num, sum);
         num++;
    }
    return EXIT_SUCCESS;
}
