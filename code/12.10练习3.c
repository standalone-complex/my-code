#include <stdio.h>

int f(int);

int main()
{
    int n;
    printf("%d", f(n));
    return 0;
}

int f(int n)
{
    if(n==1||n==2)
    return 1;
    return f(n-1) + f(n-2);
}
