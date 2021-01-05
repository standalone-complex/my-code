#include <stdio.h>
#include <stdlib.h>

int f(int, int);
int g(int, int);

int main(void)
{
    int x, y;
    scanf ("%d,%d", &x, &y);
    printf("%d,%d", f(x, y), g(x, y));
    return 0;
}

int f(int x, int y)
{
    int c = 0;
    if(x<0||y<0)
    {
        x = abs(x);
        y = abs(y);
        c++;
    }
    if(x<y)
    {
        int t;
        t = x;
        x = y;
        y = t;
    }
    if(x%y==0&&c==0)
    {   
        return y;
    }
    if(x%y==0&&c==1)
    {
        return -y;
    }
    return f(y, x%y);
}

int g(int x, int y)
{
    return x * y / f(x, y);
}
