#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char s[]);

int main (int argc,char* argv[]){
    
    int value;
    char s[200];
    printf("Enter string:\n");
    fgets(s,200,stdin);
    value = isPalindrome(s);
    if (value == 1) {
       printf("Yes, is a palindrome.");
    } else if (value == 0) {
       printf("No, not a palindrome.");
    } 
    
    return EXIT_SUCCESS;
}

int isPalindrome(char s[]){
    int value = 1;
    int i = 0;
    int j = 0;
    int count = 0;
    char s1[200];

    while (s[i] != '\n') {
        if (isalpha(s[i])) {
            s[i] = toupper(s[i]);
           s1[j] = s[i]; 
           
           j++; 
        }
        i++;
    }
    i = 0;
    for (i = 0;i < (j / 2); i++) {
       if (s1[i] != s1[j-i-1]) {
          count++;
       }
    }
    if (count != 0) {
       value = 0;
    }
    return value;
}
