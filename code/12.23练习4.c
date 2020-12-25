#include <stdio.h>

//void output(int);

int main()
{
    int n;
    scanf("%d", &n);
    //output(n);
    printf("%d = %d + %d*10 + %d*100", n, n%10, (n/10)%10, n/100);
    return 0; // return
}

void output(int n)
{
    if(n<10)
    {
        printf("%d", n);
        return;
    }
    output(n/10);
    printf(" + %d", n%10);
}