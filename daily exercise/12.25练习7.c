#include <stdio.h>
#include <stdbool.h>

bool prime(int);

int main()
{
    int m, n, sum = 0, count = 0;
    scanf("%d %d", &m, &n);
    while(m<=n)
    {
        if(prime(m))
        {
            count++;
            sum += m;
        }
        m++;
    }
    printf("%d %d", count, sum);
    return 0;
}

bool prime(int n)
{
    if(n==0||n==1)
    {
        return false;
    }
    int j;
    for(j=2; j<n; j++)
    {
        if(n%j==0)
        {
            return false;
        }
    }
    return true;
}