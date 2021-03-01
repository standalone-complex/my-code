#include <stdio.h>
#include <math.h>

int f(int);

int main()
{
    int n;
    scanf("%d", &n);
    printf("result = %d", f(n));
    return 0;
}

int f(int n)
{
    if(n==1)
    {
        return 2;
    }
    return pow(2, n) + f(n-1);
}