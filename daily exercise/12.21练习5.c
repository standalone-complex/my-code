#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct today{
    char a[100];
    int len;
}TODAY, *PTODAY;

int main()
{
    int n, i, c;
    scanf("%d", &n);
    PTODAY p = (PTODAY)malloc(sizeof(TODAY) * n);
    for(i=0; i<n; i++)
    {
        scanf("%s", p[i].a);
        p[i].len = strlen(p[i].a);
    }
    c = p[0].len;
    for(i=1; i<n; i++)
    {
        if(c<p[i].len)
        {
            c = p[i].len;
        }
    }
    for(i=0; i<n; i++)
    {
        if(c==p[i].len)
        {
            printf("The longest is:%s", p[i].a);
            return 0;
        }
    }
    return 0;
}