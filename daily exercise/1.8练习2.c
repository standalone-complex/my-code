#include <stdio.h>

int main(void)
{
    int p[6];
    int i;
    for(i=0; i<6; i++)
    {
        scanf("%d", p+i);
    }
    printf("--2--4--6--8--10\n--10--8--6--4--2");
    return 0;
}