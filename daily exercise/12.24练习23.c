#include <stdio.h>

int main()
{
    int hour, min, sec, add;
    scanf("%d:%d:%d%d", &hour, &min, &sec, &add);
    sec += add;
    if(sec>=60)
    {
        min++;
        if(min>=60)
        {
            hour++;
            if(hour>=24)
            {
                hour %= 24;
            }
            min %= 60;
        }
        sec %= 60;
    }
    printf("%02d:%02d:%02d", hour, min, sec);
    return 0;
}