#include <stdio.h>

int main()
{
    int i = 0;
    while(1)
    {
        if(i%5==1&&i%6==5&&i%7==4&&i%11==10)
        {
            printf("%d", i);
            break;
        }
        i++;
    }
    return 0;
}