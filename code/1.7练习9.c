#include <stdio.h>
#include <stdlib.h>

typedef struct tyf{
    char code[10];
    char name[15];
    int score1;
    int score2;
    int score3;
}TYF, *PTYF;

int main(void)
{   
    int n, i, token = 0;
    scanf("%d", &n);
    PTYF p = (PTYF)malloc(sizeof(TYF) * n);
    for(i=0; i<n; i++)
    {
        scanf ("%s %s %d %d %d", p[i].code, p[i].name, &p[i].score1, &p[i].score2, &p[i].score3);
    }
    for(i=1; i<n; i++)
    {
        if(p[i].score1+p[i].score2+p[i].score3>p[token].score1+p[token].score2+p[token].score3)
        {
            token = i;
        }
    }
    printf("%s %s %d", p[token].name, p[token].code, p[token].score1+p[token].score2+p[token].score3);
    return 0;
}