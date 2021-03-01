#include <stdio.h>
#include <stdlib.h>
//用什么样的数据结构去存储数据？？
//‘用push在最后一个元素后添加新的元素’，链表？
//应该如何输入，输入什么，让我分配的内存空间中的数据被正确地读取？
//在不知道数据类型的情况下，我该如何提前为数据分配内存？
typedef struct tyf{
    
    struct tyf* pNext;
}TYF, *PTYF;
typedef struct VariableLengthArray{
    PTYF data;   
    int elemSize;
    void (*push)(struct tyf*);
    void (*pop)(struct tyf*);
}VARIABLE_LENGTH_ARRAY, *PVARIABLE_LENGTH_ARRAY;

int main()
{

    return 0;
}