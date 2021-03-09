#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void my_err(const char*, int);
int my_read(int);

int main(int argc, char * argv[])
{
    int fd;
    char write_buf[32] = "Hello World!\n";

    if((fd = open("example_63.md", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU)) == -1)//打开文件,注意要带括号，不然会很奇怪
    //if((fd = creat("example_63.md", S_IRWXU)) == -1)//使用creat会报错的原因是create函数返回一个只写的文件描述符，没办法read
    {
        my_err("open", __LINE__);
    }
    else
    {
        printf("create file success!\n");
    }

    if(write(fd, write_buf, strlen(write_buf)) != strlen(write_buf))//把helloworld输入到文件中
    {
        my_err("write", __LINE__);
    }

    //printf("芜湖\n");
    my_read(fd);//输出文件内容
    //printf("好耶\n");
    if(lseek(fd, 10, SEEK_END) == -1)//把文件指针定在文件最后再向后偏移10个字节
    {
        my_err("lseek", __LINE__);
    }
    if(write(fd, write_buf, strlen(write_buf)) != strlen(write_buf))//再写入一个helloworld
    {
        my_err("write", __LINE__);
    }
    //printf("啊这\n");
    my_read(fd);//输出文件内容
    close(fd);//结束
    return 0;
}

void my_err(const char* pathname, int line)
{
    fprintf(stderr, "line:%d\n", line);
    perror(pathname);
    exit(-1);
}

int my_read(int fd)//读取文件内容的函数，所以参数只需要文件的文件描述符
{
    //读取文件中数据的流程，将文件中的数据以一种数据结构存储在内存中，然后将内存中的数据输出
    //需要的参数有
    int len;//文件数据的字节数
    int ret;//实际读取到数据的字节数
    int i;//循环变量
    char read_buf[64];//缓冲区
    //获得文件长度的方法为，使用lseek函数，将文件指针定位到文件末尾，因为lseek的返回值是当前指针位置对于文件开始处的字节数
    if(lseek(fd, 0, SEEK_END) == -1)
    {
        my_err("lseek", __LINE__);
    }
    if((len=lseek(fd, 0, SEEK_CUR)) == -1)//不要忘记括号
    {
        my_err("lseek", __LINE__);
    }
    //因为要读数据，所以再把文件指针定位到文件开头
    if(lseek(fd, 0, SEEK_SET) == -1)
    {
        my_err("lseek", __LINE__);
    }
    printf("line:%d\n", len);
    if((ret=read(fd, read_buf, len)) < 0)
    {
        my_err("read", __LINE__);
    }

    for(i=0; i<len; i++)
    {
        printf("%c", read_buf[i]);
    }
    printf("\n");
    return ret;
}

