#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    long long s = 0; 
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        s += pow(2,i+1);
    }
    printf("result = %lld", s);
    return 0;
}