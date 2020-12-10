#include <stdio.h>

int main()
{
    int K, c = 0, d = 2, s = 1, i;
    scanf("%d", &K);
    for(i=0; i<K-1; i++)
    {
        s += d;
        c++;
        if(c==d)
        {
            c = 0;
            d++; 
        }

    }
    printf("%d", s);
    return 0;
}