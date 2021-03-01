#include <stdio.h>
#include <stdlib.h>

typedef struct tyf{
    char code[20];
    int resite;
    int site;
}TYF, *PTYF;

int main()
{
    int n, i, m, j;
    scanf("%d", &n);
    PTYF p = (PTYF)malloc(sizeof(TYF) * n);
    for(i=0; i<n; i++)
    {
        scanf("%s %d %d", p[i].code, &p[i].resite, &p[i].site);
    }
    scanf("%d", &m);
    int* tokens = (int*)malloc(sizeof(int) * m);
    for(i=0; i<m; i++)
    {
        scanf("%d", tokens+i);
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(tokens[i]==p[j].resite)
            break;
        }
        printf("%s %d\n", p[j].code, p[j].site);
    }
    return 0;
}