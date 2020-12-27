#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int** p = (int**)malloc(sizeof(int*) * n);
    for(i=0; i<n; i++)
    {
        p[i] = (int*)malloc(sizeof(int) * 2);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<2; j++)
        {
            scanf("%d", p[i]+j);
        }
    }
    for(i=0; i<n; i++)
    {
        if(fabs((p[i][0]-100)*1.8-p[i][1])<0.1*(p[i][0]-100)*1.8)
        {
            printf("You are wan mei!\n");
        }
        else if(p[i][1]-(p[i][0]-100)*1.8>=0.1*(p[i][0]-100)*1.8)
        {
            printf("You are tai pang le!\n");
        }
        else
        {
            printf("You are tai shou le!\n");
        }
    }
}