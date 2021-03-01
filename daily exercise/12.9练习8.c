#include <stdio.h>

int main()
{
    int l, s = 0, c = 0, i = 2, j;
    scanf("%d", &l);
    while(s<=l)
    {   
        for(j=2; j<i; j++)
        {
            if(i%j==0)
            {
                break;
            }
        }
        if(i==j)
        {
            if(s+i<=l)
            {
                printf("%d\n", i);
                c++;
                s += i;
            }
            else
            {
                break;
            }
            
        }
        i++;
    }
    printf("%d", c);
    return 0;
}




