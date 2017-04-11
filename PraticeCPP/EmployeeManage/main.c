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
#include"LoginLog.h"
#include"Employee.h"
#include"LinkStack.h"
#include"Tools\memwatch.h"


#define FUN_EXIT      0
#define FUN_EMPLIST   1
#define FUN_ADDEMP    2
#define FUN_DELEMP    4
#define FUN_UPDATEEMP 3
#define FUN_SEAREMP    5


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
	printf("ID:%d,name:%s,pwd:%s,addtime:%ld\n",a1->ID, a1->Name, a1->PassWord,a1->AddTime);
}
/*
函数声明
*/
int SelectFunc();
int DoFunc(int funcid);
ListNode*  SearchEmployee(int idnum);
/*
函数声明结束
*/
int mycompare(void* data,void* data1)
{
	int sign = 0;
	Administrator* a1 = (Administrator*)data;
	Administrator* a2 = (Administrator*)data1;

	if (a1->ID > a2->ID)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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

int CompareEmp(void* data, void* data1)
{
	Employee* a1 = (Employee*)data;
	Employee* a2 = (Employee*)data1;

	if (a1->ID == a2->ID)
	{
		if (strcmp(a1->Address, a2->Address) == 0)
		{
			if (strcmp(a1->Name, a2->Name) == 0)
			{
				if (strcmp(a1->Born, a2->Born) == 0)
				{
					if (a1->Age== a2->Age)
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
int CompareEmpByID(void* data, void* data1)
{
	int sign = 0;
	Employee* a1 = (Employee*)data;
	Employee* a2 = (Employee*)data1;

	if (a1->ID==a2->ID)
	{
		return 1;
	}
		return 0;
}

void PrintEmployee(void* data)
{
	Employee* emp = (Employee*)data;
	printf("  %d  %s		%d	%s		%s\n", emp->ID, emp->Name, emp->Age, emp->Born, emp->Address);
	     //ID  姓名 年龄 生日 地址
}

int DoFunc(int funcid);



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
	InsertLinkList(list, HEADINSERT, &a3, sizeof(a3));//3
	InsertLinkList(list, TAILINSERT, &a4, sizeof(a4));//4
	InsertLinkList(list, HEADINSERT, &a5, sizeof(a5));//5
	InsertLinkList(list, TAILINSERT, &a6, sizeof(a6));//6

	
	/*Administrator* pa = (Administrator*)list->Tail->Data;
	RemoveNodeByValue(list, &a1,mycompare);
	TraverseLinList(list, myprintf);
	 pa = (Administrator*)list->Tail->Data;
	printf("taile name is:%s,pwd:%s,addtime:%ld\n", pa->Name, pa->PassWord,pa->AddTime);
	ClearLinkList(&list);*/

	TraverseLinList(list, myprintf);
	printf("-------------------------------------------------------------------------------------------------\n");

	ListBubbleSort(list, mycompare);

	TraverseLinList(list, myprintf);

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
int Login()
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
	if (islogin != 1)
	{
		printf("                              --------------------\n");
		printf("                              -      登陆失败    -\n");
		printf("                              --------------------\n");
	}
	else
	{
		memset(Name, 0, NAMELEN);
		memset(Pwd, 0, PWDLEN);
		WriteLoginLog(Name, time(&tm), LOGINSUCC);
	}
	


	return islogin;
}

//显示所有员工
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
//添加员工
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

void DelFunction()
{
	int IdNum = -1;
	
	while (IdNum<0)
	{
		printf("请输入员工ID,按0退出\n");
		scanf("%d", &IdNum);
		if (IdNum < 0)
		{
			printf("输入员工ID错误\n--------------------------\n");
		}
		if (IdNum == 0)
		{
			return;
		}
	}

	ListNode* node = SearchEmployee(IdNum);

	if (node == NULL)
	{
		printf("--------------------\n未找到该员工信息\n---------------------\n");
		return;
	}
	printf("\n确认按1，返回按0  ");
	scanf("%d", &IdNum);
	if (IdNum < 0||IdNum>1)
	{
		printf("\n输入错误\n");

		return;
	}
	if (IdNum == 0)
	{
		return;
	}

	int num = RemoveNodeByValue(list, node->Data, CompareEmp);

	if (num == 1)
	{
		printf("删除成功\n\n");
	}
	else
	{
		printf("删除失败\n\n");
	}

}

void UpdateFunction()
{
	int idnum = 0;
	printf("请输入员工ID号（0退出）\nID：");
	scanf("%d", &idnum);
	ListNode* find=NULL;
	
	while (idnum < 1)
	{
		if (idnum == 0)
		{
			return;
		}
		printf("输入错误，请重新输入\nID：");
		if (NULL == find)
		{
			printf("没有此ID号\n");
			idnum = 0;
		}
	}
	find = FindNodeByValue(list, &idnum, CompareEmpByID);
	Employee* emp = (Employee*)find->Data;
	printf("用户原数据为:\nID:%d\t姓名:%s\n年龄:%d\t生日:%s\n住址:%s\n",emp->ID,emp->Name,emp->Age,emp->Born,emp->Address);
	printf("确认更改 输入1，非1返回\n");
	scanf("%d", &idnum);
	if (idnum == 1)
	{
		printf("依次输入员工的姓名，年龄，生日，地址，以英文符逗号（,）间隔\n");
		char buf[1024] = { 0 };
		fflush(stdin);
		fgets(buf, 1024, stdin);
		char*sub;
		sub = strtok(buf, ",");
		if (sub != NULL)
		{
			strcpy(emp->Name, sub);
		}
		sub = strtok(NULL, ",");
		if (sub != NULL)
		{
			emp->Age = atoi(sub);
		}
		sub = strtok(NULL, ",");
		if (sub != NULL)
		{
			strcpy(emp->Born, sub);
		}
		sub = strtok(NULL, ",");
		if (sub != NULL)
		{
			sub[strlen(sub) - 1] = 0;
			strcpy(emp->Address, sub);
		}

		printf(" --------------------\n");
		printf("|------更改成功------|\n");
		printf("|-------------------|\n");
	}
}

//功能列表
void FunctionList()
{
	printf("                  ***********************************************\n");
	printf("                  *- 1 --查看员工列表          - 2 --增加员工   *\n");
	printf("                  *- 3 --更改员工              - 4 --删除员工   *\n");
	printf("                  *- 5 --查找员工              - 4 --退出系统   *\n");
	printf("                  ***********************************************\n\n");
}
//选择功能
int SelectFunc()
{
	int fun = -1;
	printf("选择操作\n");
	scanf("%d", &fun);
	printf("\n");
	return DoFunc(fun);
}

int FindEmployeeByID(void* data, void* data1)
{
	int sign = 0;
	Employee* emp = (Employee*)data1;

	int* id = (int*)data;
	if ((*id) == emp->ID)
	{
		sign = 1;
	}
	return sign;
}

//查找员工
ListNode* SearchEmployee(int idnum)
{
	
	ListNode* node = FindNodeByValue(list, &idnum, FindEmployeeByID);


	return node;
}

void SearchFunc()
{
	int idnum = 0;
	while (idnum < 1)
	{
		printf("请输入员工工号,按0退出\n");
		scanf("%d", &idnum);
		if (idnum < 0)
		{
			printf("员工工号错误，请重新输入\n--------------------------------\n");
		}
		if (idnum == 0)
		{
			return;
		}
	}

	ListNode* node= SearchEmployee(idnum);
	if (NULL == node)
	{
		printf("未找到该员工\n");
		return;
	}


	Employee* emp = (Employee*)node->Data;
	printf("用户数据为:\nID:%d\t姓名:%s\n年龄:%d\t生日:%s\n住址:%s\n", emp->ID, emp->Name, emp->Age, emp->Born, emp->Address);
}


//执行选择后的函数
int DoFunc(int funcid)
{
	int state = -1;
	switch (funcid)
	{
	case FUN_EMPLIST:
	{
						state = FUN_EMPLIST;
						ShowEmployeeList();
						break;
	}
	case FUN_ADDEMP:
	{
					   state = FUN_ADDEMP;
					   AddEmployee();
					   break;
	}
	case FUN_UPDATEEMP:
	{
						  UpdateFunction();
						  state = FUN_UPDATEEMP;
						  break;
	}
	case FUN_DELEMP:
	{
					   DelFunction();
					   state = FUN_DELEMP;
					   break;
	}
	case FUN_EXIT:
	{
					 time_t t;
					 WriteExitLog(CurrentAdmin.Name, time(&t));
					 system("cls");
					 ProgmExit();
					 state = FUN_EXIT;
					 // Login();
	}
	case FUN_SEAREMP:
	{
						SearchFunc();
						state = FUN_SEAREMP;
						break;
	}
		
	}

	return state;
}


int main()
{
	mwInit();
	ExitStack= Init_LinkStack();//初始化退出函数队列
	Push_LinkStack(ExitStack, ExitPfun);
	int islogin = 0;
	while (islogin!=1)
	{
		islogin=Login();//登陆
	}
    FunctionList();//登陆成功显示功能列表
	int state=SelectFunc();//选择功能
	while (state != FUN_EXIT)
	{
		FunctionList();
		state=SelectFunc();//选择功能
	}
	if (ExitStack != NULL)
	{
		Destroy_LinkStack(ExitStack);
	}
	mwTerm();
	system("pause");
	return EXIT_SUCCESS;
}