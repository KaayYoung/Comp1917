#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {

    int k = 0;  
    int i = 1;  
    int sum = 0;   

    printf("Enter number:");
    scanf("%d", &k);
    printf("The factors of %d are:\n", k);
    while (i <= k) {
        if (k%i == 0) {
            printf("%d\n",i);
            sum = sum +i;   	
        }
        i++;
    }
    sum = sum - k;
    printf("Sum of factors = %d\n", sum);
    if (sum == k) {
        printf("%d is a perfect number.\n", k);
    } else {
        printf("%d is not a perfect number.\n", k);
    }      

    return EXIT_SUCCESS;
}
