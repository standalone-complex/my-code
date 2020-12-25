#include <stdio.h>

int main()
{
    int n, c = 0, s = 0;
    scanf("%d", &n);
    while(n>0)
    {
        s += n % 10;
        c++;
        n /= 10;
    }
    printf("%d %d", c, s);
    return 0;
}