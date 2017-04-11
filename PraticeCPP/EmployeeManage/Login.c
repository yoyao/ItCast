#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include"Login.h"
#include"Tools\cJSON.h"
#include"MyTools.h"

extern void AddExitFun(void(*pfun)(void));

static FILE* FileAdmin = NULL;

#define BUFFSIZE 1024


void ExitFun(void)
{
	printf("admin 退出中....\n");
	if (FileAdmin != NULL)
	{
		fflush(FileAdmin);
		fclose(FileAdmin);
	}
}


int VerifyLogin(char* Name, char*Pwd, Administrator* admin)
{
	if (FileAdmin == NULL)
	{
		AddExitFun(ExitFun);//注册退出函数
		FileAdmin = fopen("./admin/admin.ls", "rb+");
	}
	
	if (FileAdmin == NULL)
	{
		return VERYERROR;
	}
	char buf[BUFFSIZE] = {0};

	while (!feof(FileAdmin))
	{
		fgets(buf, BUFFSIZE, FileAdmin);
		if (buf != NULL&&buf[0] != '\n'&&buf[0] != '#')
		{
			int i = strlen(buf);
			if (buf[i - 1] == '\n') //判断最后一行有没有回车符,windows上是\r\n 所以要减2
			{
				buf[i - 2] = 0;
			}
			StringTrim(buf, buf);//去除两段空格
			cJSON* json = cJSON_Parse(buf);//
			if (json != NULL)
			{
				cJSON* uname = cJSON_GetObjectItem(json, "UserName");
				cJSON* pwd = cJSON_GetObjectItem(json, "PassWord");
				if (strcmp(uname->valuestring, Name) == 0 && strcmp(pwd->valuestring, Pwd) == 0)
				{
					admin->AddTime = atof(cJSON_GetObjectItem(json, "RegTime")->valuestring);
					admin->ID = atoi(cJSON_GetObjectItem(json, "ID")->valuestring);
					strcpy(admin->Name,Name);
					strcpy(admin->PassWord, Pwd);
					rewind(FileAdmin);
					return 1;
				}
			}
		}
	}
	rewind(FileAdmin);
	return 1;
}

int LoginForm(char* Name, char* Pwd)
{
	/*char Name[NAMELEN];
	char Pwd[PWDLEN];*/
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("=================================================================================================\n");
	printf("                                 用户名：");
	scanf("%s", Name);
	printf("                                 密  码：");
	
	int count = 0;
	while (count<16)//循环输入密码
	{
		int ch = _getch();
		if (ch == 13)
		{
			break;
		}
		Pwd[count++] = ch;
		putc('*', stdout);
	}
	Pwd[count] = '\0';
	printf("\n=================================================================================================\n");
	return VerifyLogin(Name, Pwd, &CurrentAdmin);
}


