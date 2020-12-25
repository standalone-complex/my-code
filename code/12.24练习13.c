#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x, i;
    scanf("%d %d", &n, &x);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }
    for(i=0; i<n; i++)
    {
        if(x==a[i])
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("Not Found");
    return 0;  
}