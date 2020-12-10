#include <stdio.h>

long long f(long long);
long long g(long long);

int main()
{
    long long n;
    scanf("%lld", &n);
    printf("%lld.00", g(n));
    return 0;
}

long long f(long long n)
{
    if(n==1|n==2)
    return 1;
    return f(n-1) + f(n-2);
}

long long g(long long n)
{
    long long i, x1=1, x2 = 1, x3;
    if(n==1||n==2)
    {
        return 1;
    }
    else if(n==0)
    {
        return 0;
    }
    else
    {
        for(i=0; i<n-2; i++)
        {
            x3 = x1 + x2;
            x1 = x2;
            x2 = x3;
        }
        return x3;
    }
}
