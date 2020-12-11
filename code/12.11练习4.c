#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

typedef struct s
{
    int a;
    int b;
    int r;
    int h;
    double distance;
    double x;
    double y; 
}S, *PS;

int main()
{
    int t, i;
    scanf("%d", &t);
    PS p  = (PS)malloc(sizeof(S) * t);
    for(i=0; i<t; i++)
    {
        scanf("%d %d %d %d", &p[i].a, &p[i].b, &p[i].r, &p[i].h);
    }

    for(i=0; i<t; i++)
    {
        if(fabs(p->a-p->b)>180)
        {
            p->x = 360 - fabs(p->a-p->b);
        }
        else
        {
            p->x = fabs(p->a-p->b);
        }
        p->y = (p->x * PI / 180) * p->r;
        p->distance = p->y * p->y + p->h * p->h;
        printf("%.2lf", p->distance);
    }
/*    while (t>0)
    {
        scanf("%d %d %d %d", &a, &b, &r, &h); 
        if(fabs(a-b)>180)
        {
            x = 360 - fabs(a-b);
        }
        else
        {
            x = fabs(a-b);
        }
        y = (x * PI / 180) * r;
        distance = y * y + h * h;
        printf("%.2lf", distance);
    }
    */
    return 0;
}