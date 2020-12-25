#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, i, j, s;
    scanf("%d %d", &m, &n);
    int** a = (int**)malloc(sizeof(int*) * m);
    for(i=0; i<m; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * n);
    }
    for(i=0 ;i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", a[i]+j);
        }
    }
    for(i=0; i<m; i++)
    {
        s = 0;
        for(j=0; j<n; j++)
        {
            s += a[i][j];
        }
        printf("%d\n", s);
    }
    return 0;
}