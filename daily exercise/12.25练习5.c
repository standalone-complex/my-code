#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, count = 0;;
    double average = 0;

    scanf("%d", &n);
    if(n==0)
    {
        printf("average = 0.0\ncount = 0");
        return 0;
    }
    int* p = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        scanf("%d", p+i);
    }
    for(i=0; i<n; i++)
    {
        average += p[i];
        if(p[i]>=60)
        {
            count++;
        }
    }
    printf("average = %.1lf\ncount = %d", average/n, count);
    return 0;
}