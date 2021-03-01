#include <stdio.h>

int main()
{
    int hour, sec;
    scanf("%d:%d", &hour, &sec);
    if(hour>11)
    {
        if(hour==12)
        {
            printf("12:%d PM", sec);
        }
        else
        {
            hour %= 12;
            printf("%d:%d PM", hour, sec);
        }
    }
    else
    {
        printf("%d:%d AM", hour, sec);
    }
    return 0;
}