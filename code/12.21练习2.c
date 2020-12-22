#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        if(i!=0)
            scanf(",%d", a+i);
        else
            scanf("%d", a+i);
        
    }
    for(i=n-1; i>=0; i--)
    {
        if(i!=n-1)
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