#include <stdio.h>

int main()
{
    int i, j, n, x, k, s = 0;
    scanf("%d", &n);
    x = n/364 - 3;
    k = 1;
    if(x>100)
    {
        while(1)
        {
            for(x=100; x>0; x--)
            {
                if(1092 * k + 364 * x == n)
                {
                    printf("%d\n%d", x, k);
                    return 0;
                }
            }
            k++;
        }
    }
    printf("%d\n%d", x, k);
    return 0;
}