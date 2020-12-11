#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, max, min, s;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }
    min = a[0];
    max = a[0];
    s = a[0];
    for(i=1; i<n; i++)
    {
        if (max<a[i])
        {
            max = a[i];
        }
        if (min>a[i])
        {
            min = a[i];
        }
        s  += a[i];
    }
    s = s - min - max;
    //printf("%d %d %d", s, min, max);
    printf("%.2f", s * 1.0 / (n-2));
    return 0;
}