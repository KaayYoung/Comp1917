#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize(char *s);

int main(int argc, char *argv[]) {
    
    char s[40];
    printf("Input string: \n");
    scanf("%s",s);
    sanitize(s);
    printf("%s\n",s);
	return EXIT_SUCCESS;
}
 
void sanitize(char *s) {
    
    int i = 0;
    int t = 0;
    char q[40];
    while (s[i] != '\0' && s[i] != '\n') {
        if (s[i] != s[i+1]) {
            q[t] = s[i];
            t++;
        } else {
        	
        	    while (s[i] == s[i+1]) {
        		     i++;
        	    }
              
        }
        i++;
    }
    strcpy(s,q);
}