#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include"LinkList.h"
#include"Administrator.h"
#include"Login.h"
#include"Tools\memwatch.h"
#include"LoginLog.h"
#include"Employee.h"
#include"LinkStack.h"

#define FUN_EXIT      0
#define FUN_EMPLIST   1
#define FUN_ADDEMP    2
#define FUN_UPDATEEMP 3
#define FUN_DELEMP    4

static LinkStack ExitStack;
extern Administrator CurrentAdmin;
extern  LinkList* list;

void AddExitFun(void(*pfun)(void))
{
	Push_LinkStack(ExitStack, pfun);
}

void myprintf(void* data)
{
	Administrator* a1 = (Administrator*)data;
	printf("name:%s,pwd:%s,addtime:%ld\n", a1->Name, a1->PassWord,a1->AddTime);
}

int mycompare(void* data,void* data1)
{
	int sign = 0;
	Administrator* a1 = (Administrator*)data;
	Administrator* a2 = (Administrator*)data1;
	if (a1->AddTime == a2->AddTime)
	{
		if (a1->ID == a2->ID)
		{
			if (strcmp(a1->Name, a2->Name) == 0)
			{
				if (strcmp(a1->PassWord, a2->PassWord) == 0)
				{
					sign = 1;
				}
			}
		}
	}
	return sign;
}

void PrintEmployee(void* data)
{
	Employee* emp = (Employee*)data;
	printf("  %d  %s		%d	%s		%s\n", emp->ID, emp->Name, emp->Age, emp->Born, emp->Address);
	     //ID  姓名 年龄 生日 地址
}
void testlist()
{
	time_t tm;
	LinkList* list = InitLinkList();
	Administrator a1 = { 1, "admin1", "0123456" ,time(&tm)};
	Administrator a2 = { 2, "admin2", "1234567", time(&tm) };
	Administrator a3 = { 3, "admin3", "1234568", time(&tm) };
	Administrator a4 = { 4, "admin4", "1234569", time(&tm) };
	Administrator a5 = { 5, "admin5", "1234560", time(&tm) };
	Administrator a6 = { 6, "admin6", "1234561", time(&tm) };
	InsertLinkList(list, TAILINSERT, &a1, sizeof(a1));//1
	InsertLinkList(list, TAILINSERT, &a2, sizeof(a2));//2
	InsertLinkList(list, TAILINSERT, &a3, sizeof(a3));//3
	InsertLinkList(list, TAILINSERT, &a4, sizeof(a4));//4
	InsertLinkList(list, TAILINSERT, &a5, sizeof(a5));//5
	InsertLinkList(list, TAILINSERT, &a6, sizeof(a6));//6

	TraverseLinList(list, myprintf);

	
	printf("-------------------------------------------------------------------------------------------------\n");
	Administrator* pa = (Administrator*)list->Tail->Data;
	RemoveNodeByValue(list, &a1,mycompare);
	TraverseLinList(list, myprintf);
	 pa = (Administrator*)list->Tail->Data;
	printf("taile name is:%s,pwd:%s,addtime:%ld\n", pa->Name, pa->PassWord,pa->AddTime);
	ClearLinkList(&list);
	DestroyLinkList(&list);
}

//执行注册的退出函数列表
void ProgmExit()
{
	while (Size_LinkStack(ExitStack)>0)
	{
		void(*fun)(void) = Top_LinkStack(ExitStack);
		fun();
		Pop_LinkStack(ExitStack);
	}
}
//主程序退出的函数
void ExitPfun(void)
{
	printf("main prg exit....\n");
	if (list != NULL)
	{
		DestroyLinkList(&list);
	}
}
 //登陆方法
void Login()
 {
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("-*-------------*-----***------*----------*****-------****--------*--------*----------***---------\n");
	printf("--*-----------*----*------*---*---------*-----------*----*------*-*------*-*-------*------*------\n");
	printf("---*----*----*----*********---*--------*------------*----*-----*---*----*---*-----*********-----\n");
	printf("----*--*-*--*-----*-----------*--------*------------*----*----*-----*--*-----*----*--------------\n");
	printf("-----*----*-------*********---*******---*******------****----*-------*--------*---*********------\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	char Name[NAMELEN];
	char Pwd[PWDLEN];
	int islogin = 0;
	time_t tm;
	islogin = LoginForm(Name, Pwd);
	while (islogin == 0)
	{
		printf("                              --------------------\n");
		printf("                              -      登陆失败    -\n");
		printf("                              --------------------\n");
		WriteLoginLog(Name, time(&tm), LOGINFAIL);
		memset(Name, 0, NAMELEN);
		memset(Pwd, 0, PWDLEN);
		islogin = LoginForm(Name, Pwd);
		int a = 89;
	}
	WriteLoginLog(Name, time(&tm), LOGINSUCC);

 }
//功能列表
void FunctionList()
{
	printf("***********************************************\n");
	printf("*- 1 --查看员工列表          - 2 --增加员工   *\n");
	printf("*- 3 --更改员工              - 4 --删除员工   *\n");
	printf("*- 0 --退出	                              *\n");
	printf("***********************************************\n\n");
}

void ShowEmployeeList()
{
	printf("  ##################################################\n\n");
	printf("  ID  姓名		年龄	 生日	                               地址\n");
	if (list == NULL)
	{
		list = GetEmployeeList();
	}
	TraverseLinList(list, PrintEmployee);
	printf("  ##################################################\n\n");
}
void AddEmployee()
{
	printf("依次输入员工的ID，姓名，年龄，生日，地址，以英文符逗号（,）间隔\n");
	char buf[1024] = { 0 };
	fflush(stdin);
	//gets(buf);
	fgets(buf, 1024, stdin);
	size_t len=strlen(buf);
	if (len > 0)
	{
		buf[len - 1] = 0;
	}
	Employee em;
	if (buf != NULL && len > 0)
	{
		char* sub = strtok(buf, ",");
		em.ID = atoi(sub);//ID
		sub = strtok(NULL, ",");
		strcpy(em.Name, sub);//名字
		sub = strtok(NULL, ",");
		em.Age = atoi(sub);//年龄
		sub = strtok(NULL, ",");
	    strcpy(em.Born, sub);//生日
		sub = strtok(NULL, ",");
		strcpy(em.Address, sub);//地址
		printf("确认无误后按1添加，0返回\n");
		int sign = 0;
		scanf("%d", &sign);
		if (sign == 1)
		{
			int s=InsertLinkList(list, TAILINSERT, &em, sizeof(Employee));
			if (s == 1)
			{
				WriteEmployeeList(list);
				printf("+++++++++++++++++\n");
				printf("+++++添加成功++++\n");
				printf("+++++++++++++++++\n");
			}
		}
		
	}
}
void SelectFunc()
{
	int fun = -1;
	printf("选择操作\n");
	scanf("%d", &fun);
	printf("\n");
	switch (fun)
	{
	case FUN_EMPLIST:
	{
						ShowEmployeeList();
						break;
	}
	case FUN_ADDEMP:
	{
					   AddEmployee();
					   break;
	}
	case FUN_UPDATEEMP:
	{

	}
	case FUN_DELEMP:
	{

	}
	case FUN_EXIT:
	{
					 time_t t;
					 WriteExitLog(CurrentAdmin.Name, time(&t));
					 system("cls");
					 ProgmExit();
					 Login();
	}
	default:
		SelectFunc();
	}
	SelectFunc();
}

int main()
{
	ExitStack= Init_LinkStack();//初始化退出函数队列
	Push_LinkStack(ExitStack, ExitPfun);
	mwInit();
	Login();//登陆
    FunctionList();//登陆成功显示功能列表
	SelectFunc();//选择功能
	mwTerm();
	system("pause");
	return EXIT_SUCCESS;
}