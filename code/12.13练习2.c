#include <stdio.h>
#include <stdlib.h>

int* buildarr();
void heapsort(int*);
void displayarr(int*);

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