#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    scanf("%lf", &x);
    if(x>=0)
    {
        printf("f(%.2lf) = %.2lf", x, sqrt(x));
    }
    else
    {
        printf("f(%.2lf) = %.2lf", x, (x+1)*(x+1)+2*x+1/x);
    }
    return 0;
}