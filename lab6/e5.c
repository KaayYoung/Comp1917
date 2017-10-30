#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define NUM_DIGITS 10

int isDigit(char c);
int digitVal(char c);

int main (int argc, char * argv[]) {
    
    int count[NUM_DIGITS] = {0};
    int val;
    printf("Please input numbers:\n");
    char c = getchar();
    while (c != EOF) {
       if (isDigit(c)) {
       	val = digitVal(c);
       	count[val]++;
       }
       c = getchar();
    }

    int i = 0;
    while (i < NUM_DIGITS) {
    	printf("%d  %d\n", i, count[i]);
    	i++;
    }
    return EXIT_SUCCESS;
}

int isDigit(char c){

	int flag = FALSE;
    if (c >= '0' && c<= '9') {
    	flag = TRUE;
    }
    return flag;
}

int digitVal(char c){

	int val = c - '0';
	return val;
}