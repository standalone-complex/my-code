#include<stdio.h>
double fact(int i);
double odd_multiple(int h);
int main()
{
	double eps,j=1,k=1,sum=1,PI;
	int i=1;
	scanf("%le",&eps);
		while(j/k>=eps){
			j=fact(i);
			k=odd_multiple(i+1);
			sum=sum+j/k;
            printf("%lf ", j/k);
			i++;
		}
	PI=2*sum;
	printf("PI = %.5lf",PI);
	return 0;
}
double fact(int i)
{ 
	double j=1;
	for(;i>1;i--)
		{
	j=j*i;
}
	return (j);
	}
double odd_multiple(int h)
{ 
	double k=1;
	for(;h>1;h--){
		k=k*(2*h-1);
	}
	return (k);
}