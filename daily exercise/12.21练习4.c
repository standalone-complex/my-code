#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, t, j;
    scanf("%d,%d", &n, &m);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        if(i!=0)
        {
            scanf(",%d", a+i);
        }
        else
        {
            scanf("%d", a+i);
        }
        
    }
    for(i=0; i<m; i++)
    {
        t = a[n-1];
        for(j=n-2; j>=0; j--)
        {
            a[j+1] = a[j];
        }
        a[0] = t;
    }
    for(i=0; i<n; i++)
    {
        if(i!=0)
        {
            printf(",%d", a[i]);
        }
        else
        {
            printf("%d", a[i]);
        }
        
    }
    return 0;
}