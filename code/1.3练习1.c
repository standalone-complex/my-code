#include<stdio.h>

int k=1;

void fun(int m)

{ 

 m+=k;

   k+=m;

  { 

char k='B';

    printf("%d,",k-'A');

  }

  printf("%d,%d",m,k);

}

int main(void)

{ 

int i=4;

  fun(i);

  printf("%d,%d",i,k);
    return 0;
}
