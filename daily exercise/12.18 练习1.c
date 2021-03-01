#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    int data;
    struct BTNode* pLchild;
    struct BTNode* pRchild;
}BTNODE, *PBTNODE;

PBTNODE CreatBTree();

int main()
{
    PBTNODE ph = CreateBTree();
    
    return 0;
}