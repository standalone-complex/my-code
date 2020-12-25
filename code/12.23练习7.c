#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n>1600&&n<=2500)
    {
        printf("%.2f", 0.05*(n-1600));
    }
    else if(n>2500&&n<=3500)
    {
        printf("%.2f", 0.1*(n-1600));
    }
    else if (n>3500&&n<=4500)
    {
        printf("%.2f", 0.15*(n-1600));
    }
    else if(n>4500)
    {
        printf("%.2f", 0.2*(n-1600));
    }
    else
    {
        printf("0.00");
    }
    
    return 0;
}