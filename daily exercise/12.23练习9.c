#include <stdio.h>

int main()
{
    int year, mouth;
    scanf("%d, %d", &year, &mouth);
    if(mouth==1||mouth==3||mouth==5||mouth==7||mouth==8||mouth==10||mouth==12)
    {
        printf("31");
    }
    else
    {
        if(mouth==2)
        {
            if((year%4==0&&year%100!=0)||year%400==0)
            {
                printf("29");
            }
            else
            {
                printf("28");
            }
        }
        else
        {
            printf("30");
        }
        
    }
    
    return 0;//
}