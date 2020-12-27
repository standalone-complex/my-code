#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j;
    char p[10000];
    //char* p = (char**)malloc(n*sizeof(char*));
    char* a[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    scanf("%d", &n);    
    for(i=0; i<n; i++)
    {
        scanf("%s", p);
        for(j=0; j<7; j++)
        {
            if(!strcmp(a[j], p))
            {
                printf("%d\n", j+1);
                break;
            }
        }
        if(j==7)
            printf("-1");
    }
    /*
    for(i=0; i<n; i++)
    {
        if(!strcmp(p[i],a[0]))
        {
            printf("0");
            return 0;
        }
        if(!strcmp(p[i],a[1]))
        {
            printf("1");
            return 0;
        }
        if(!strcmp(p[i],a[2]))
        {
            printf("2");
            return 0;
        }
        if(!strcmp(p[i],a[3]))
        {
            printf("3");
            return 0;
        }
        if(!strcmp(p[i],a[4]))
        {
            printf("4");
            return 0;
        }
        if(!strcmp(p[i],a[5]))
        {
            printf("5");
            return 0;
        }
        if(!strcmp(p[i],a[6]))
        {
            printf("6");
            return 0;
        }
        printf("-1");
    }
    */
    return 0;
}