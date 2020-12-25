#include <stdio.h>

int main()
{
    int five = 1, two = 1, one;
    int i, j, t = 0;
    int c;
    scanf("%d", &c);
    for(i=five; i<30; i++)
    {
        for(j=two; j<75; j++)
        {
            one = 100 - i - j;
            if(i*5+j*2+one==150)
            {
                printf("%d %d %d\n", i, j, one);
                t++;
                if(t==c)
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}