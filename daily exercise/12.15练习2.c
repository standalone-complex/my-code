#include <stdio.h>

double f(int);
double g(int);

int main()
{
    double eps;
    int i = 0;
    double s  = 1, ss = 0;
    scanf("%le", &eps);
    while(s>=eps)
    {   
        s = (f(i)) * 1.0 / (g(i));
        printf("%lf %lf %lf ", f(i), g(i), s);
        ss += s;
        i++;
    }
    printf("PI = %.5lf", ss * 2);
    return 0;
}

double f(int n)//阶乘
{
    if(n==0)
    {
        return 1;
    }
    return (n * f(n-1));
}

double g(int n)//
{
    if(n==0)
    {
        return 1;
    }
    return ((2 * n + 1) * g(n-1));
}
