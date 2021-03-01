#include <stdio.h>

int main()
{
    int A;
    scanf("%d", &A);
    int i, j ,o, c = 0;;
    for(i=A; i<=A+3; i++)
    {
        for (j=A; j<=A+3; j++)
        {
            for(o=A; o<=A+3; o++)
            {
                if(i!=j&&i!=o&&j!=o)
                {
                    printf("%d%d%d", i, j, o);
                    c++;
                    if(c%6==0)
                    {
                        printf("\n");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
    }
    return 0;
}