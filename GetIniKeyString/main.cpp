#include "GetIniKeyString.h"
#include <stdio.h>  
#include <stdlib.h>

int main()
{
	char buff[100];
	int ret;
	ret = GetIniKeyString("DOG", "sex", "config.ini", buff);
	printf("ret:%d,�ַ���=%s\n", ret, buff);
	printf("����=%d\n", atoi(buff));
	return 0;
}