#include <stdio.h>

int main()
{
    int n, x, y, c = 0;
    scanf("%d", &n);
    for(x=0; x<100; x++)
    {
        for(y=0; y<100; y++)
        {
            if(x*x+y*y==n&&x<=y)
            {
                printf("%d %d\n", x, y);
                c++;
            }
        }
    }
    if(c==0)
    {
        printf("No Solution");
    }
    return 0;
}