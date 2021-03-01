#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, t, c = 0;
    scanf("%d", &n);
    if(n>=0)
    {
        t = n;
        while(t>0)
        {
            c = c * 10 + t%10;
            t /= 10;
        }
        printf("%d", c);
    }
    else
    {
        t = abs(n);
        while(t>0)
        {
            c = c * 10 + t%10;
            t /= 10;
        }
        printf("-%d", c);
    }
    
    return 0;
}