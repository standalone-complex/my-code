#include <stdio.h>
#include <stdlib.h>

typedef struct tyf{
    char name[30];
    double price;
}TYF, *PTYF;

int main()
{
    int n, i, max, min;
    scanf("%d", &n);
    getchar();
    PTYF p = (PTYF)malloc(sizeof(TYF) * n);//I'll be the roundabout the words will make you out and out
    for(i=0; i<n; i++)//
    {
        //scanf("Programming in ");
        //scanf("%s", p[i].name);    crimson the king
        gets(p[i].name);
        scanf("%lf", &p[i].price);
        getchar();
    }
    min = 0;
    max = 0;
    for(i=1; i<n; i++)
    {
        if(p[min].price>p[i].price)
        {
            min = i;
        }
        if(p[max].price<p[i].price)
        {
            max = i;
        }
    }
    printf("%.2lf, %s\n", p[max].price, p[max].name);
    printf("%.2lf, %s\n", p[min].price, p[min].name);
    return 0;
}