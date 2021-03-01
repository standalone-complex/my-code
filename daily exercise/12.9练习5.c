#include <stdio.h>

int main()
{
    int n, x, i, t;
    int a[10] = {0};
    scanf("%d %d", &n, &x);
for(i=1; i<=n; i++)
{
    t = i;
    while(t>0)//通过取余来得到数的个位
    {
        a[t%10]++;
        t /= 10;
    }
}
printf("%d",a[x]);
    return 0;
}