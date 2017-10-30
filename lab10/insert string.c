#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_string(char s[], char t[], int k);
void printString(char q[]);

int main(int argc, char *argv[]){
    
    char s[30];
    char t[30];
    int k;
    printf("Please input the first string:\n");
    scanf("%s", s);
    printf("Please input the second string:\n");
    scanf("%s", t);
    printf("Input k\n");
    scanf("%d", &k);
    
    insert_string(s,t,k);
    
    return EXIT_SUCCESS;
}	

void insert_string(char s[], char t[], int k) {
	char q[30] = {0};
	int leng1 = strlen(s);
	if (k >= leng1) {
       strcat(s,t);
       printString(s);
	} else if (k <= 0) {
       strcat(t,s);
       printString(t);
	} else {
	   
	    int count = 0;
	    while (count < k) {
            q[count] = s[count];
            count++; 
	    }
	    printString(q);
        strcat(q,t);
        int leng2 = strlen(t);
        while (count < leng1+leng2) {
        	q[count+leng2] = s[count];
        	count++; 
        }
        printString(q);
    }
}

void printString(char x[]) {
	int i = 0;
	while (i < strlen(x)) {
		printf("%c",x[i]);
		i++;
	}
	printf("\n");
}