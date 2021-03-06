#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <limits.h>

void my_error(const char*, int);
void display(const char*, int);
void display_dir(const char*, int);
void display_dir_recurrence(const char*, int);
void display_single(const char*);
void display_attribute(struct stat, const char*);
int transform(const char*);
int my_cmp(const void*, const void*);
char* name(const char*);

#define MAXROWLEN 80
#define NONE 0
#define A 1
#define L 2
#define R 4

int g_leave_len = MAXROWLEN;
int g_maxlen;

//那必然先写主函数
int main(int argc, char * argv[])
{
    //先对输入的数据进行处理
    int i, j, k;//循环变量
    int num = 0;//判断输入了几个'-'，用于判断命令行输入字符串数量，可以判断出是否输入路径，若无输入路径默认按当前目录遍历
    int flag_param = NONE;//需要输入函数来判断的变量
    char param[32];//存参数的字符串
    //char pathname[64];//存路径的字符串 真的需要吗？
    struct stat buf;//存目录文件数据的缓冲区
    //解析命令行
    k = 0;
    for(i=1; i<argc; i++)
    {
        //如果是参数
        if(argv[i][0]=='-')
        {
            for(j=1; j<strlen(argv[i]); j++, k++)
            {   
                param[k] = argv[i][j];
            }
            num++;
        }
    }
    param[k] = '\0';
    //把解析好的参数转化为宏定义的整形
    flag_param = transform(param);
    //如果命令行没有输入路径，默认路径为当前目录直接遍历
    if((num + 1) == argc)
    {
        //如果没R
        if((flag_param & R) == 0)//这里要注意宏展开的问题，记得带上括号
            {
                display_dir("./", flag_param);
            }
            //如果有R
            else
            {
                //把R位置0
                flag_param -= R;
                display_dir_recurrence("./", flag_param);
            }
        return 0;
    }
    //开始遍历命令行，把符合条件的路径和参数输入遍历函数
    for(i=1; i<argc; i++)
    {
        //跳过参数项
        if(argv[i][0] == '-')
        {
            continue;
        }
        //判断路径合法性
        if(stat(argv[i], &buf) == -1)
        {
            my_error("stat", __LINE__);
        }
        //如果是目录
        if(S_ISDIR(buf.st_mode))
        {
            //判断路径名带不带`/`，不带就加上
            if(argv[i][strlen(argv[i])-1]!= '/')
            {
                argv[i][strlen(argv[i])] = '/';
                argv[i][strlen(argv[i])+1] = '\0';
            }
            //在这里做个判断，如果有R就跑另一个函数
            if(flag_param&R==0)
            {
                display_dir(argv[i], flag_param);
            }
            else
            {
                //把R位置0
                flag_param &= R;
                display_dir_recurrence(argv[i], flag_param);
            }
        }
        //如果是文件
        else
        {
            display(argv[i], flag_param);
        }
    }
    //结束
    return 0;
}

int my_cmp(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

void my_error(const char* err_string, int line)
{
    fprintf(stderr, "line:%d\n", line);
    perror("err_string");
    exit(-1);
}

int transform(const char* flag_c)
{
    int i;
    int flag_d = 0;
    for(i=0;i<strlen(flag_c);i++)
    {
        switch (flag_c[i])
        {
            case 'a':
            {
                flag_d |= A;
                break;
            }
            case 'l':
            {
                flag_d |= L;//芜湖，位运算！
                break;
            }
            case 'R':
            {
                flag_d |= R;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return flag_d;
}

void display_dir(const char * pathname, int flag)
{
    int i, j;//循环变量
    int len = strlen(pathname);//获取路径长度，待会连接路径用
    int count;//统计目录下有多少文件，排序用，调用display函数也用
    //二维数组，其实就是256个字符串
    char filename[256][PATH_MAX+1], temp[PATH_MAX+1];//加一难道是为了加\0吗
    DIR* dir;
    struct dirent* ptr;
    if((dir = opendir(pathname)) == NULL)
    {
        my_error("opendir", __LINE__);
    }
    //这个循环有两个作用，获得目录下文件名最大字节长度，统计目录下有文件的数量，方便排序
    while((ptr = readdir(dir)) != NULL)
    {
        //先获得数量，然后排序，再输出
        if(g_maxlen<strlen(ptr->d_name))
        {
            g_maxlen = strlen(ptr->d_name);
        }
        count++;
    }
    closedir(dir);
    //判断文件数量是否超限
    if(count>256)
    {
        my_error("too many files under this dir", __LINE__);
    }
    //再次打开目录流
    if((dir = opendir(pathname)) == NULL)
    {
        my_error("opendir", __LINE__);
    }
    //然后将数据存储到字符串中，进行排序，排序完成后遍历调用display函数
    for(i=0; i<count; i++)
    {
        if((ptr = readdir(dir)) == NULL)
        {
            my_error("readdir", __LINE__);
        }
        //接下来先把路径放入字符串中,用strncpy比较安全
        strncpy(filename[i], pathname, len);
        filename[i][len] = '\0';
        //然后字符串连接,使用strcat;
        strcat(filename[i], ptr->d_name);
        //再加个\0
        filename[i][len+strlen(ptr->d_name)] = '\0';
        //好了
    }
    //排个序
    qsort(filename, count, PATH_MAX+1, my_cmp);
    //好了，可以整了
    for(i=0; i<count; i++)
    {
        display(filename[i], flag);
    }
    //其实这个closedir在可以放到上面那个循环之前
    closedir(dir);

    //按位与 如果没有-l参数，打印换行符
    //为啥？？？
    if((flag & L) == 0)
    {
        printf("\n");
    }
    return;
}

void display(const char* pathname, int flag)//基本单位
{
    //对了，发来的是路径，得先获得文件名
    //从pathname中获得，使用lstat函数
    //struct stat* buf;
    struct stat buf;//不能像上面那样写，不然内存会因为函数的结束被释放掉
    char* name_1 = name(pathname);//解析文件名函数
    if(lstat(pathname, &buf) == -1)
    {
        my_error("lstat", __LINE__);
    }
    switch (flag)
    {
        case NONE:
        {
            if(name_1[0] != '.')
            {
                display_single(name_1);
            }
            break;
        }
        case A:
        {
            display_single(name_1);
            break;
        }
        case L:
        {
            if(name_1[0] != '.')
            {
                display_attribute(buf, name_1);
                printf("%s\n", name_1);
            }
        }
        case A+L:
        {
            display_attribute(buf, name_1);
            printf("%s\n", name_1);
        }
        default:
        {
            break;
        }
    }
    return;
}

void display_single(const char* name)
{
    printf("%s ", name);
    return;
}

void display_attribute(struct stat buf, const char* name)
{
    char buf_time[32];
    //现在接收的数据有，文件信息和文件名
    
    //先打印文件类型
    if(S_ISLNK(buf.st_mode))
    {
        printf("l");
    }
    else if(S_ISREG(buf.st_mode))
    {
        printf("-");
    }
    else if(S_ISDIR(buf.st_mode))
    {
        printf("d");
    }
    else if(S_ISCHR(buf.st_mode))
    {
        printf("c");
    }
    else if(S_ISBLK(buf.st_mode))
    {
        printf("b");
    }
    else if(S_ISFIFO(buf.st_mode))
    {
        printf("f");
    }
    else if(S_ISSOCK(buf.st_mode))
    {
        printf("s");
    }
    //依次打印拥有者用户组其他用户权限
    if(buf.st_mode & S_IRUSR)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if(buf.st_mode & S_IWUSR)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if(buf.st_mode & S_IXUSR)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    if(buf.st_mode & S_IRGRP)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if(buf.st_mode & S_IWGRP)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if(buf.st_mode & S_IXGRP)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    if(buf.st_mode & S_IROTH)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if(buf.st_mode & S_IWOTH)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if(buf.st_mode & S_IXOTH)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    //打印文件所属用户和用户组,因为buf的是uid和gid所以需要调用函数转换下
    printf("%4ld%-8s%-8s", buf.st_nlink, getpwuid(buf.st_uid)->pw_name, getgrgid(buf.st_gid)->gr_name);
    //打印文件大小
    printf("%6ld", buf.st_size);
    //打印日期
    strcpy(buf_time, ctime(&buf.st_mtim.tv_sec));
    buf_time[strlen(buf_time) - 1] = '\0';
    printf("%s", buf_time);
    //打印时间
    return;
}

void display_dir_recurrence(const char* pathname, int flag)
{
    int i, j;//循环变量
    int len = strlen(pathname);//获取路径长度，待会连接路径用
    int count = 0;//统计目录下有多少文件，排序用，调用display函数也用
    //二维数组，其实就是256个字符串
    char pathname_recur[256][PATH_MAX+1] = {0};
    char filename[256][PATH_MAX+1], temp[PATH_MAX+1];//加一难道是为了加\0吗
    DIR* dir;
    struct dirent* ptr;
    struct stat buf;
    if((dir = opendir(pathname)) == NULL)
    {
        my_error("opendir", __LINE__);
    }
    //这个循环有两个作用，获得目录下文件名最大字节长度，统计目录下有文件的数量，方便排序
    while((ptr = readdir(dir)) != NULL)
    {
        //先获得数量，然后排序，再输出
        if(g_maxlen<strlen(ptr->d_name))
        {
            g_maxlen = strlen(ptr->d_name);
        }
        count++;
    }
    closedir(dir);//这里用rewinddir应该也行
    //判断文件数量是否超限
    if(count>256)
    {
        my_error("too many files under this dir", __LINE__);
    }
    //再次打开目录流
    if((dir = opendir(pathname)) == NULL)
    {
        my_error("opendir", __LINE__);
    }
    //然后将数据存储到字符串中，进行排序，排序完成后遍历调用display函数
    for(i=0; i<count; i++)
    {
        if((ptr = readdir(dir)) == NULL)
        {
            my_error("readdir", __LINE__);
        }
        //接下来先把路径放入字符串中,用strncpy比较安全
        strncpy(filename[i], pathname, len);
        filename[i][len] = '\0';
        //然后字符串连接,使用strcat;
        strcat(filename[i], ptr->d_name);
        //再加个\0
        filename[i][len+strlen(ptr->d_name)] = '\0';
        //好了
    }
    //排个序
    qsort(filename, count, PATH_MAX+1, my_cmp);
    //好了，可以整了
    //打印当前目录名
    printf("%s\n", pathname);
    for(i=0, j=0; i<count; i++)
    {
        
        //如果是目录,小心，需要忽略.和..的影响
        if(lstat(filename[i], &buf) == -1)
        {
            my_error("lstat", __LINE__);
        }
        if((S_ISDIR(buf.st_mode))&&(i>2))
        {
            /* switch (flag)
            {
                case NONE:
                {
                    if((name(filename[i]))[0]!='.')
                    {
                        strcpy(pathname_recur[j], filename[i]);
                        j++;
                    }
                    break;
                }
                case A:
                {
                    strcpy(pathname_recur[j], filename[i]);
                    j++;
                    break;
                }
                default:
                {
                    break;
                }
            } */
            if((flag&A)==1)
            {
                strcpy(pathname_recur[j], filename[i]);
                j++;
            }
            else
            {
                if((name(filename[i]))[0]!='.')
                {
                    strcpy(pathname_recur[j], filename[i]);
                    j++;
                }
            }
        }
        display(filename[i], flag);
    }
    //其实这个closedir在可以放到上面那个循环之前
    closedir(dir);
    //按位与 如果没有-l参数，打印换行符
    //为啥？？？
    if((flag & L) == 0)
    {
        printf("\n");
    }
    //给目录字符串数组每个字符串最后加/
    for(i=0; i<j; i++)
    {
        pathname_recur[i][strlen(pathname_recur[i])] = '/';
    }
    //递归调用
    
    for(i=0; i<j; i++)
    {
        //printf("%s\n", pathname_recur[i]);
        display_dir_recurrence(pathname_recur[i], flag);
    }
    return;
}

char * name(const char * pathname)
{
    int i, j;//循环变量
    //char name[NAME_MAX+1];
    char* name = (char*)malloc(NAME_MAX+1);
    //解析文件名
    for(i=0, j=0; i<strlen(pathname); i++)
    {
        if(pathname[i] != '/')
        {
            name[j] = pathname[i];
            j++;
        }
        else
        {
            j = 0;
        } 
    }
    name[j] = '\0';
    return name;
}