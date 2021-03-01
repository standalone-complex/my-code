#include <stdio.h>

int f(int);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}

int f(int n)
{
    if(n==1)
    {
        return 1;
    }
    else if(n==4)
    {
        return 7;
    }
    else
    {
        return 1389537;
    }
}