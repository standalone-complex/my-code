#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, i;
    scanf("%d", &t);
    int* a = (int*)malloc(sizeof(int) * t);
    for(i=0; i<t; i++)
    {
        scanf("%d", a+i);
    }    
    for(i=0; i<t; i++)
    {
        a[i] %= 5;
        if(a[i]==1||a[i]==3||a[i]==4)
        {
            printf("Pig\n");
        }
        else
        {
            printf("Cow\n");
        }
    }
    return 0;
}