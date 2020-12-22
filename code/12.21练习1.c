#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, t;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        if(i!=0)
        {scanf(",%d", a+i);}
        else
        scanf("%d", a+i);
    }
    for(i=1; i<n; i++)
    {
        t = a[i];
        for(j=i-1; j>=0&&a[j]<=t; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = t;
    }
    printf("%d,%d", a[0], a[1]);
    return 0;
}