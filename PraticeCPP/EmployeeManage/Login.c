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
	printf("admin �˳���....\n");
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
		AddExitFun(ExitFun);//ע���˳�����
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
			if (buf[i - 1] == '\n') //�ж����һ����û�лس���,windows����\r\n ����Ҫ��2
			{
				buf[i - 2] = 0;
			}
			StringTrim(buf, buf);//ȥ�����οո�
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
	return 0;
}

int LoginForm(char* Name, char* Pwd)
{
	/*char Name[NAMELEN];
	char Pwd[PWDLEN];*/
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("=================================================================================================\n");
	printf("                                 �û�����");
	scanf("%s", Name);
	printf("                                 ��  �룺");
	
	int count = 0;
	while (count<16)//ѭ����������
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


