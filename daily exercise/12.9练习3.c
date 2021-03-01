#include <stdio.h>

int main()
{
    int n, i, j, d = 1;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i; j++)
        {
            printf("%02d", d);
            d++;
        }
        printf("\n");
    }
    return 0;
}