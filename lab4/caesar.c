#include <stdio.h>
#include <stdlib.h>

int rotate_right(int ch);
int rotate_left(int ch);
int encode(int ch, int shift);

int main(int argc, char **argv){
    int shift;
    int ch;
    printf("Enter shift:");
    scanf("%d", &shift);
    printf(" Enter Text:");
    ch = getchar();
    while(ch != EOF){
       putchar(encode (ch, shift));
       ch = getchar();
    }
 
    
    return EXIT_SUCCESS;
}

int rotate_right(int ch){
// if ch is 'z',
    // ch = 'a'
// else if ch is 'Z'
    // ch = 'z';
    if(ch == 'z'){
       ch = 'a';
    }else if(ch == 'Z'){
       ch = 'A';
    }   else{
       ch = ch + 1;
    }
    return ch;
}

int rotate_left(int ch){
    if(ch == 'a'){
       ch = 'z';
    }else if(ch == 'A'){
       ch = 'Z';    
     }else {
        ch = ch - 1;
    }
    return ch;
}

int encode(int ch, int shift){
    
    if(('a' <= ch && ch <= 'z')||('A' <= ch && ch <= 'Z' )){
        int i = 0;
        if(shift < 0){
           while(i > shift){
              ch = rotate_left(ch);
              i--;
           }
        } else if(shift > 0){
           while(i < shift){
               ch = rotate_right(ch);
               i++;
               }
           } 
    }
    else{
           ch = ch;
       }
       return ch;
}
