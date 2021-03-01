#include <stdio.h>
#include <stdlib.h>

typedef struct tyf{
    char name[20];
    char birth[20];
    char sex;
    char guhua[20];
    char phone[20];
}TYF, *PTYF;

int main()
{
    int n, i, k;
    scanf("%d", &n);
    PTYF p = (PTYF)malloc(sizeof(TYF) * n);
    for(i=0; i<n; i++)
    {
        scanf("%s %s %c %s %s", p[i].name, p[i].birth, &p[i].sex, p[i].guhua, p[i].phone);
    }
    scanf("%d", &k);
    int* tokens = (int*)malloc(sizeof(int) * k);
    for(i=0; i<k; i++)
    {
        scanf("%d", tokens + i);
    }
    
    for(i=0; i<k; i++)
    {
        if(tokens[i]>=0&&tokens[i]<n)
        {
            printf("%s %s %s %c %s\n", p[tokens[i]].name, p[tokens[i]].guhua, p[tokens[i]].phone, p[tokens[i]].sex, p[tokens[i]].birth);
        }
        else
        {
            printf("Not Found\n");
        }
    }
    return 0;
}