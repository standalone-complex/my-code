#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

typedef struct Statistic_Struct{
    char string[20];
    int count;
    struct Statistic_Struct* pNext;
}SS, *PSS;

typedef struct Statistic_Struct_2{
    char string_1[20];
    char string_2[20];
    int count;
    struct Statistic_Struct_2* pNext;
}SS_2, *PSS_2;

PASMS create_list(FILE*);
PSS get_statistic_data_style(PASMS);
PSS get_statistic_data_material(PASMS);
PSS_2 get_statistic_data_brand_supplier(PASMS);
void add_list(PASMS);
void traverse_list(PASMS);
void sentback(FILE*, PASMS);
void search(PASMS);
void search_1_identifier(PASMS, char*);
void search_1_name(PASMS, char*);
void search_1_style(PASMS, char*);
void search_1_supplier(PASMS, char*);
void search_2_size_style(PASMS, char*, char*);
void search_2_brand_supplier(PASMS, char*, char*);
void change(PASMS, char*);
void delete_1(PASMS, char*);
void List_BubbleSort_Rise_1(PASMS);
void List_BubbleSort_Drop_1(PASMS);
void List_BubbleSort_Rise_2(PASMS);
void List_BubbleSort_Drop_2(PASMS);
void statistics(PASMS);
void statistic_style(PASMS);
void statistic_material(PASMS);
void statistic_brand_supplier(PASMS);
int List_Len(PASMS);
int menu(void);
bool sign_in(void);//登录
void sign_up(void);//注册

int main(int argc, char * argv[])
{
    //书到用时方恨少...
    //流程大概是先读文件，以链表形式将数据存储在内存中，然后再对数据进行操作，最后将数据再存储在文件中。
    //需要的变量
    FILE* fp;
    PASMS pHead;
    int judge, n, loop_1, loop_2, c;
    char temp[20];
    judge = menu();
    if(judge==0)
    {
        return 0;
    }
    printf("\033c");//清屏
    printf("——————————##########登录成功!##########——————————\n\n");
    printf("——————————##########服装销售管理系统##########——————————\n");
    printf("——————————##########服装销售管理系统##########——————————\n");
    printf("——————————#####欢迎使用服装销售管理系统#####——————————\n");
    //打开文件
    fp = fopen("./21C课设/data.txt", "a+");
    pHead = create_list(fp);
    printf("1：录入\t\t2：排序\t\t3：遍历\t\t4：查询\n5：删除\t\t6：修改\t\t7：统计\t\t8：保存并退出\n请输入：___\b\b");//后期用函数替换
    while(1)
    {
        judge = scanf("%d", &n);
        if(judge!=1)
        {
            //清除缓冲区（fflush没用）
            while((c = getchar()) != '\n' && c != EOF);
            printf("输入格式错误！，请重新输入：___\b\b");
        }
        else
        {
            if(n<=0||n>=9)
            {
                printf("输入范围错误！，请重新输入：___\b\b");
            }
            else
            {
                break;
            }
        }
    }
    while(1)
    {
        switch(n)
        {
            case(1):
            {
                printf("请输入录入服装的数量：___\b\b");
                //scanf("%d", &loop_2);
                while(1)
                {
                    judge = scanf("%d", &loop_2);
                    if(judge!=1)
                    {
                        //清除缓冲区（fflush没用）
                        while((c = getchar()) != '\n' && c != EOF);
                        printf("输入格式错误！，请重新输入：___\b\b");
                    }
                    else
                    {
                        if(loop_2<0)
                        {
                            printf("输入范围错误！，请重新输入：___\b\b");
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                for(loop_1=0; loop_1<loop_2; loop_1++)
                {   
                    if(loop_1==0)
                    {
                        printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
                    }
                    add_list(pHead);
                    printf("\n");
                }
                printf("\033c");
                printf("——————————##########录入完毕!##########——————————\n\n");
                break;
            }
            case(2):
            {
                printf("1：代码排序\t\t2：库存数量排序\n其他数字返回\n请输入：___\b\b");
                while(1)
                {
                    judge = scanf("%d", &n);
                    if(judge!=1)
                    {
                        //清除缓冲区（fflush没用）
                        while((c = getchar()) != '\n' && c != EOF);
                        printf("输入格式错误！，请重新输入：___\b\b");
                    }
                    else
                    {
                        break;
                    }
                }
                if(n==1)
                {
                    //按代码排序，实现顺序逆序两种功能
                    printf("1：升序\t\t2：降序\n其他数字返回\n请输入：___\b\b");
                    //scanf("%d", &n);
                    while(1)
                    {
                        judge = scanf("%d", &n);
                        if(judge!=1)
                        {
                            //清除缓冲区（fflush没用）
                            while((c = getchar()) != '\n' && c != EOF);
                            printf("输入格式错误！，请重新输入：___\b\b");
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(n==1)
                    {
                        List_BubbleSort_Rise_1(pHead);
                        printf("\033c");
                        printf("——————————##########排序完成!##########——————————\n\n");
                    }
                    else if(n==2)
                    {
                        List_BubbleSort_Drop_1(pHead);
                        printf("\033c");
                        printf("——————————##########排序完成!##########——————————\n\n");
                    }
                    else
                    {
                        printf("\033c");
                    }
                    break;
                }
                else if(n==2)
                {
                    //按库存数量排序，实现顺序逆序两种功能
                    printf("1：升序\t\t2：降序\n其他数字返回\n请输入：___\b\b");
                    //scanf("%d", &n);
                    while(1)
                    {
                        judge = scanf("%d", &n);
                        if(judge!=1)
                        {
                            //清除缓冲区（fflush没用）
                            while((c = getchar()) != '\n' && c != EOF);
                            printf("输入格式错误！，请重新输入：___\b\b");
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(n==1)
                    {
                        List_BubbleSort_Rise_2(pHead);
                        printf("\033c");
                        printf("——————————##########排序完成!##########——————————\n\n");
                    }
                    else if(n==2)
                    {
                        List_BubbleSort_Drop_2(pHead);
                        printf("\033c");
                        printf("——————————##########排序完成!##########——————————\n\n");
                    }
                    else
                    {
                        printf("\033c");
                    }
                    break;
                }
                else
                {
                    printf("\033c");
                }
                break;
            }
            case(3):
            {
                printf("\033c");
                traverse_list(pHead);
                printf("\n\n任意键返回...\n");
                while((c = getchar()) != '\n' && c != EOF);
                getchar();
                printf("\033c");
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
                statistics(pHead);
                break;
            }
            case(8):
            {
                sentback(fp, pHead);//链表中存储的数据对文件数据进行替换
                fclose(fp);
                return 0;
            }
        }
        //printf("录入1，排序2，遍历3，查询4，删除5，修改6,保存并结束7\n请输入：___\b\b");
        //printf("\033c");//清屏
        printf("——————————##########服装销售管理系统##########——————————\n");
        printf("——————————##########服装销售管理系统##########——————————\n");
        printf("——————————#####欢迎使用服装销售管理系统#####——————————\n");
        printf("1：录入\t\t2：排序\t\t3：遍历\t\t4：查询\n5：删除\t\t6：修改\t\t7：统计\t\t8：保存并退出\n请输入：___\b\b");
        while(1)
        {   
            judge = scanf("%d", &n);
            if(judge!=1)
            {
                fflush(stdin);
                printf("输入格式错误！，请重新输入：___\b\b");
            }
            else
            {
                if(n<=0||n>=9)
                {
                    printf("输入范围错误！，请重新输入：___\b\b");
                }
                else
                {
                    break;
                }
            }
        }
    }

    return 0;
}

PASMS create_list(FILE* fp)
{
    char ch;
    PASMS pNew;
    PASMS pTail;
    //整个头结点
    PASMS ph = (PASMS)malloc(sizeof(ASMS));
    if(ph==NULL)
    {
        exit(-1);
    }
    ph->pNext = NULL;
    pTail = ph;
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
        //尾插
        pTail->pNext = pNew;
        pTail = pTail->pNext;
    }
    pTail->pNext = NULL;
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
            printf("代码    品牌    名称    颜色    尺码    款式    供应商  面料    包装    库存数量\n");
        }
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
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
    int n, judge, c;
    char ch;
    char temp_1[20];
    char temp_2[20];
    printf("1：单项查询\t\t2:混合查询\n其他数字返回\n请输入：___\b\b");
    //scanf("%d", &n);
    while(1)
    {
        judge = scanf("%d", &n);
        if(judge!=1)
        {
            //清除缓冲区（fflush没用）
            while((c = getchar()) != '\n' && c != EOF);
            printf("输入格式错误！，请重新输入：___\b\b");
        }
        else
        {
            break;
        }
    }
    if(n==1)
    {
        //查代码，查品牌，查款式，查名称
        printf("1：查代码\t\t2：查款式\n3：查名称\t\t4：查供应商\n其他数字返回\n请输入：___\b\b");
        //scanf("%d", &n);
        while(1)
        {
            judge = scanf("%d", &n);
            if(judge!=1)
            {
                //清除缓冲区（fflush没用）
                while((c = getchar()) != '\n' && c != EOF);
                printf("输入格式错误！，请重新输入：___\b\b");
            }
            else
            {
                break;
            }
        }
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
        else
        {
            printf("\033c");
        }
    }   
    else if(n==2)//3.3 这里有一个bug
    {
        //查尺码&款式
        printf("1：尺码&款式查询\t\t2：供应商&品牌查询\n其他数字返回\n请输入：___\b\b");
        while(1)
        {
            judge = scanf("%d", &n);
            if(judge!=1)
            {
                //清除缓冲区（fflush没用）
                while((c = getchar()) != '\n' && c != EOF);
                printf("输入格式错误！，请重新输入：___\b\b");
            }
            else
            {
                break;
            }
        }
        if(n==1)
        {
            printf("请输入尺码和款式：___________________\b\b\b\b\b\b\b\b\b");
            //while((ch = getchar()) != '\n' && c != EOF);
            scanf("%s%s", temp_1, temp_2);
            //printf("不会吧不会吧，不会真有人在这卡住吧\n");
            search_2_size_style(ph, temp_1, temp_2);
        }
        else if(n==2)
        {
            printf("请输入品牌和供应商：___________________\b\b\b\b\b\b\b\b\b");
            //while((ch = getchar()) != '\n' && c != EOF);
            scanf("%s%s", temp_1, temp_2);
            //printf("不会吧不会吧，不会真有人在这卡住吧\n");
            search_2_brand_supplier(ph, temp_1, temp_2);
        }
        else
        {
            printf("\033c");
        }
        
    }
    else
    {
        printf("\033c");
    }
    return;
}

void search_1_identifier(PASMS ph, char* identifier)
{
    int i = 0;
    char c;
    PASMS pc = ph->pNext;
    printf("\033c");
    while(pc!=NULL)
    {
        if(strcmp(pc->identifier, identifier)==0)
        {
            if(i==0)
            {
                printf("代码    品牌    名称    颜色    尺码    款式    供应商  面料    包装    库存数量\n");
            }
            i++;
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            printf("输入任意键返回...");
            while((c = getchar()) != '\n' && c != EOF);
            getchar();
            printf("\033c");
            return;
        }
        pc = pc->pNext;
    }
    printf("——————————##########无此服装数据!##########——————————\n\n");
    return;
}

void search_1_name(PASMS ph, char* name)
{
    int i = 0;
    char c;
    PASMS pc = ph->pNext;
    printf("\033c");
    while(pc!=NULL)
    {
        if(strcmp(pc->name, name)==0)
        {
            if(i==0)
            {
                printf("代码    品牌    名称    颜色    尺码    款式    供应商  面料    包装    库存数量\n");
            }
            i++;
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            printf("输入任意键返回...");
            while((c = getchar()) != '\n' && c != EOF);
            getchar();
            printf("\033c");
            return;
        }
        pc = pc->pNext;
    }
    printf("——————————##########无此服装数据!##########——————————\n\n");
    return;
}

void search_1_style(PASMS ph, char* style)
{
    int i = 0;
    char c;
    PASMS pc = ph->pNext;
    printf("\033c");
    while(pc!=NULL)
    {
        if(strcmp(pc->style, style)==0)
        {
            if(i==0)
            {
                printf("代码    品牌    名称    颜色    尺码    款式    供应商  面料    包装    库存数量\n");
            }
            i++;
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            printf("输入任意键返回...");
            while((c = getchar()) != '\n' && c != EOF);
            getchar();
            printf("\033c");
            return;
        }
        pc = pc->pNext;
    }
    printf("——————————##########无此服装数据!##########——————————\n\n");
    return;
}

void search_1_supplier(PASMS ph, char* supplier)
{
    int i = 0;
    char c;
    PASMS pc = ph->pNext;
    printf("\033c");
    while(pc!=NULL)
    {
        if(strcmp(pc->supplier, supplier)==0)
        {
            if(i==0)
            {
                printf("代码    品牌    名称    颜色    尺码    款式    供应商  面料    包装    库存数量\n");
            }
            i++;
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            printf("输入任意键返回...");
            while((c = getchar()) != '\n' && c != EOF);
            getchar();
            printf("\033c");
            return;
        }
        pc = pc->pNext;
    }
    printf("——————————##########无此服装数据!##########——————————\n\n");
    return;
}

void search_2_size_style(PASMS ph, char* size, char* style)
{
    //printf("这里是一个printf调试大法1\n");
    int i = 0;
    char c;
    PASMS pc = ph->pNext;
    printf("\033c");
    while (pc!=NULL)
    {
        if(strcmp(pc->size, size)==0&&strcmp(pc->style, style)==0)
        {
            if(i==0)
            {
                printf("代码    品牌    名称    颜色    尺码    款式    供应商  面料    包装    库存数量\n");
            }
            i++;
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
        }
        pc = pc->pNext;
    }
    //printf("这里是一个printf调试大法2\n");
    if(i==0)
    {
        printf("——————————##########无此服装数据!##########——————————\n\n");
        return;
    }
    printf("输入任意键返回...");
    while((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033c");
    return;
}

void search_2_brand_supplier(PASMS ph, char* brand, char* supplier)
{
    //printf("这里是一个printf调试大法1\n");
    int i = 0;
    char c;
    PASMS pc = ph->pNext;
    printf("\033c");
    while (pc!=NULL)
    {
        if(strcmp(pc->brand, brand)==0&&strcmp(pc->supplier, supplier)==0)
        {
            if(i==0)
            {
                printf("代码    品牌    名称    颜色    尺码    款式    供应商  面料    包装    库存数量\n");
            }
            i++;
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
        }
        pc = pc->pNext;
    }
    //printf("这里是一个printf调试大法2\n");
    if(i==0)
    {
        printf("——————————##########无此服装数据!##########——————————\n\n");
        return;
    }
    printf("输入任意键返回...");
    while((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033c");
    return;
}

void change(PASMS ph, char* identifier)
{
    //先找到
    char c;
    PASMS pc = ph->pNext;
    printf("\033c");
    while(pc!=NULL)
    {
        if(strcmp(pc->identifier, identifier)==0)
        {
            printf("原数据为：\n");
            printf("代码    品牌    名称    颜色    尺码    款式    供应商  面料    包装    库存数量\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            printf("请输入修改后的数据：\n");
            printf("代码 品牌 名称 颜色 尺码 款式 供应商 面料 包装方式 库存数量\n");
            scanf("%s%s%s%s%s%s%s%s%s%s", pc->identifier, pc->brand, pc->name, pc->color, pc->size, pc->style, pc->supplier, pc->material, pc->package, pc->amount);
            printf("修改成功！输入任意键返回...\n");
            while((c = getchar()) != '\n' && c != EOF);
            getchar();
            printf("\033c");
            return;
        }
        pc = pc->pNext;
    }
    printf("——————————##########无此服装数据##########——————————\n\n");
    return;
}

void delete_1(PASMS ph, char* identifier)
{
    PASMS pb, pf;
    pb = ph->pNext;
    pf = ph;
    printf("\033c");
    while(pb!=NULL)
    {
        if(strcmp(pb->identifier,identifier)==0)
        {
            pb = pb->pNext;
            pf->pNext = pb;
            printf("——————————##########删除成功!##########——————————\n\n");
            return;
        }
        else
        {
            pb = pb->pNext;
            pf = pf->pNext;
        }
    }
    printf("——————————##########无此服装数据!##########——————————\n\n");
    return;
}

void List_BubbleSort_Rise_1(PASMS ph)
{
    int len = List_Len(ph);
    int loop_1, loop_2;
    if(len<2)
    {
        return;
    }
    else
    {
        PASMS pf, pm, pb;
        for(loop_1=0; loop_1<len-1; loop_1++)//这里的循环变量与链表无关
        {
            pf = ph;
            pm = pf->pNext;
            pb = pm->pNext;
            for(loop_2=0; loop_2<len-1-loop_1; loop_2++)
            {
                if(strcmp(pm->identifier,pb->identifier)>0)//升序，
                {
                    //指针域交换
                    pf->pNext = pm->pNext;
                    pm->pNext = pb->pNext;
                    pb->pNext =pm; 
                    //数据域交换
                    pm = pf->pNext;
                    pb = pf->pNext->pNext;
                }
                pf = pf->pNext;
                pm = pm->pNext;
                pb = pb->pNext;
            }
        }
        return;
    }
}

void List_BubbleSort_Drop_1(PASMS ph)
{
    int len = List_Len(ph);
    int loop_1, loop_2;
    if(len<2)
    {
        return;
    }
    else
    {
        PASMS pf, pm, pb;
        for(loop_1=0; loop_1<len-1; loop_1++)//这里的循环变量与链表无关
        {
            pf = ph;
            pm = pf->pNext;
            pb = pm->pNext;
            for(loop_2=0; loop_2<len-1-loop_1; loop_2++)
            {
                if(strcmp(pm->identifier,pb->identifier)<0)//降序，
                {
                    //指针域交换(这三行用函数应该也行，属于指针操作，但接下来两行就不行了)
                    pf->pNext = pm->pNext;
                    pm->pNext = pb->pNext;
                    pb->pNext =pm; 
                    //数据域交换
                    pm = pf->pNext;
                    pb = pf->pNext->pNext;
                }
                pf = pf->pNext;
                pm = pm->pNext;
                pb = pb->pNext;
            }
        }
        return;
    }
    return;
}

void List_BubbleSort_Rise_2(PASMS ph)
{
    int len = List_Len(ph);
    int loop_1, loop_2;
    if(len<2)
    {
        return;
    }
    else
    {
        PASMS pf, pm, pb;
        for(loop_1=0; loop_1<len-1; loop_1++)//这里的循环变量与链表无关
        {
            pf = ph;
            pm = pf->pNext;
            pb = pm->pNext;
            for(loop_2=0; loop_2<len-1-loop_1; loop_2++)
            {
                if(strcmp(pm->amount,pb->amount)>0)//升序，
                {
                    //指针域交换
                    pf->pNext = pm->pNext;
                    pm->pNext = pb->pNext;
                    pb->pNext =pm; 
                    //数据域交换
                    pm = pf->pNext;
                    pb = pf->pNext->pNext;
                }
                pf = pf->pNext;
                pm = pm->pNext;
                pb = pb->pNext;
            }
        }
        return;
    }
}

void List_BubbleSort_Drop_2(PASMS ph)
{
    int len = List_Len(ph);
    int loop_1, loop_2;
    if(len<2)
    {
        return;
    }
    else
    {
        PASMS pf, pm, pb;
        for(loop_1=0; loop_1<len-1; loop_1++)//这里的循环变量与链表无关
        {
            pf = ph;
            pm = pf->pNext;
            pb = pm->pNext;
            for(loop_2=0; loop_2<len-1-loop_1; loop_2++)
            {
                if(strcmp(pm->amount,pb->amount)<0)//降序，
                {
                    //指针域交换(这三行用函数应该也行，属于指针操作，但接下来两行就不行了)
                    pf->pNext = pm->pNext;
                    pm->pNext = pb->pNext;
                    pb->pNext =pm; 
                    //数据域交换
                    pm = pf->pNext;
                    pb = pf->pNext->pNext;
                }
                pf = pf->pNext;
                pm = pm->pNext;
                pb = pb->pNext;
            }
        }
        return;
    }
    return;
}

int  List_Len(PASMS ph)
{
    PASMS pc = ph->pNext;
    int i = 0;
    while(pc!=NULL)
    {
        i++;
        pc = pc->pNext;
    }
    return i;
}

int menu(void)
{
    int n, judge, c;
    do
    {
        printf("——————————##########服装销售管理系统##########——————————\n");
        printf("——————————##########服装销售管理系统##########——————————\n");
        printf("—————————###欢迎使用服装销售管理系统,请先登录!###——————————\n");
        printf("#菜单#\n");
        printf("1：登录\n");
        printf("2：注册\n");
        printf("0：退出\n");
        printf("****************************************************************\n");
        printf("请输入您的操作：___\b\b");
        while(1)
        {   
            judge = scanf("%d", &n);
            if(judge!=1)
            {
                //清除缓冲区（fflush没用）
                while((c = getchar()) != '\n' && c != EOF);
                printf("输入格式错误！，请重新输入：___\b\b");
            }
            else
            {
                if(n!=1&&n!=2&&n!=0)
                {
                    printf("输入范围错误！，请重新输入！：___\b\b");
                }
                else
                {
                    //system("cls"); 
                    //printf("\033c");//linux下的清屏
                    break;
                }
            }
        }
        judge = 1;

        switch(n)
        {
            case(1):
            {
                judge=sign_in();
                break;
            }
            case(2):
            {
                sign_up();
                judge = 0;
                break;
            }
            default:
            {
                printf("\033c");
                printf("bye~");
                return 0;//退出
            }
        }
    }while(!judge);
    return 1;//登录成功
}

bool sign_in(void)//登录
{
    FILE* fp = fopen("./21C课设/user.txt", "a+");
    char name[20], name_f[20];
    char password[20], password_f[20];
    printf("请输入用户名：\n");
    scanf("%s", name);
    printf("请输入密码：\n");
    scanf("%s", password);
    //这里直接遍历得了
    int c;
    while(c=getc(fp)!=EOF)
    {
        fscanf(fp, "%s%s", name_f, password_f);
        if(strcmp(name, name_f)==0)
        {
            if(strcmp(password, password_f)==0)
            {
                fclose(fp);
                return true;
            }
        }
    }
    printf("\033c");
    printf("登录失败，将返回登录界面！\n任意键继续...");
    while((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033c");
    fclose(fp);
    return false;
}

void sign_up(void)//向文件末尾添加内容
{
    char c;
    FILE* fp = fopen("./21C课设/user.txt", "a+");
    char name[20], password[20];
    printf("请输入用户名：\n");
    scanf("%s", name);
    printf("请输入密码：\n");
    scanf("%s", password);
    fprintf(fp, " %s %s", name, password);
    printf("添加账户成功！按任意键回到登录系统...\n");
    while((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033c");
    //fflush(fp);
    fclose(fp);
    return;
}

void statistics(PASMS ph)
{
    int n, judge, c;
    char ch;
    char temp_1[20];
    char temp_2[20];
    printf("1：单项统计\t\t2:混合统计\n其他数字返回\n请输入：___\b\b");
    //scanf("%d", &n);
    while(1)
    {
        judge = scanf("%d", &n);
        if(judge!=1)
        {
            //清除缓冲区（fflush没用）
            while((c = getchar()) != '\n' && c != EOF);
            printf("输入格式错误！，请重新输入：___\b\b");
        }
        else
        {
            break;
        }
    }
    if(n==1)
    {  
        printf("1：统计款式\t\t2：统计面料\n其他数字返回\n请输入：___\b\b");
        while(1)
        {
            judge = scanf("%d", &n);
            if(judge!=1)
            {
                //清除缓冲区（fflush没用）
                while((c = getchar()) != '\n' && c != EOF);
                printf("输入格式错误！，请重新输入：___\b\b");
            }
            else
            {
                break;
            }
        }
        if(n==1)
        {
            statistic_style(ph);
        }
        else if(n==2)
        {
            statistic_material(ph);
        }
        else
        {
            printf("\033c");
        }
    }
    else if(n==2)
    {
        statistic_brand_supplier(ph);
    }
    else
    {
        printf("\033c");
    }
    return;
}

void statistic_style(PASMS ph)//面料和这个一样
{
    int c;
    if(ph->pNext==NULL)
    {
        printf("\033c");
        printf("——————————#####无服装数据!#####——————————\n");
        return;
    }
    PSS ph_1 = get_statistic_data_style(ph);//得到不重复的所有类型   
    PASMS pc = ph->pNext;
    PSS pc_1;
    while(pc!=NULL)
    {
        pc_1 = ph_1->pNext;
        while(pc_1!=NULL)
        {
            if(strcmp(pc_1->string,pc->style)==0)
            {
                pc_1->count++;
                break;
            }
            pc_1 = pc_1->pNext;
        }
        pc = pc->pNext;
    }
    printf("\033c");
    pc_1 = ph_1->pNext;
    printf("款式            库存数量\n");
    while(pc_1!=NULL)
    {
        printf("%s\t\t%d\n", pc_1->string, pc_1->count);
        pc_1 = pc_1->pNext;
    }
    printf("输入任意键返回...");
    while((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033c");
    return;
}

void statistic_material(PASMS ph)//面料和这个一样
{
    int c;
    if(ph->pNext==NULL)
    {
        printf("\033c");
        printf("——————————#####无服装数据!#####——————————\n");
        return;
    }
    PSS ph_1 = get_statistic_data_material(ph);//得到不重复的所有类型   
    PASMS pc = ph->pNext;
    PSS pc_1;
    while(pc!=NULL)
    {
        pc_1 = ph_1->pNext;
        while(pc_1!=NULL)
        {
            if(strcmp(pc_1->string,pc->material)==0)
            {
                pc_1->count++;
                break;
            }
            pc_1 = pc_1->pNext;
        }
        pc = pc->pNext;
    }
    printf("\033c");
    pc_1 = ph_1->pNext;
    printf("面料            库存数量\n");
    while(pc_1!=NULL)
    {
        printf("%s\t\t%d\n", pc_1->string, pc_1->count);
        pc_1 = pc_1->pNext;
    }
    printf("输入任意键返回...");
    while((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033c");
    return;
}

void statistic_brand_supplier(PASMS ph)
{
    int c;
    if(ph->pNext==NULL)
    {
        printf("\033c");
        printf("——————————#####无服装数据!#####——————————\n");
        return;
    }
    PSS_2 ph_1 = get_statistic_data_brand_supplier(ph);//得到不重复的所有类型   
    PASMS pc = ph->pNext;
    PSS_2 pc_1;
    while(pc!=NULL)
    {
        pc_1 = ph_1->pNext;
        while(pc_1!=NULL)
        {
            if(strcmp(pc_1->string_1, pc->brand)==0&&strcmp(pc_1->string_2, pc->supplier)==0)
            {
                pc_1->count++;
                break;
            }
            pc_1 = pc_1->pNext;
        }
        pc = pc->pNext;
    }
    printf("\033c");
    pc_1 = ph_1->pNext;
    printf("品牌   供应商         库存数量\n");
    while(pc_1!=NULL)
    {
        printf("%s\t\t%s\t\t%d\n", pc_1->string_1, pc_1->string_2, pc_1->count);
        pc_1 = pc_1->pNext;
    }
    printf("输入任意键返回...");
    while((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033c");
    return;
}

PSS get_statistic_data_style(PASMS ph)
{
    PSS ph_1 = (PSS)malloc(sizeof(SS));
    if(ph_1==NULL)
    {
        exit(-1);
    }
    ph_1->pNext = NULL;
    PSS pNew;
    PSS pc_1 = ph_1->pNext;
    PASMS pc = ph->pNext;
    int i;
    while(pc!=NULL)
    {
        i = 0;
        while(pc_1!=NULL)
        {
            if(strcmp(pc->style, pc_1->string)==0)//如果有相同的
            {
                i = 1;
                break;
            }
            pc_1 = pc_1->pNext;
        }
        if(i==0)
        {
            pNew = (PSS)malloc(sizeof(SS));
            pNew->count = 0;
            strcpy(pNew->string, pc->style);
            //头插
            pNew->pNext = ph_1->pNext;
            ph_1->pNext = pNew;
        }
        pc = pc->pNext;
    }
    return ph_1;
}

PSS get_statistic_data_material(PASMS ph)
{
    PSS ph_1 = (PSS)malloc(sizeof(SS));
    if(ph_1==NULL)
    {
        exit(-1);
    }
    ph_1->pNext = NULL;
    PSS pNew;
    PSS pc_1 = ph_1->pNext;
    PASMS pc = ph->pNext;
    int i;
    while(pc!=NULL)
    {
        i = 0;
        while(pc_1!=NULL)
        {
            if(strcmp(pc->material, pc_1->string)==0)//如果有相同的
            {
                i = 1;
                break;
            }
            pc_1 = pc_1->pNext;
        }
        if(i==0)
        {
            pNew = (PSS)malloc(sizeof(SS));
            pNew->count = 0;
            strcpy(pNew->string, pc->material);
            //头插
            pNew->pNext = ph_1->pNext;
            ph_1->pNext = pNew;
        }
        pc = pc->pNext;
    }
    return ph_1;
}

PSS_2 get_statistic_data_brand_supplier(PASMS ph)
{
    PSS_2 ph_1 = (PSS_2)malloc(sizeof(SS_2));
    if(ph_1==NULL)
    {
        exit(-1);
    }
    ph_1->pNext = NULL;
    PSS_2 pNew;
    PSS_2 pc_1 = ph_1->pNext;
    PASMS pc = ph->pNext;
    int i;
    while(pc!=NULL)
    {
        i = 0;
        while(pc_1!=NULL)
        {
            if(strcmp(pc->brand, pc_1->string_1)==0&&strcmp(pc->supplier, pc_1->string_2)==0)//如果有相同的
            {
                i = 1;
                break;
            }
            pc_1 = pc_1->pNext;
        }
        if(i==0)
        {
            pNew = (PSS_2)malloc(sizeof(SS_2));
            pNew->count = 0;
            strcpy(pNew->string_1, pc->brand);
            strcpy(pNew->string_2, pc->supplier);
            //头插
            pNew->pNext = ph_1->pNext;
            ph_1->pNext = pNew;
        }
        pc = pc->pNext;
    }
    return ph_1;
}