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
    int** p = (int**)malloc(sizeof(int*) * n);
    for(i=0; i<n; i++)
    {
        p[i] = (int*)malloc(sizeof(int) * (i+1));
    }
    for(i=0; i<n; i++)
    {
        p[i][0] = 1;
        p[i][i] = 1;
    }
    for(i=2; i<n; i++)
    {
        for(j=1; j<i; j++)
        {
            p[i][j] = p[i-1][j-1] + p[i-1][j]; 
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            printf(" ");
        }
        for(j=0; j<=i; j++)
        {
            printf("%4d", p[i][j]);
        }
        printf("\n");
    }
}