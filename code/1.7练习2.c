#include <stdio.h>

int main(void)
{
    int year, i, c = 0;
    scanf("%d", &year);
    if(year<2000||year>2100)
    {
        printf("Invalid year!");
        return 0;
    }
    for(i=2001; i<=year; i++)
    {
        if ((i%4==0&&i%100!=0)||i%400==0)
        {
            printf("%d\n", i);
            c++;
        }
        
    }
    if(c==0)
    {
        printf("None");
    }
    return 0;
}