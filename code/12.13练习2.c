#include <stdio.h>
#include <stdlib.h>

int* buildarr();//构建数组
void heapsort(int*);//堆排序
void displayarr(int*);//遍历数组
void swap(int*, int, int);//交换元素
void buildheap(int*);//将数组堆化（堆的初始化）（这里要建立很多次堆，不然可能出现不符合要求的情况）
void down(int*, int);//建立堆

int main()//堆排序_完全二叉树
{
    int* a = buildarr();
    heapsort(a);
    displayarr(a);
    return 0;
}

int* buildarr()
{
    int n, i;
    printf("要放几个元素？请输入:");
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }
    return a;
}

void heapsort(int* ac)
{

    return;
}

void displayarr(int* ac)
{
    int len = sizeof(ac)/sizeof(int);
    int i;
    for(i=0; i<len; i++)
    {
        printf("%d", ac[i]);
        if(i!=len-1)
        {
            printf(" ");
        }
    }
    return;
}

void swap(int* ac, int x, int y)
{
    int t;
    t = ac[x];
    ac[x] = ac[y];
    ac[y] = t;
    return;
}

void buildheap(int* ac)
{
    
    return;
}

void down(int* ac, int i)//这个是堆排的核心,从小到大排序，所以是最大堆
{
    int len = sizeof(ac)/sizeof(int);
    int parent = i;//
    int child = 2 * i + 1;
    while(child<len)
    {
        if(ac[child]<ac[child+1]&&child+1<len)//判断两个子节点哪个大，用大的那个
        {
            child++;
        }
        if(ac[child]>ac[parent])//如果子节点大于父节点就交换
        {
            swap(ac, child, parent);
        }
    }
    return;
}