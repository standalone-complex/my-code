#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* pNext;
}NODE, *PNODE;


PNODE create_list();
void output_list(PNODE);
void reverse_list1(PNODE);//头插
PNODE reverse_list2(PNODE);//递归

int main()
{
    PNODE pHead = create_list();
    reverse_list1(pHead);
    //reverse_list2(pHead);
    output_list(pHead);
    return 0;
}

PNODE create_list()
{
    PNODE ph = (PNODE)malloc(sizeof(NODE));
    if(ph==NULL)
    {
        exit(-1);
    }
    ph->pNext = NULL;
    PNODE ptail = ph;

    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew==NULL)
        {
            exit(-1);
        }
        pNew->data = i + 1;
        ptail->pNext = pNew;
        ptail = ptail->pNext;
    }
    ptail->pNext = NULL;

    return ph;
}

void output_list(PNODE ph)
{
    PNODE pc = ph->pNext;
    while(pc!=NULL)
    {
        printf("%d ",pc->data);
        pc = pc->pNext;
    }

    return;
}

void reverse_list1(PNODE ph)
{
    PNODE p, q;
    p = ph->pNext;
    ph->pNext = NULL;
    while(p!=NULL)
    {
        q = p;
        p = p->pNext;

        q->pNext = ph->pNext;
        ph->pNext = q;
    }
    
    return;
}

PNODE reverse_list2(PNODE ph)
{
    if(ph==NULL||ph->pNext==NULL)
    {
        return ph;
    }
    PNODE cur = reverse_list2(ph->pNext);
    ph->pNext->pNext = ph;
    ph->pNext == NULL;

    return cur;
}
