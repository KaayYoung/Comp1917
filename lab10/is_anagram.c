#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_anagram(char s[], char t[]);

int main(int argc, char *argv[]){
  
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
    
    int i = 0;
    int val;
    int leng1 = strlen(s);
    int leng2 = strlen(t); 
    while (i < leng1) {
       s[i] = toupper(s[i]);
       i++;
    }
    i = 0;
    while (i < leng2) {
    	t[i] = toupper(t[i]);
    	i++;
    }
    i = 0;
    int j = 0;
    int count[30] = {0};
    if (leng1 == leng2) {
      while (i < leng1) {
          while (j < leng1) {
              if (s[i] == t[j]) {
                 t[j] = '*';
              } else {
                 count[i]++;
              }
              j++;
          } 
            j = 0;
            i++;
      }
      i = 0;
      j = 0;
      while (i < leng1) {
        if (count[i] == leng1) {
          j++;
        }
        i++;
      }
      if (j == 0) {
        val = 1;
      } else {
        val = 0;
      }
    } else {
    	val = 0;
    }
	return val;
}
