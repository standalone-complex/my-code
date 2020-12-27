#include <stdio.h>

int main()
{
    int year, time;
    double salary;
    scanf("%d %d", &year, &time);
    if(year>=5)
    {
        if(time>40)
        {
            salary = 50 * 40 + (time-40) * 1.5 * 50;
        }
        else
        {
            salary =50 * time;
        }
    }
    else
    {
        if(time>40)
        {
            salary = 30 * 40 + (time-40) * 1.5 * 30;
        }
        else
        {
            salary = 30 * time;
        }
    }
    printf("%.2lf", salary);
    return 0;
}