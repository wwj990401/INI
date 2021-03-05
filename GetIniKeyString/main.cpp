#include "GetIniKeyString.h"
#include <stdio.h>  
#include <stdlib.h>

int main()
{
	char buff[100];
	int ret;
	ret = GetIniKeyString("DOG", "sex", "config.ini", buff);
	printf("ret:%d,×Ö·û´®=%s\n", ret, buff);
	printf("ÕûÐÎ=%d\n", atoi(buff));
	return 0;
}