#include <stdio.h>

int main()
{
    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);
    int a[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int b[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    if((year%4==0&&year%100!=0)||(year%400==0))
    {
        printf("%d", b[month-1] + day);
    }
    else
    {
        printf("%d", a[month-1] + day);
    }
    
    return 0;//
}