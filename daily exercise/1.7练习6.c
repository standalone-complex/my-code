#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, n;
    scanf("%d", &n);
    int* p = (int*)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d", p+i);
    }
    for(i=1; i<n; i++)
    {
        printf("%d", p[i]-p[i-1]);
        if(i!=n-1)
        {
            if(i%3==0)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
    return 0;  
}