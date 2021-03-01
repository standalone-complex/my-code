#include <stdio.h>
#include <stdlib.h>

typedef struct tyf{
    char name[10];
    int birth;
    char phone[20];
}TYF, *PTYF;

int main()
{
    int n, i, j;
    TYF t;
    scanf("%d", &n);
    PTYF p = (PTYF)malloc(sizeof(TYF) * n);
    for(i=0; i<n; i++)
    {
        scanf("%s %d %s", p[i].name, &p[i].birth, p[i].phone);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(p[j].birth>p[j+1].birth)
            {
                t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%s %d %s\n", p[i].name, p[i].birth, p[i].phone);
    }
    return 0;
}