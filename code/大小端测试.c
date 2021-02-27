#include <stdio.h>

int main()
{
    short int x;
    char x0, x1;
    x = 0x1122;//11高字节，22低字节
    x0 = ((char*)&x)[0];//低地址
    x1 = ((char*)&x)[1];//高地址
    printf("%#x", x0);
    //这个电脑是小端，
    return 0;
}