#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_anagram(char s[], char t[]);

int main(int arge, char* argv[]){
    

   int val;
   char s[30] ;
   char t[30] ;
   printf("Please input the first string:\n");
   scanf("%s",s);
   printf("Please input the second string:\n");
   scanf("%s",t);
   val = is_anagram(s,t);
   if (val == 1) {
       printf("It is an anagram.\n");
   } else if (val == 0) {
       printf("It is not an anagram.\n");
   }
	return EXIT_SUCCESS;
}

int is_anagram(char s[], char t[]){
    
    int result_s[26] = {0};
    int result_t[26] = {0};
    int i = 0;
    while (s[i] != '\0') {
    	result_s[toupper(s[i])-65] = result_s[toupper(s[i])-65]+1;
    	i++;
    }
    i = 0;
    while (t[i] != '\0') {
    	result_t[toupper(s[i])-65] = result_t[toupper(t[i])-65]+1;
    	i++;
    }
    i = 0;
    int val = 0;
    while (i < 26) {
    	if (result_s[i] != result_t[i]) {
    		val = 0;
    	}
    	i++;
    }
	return val;
}