#include <stdio.h>

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("sum = %.2f; average = %.2f", a+b+c, (a+b+c)/3);
    return 0;
}