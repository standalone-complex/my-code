#include <stdio.h>
#include <stdlib.h>

void yanghui(int);

int main()
{
    int n;
    scanf("%d", &n);
    yanghui(n);
    return 0;
}

void yanghui(int n)
{
    int i, j;
    int** a = (int**)malloc(sizeof(int*) * n);
    for(i=0; i<n; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * (i + 1));
    }
    for(i=0; i<n; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for(i=2; i<n; i++)
    {
        for(j=1; j<i ; j++)
        {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<i+1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}