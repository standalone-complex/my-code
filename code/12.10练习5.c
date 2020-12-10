#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, c = 0, cc = 0;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }
    for(i=0; i<n-1; i++)
    {
        if(a[i+1]-a[i]==1)
        {
            c++;
            if(c>cc)
            {
                cc = c;
            }
        }
        else
        {
            c = 0;
        }
    }
    printf("%d", cc);
    return 0;
}