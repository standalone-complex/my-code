#include <stdio.h>

#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)
int main(int argc, char* argv[])
{
printf("%s\n", h(f(1,2)));
printf("%s\n", g(f2w(1,2)));
return 0;
}