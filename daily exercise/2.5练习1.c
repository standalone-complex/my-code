#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"


int main(void)
{
    PTYF pHead = List_Create();
    /* List_Output(pHead);
    List_HeadAdd(pHead);
    List_Output(pHead);
    List_TailAdd(pHead);
    List_Output(pHead);
    List_Delete_1(pHead, 1);
    List_Output(pHead);
    List_Delete_2(pHead, 5);
    List_Output(pHead); */
    List_Output(pHead);
    List_Delete_2(pHead, 3);
    List_Output(pHead);
    return 0;
}