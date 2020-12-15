#include <stdio.h>

int f(int);
int g(int);

int main()
{
    double eps;
    int i = 0;
    //printf("%d %d %lf", f(2), g(2), f(2)*1.0/g(2));
    double s  = 1, ss = 0;
    scanf("%le", &eps);
    while(s>=eps)
    {   
        //printf("%%\n");
        s = (f(i)) * 1.0 / (g(i));

        ss += s;
        printf("%lf ", s);
        i++;
    }
    printf("PI = %.5lf", ss);
    return 0;
}

int f(int n)//阶乘
{
    if(n==0)
    {
        return 1;
    }
    return (n * f(n-1));
}

int g(int n)//
{
    if(n==0)
    {
        return 1;
    }
    return ((2 * n + 1) * g(n-1));
}
