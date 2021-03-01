#include <stdio.h>

#define PI 3.1415926535897932384626

int main()
{
    double r;
    scanf("%lf", &r);
    printf("%.2lf", (4*PI*r*r*r)/3);
    return 0;  
}  