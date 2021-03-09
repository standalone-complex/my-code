#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    int i = 0;
    while(argv[0][i]!='\0')
    {
        printf("%c", argv[0][i]);
        i++;
    }
    printf("\n");
    printf("%d %ld\n", i, strlen(argv[0]));
    //打印了39个字符，说明argv是自带`\0`的
    return 0;
}