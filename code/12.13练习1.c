#include <stdio.h>

int main()
{
    int a, b, i, j, t, tt;
    scanf("%d %d", &a, &b);
    for(i=a; i<=b; i++)
    {
        t = i;
        tt = 0;
        while(t>0)
        {
            tt = tt * 10 + t % 10;
            t /= 10;
        }
        if(i==tt)
        {
            if(i%2!=0)
            {
                for(j=2; j<i; j++)
                {
                    if(i%j==0)
                    {
                        break;
                    }
                }
                if(j==i)
                {
                    printf("%d\n", i);
                }
            }
        }
    }
    return 0;
}