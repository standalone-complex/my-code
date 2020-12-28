#include <stdio.h>
#include <stdlib.h>

typedef struct tyf{
    char code[20];
    char name[20];
    int score1;
    int score2;
    int score3;
}TYF, *PTYF;

int main()
{
    int n, i, token;
    scanf("%d", &n);
    PTYF p = (PTYF)malloc(sizeof(TYF) * n);
    for(i=0; i<n; i++)
    {
        //scanf("%s", p[i].code);
        //scanf("%s", p[i].name);
        //gets(p[i].code);
        //gets(p[i].name);
        scanf("%s %s %d %d %d", p[i].code, p[i].name, &p[i].score1, &p[i].score2, &p[i].score3);
    }
    token = 0;
    for(i=1; i<n; i++)
    {
        if(p[token].score1+p[token].score2+p[token].score3<p[i].score1+p[i].score2+p[i].score3)
        {
            token = i;
        }
        //printf("%s %s %d %d %d\n", p[i].code, p[i].name, p[i].score1, p[i].score2, p[i].score3);
    }
    printf("%s %s %d", p[token].name, p[token].code, p[token].score1+p[token].score2+p[token].score3);
    return 0;
}