#include <stdio.h>

int main()
{
    int p;
    int i;
    while(scanf("%d", &p)!=EOF&&p!=-1)
    {
        printf("--%d", p);
    }
    return 0;
}