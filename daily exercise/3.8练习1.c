/*
    程序目的：读取输入的参数，实现文件或是目录的遍历
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int display_dir(const char *);
int display(const char *);

int main(int argc, char * argv[])
{
    struct stat buf;

    if(argc < 2)
    {
        printf("输入格式有误\n");
        exit(-1);
    }

    if(stat(argv[1],&buf) == -1)
    {
        perror("stat");
        exit(-1);
    }

    if(S_ISDIR(buf.st_mode))
    {
        if(display_dir(argv[1]) == -1)
        {
            perror("display_dir");
            exit(-1);
        }
    }
    else
    {
        if(display(argv[1]) == -1)
        {
            perror("display");
            exit(-1);
        }
    }
    return 0;
}

int display_dir(const char * pathname)
{
    DIR* dir;
    struct dirent* ptr; //dirent是目录项的意思
    if((dir = opendir(pathname)) == NULL)//打开目录流
    {
        perror("opendir");
        return -1;
    }
    while((ptr = readdir(dir)) != NULL)
    {
        printf("%ld %ld %d %c %s\n", ptr->d_ino, ptr->d_off, ptr->d_reclen, ptr->d_type, ptr->d_name);
    }
    closedir(dir);
    return 0;
}

int display(const char * pathname)
{
    //用lstat读
    struct stat buf;
    if((lstat(pathname, &buf)) == -1)
    {
        perror("lstat");
        return -1;
    }
    printf("%ld %ld %d %ld %d %d %ld %ld %ld %ld\n", buf.st_dev, buf.st_ino, buf.st_mode, buf.st_nlink, buf.st_uid, buf.st_gid, buf.st_rdev, buf.st_size, buf.st_blksize, buf.st_blocks);
    return 0;
}

