#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[81] = {0};
    int b[26] = {0};
    gets(a);
    int i, len, c = 0;
    len = strlen(a);
    for(i=0; i<len; i++)
    {
        if(a[i]>='A'&&a[i]<='Z'&&b[a[i]-65]==0)
        {
            printf("%c", a[i]);
            b[a[i]-65]++;
            c++;
        }
    }
    if(c==0)
    {
        printf("Not Found");
    }
    return 0;
}