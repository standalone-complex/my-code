#include <stdio.h>

void TowerOfHanoi(int, char, char, char);

int main()
{
    int n;
    printf("几层汉诺塔？请输入：");
    scanf("%d", &n);
    TowerOfHanoi(n , 'A', 'B', 'C');
    return 0;
}

void TowerOfHanoi(int n, char cur, char tmp, char tgt)//这是三根柱子 他们是固定的。cur为起始柱子，tgt为目标柱，tmp为缓冲柱
{
    if(n==1)
    {
        printf("将在%c柱子上的%d号盘挪到%c柱子\n", cur, 1, tgt);
        return;
    }
    else
    {
        TowerOfHanoi(n-1, cur, tgt, tmp);
        printf("将在%c柱子上的%d号盘挪到%c柱子\n",  cur, n, tgt);
        TowerOfHanoi(n-1, tmp, cur, tgt);
    }
}