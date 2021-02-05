#ifndef _MYFUNCTIONS_H_
#define _MYFUNCTIONS_H_

typedef struct tyf{
    int data;
    struct tyf* pNext;
}TYF, *PTYF;

PTYF List_Create(void)//有头结点的单链表
{
    PTYF pHead = (PTYF)malloc(sizeof(TYF));
    if(pHead==NULL)
    {
        exit(-1);
    }
    PTYF pTail = pHead;
    PTYF pNew;
    int i, val, n;
    printf("请输入节点个数：");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        pNew = (PTYF)malloc(sizeof(TYF));
        if(pNew==NULL)
        {
            exit(-1);
        }
        printf("请输入该节点的值：");
        scanf("%d", &val);
        pNew->data = val;//为啥不直接scanf给pNew->data呢
        pTail->pNext = pNew;
        pTail = pTail->pNext;
    }
    pTail->pNext = NULL;
    return pHead;
}

void List_HeadAdd(PTYF pHead)
{
    int i, n, val;
    PTYF pNew;
    printf("请输入要插入的数量：");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        pNew = (PTYF)malloc(sizeof(PTY));
        if(pNew==NULL)
        {
            exit(-1);
        }
        printf("请输入要插入的值：");
        scanf("%d", &val);
        pNew->data = val;
        pNew->pNext = pHead->pNext;
        pHead->pNext = pNew;
    }
    return;
}

void List_TailAdd(PTYF pHead)
{
    int i, n, val;
    PTYF pTail = pHead;
    PTYF pNew;
    while(pTail->pNext!=NULL)
    {
        pTail = pTail->pNext;
    }
    printf("请输入要插入的数量：");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        pNew = (PTYF)malloc(sizeof(TYF));
        if(pNew==NULL)
        {
            exit(-1);
        }
        printf("请输入要插入的值：");
        scanf("%d", &val);
        pNew->data = val;
        pTail->pNext = pNew;
        pTail = pTail->pNext;
    }
    pTail->pNext = NULL;
}

void List_Output(PTYF pHead)
{
    PTYF p = pHead->pNext;
    if(p!=NULL)
    {
        printf("%d", p->data);
        p = p->pNext;
    }
    return;
}

bool List_Delete_1(PTYF pHead, int pos)//删第i个
{
    int i = 0;
    PTYF p = pHead;
    while(p->pNext != NULL&&i<pos-1)
    {
        p = p->pNext;
        i++;
    }
    if(i>pos-1||p->pNext==NULL)
        return false;
    PTYF t = p->pNext;
    p->pNext = p->pNext->pNext;
    free(t);
    return true;
}

void List_Delete_2(PTYF pHead, int key)//删所有值为key的
{
//整个双指针
    PTYF pb = pHead;
    PTYF pf = pHead->pNext;
    while(pf!=NULL&&pb->pNext!=NULL)
    {
        if(pf->data==key)
        {   
            pf = pf->pNext;
            pb = pf;
        }
        else
        {
            pf = pf->pNext;
            pb = pb->pNext;
        }
    }
    return;
}

#endif