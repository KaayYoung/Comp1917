#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UPPER_LIMIT 15

int main(int argc,char* argv[]) {

    int num = 1;
    while (num <= UPPER_LIMIT) {
         int sum = pow(num, 2) * pow((num + 1), 2) / 4;
         printf("%2d %5d\n", num, sum);
         num++;
    }
    return EXIT_SUCCESS;
}
