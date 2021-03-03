#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main()
{
	char password[10] = {0};
	int i = 0;
	
	char ch;
	
	struct termios oldt,newt;
	
	while(1)
	{
		tcgetattr(STDIN_FILENO,&oldt);
		newt = oldt;
		
		newt.c_lflag &= ~(ECHO | ICANON);
		
		tcsetattr(STDIN_FILENO,TCSANOW,&newt);
		
		ch = getchar();
		
		if(ch == '\n')
		{
			password[10] = '\0';
			tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
			break;
		}
		
		password[i] = ch;
		i++;
		
		tcsetattr(STDIN_FILENO,TCSANOW,&oldt);//每次输入一个字符后恢复回显状态
		printf("*");
	}
	
    printf("%s", password);
	return 0;
}