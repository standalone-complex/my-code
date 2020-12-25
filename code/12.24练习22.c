#include <stdio.h>
#include <stdlib.h>

typedef struct tyf{
    char name[11];
    float base;
    float flow;
    float out;
}TYF, *PTYF;

int main()
{
    int n, i;
    scanf("%d", &n);
    PTYF p = (PTYF)malloc(sizeof(TYF) * n);
    for(i=0; i<n; i++)
    {
        scanf("%s %f %f %f", p[i].name, &p[i].base, &p[i].flow, &p[i].out);
    }
    for(i=0; i<n; i++)
    {
        printf("%s %.2f\n", p[i].name, p[i].base+p[i].flow-p[i].out);
    }
    return 0;
}