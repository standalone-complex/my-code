#include <stdio.h>

int main()
{
    double m, n, s = 0;
    scanf("%lf %lf", &m, &n);
    int i;
    for(i=m; i<=n; i++)
    {
        s += i * i + 1.0 / i;
    }
    printf("sum = %.6lf", s);
    return 0;
}