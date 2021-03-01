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
        if(fabs(p[i].a-p[i].b)>180)
        {
            p[i].x = 360 - fabs(p[i].a-p[i].b);
        }
        else
        {
            p[i].x = fabs(p[i].a-p[i].b);
        }
        p[i].y = (p[i].x * PI / 180) * p[i].r;
        p[i].distance = p[i].y * p[i].y + p[i].h * p[i].h;
        printf("%.2lf", p[i].distance);
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