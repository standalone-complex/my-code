#include <stdio.h>

int main(){
    long num=1;
    while(num++ > 0) for(long i=num; i >=0; i--)printf("i :=\n \t %ld \n" , i);
    return 0;
}