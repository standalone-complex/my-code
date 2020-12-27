#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,day,x;
    char *date[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char str[10000];

    scanf("%d",&x);
    for(day=1;day<=x;day++)
    {
        scanf("%s",str);
    for( i=0;i<7;i++ )
        if ( !strcmp( date[i] , str ) )
            break ;
        if ( i >= 7 )
            printf("-1\n");
        else
            printf("%d\n" , i+1 );
    }
    return 0;
}

