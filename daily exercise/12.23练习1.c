#include <stdio.h>

int Ack(int m, int n)
{
    if(m>0)
    {
        if(n==0)
        {
            return Ack(m-1, 1);
        }
        else
        {
            return Ack(m-1, Ack(m, n-1));
        }
        
    }
    else
    {
        return n-1;
    }
    

}

int f(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return f(n-1) + f(n-2);
}

double fn(double x, int n)
{
    if(n==1)
    {
        return x;
    }
    return fn(x, n-1) + pow(-1, n-1)* pow(x, n);
}

void dectobin( int n )
{
    if(n == 0)
        printf("0");
    else if(n == 1)
        printf("1");
    else{
        dectobin(n/2);//利用二进制的原理
        printf("%d", n%2);
    }
}

double fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n * f(n-1);
}

double factsum(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return fact(1);
    }
    return factsum(n-1) + fact(n);

}

double P(int n, double x)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return x;
    }
    return ((2*n-1)*P(n-1,x)-(n-1)*P(n-2,x))/n;
}

int sum(int n)
{
    if(n<=0)
    {
        return 0;
    }
    return sum(n-1) + n;
}

double calc_pow(double x, int n)
{
    if(n==0)
    {
        return 1;
    }
    return calc_pow(x, n-1) * x;
}

void printdigits(int n)
{
    if(n<10)
    {
        printf("%d\n", n);
        return;
    } 
    printdigits(n/10);
    printf("%d\n", n%10);
}

int search(int n)
{
    int x, temp, s = 0;
    int a, b, c;
    while(temp>=121)
    {
        x = sqrt(temp);
        a = temp / 100;
        b = (temp/10) % 10;
        c = temp % 10;
        if((x*x==temp)&&(a==b||a==c||b==c))
        {   
            s++;
        }
        temp--;
    }
    return s;
}