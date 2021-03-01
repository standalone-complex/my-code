#include <stdio.h>
#include <stdbool.h>

bool prime(int);

int main()
{
    int a[10];
    int i, j, t, c = 0;
    for(i=0; i<10; i++)
    {
        if(i!=0)
        {
            scanf(",%d", a+i);
            //c++;
        }
        else
        {
            scanf("%d", a+i);
            //c++;
        }
        
    }
    for(i=1; i<10; i++)
    {
        t = a[i];
        for(j=i-1; j>=0&&a[j]>=t; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = t;
    }
    for(i=0; i<10; i++)
    {
        if(c!=0)
        {
            if(prime(a[i]))
            {
                printf(",%d", a[i]);
                c++;
            }
        }
        else
        {
            if(prime(a[i]))
            {
                printf("%d", a[i]);
                c++;
            }
        }
        
    }
    if(c==0)
    {
        printf("Not found!");
    }
    return 0;
}

bool prime(int n)
{
    int i;
    for(i=2; i<n; i++)
    {
        if(n%i==0)
        {
            break;
        }
    }
    if(i==n)
    {
        return true;
    }
    return false;
}