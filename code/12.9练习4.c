#include <stdio.h>

int main()
{
    long long n, s = 1, ss = 0, i;
    scanf("%lld", &n);
    for(i=1; i<=n; i++)
    {
        s *= i;
        ss += s;
    }
    printf("%lld", ss);
    return 0;
}