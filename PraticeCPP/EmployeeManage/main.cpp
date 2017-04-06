#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include"LinkList.h"
#include"Administrator.h"


void myprintf(void* data)
{

}

void testlist()
{
	LinkList* list = InitLinkList();
	Administrator a1 = {1,"admin","123456"};
	Administrator a2 = { 2, "admin1", "1234567" };
	Administrator a3 = { 3, "admin2", "1234568" };
	Administrator a4 = { 4, "admin3", "1234569" };
	Administrator a5 = { 5, "admin4", "1234560" };
	Administrator a6 = { 6, "admin5", "1234561" };
}

void Login()
{
	char Name[64];
	char Pwd[64];
	printf("==================\n用户名：");
	scanf("%s", Name);
	printf("==================\n密码：");
	int count=0;
	while (count<16)
	{
		int ch = _getch();
		if (ch == 13)
		{
			break;
		}
		Pwd[count++]=ch;
		putc('*', stdout);
	}
	Pwd[count] = '\0';
	printf("\n==================\n");
	printf("用户名：%s,密码：%s\n",Name,Pwd);
}

int main()
{

	printf("-------------------------------------------------------------------------------------------------\n");
	printf("-*-------------*-----***------*----------*****-------****--------*--------*----------***---------\n");
	printf("--*-----------*----*------*---*---------*-----------*----*------*-*------*-*-------*------*------\n");
	printf("---*----*----*----*********---*--------*------------*----*-----*---*----*---*-----*********-----\n");
	printf("----*--*-*--*-----*-----------*--------*------------*----*----*-----*--*-----*----*--------------\n");
	printf("-----*----*-------*********---*******---*******------****----*-------*--------*---*********------\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	
	
	Login();

	system("pause");
	return EXIT_SUCCESS;
}