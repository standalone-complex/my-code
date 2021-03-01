#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, even = 0, odd = 0;
    scanf("%d", &n);
    int* p = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        scanf("%d", p+i);
    }
    for(i=0; i<n; i++)
    {
        if(p[i]%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("%d %d", odd, even);
    return 0;
}