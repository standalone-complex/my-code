#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, token = 0;
    scanf("%d", &n);
    int* p = (int*)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d", p+i);
    }
    for(i=1; i<n; i++)
    {
        if(p[i]>p[token])
        {
            token = i;
        }
    }
    printf("%d %d", p[token], token);
    return 0;
}