#include <stdio.h>

int TowerOfHanoi(int);

int main()
{
    int n;
    printf("几层汉诺塔？请输入：");
    scanf("%d", &n);
    printf("需要%d次移动", TowerOfHanoi(n));
    return 0;
}

int TowerOfHanoi(int n)
{
    if(n==0)
    {
        return 0;
    }
    return 2 * TowerOfHanoi(n-1) + 1; 
}