#include <stdio.h>

int main()
{
    int n, i = 0, t;
    int p[10000];
    
    scanf("%d", &n);
    t = n;
    do{
        if(n%2!=0)
        {
            n = n * 3 + 1;
            p[i] = n;
            i++;
        }
        else
        {
            n /= 2;
            p[i] = n;
            i++;
        }
        
    }while(n!=1);
    
    if(t==1)
    {
        printf("1");
    }
    else
    {
        while(i-1>=0)
        {
            printf("%d ", p[i-1]);
            i--;
        }
        printf("%d", t);
    }
    return 0;
}