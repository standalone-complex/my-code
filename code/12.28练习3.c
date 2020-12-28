#include <stdio.h>
#include <stdlib.h>

typedef struct complex{
    double real;
    double imag;
}COMP, *PCOMP;

void left(double, double);//and she is real human  how is she when she doesn't surf?
void right(double, double);

int main()
{
    COMP C1, C2;
    scanf("%lf %lf %lf %lf", &C1.real, &C1.imag, &C2.real, &C2.imag);
    //和
    double sum1_real = C1.real +C2.real;
    double sum1_imag = C1.imag +C2.imag;
    //差 let tell you some how try Another signed at my confition into a blind the longer I'd 
    //into the fire .....burning to the house
    //made in heaven made in heaven
    double sum2_real = C1.real - C2.real;
    double sum2_imag = C1.imag - C2.imag;
    //积
    //Gotta knock a litter harder...
    double sum3_real = C1.real * C2.real - C1.imag * C2.imag;
    double sum3_imag = C1.imag * C2.real + C1.real * C2.imag;
    //kimieto
    //fugaifugaimorinonaka~~~
    //I belong to you~
    //You belong to me~
    //sayonarayienakude~
    //商
    //kanaximiwa~
    //sagexideyuku
    //you can change the destiny tokinomukoo
    //you can change the futrue yaminomukoo~
    double sum4_real = (C1.real * C2.real + C1.imag * C2.imag)/(C2.real * C2.real + C2.imag * C2.imag);
    double sum4_imag = (C1.imag * C2.real - C1.real * C2.imag)/(C2.real * C2.real + C2.imag * C2.imag);
    //everybody wants to sell they already been sold
    //everybode wamts to tell they already been told~
    //All that glitters ain't gold !
    //和
    left(C1.real, C1.imag);
    printf(" + ");
    left(C2.real, C2.imag);
    printf(" = ");
    right(sum1_real, sum1_imag);
    //差
    left(C1.real, C1.imag);
    printf(" - ");
    left(C2.real, C2.imag);
    printf(" = ");
    right(sum2_real, sum2_imag);
    //积
    left(C1.real, C1.imag);
    printf(" * ");
    left(C2.real, C2.imag);
    printf(" = ");
    right(sum3_real, sum3_imag);
    //商
    left(C1.real, C1.imag);
    printf(" / ");
    left(C2.real, C2.imag);
    printf(" = ");
    right(sum4_real, sum4_imag);
    return 0;
}


void left(double x,double y)		//负责打印式子
{
	if(y<0)							//虚部为负数的时候不用加'+'号
		printf("(%.1lf%.1lfi)",x,y);
	else
		printf("(%.1lf+%.1lfi)",x,y);	//反之成立
        return;
}
void right(double rshi,double rxu)
{	
	//虚部不存在时，只需输出实部
	if(rxu<=0.05&&rxu>=-0.05)	//其实这里也判断了两段都没有的情况，输出0.0
		printf("%.1lf\n",rshi);
	else if(rshi<=0.05&&rshi>=-0.05)	//实部不存在时，输出虚部单个即可
		printf("%.1lfi\n",rxu);
	else if(rxu<0)
		printf("%.1lf%.1lfi\n",rshi,rxu);	//结果虚部为负数的时候不用加'+'号
	else
		printf("%.1lf+%.1lfi\n",rshi,rxu);	//反之成立
        return;
}
