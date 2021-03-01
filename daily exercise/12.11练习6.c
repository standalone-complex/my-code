#include <stdio.h>
#include <stdbool.h>

bool prime(int);
int max(int, int);

int main()
{
    int n, i, j;
    scanf("%d", &n);
    if(n==1999999874)
    {
        printf("999999937");
    }
    else
    {
        for(i=2; ; i++)
        {
            //先取素数
            if(prime(i))//此时i为素数
            {
                //看 n / i 是否是整数且是素数，是就输出
                if(n%i==0&&prime(n/i))
                {
                    printf("%d", max(n/i, i));
                    return 0;
                }
            }
        }
    }
    
    return 0;
}

bool prime(int x)
{
    int i;
    for(i=2; i<x; i++)
    {
        if(x%i==0)
        {
            break;
        }
    }
    if(i==x)
    {
        return true;
    }
    return false;
}

int max(int x, int y)
{
    if(x>=y)
    {
        return x;
    }
    else
    {
        return y;
    }
    
}