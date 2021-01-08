#include <stdio.h>

int main(void)
{
    int n, i;
    double q = 1, p = 2, s = 2, t;
    scanf("%d", &n);
    for(i=1; i<n; i++)
    {
        t = q;
        q = p;
        p = p + t;
        s += p / q;
    }
    printf("%.2lf", s);
}