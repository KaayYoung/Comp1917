#include <stdio.h>
#include <stdlib.h>

void average(int n,int a[]);

int main(int argc, char *argv[]){
    int n = 0;
    int a[n];
    average(n,a);
   
    return EXIT_SUCCESS;
}

void average(int n, int a[]){
    double avevalue;
    scanf("%d",&n);
    int i = 0;
    while (i < n){
       scanf("%d",&a[i]);
       i++;
    }
    i = 0;
    int sum = 0;
    while (i < n){
       sum = sum + a[i];
       i++;
    }
    avevalue = sum / n;
    printf("%lf",avevalue);
}
