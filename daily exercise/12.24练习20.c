#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int** p = (int**)malloc(sizeof(int*) * n);
    for(i=0; i<n; i++)
    {
        p[i] = (int*)malloc(sizeof(int) * n);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            p[i][j] = j * n + i + 1;
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%4d", p[i][j]);
            if(j==n-1)
            {
                printf("\n");
            }
        }
    }
    return 0;  
}