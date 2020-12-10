#include <stdio.h>

int main()
{
    int a, b, i, j, t, c;
    scanf("%d %d", &a, &b);
    for(i=a; i<=b; i++)
    {
        for(j=2; j<i; j++)
        {
            if(i%j==0)
            {
                break;
            }
        }
        if(i==j)
        {
            t = i;
            c = 0;
            while(t>0)
            {
                c = c*10 + t%10;
                t /= 10; 
            }
            if(c==i)
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}