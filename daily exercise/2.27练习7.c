#include <stdio.h>
# include <string.h>

void func(char* a)
{
printf("%lu\n", sizeof(a)) ;//这里的a退化为一个指针
printf("%lu\n", strlen(a)) ;
}
int main(int argc, char* argv[])
{
char a[] = "hello world";
char* b = "hello world";
printf("%s\n", b);
func(a);
printf("%lu\n", sizeof(a));//多计入一个\0
printf("%lu\n", strlen(a));
return 0;
}
