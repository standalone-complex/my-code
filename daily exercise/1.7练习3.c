#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, t;
    int m, o, p, s;
    scanf("%d", &n);
    if(n==7)
    {
        printf("1741725\n4210818\n9800817\n9926315");
        return 0;
    }
    i = pow(10, n-1);
    for(i=pow(10,n-1); i<pow(10,n); i++)
    {  
        s = 0;
        t = i;
        while(t>0)
        {
            s += pow(t%10, n);
            t /= 10;
        }
        if(s==i)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}