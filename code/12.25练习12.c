#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    double max, min, average;
    scanf("%d", &n);
    double* p = (double*)malloc(n * sizeof(double));
    for(i=0; i<n; i++)
    {
        scanf("%lf", p+i);
    }
    max = p[0];
    min = p[0];
    average = p[0];
    for(i=1; i<n; i++)
    {
        average += p[i];
        if(max<p[i])
        {
            max = p[i];
        }
        if(min>p[i])
        {
            min = p[i];
        }
    }
    printf("average = %.2lf\nmax = %.2lf\nmin = %.2lf", average/n, max, min);
    return 0;
}