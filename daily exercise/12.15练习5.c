#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }
    for(i=0; i<n; i++)
    {
        if(a[i]==1)
        {
            printf("No");
        }
        else
        {
            for(j=2; j<=sqrt(a[i]); j++)
            {
                if(a[i]%j==0)
                {
                    break;
                }
            }
            if(j>sqrt(a[i]))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        
        
    }
    return 0;
}