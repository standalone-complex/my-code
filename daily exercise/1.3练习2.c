#include <stdio.h>

int prime(int);

int main(void)
{
    int i, c = 0;
    for(i=2; i<=100; i++)
    {
        if(prime(i))
        {
            printf("%6d", i);
            c++;
        }
        if(c%10==0)
        {
            printf("\n");
        }
    }
    return 0;
}

int prime(int x)
{
    int i;
    for(i=2; i<x; i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1;
}