#include "GetIniKeyString.h"
#include <stdio.h>  
#include <string.h>

int GetIniKeyString(char *title, char *key, char *filename, char *buf)
{
	FILE *fp;
	int  flag = 0;
	char sTitle[64], *wTmp;
	char sLine[1024];
	sprintf(sTitle, "[%s]", title);

	if (NULL == (fp = fopen(filename, "r")))
	{
		perror("fopen");
		return -1;
	}
	while (NULL != fgets(sLine, 1024, fp))
	{
		if (0 == strncmp("//", sLine, 2)) continue;
		if ('#' == sLine[0])              continue;
		wTmp = strchr(sLine, '=');
		if ((NULL != wTmp) && (1 == flag))
		{
			if (0 == strncmp(key, sLine, strlen(key)))
			{
				sLine[strlen(sLine) - 1] = '\0';
				fclose(fp);
				while (*(wTmp + 1) == ' ')
				{
					wTmp++;
				}
				strcpy(buf, wTmp + 1);
				return 0;
			}
		}
		else
		{
			if (0 == strncmp(sTitle, sLine, strlen(sTitle)))
			{
				flag = 1;
			}
		}
	}
	fclose(fp);
	return -1;
}