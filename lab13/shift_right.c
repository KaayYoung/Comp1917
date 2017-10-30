#include <stdio.h>
#include <stdlib.h>

void shift_right(int *array, int n);

int main(int argc, char* argv[]) {
    
    int n;
    int i = 0;
    printf("Input n: \n");
    scanf("%d",&n);
    printf("Input %d nums: \n",n);
    int array[40];
    while (i < n) {
        scanf("%d",&array[i]);
        i++;
    }
    i = 0;
    shift_right(array,n);
    while (i < n) {
    	printf("array[%d]: %d\n",i,array[i]);
    	i++;
    }
	return EXIT_SUCCESS;
}

void shift_right(int *array, int n) {
    
    int i = 1;
    int copy[40];
    copy[0] = array[n-1];
    printf("copy[0]:%d: array[%d]:%d\n", copy[0],n-1, array[n-1]);
    while (i < n) {
    	copy[i] = array[i-1];
    	printf("copy[%d]:%d, array[%d]:%d\n",i, copy[i], i-1,array[i-1]);
    	i++;
    }
    i = 0;
    while (i < n) {
       array[i] = copy[i];
       i++;
    }
}