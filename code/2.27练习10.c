#include <stdio.h>

int f(unsigned int num)//可以统计一段数据其中有多少个1
{
    unsigned int i;
    for (i = 0; num; i++) {
    num &= (num - 1);//去掉最右边的1
    }
    return i;
}

int main()
{
    printf("%d", f(2018));
    return 0;
}


