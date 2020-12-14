#include <stdio.h>
#include <stdlib.h>

int* buildarr(int);//构建数组
void heapsort(int*, int);//堆排序
void displayarr(int*, int);//遍历数组
void swap(int*, int, int);//交换元素
void buildheap(int*, int);//将数组堆化（堆的初始化）（这里要建立很多次堆，不然可能出现不符合要求的情况）
void down(int*, int, int);//建立堆

int main()//堆排序_完全二叉树
{
    int len;
    printf("要放几个元素？请输入:");
    scanf("%d", &len);
    int* a = buildarr(len);
    heapsort(a, len);
    displayarr(a, len);
    return 0;
}

int* buildarr(int n)
{
    int i;
    int* a = (int*)malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }
    return a;
}

void heapsort(int* ac, int len)//堆排
{
    int i;
    buildheap(ac, len);
    for(i=len-1; i>=0; i--)
    {
        swap(ac, 0, i);
        down(ac, 0, i);
    }
    return;
}

void displayarr(int* ac, int len)
{
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

void swap(int* ac, int x, int y)//交换，没啥说的
{
    int t;
    t = ac[x];
    ac[x] = ac[y];
    ac[y] = t;
    return;
}

void buildheap(int* ac, int len)//初始化一个堆
{
    int i;
    for(i=len/2-1; i>=0; i--)//从倒数第二行开始最后一个节点开始堆化，直到从第一个元素的堆化结束
    {
        down(ac, i, len);
    }
    return;
}

void down(int* ac, int i, int len)//这个是堆排的核心,从小到大排序，所以是最大堆
{
    int parent = i;//
    int child = 2 * i + 1;
    while(child<len)//其实单纯的初始化堆不需要这个循环，只需要从倒数第二行最后一个节点往前遍历就行，这个循环的目的有二。
    //1.满足堆的初始化。2.初始化之后，满足堆排序时的重新构建堆的要求。
    {
        if(ac[child]<ac[child+1]&&child+1<len)//判断两个子节点哪个大，用大的那个
        {
            child++;
        }
        if(ac[child]>ac[parent])//如果子节点大于父节点就交换
        {
            swap(ac, child, parent);
            parent = child;//改变父节点位置
        }
        child = child * 2 + 1;//转进下面的子节点
    }
    return;
}