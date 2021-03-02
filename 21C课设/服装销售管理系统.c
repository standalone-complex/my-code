#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ApparelSalesManagementSystem{
    char name[20];
    char identifier[20];
    char supplier[20];
    char brand[20];
    char package[20];
    char material[20];
    char color[20];
    char style[20];
    char size[20];
    char amount[20];
    struct ApparelSalesManagementSystem* pNext;
}ASMS, *PASMS;

PASMS create_list(FILE*);
void add_list(PASMS);
void traverse_list(PASMS);
void sentback(FILE*, PASMS);
void search(PASMS);
void search_1_identifier(PASMS, char*);
void search_1_name(PASMS, char*);
void search_1_style(PASMS, char*);
void search_1_supplier(PASMS, char*);
void search_2_size_style(PASMS, char*, char*);
void change(PASMS, char*);
void delete_1(PASMS, char*);

int main(int argc, char * argv[])
{
    //书到用时方恨少...
    //流程大概是先读文件，以链表形式将数据存储在内存中，然后再对数据进行操作，最后将数据再存储在文件中。
    //需要的变量
    FILE* fp;
    PASMS pHead;
    int n, loop_1, loop_2;
    char temp[20];
    //打开文件
    fp = fopen("./21C课设/data.txt", "a+");
    pHead = create_list(fp);
    printf("录入1，排序2，遍历3，查询4，删除5，修改6,结束7\n请输入：___\b\b");//后期用函数替换
    scanf("%d", &n);
    while(n<=0||n>=8)
    {
        printf("请重新输入：___\b\b");
    }
    while(1)
    {
        switch(n)
        {
            case(1):
            {
                printf("请输入录入服装的数量：___\b\b");
                scanf("%d", &loop_2);
                printf("\n");
                for(loop_1=0; loop_1<loop_2; loop_1++)
                {   
                    if(loop_1==0)
                    {
                        printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
                    }
                    add_list(pHead);
                    printf("\n");
                }
                break;
            }
            case(2):
            {
                //按代码排序，实现顺序逆序两种功能
                break;
            }
            case(3):
            {
                traverse_list(pHead);
                break;
            }
            case(4):
            {
                search(pHead);
                break;
            }
            case(5):
            {
                //就是删除节点，用双指针吧
                printf("请输入要删除的服装代码：_________\b\b\b\b");
                scanf("%s", temp);
                delete_1(pHead, temp);
                break;
            }
            case(6):
            {
                //修改通过代码查找，然后将数据全部打印，再将新数据全部由键盘输入
                printf("请输入服装代码：_________\b\b\b\b");
                scanf("%s", temp);
                change(pHead, temp);
                break;
            }
            case(7):
            {
                sentback(fp, pHead);//链表中存储的数据对文件数据进行替换
                fclose(fp);
                return 0;
            }
        }
        printf("录入1，排序2，遍历3，查询4，删除5，修改6,结束7\n请输入：___\b\b");
        scanf("%d", &n);
    }

    return 0;
}

PASMS create_list(FILE* fp)
{
    char ch;
    PASMS pNew;
    //整个头结点
    PASMS ph = (PASMS)malloc(sizeof(ASMS));
    if(ph==NULL)
    {
        exit(-1);
    }
    ph->pNext = NULL;
    //如果文件不为空
    while(ch=getc(fp)!=EOF)
    {
        pNew = (PASMS)malloc(sizeof(ASMS));
        if(pNew==NULL)
        {
            exit(-1);
        }
        fscanf(fp, "%s%s%s%s%s%s%s%s%s%s", pNew->brand, pNew->color, pNew->identifier, pNew->material, pNew->name, pNew->package, pNew->size, pNew->style, pNew->supplier, pNew->amount);
        //品牌，颜色，代码，面料，名称，包装方式，尺码，款式，供应商, 库存数量(注意读进去的时候顺序要一样)
        //头插
        pNew->pNext = ph->pNext;
        ph->pNext = pNew;
    }
    return ph;
}

void traverse_list(PASMS ph)
{
    int i = 0;
    PASMS pc = ph->pNext;
    while(pc!=NULL)
    {
        if(i==0)
        {
            printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
        }
        printf("%s %s %s %s %s %s %s %s %s %s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
        i++;
        pc = pc->pNext;
    }
    if(i==0)
    {
        printf("无服装数据！\n");
    }
    return;
}

void add_list(PASMS ph)
{
    PASMS pNew = (PASMS)malloc(sizeof(ASMS));
    //头插
    pNew->pNext = ph->pNext;
    ph->pNext = pNew;
    scanf("%s %s %s %s %s %s %s %s %s %s",pNew->identifier, pNew->brand, pNew->name, pNew->color, pNew->size, pNew->style, pNew->supplier, pNew->material, pNew->package, pNew->amount);
    printf("\n");
    return;
}

void sentback(FILE* fp, PASMS ph)
{
    //fopen以w+模式打开,将文件清空
    fp = fopen("./21C课设/data.txt", "w+");
    //再写入链表中的数据
    PASMS pc = ph->pNext;
    while(pc!=NULL)
    {
        //品牌，颜色，代码，面料，名称，包装方式，尺码，款式，供应商, 库存数量
        fprintf(fp, " %s %s %s %s %s %s %s %s %s %s", pc->brand, pc->color, pc->identifier, pc->material, pc->name, pc->package, pc->size, pc->style, pc->supplier, pc->amount);
        pc = pc->pNext;
    }
    return;
}

void search(PASMS ph)
{
    int n;
    char temp_1[20];
    char temp_2[20];
    printf("单项查询1，混合查询2，其他任意键退出\n请输入：___\b\b");
    scanf("%d", &n);
    if(n==1)
    {
        //查代码，查品牌，查款式，查名称
        printf("查代码1，查款式2，查名称3，查供应商4，其他任意键退出\n请输入：___\b\b");
        scanf("%d", &n);
        if(n==1)
        {
            printf("请输入服装代码：_________\b\b\b\b");
            scanf("%s", temp_1);
            search_1_identifier(ph, temp_1);
        }
        else if(n==2)
        {
            printf("请输入服装款式：_________\b\b\b\b");
            scanf("%s", temp_1);
            search_1_style(ph, temp_1);
        }
        else if(n==3)
        {
            printf("请输入服装名称：_________\b\b\b\b");
            scanf("%s", temp_1);
            search_1_name(ph, temp_1);
        }
        else if(n==4)
        {
            printf("请输入服装供应商名称：_________\b\b\b\b");
            scanf("%s", temp_1);
            search_1_supplier(ph, temp_1);
        }
    }   
    else if(n==2)
    {
        //查尺码&款式
        printf("请输入尺码和款式：___________________\b\b\b\b\b\b\b\b\b");
        scanf("%s %s", temp_1, temp_2);
        search_2_size_style(ph, temp_1, temp_2);
    }
    return;
}

void search_1_identifier(PASMS ph, char* identifier)
{
    int i = 0;
    PASMS pc = ph->pNext;
    while(pc!=NULL)
    {
        if(strcmp(pc->identifier, identifier)==0)
        {
            if(i==0)
            {
                printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
            }
            i++;
            printf("%s %s %s %s %s %s %s %s %s %s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            return;
        }
        pc = pc->pNext;
    }
    printf("无此服装数据！\n");
    return;
}

void search_1_name(PASMS ph, char* name)
{
    int i = 0;
    PASMS pc = ph->pNext;
    while(pc!=NULL)
    {
        if(strcmp(pc->name, name)==0)
        {
            if(i==0)
            {
                printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
            }
            i++;
            printf("%s %s %s %s %s %s %s %s %s %s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            return;
        }
        pc = pc->pNext;
    }
    printf("无此服装数据！\n");
    return;
}

void search_1_style(PASMS ph, char* style)
{
    int i = 0;
    PASMS pc = ph->pNext;
    while(pc!=NULL)
    {
        if(strcmp(pc->style, style)==0)
        {
            if(i==0)
            {
                printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
            }
            i++;
            printf("%s %s %s %s %s %s %s %s %s %s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
        }
        pc = pc->pNext;
    }
    if(i==0)
    {
        printf("无此服装数据！\n");
    }
    return;
}

void search_1_supplier(PASMS ph, char* supplier)
{
    int i = 0;
    PASMS pc = ph->pNext;
    while(pc!=NULL)
    {
        if(strcmp(pc->supplier, supplier)==0)
        {
            if(i==0)
            {
                printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
            }
            i++;
            printf("%s %s %s %s %s %s %s %s %s %s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
        }
        pc = pc->pNext;
    }
    if(i==0)
    {
        printf("无此服装数据！\n");
    }
    return;
}

void search_2_size_style(PASMS ph, char* size, char* style)
{
    int i = 0;
    PASMS pc = ph->pNext;
    while (pc!=NULL)
    {
        if(strcmp(pc->size, size)==0&&strcmp(pc->style, style)==0)
        {
            if(i==0)
            {
                printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
            }
            i++;
            printf("%s %s %s %s %s %s %s %s %s %s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
        }
    }
    if(i==0)
    {
        printf("无此服装数据！\n");
    }
    return;
}

void change(PASMS ph, char* identifier)
{
    //先找到
    PASMS pc = ph->pNext;
    while(pc!=NULL)
    {
        if(strcmp(pc->identifier, identifier)==0)
        {
            printf("原数据为：\n");
            printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
            printf("%s %s %s %s %s %s %s %s %s %s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            printf("请输入修改后的数据：\n");
            printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
            scanf("%s%s%s%s%s%s%s%s%s%s", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            printf("修改成功！\n");
            return;
        }
        pc = pc->pNext;
    }
    printf("无此服装数据！\n");
    return;
}

void delete_1(PASMS ph, char* identifier)
{
    PASMS pb, pf;
    pb = ph->pNext;
    pf = ph;
    while(pb!=NULL)
    {
        if(strcmp(pb->identifier,identifier)==0)
        {
            pb = pb->pNext;
            pf->pNext = pb;
            printf("删除成功！\n");
            return;
        }
        else
        {
            pb = pb->pNext;
            pf = pf->pNext;
        }
    }
    printf("无此服装数据！\n");
    return;
}