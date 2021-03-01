#include <stdio.h>

int main()
{
    int day = 0;
    double a;
    scanf("%lf", &a);
    while(a>=1)
    {
        a /= 2;
        day++;
    }
    printf("%d", day);
    return 0;
}