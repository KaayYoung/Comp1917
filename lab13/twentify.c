#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * twentify(char s[]);

int main(int argc, char* argv[]) {
    
    char s[40];
    printf("Input the string: \n");
    fgets(s,40,stdin);
    s[strlen(s)-1] = '\0';
    char *new= twentify(s);
    printf("%s\n",new);
	return EXIT_SUCCESS;
}

char * twentify(char s[]) {
    
    int i = 0;
    int countSpace = 0;
    char *q = malloc(sizeof(char) *50);
    while (s[i] != '\0') {
    	while (s[i] != ' ' && s[i] != '\0') {
            q[i+countSpace*2] = s[i];
            i++;
    	}
    	if (s[i] == ' ') {
            q[i+countSpace*2] = '%';
            q[i+countSpace*2+1] = '2';
            q[i+countSpace*2+2] = '0';
            countSpace++;
    	}
        i++;
    }
	return q;
}