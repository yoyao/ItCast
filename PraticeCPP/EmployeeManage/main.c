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
��������
*/
int SelectFunc();
int DoFunc(int funcid);
ListNode*  SearchEmployee(int idnum);
/*
������������
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
	     //ID  ���� ���� ���� ��ַ
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

//ִ��ע����˳������б�
void ProgmExit()
{
	while (Size_LinkStack(ExitStack)>0)
	{
		void(*fun)(void) = Top_LinkStack(ExitStack);
		fun();
		Pop_LinkStack(ExitStack);
	}
}
//�������˳��ĺ���
void ExitPfun(void)
{
	printf("main prg exit....\n");
	if (list != NULL)
	{
		DestroyLinkList(&list);
	}
	
}
 //��½����
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
		printf("                              -      ��½ʧ��    -\n");
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

//��ʾ����Ա��
void ShowEmployeeList()
{
	printf("  ##################################################\n\n");
	printf("  ID  ����		����	 ����	                               ��ַ\n");
	if (list == NULL)
	{
		list = GetEmployeeList();
	}
	TraverseLinList(list, PrintEmployee);
	printf("  ##################################################\n\n");
}
//���Ա��
void AddEmployee()
{
	printf("��������Ա����ID�����������䣬���գ���ַ����Ӣ�ķ����ţ�,�����\n");
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
		strcpy(em.Name, sub);//����
		sub = strtok(NULL, ",");
		em.Age = atoi(sub);//����
		sub = strtok(NULL, ",");
	    strcpy(em.Born, sub);//����
		sub = strtok(NULL, ",");
		strcpy(em.Address, sub);//��ַ
		printf("ȷ�������1��ӣ�0����\n");
		int sign = 0;
		scanf("%d", &sign);
		if (sign == 1)
		{
			int s=InsertLinkList(list, TAILINSERT, &em, sizeof(Employee));
			if (s == 1)
			{
				WriteEmployeeList(list);
				printf("+++++++++++++++++\n");
				printf("+++++��ӳɹ�++++\n");
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
		printf("������Ա��ID,��0�˳�\n");
		scanf("%d", &IdNum);
		if (IdNum < 0)
		{
			printf("����Ա��ID����\n--------------------------\n");
		}
		if (IdNum == 0)
		{
			return;
		}
	}

	ListNode* node = SearchEmployee(IdNum);

	if (node == NULL)
	{
		printf("--------------------\nδ�ҵ���Ա����Ϣ\n---------------------\n");
		return;
	}
	printf("\nȷ�ϰ�1�����ذ�0  ");
	scanf("%d", &IdNum);
	if (IdNum < 0||IdNum>1)
	{
		printf("\n�������\n");

		return;
	}
	if (IdNum == 0)
	{
		return;
	}

	int num = RemoveNodeByValue(list, node->Data, CompareEmp);

	if (num == 1)
	{
		printf("ɾ���ɹ�\n\n");
	}
	else
	{
		printf("ɾ��ʧ��\n\n");
	}

}

void UpdateFunction()
{
	int idnum = 0;
	printf("������Ա��ID�ţ�0�˳���\nID��");
	scanf("%d", &idnum);
	ListNode* find=NULL;
	
	while (idnum < 1)
	{
		if (idnum == 0)
		{
			return;
		}
		printf("�����������������\nID��");
		if (NULL == find)
		{
			printf("û�д�ID��\n");
			idnum = 0;
		}
	}
	find = FindNodeByValue(list, &idnum, CompareEmpByID);
	Employee* emp = (Employee*)find->Data;
	printf("�û�ԭ����Ϊ:\nID:%d\t����:%s\n����:%d\t����:%s\nסַ:%s\n",emp->ID,emp->Name,emp->Age,emp->Born,emp->Address);
	printf("ȷ�ϸ��� ����1����1����\n");
	scanf("%d", &idnum);
	if (idnum == 1)
	{
		printf("��������Ա�������������䣬���գ���ַ����Ӣ�ķ����ţ�,�����\n");
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
		printf("|------���ĳɹ�------|\n");
		printf("|-------------------|\n");
	}
}

//�����б�
void FunctionList()
{
	printf("                  ***********************************************\n");
	printf("                  *- 1 --�鿴Ա���б�          - 2 --����Ա��   *\n");
	printf("                  *- 3 --����Ա��              - 4 --ɾ��Ա��   *\n");
	printf("                  *- 5 --����Ա��              - 4 --�˳�ϵͳ   *\n");
	printf("                  ***********************************************\n\n");
}
//ѡ����
int SelectFunc()
{
	int fun = -1;
	printf("ѡ�����\n");
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

//����Ա��
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
		printf("������Ա������,��0�˳�\n");
		scanf("%d", &idnum);
		if (idnum < 0)
		{
			printf("Ա�����Ŵ�������������\n--------------------------------\n");
		}
		if (idnum == 0)
		{
			return;
		}
	}

	ListNode* node= SearchEmployee(idnum);
	if (NULL == node)
	{
		printf("δ�ҵ���Ա��\n");
		return;
	}


	Employee* emp = (Employee*)node->Data;
	printf("�û�����Ϊ:\nID:%d\t����:%s\n����:%d\t����:%s\nסַ:%s\n", emp->ID, emp->Name, emp->Age, emp->Born, emp->Address);
}


//ִ��ѡ���ĺ���
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
	ExitStack= Init_LinkStack();//��ʼ���˳���������
	Push_LinkStack(ExitStack, ExitPfun);
	int islogin = 0;
	while (islogin!=1)
	{
		islogin=Login();//��½
	}
    FunctionList();//��½�ɹ���ʾ�����б�
	int state=SelectFunc();//ѡ����
	while (state != FUN_EXIT)
	{
		FunctionList();
		state=SelectFunc();//ѡ����
	}
	if (ExitStack != NULL)
	{
		Destroy_LinkStack(ExitStack);
	}
	mwTerm();
	system("pause");
	return EXIT_SUCCESS;
}