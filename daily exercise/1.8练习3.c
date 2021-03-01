#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* pNext;
}NODE, *PNODE;

PNODE create_list(void);
PNODE mergeTwoLists(PNODE, PNODE);
void outputlist(PNODE);

int main(void)
{
    PNODE p1 = create_list();
    PNODE p2 = create_list();
    PNODE p = mergeTwoLists(p1->pNext, p2->pNext);
    outputlist(p);
    return 0;
}

PNODE create_list(void)
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead==NULL)
    {
        exit(-1);
    }
    pHead->pNext = NULL;
    PNODE pTail = pHead;
    PNODE pNew;
    int val = 0;
    do{
        scanf("%d", &val);
        if(val!=-1)
        {
            pNew = (PNODE)malloc(sizeof(NODE));
            if(pNew==NULL)
            {
                exit(-1);
            }
            pNew->data = val;
            pTail->pNext = pNew;
            pTail = pTail->pNext;
        }
        else
        {
            break;
        }
    }while(1);
    pTail->pNext = NULL;
    return pHead;
}

PNODE mergeTwoLists(PNODE l1, PNODE l2)
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    PNODE ptail = pHead;
    PNODE pc = l1;
    PNODE pcc = l2;
    while(pc!=NULL&&pcc!=NULL)
    {
        if(pc->data<pcc->data)
        {
            ptail->pNext = pc;
            ptail = ptail->pNext;
            pc = pc->pNext;
        }
        else
        {
            ptail->pNext = pcc;
            ptail = ptail->pNext;
            pcc = pcc->pNext;
        }
    }
    if(pc==NULL)
    {
        ptail->pNext = pcc;
    }
    if(pcc==NULL)
    {
        ptail->pNext = pc;
    }
    return pHead->pNext;
}

void outputlist(PNODE ph)
{
    while(ph!=NULL)
    {
        printf("--%d", ph->data);
        ph = ph->pNext;
    }
    return;
}