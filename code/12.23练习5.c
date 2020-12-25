#include <stdio.h>

int main()
{
    double money, year, rate;
    scanf("%lf %lf %lf", &money, &year, &rate);
    printf("interest = %.2lf", money*pow(1+rate, year)-money);
    return 0; // return
}