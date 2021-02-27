#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[6];
    printf("%p\n", a);
    printf("%p\n", a+1);//偏移4个字节
    printf("%p\n", &a);
    printf("%p\n", &a+1);//偏移20个字节
    return 0;
}