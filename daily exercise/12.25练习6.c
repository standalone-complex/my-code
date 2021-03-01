#include <stdio.h>

int f(int);
int g(int);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", g(n));
    return 0;
}

int f(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n * f(n-1);
}

int g(int n)
{
    if(n==1)
    {
        return f(1);
    }
    return f(n) + g(n-1);
}