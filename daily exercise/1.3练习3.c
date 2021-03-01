#include <stdio.h>

double fact(int);

int main(void)
{
    int m, n;
    scanf("%d,%d",&m,&n);
    printf("%.0lf", fact(n)/(fact(m)*fact(n-m)));
    return 0;
}

double fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n * fact(n-1);
}