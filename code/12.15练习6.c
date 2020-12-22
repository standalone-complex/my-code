#include <stdio.h>

double f(int, int);
int g(int);

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("result = %.0lf", f(m, n));
    return 0;
}

double f(int m, int n)
{
    return g(n) / (g(m) * g(n-m));
}

int g(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n * g(n-1);
}