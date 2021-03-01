#include <stdio.h>
#include <stdlib.h>

void fun(int*, int, int);

int main(void)
{
    int l, m, u, v, i, s = 0;
    scanf("%d %d", &l, &m);
    int* p = (int*)malloc(sizeof(int)*(l+1));
    for(i=0; i<=l; i++)
    {
        p[i] = 1;
    }
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &u, &v);
        fun(p, u, v);
    }
    for(i=0; i<=l; i++)
    {
        if(p[i]==1)
        {
            s++;
        }
    }
    printf("%d", s);
    return 0;
}

void fun(int*p, int u, int v)
{
    int i;
    for(i=u; i<=v; i++)
    {
        p[i] = 0;
    }
    return;
}