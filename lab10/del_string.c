#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delString(char s[], int lo, int h1);
void printString(char x[]);

int main(int argc, char *argv[]){
    
    char s[30];
    int lo;
    int hi;
    printf("Please input the string:\n");
    scanf("%s",s);
    printf("Please input the lower limit:\n");
    scanf("%d", &lo);
    printf("Please input the upper limit:\n");
    scanf("%d", &hi);
    delString(s,lo,hi);

    return EXIT_SUCCESS;
}

void delString(char s[], int lo, int hi){
    
    int leng = strlen(s);
    int i = 0;
    int j = hi;
    char t[30] = {0};
    if (lo >= 0 && hi >= 0) {
    	while (i < lo) {
    		t[i] = s[i];
    		i++;
    	}
    	while (s[j+1] != 0) {
    		t[i] = s[j+1];
    		i++;
    		j++;
    	}
    } else {
        while (i < leng) {
            t[i] = s[i];
            i++;
        }  
    }
    printString(t);
}

void printString(char x[]){
    
    int i = 0 ;
    while (i < strlen(x)) {
    	printf("%c",x[i]);
    	i++;
    } 
    printf("\n");
}