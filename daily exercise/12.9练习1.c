#include <stdio.h>

int main()
{
    int n, k, i, c1 = 0, c2 = 0;
    double s1 = 0, s2 = 0;
    scanf("%d %d", &n, &k);
    for(i=1; i<=n; i++)
    {
        if(i%k==0)
        {
            s1 += i;
            c1++;
        }
        else
        {
            s2 += i;
            c2++;
        }
    }
    printf("%.1lf %.1lf", s1/c1, s2/c2);
    return 0;
}