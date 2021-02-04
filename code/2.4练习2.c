#include <stdio.h>
#include <stdlib.h>

typedef struct tyf{
    int ch;
    int ma;
    int en;
}TYF, *PTYF;

int main(void)
{
    int N, i, j, s = 0;
    scanf("%d", &N);
    PTYF p = (PTYF)malloc(sizeof(TYF) * N);
    for(i=0; i<N; i++)
    {
        scanf("%d %d %d", &p[i].ch, &p[i].ma, &p[i].en);
    }
    //for(i=1; i<N; i++)
    //{
    //    if(abs(p[0].ch+p[0].ma+p[0].en-(p[i].ch+p[i].ma+p[i].en))<=10&&abs(p[0].ch-p[i].ch)<=5&&abs(p[0].en-p[i].en)<=5&&abs(p[0].ma-p[i].ma)<=5)
    //    {
    //        s++;
    //    }
    //}
    for(i=0; i<N; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(abs(p[i].ch+p[i].ma+p[i].en-(p[j].ch+p[j].ma+p[j].en))<=10&&abs(p[i].ch-p[j].ch)<=5&&abs(p[i].en-p[j].en)<=5&&abs(p[i].ma-p[j].ma)<=5)
            {
                s++;
            }
        }
    }
    printf("%d", s);
    return 0;
}