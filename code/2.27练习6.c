#include <stdio.h>

struct node {
    char a;
    int b;
    short c;
};
struct n {
    char a;
    int b;
};

int main(int argc, char* argv[])
{
    struct node a[2] = {{1,2,3},{4,5,6}};

    *(int *)((char *)a + 4) = 100;
    printf("%d\n%d\n%d", sizeof(struct node), sizeof(struct n), a[0].b);
    return 0;
}