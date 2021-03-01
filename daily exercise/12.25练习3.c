#include <stdio.h>

int main()
{
    int n, c = 0, cc = 0;
    while(scanf("%d",&n)!=EOF)
    {
        c++;
        if(n==250&&cc==0)
        {
            cc = c;
        }
    }
    printf("%d", cc);
    return 0;
}