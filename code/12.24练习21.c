#include <stdio.h>
#include <stdlib.h>

typedef struct tyf{
    char code[6];
    char name[11];
    int score;
}TYF, *PTYF;

int main()
{
    int n, i;
    double average = 0;
    scanf("%d", &n);
    PTYF p = (PTYF)malloc(sizeof(TYF) * n);
    for(i=0; i<n; i++)
    {
        scanf("%s %s %d", p[i].code, p[i].name, &p[i].score);
    }
    for(i=0; i<n; i++)
    {
        average += p[i].score;
    }
    average /= n;
    printf("%.2lf\n", average);
    for(i=0; i<n; i++)
    {
        if(p[i].score<average)
        {
            printf("%s %s\n", p[i].name, p[i].code);
        }
    }
    return 0;
}