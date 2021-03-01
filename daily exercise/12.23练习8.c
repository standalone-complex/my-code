#include <stdio.h>

int main()
{
    int n, t, s = 0;
    scanf("%d", &n);
    t = n;
    while(t>0)
    {
        s = s * 10 + t % 10;
        t /= 10;
    }
    if(s==n)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    
    return 0; // return
}