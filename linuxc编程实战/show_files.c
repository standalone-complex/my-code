#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_readdir(const char*);

int main(int argc, char * argv[])
{
    if(argc < 2)//检查输入参数
    {
        printf("listfile <target path>\n");
        exit(-1);
    }

    if(my_readdir(argv[1]) == -1)
    {
        exit(-1);
    }
    
    return 0;
}

int my_readdir(const char* pathname)
{
    DIR* dir;
    struct dirent* ptr;

    if((dir = opendir(pathname)) == NULL)//获得目录流
    {
        perror("opendir");
        return -1;
    }

    while((ptr = readdir(dir)) != NULL)
    {
        printf("filename : %s\n", ptr->d_name);
    }

    closedir(dir);
    return 0;
}