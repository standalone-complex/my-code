#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int t, i, j, k, n, c = 0;
    scanf("%d %d", &n, &k);
    int* p = (int*)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d", p+i);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(p[j]>p[j+1])
            {
                t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
        c++;
        if(k==c)
        {
            break;
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d", p[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    return 0;
}