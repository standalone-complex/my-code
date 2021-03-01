#include <stdio.h>

int main()
{
    int a[12] = {0};
    int i, m = 0, c = 0;
    for(i=0; i<12; i++)
    {
        scanf("%d", a+i);
    }
    for(i=0; i<12; i++)
    {
        m += 300;
        if(m<a[i])
        {
            printf("-%d", i + 1);
            return 0;
        }
        m -= a[i];
        if(m>=100)
        {
            c += m / 100;
            m %= 100; 
        } 
    }
    //printf("%d %d", m, c);
    printf("%.0lf", c * 120 +(double)m);
    return 0;
}

