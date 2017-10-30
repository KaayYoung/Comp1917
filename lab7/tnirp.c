#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 128

char* reverse_string(char *s);

int main(void){
    
    char s[MAXLEN];
    
    printf("Enter string:\n");
    fgets(s,MAXLEN,stdin);
    char *rev = reverse_string(s);
    printf("%s", rev);
    
   // free(rev);
    return EXIT_SUCCESS;
}

char* reverse_string(char s[]){
    
    int length;
    int i = 0;
    length = strlen(s);
    char* rev; //= malloc(sizeof(char) * (length + 1)); 
    while (i!= length / 2) {
       char* a = &s[i];
       char* b = &s[length - i - 2];
       char temp = *a;
       *a = *b;
       *b = temp;
       i++;

    }
  //  for (i = 0; i <= length; i++){
       rev = s;
  //  }
    return rev;
}
