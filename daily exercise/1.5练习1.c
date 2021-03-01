#include <stdio.h>
//#include <stdlib.h>

int main()
{
    FILE* fp = fopen("/home/tyf/tesst", "r");
    char* str = NULL;
    size_t len = 0;
    ssize_t read;
    while((read = getline(&str, &len, fp)) != -1)
    {
        printf("%zu\n", read);
        printf("%s", str);
    }
    printf("%s", str);
    return 0;
}