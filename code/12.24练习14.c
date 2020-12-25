#include <stdio.h>
#include <stdlib.h>

void swap(int*, int, int);

int main()
{
    int n, i;
    int token = 0;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }
    for(i=1; i<n; i++)
    {
        if(a[i]<a[token])
        {
            token = i;
        }
    }
    swap(a, 0, token);
    token = 0;
    for(i=1; i<n; i++)
    {
        if(a[i]>a[token])
        {
            token = i;
        }
    }
    swap(a, n-1, token);
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void swap(int* a, int n, int m)
{
    int t;
    t = a[n];
    a[n] = a[m];
    a[m] = t;
    return;
}