
#include"Employee.h"

static FILE* FileEmp = NULL;
extern void AddExitFun(void(*pfun)(void));



void Exit_Fun(void)
{
	printf("emp exit funtion...\n");
	if (FileEmp != NULL)
	{
		fflush(FileEmp);
		fclose(FileEmp);
	}
}


LinkList* GetEmployeeList()
{
	if (FileEmp == NULL)
	{
		AddExitFun(Exit_Fun);
		FileEmp = fopen("./employee/employee.ls", "rb+");
	}
	if (FileEmp == NULL)
	{
		return NULL;
	}

	LinkList*list=InitLinkList();

	while (!feof(FileEmp))
	{
		char buf[1024] = {0};
		fgets(buf, 1024, FileEmp);
		size_t len = strlen(buf);
		if (buf != NULL&&buf[0] != '#'&&buf[0] != '\n'&&buf[0] != '\r'&&buf[0] != EOF&&len>0)
		{
			StringTrim(buf, buf);
			if (buf[len - 2] == '\r' )
			{
				buf[len - 2] = 0;
			}
			if (buf[len - 1] == '\n')
			{
				buf[len - 1] = 0;
			}
			cJSON* json = cJSON_Parse(buf);
			if (NULL != json)
			{
				Employee* emp = (Employee*)calloc(1, sizeof(Employee));
				cJSON * tmp = cJSON_GetObjectItem(json, "Address");
				strcpy(emp->Address, tmp->valuestring);//地址
				tmp = cJSON_GetObjectItem(json, "Name");
				strcpy(emp->Name, tmp->valuestring);//名字
				tmp = cJSON_GetObjectItem(json, "Age");
				emp->Age = atoi(tmp->valuestring);//年龄
				tmp = cJSON_GetObjectItem(json, "ID");
				emp->ID = atoi(tmp->valuestring);//ID
				tmp = cJSON_GetObjectItem(json, "Born");
				strcpy(emp->Born, tmp->valuestring);//地址
				InsertLinkList(list, TAILINSERT, emp, sizeof(Employee));
			}

		}
	}
	rewind(FileEmp);

	return list;
}


int WriteEmployeeList(LinkList* list)
{
	int sig = 0;
	if (NULL == list)
	{
		return -1;
	}
	if (FileEmp == NULL)
	{
		AddExitFun(Exit_Fun);
		FileEmp = fopen("./employee/employee.ls", "rb+");
	}
	ListNode* node = list->Header.Next;

	while (node !=NULL)
	{
		Employee * emp = (Employee *)node->Data;
		fprintf(FileEmp, "{\"ID\":\"%d\",\"Name\":\"%s\",\"Born\":\"%s\",\"Age\":\"%d\",\"Address\":\"%s\"}\n",emp->ID,emp->Name,emp->Born,emp->Age,emp->Address);
		node = node->Next;
		++sig;
	}
	rewind(FileEmp);
	return sig;

}

