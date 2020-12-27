#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j;
    char* p[21];
    char* t;
    for(i=0; i<21; i++)
    {
        p[i] = (char*)malloc(11);
    }
    for(i=0; i<21; i++)
    {
        scanf("%s", p[i]);
        if(p[i][0]=='#')
        {
            break;
        }
    }
    for(i=0; p[i][0]!='#'; i++)
    {
        t = p[i];
        for(j=i-1; j>=0&&strlen(p[j])>strlen(t); j--)
        {
            p[j+1] = p[j];
        }
        p[j+1] = t;
    }
    for(i=0; p[i][0]!='#'; i++)
    {
        printf("%s ", p[i]);
    }
    return 0;
}