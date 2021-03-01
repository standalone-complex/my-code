#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i;
    int a, b, c, d, e, f;
    scanf("%d", &n);
    int* p = (int*)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d", p+i);
    }
    for(i=0; i<n; i++)
    {
        a = p[i]/100000;
        b = (p[i]/10000)%10;
        c = (p[i]/1000)%10;
        d = (p[i]/100)%10;
        e = (p[i]/10)%10;
        f = p[i]%10;
        if(a+b+c==d+e+f)
        {
            printf("You are lucky!\n");
        }
        else
        {
            printf("Wish you good luck.\n");
        }
    }
    return 0;
}