#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double a=0;
    double b=0;
    double c=0;
    double s,area;
    printf("Enter sidelengths of a triangle:\n");
    scanf("%lf %lf %lf",&a, &b, &c);
    if (a >= b + c || b >= a+c || c >= a + b) {
        printf("error\n");  
    } else if (a <= 0 || b<=0 || c<=0) {
        printf("error\n");
    } else {
        s=(a+b+c)/2;
        area=sqrt(s* (s - a)*(s - b)*(s - c));
        printf("Area = %.2lf\n", area);
    }
    return EXIT_SUCCESS;
}
