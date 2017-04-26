
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

using namespace std;


class Single
{
public:
	static Single* GetInstance()
	{
		return Instance;
	}
private:
	Single(const Single& s)
	{

	}
	Single()
	{

	}
static Single* Instance;

};

Single* Single::Instance=new Single;

/*
1.	 传入一个字符串，
1求出该字符串中字符的个数<重复字符不计入个数>
2出现频次最高的字符
若有多个相同的字符备选,返回其中最早出现的字符
函数原型：
(1)int   getCountOfString(const char *str);
int getCountOfString1(const char *str,int *count);

char  getMostCharFromString(const char *str);
char  getMostCharFromString1(const char *str,char * chr);
*/


void StrSort(char* str)
{
	if (str == NULL)
	{
		return;
	}
	size_t len = strlen(str);
	
	for (size_t i = 0; i < len; ++i)
	{
		int index = i;
		for (size_t j = i + 1; j < len; ++j)
		{
			if (str[index] > str[j])
			{
				index = j;
			}
		}
		char tmp = str[i];
		str[i] = str[index];
		str[index] = tmp;
	}




}


// 计算字符个数
int CalcuCharCount(char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	size_t len = strlen(str);
	char* p_assist = (char*)calloc(len + 1, sizeof(char));
	memcpy(p_assist, str, len + 1);

	StrSort(p_assist);

	int count = 0;
	char pre = '\0';
	for (size_t j = 0; j < len; ++j)
	{
		if (pre != p_assist[j] && (p_assist[j]<'0'||p_assist[j]>'9'))
		{
			++count;
			pre = p_assist[j];
		}
		
	}
	if (p_assist != NULL)
	{
		free(p_assist);
	}
	return count;
}

//最多的字符
char  GetMostCharFromString(const char *str)
{
	if (str == NULL)
	{
		return 0;
	}
	
	size_t len = strlen(str);
	if (len == 1)
	{
		return *str;
	}
	
	char* p_assist = (char*)calloc(len + 1, sizeof(char));
	memcpy(p_assist, str, len + 1);

	StrSort(p_assist);

	char ret ;
	int ccount = 0;
	char pre = '\0';
	for (size_t i = 0; i < len; ++i)
	{
		int t_cout = 0;
		for (size_t j = i + 1; j < len && (p_assist[i] == p_assist[j]); ++j)
		{
			++t_cout;
		}
		if (t_cout>ccount)
		{
			ccount = t_cout;
			ret = p_assist[i];
		}
	}
	if (p_assist != NULL)
	{
		free(p_assist);
	}
	return ret;
}




// 计算字符个数
int CalcuCharCountW(wchar_t* str)
{
	if (str == NULL)
	{
		return 0;
	}
	size_t len = wcslen(str);
	char* p_assist = (char*)calloc(len + 1, sizeof(char));


	memcpy(p_assist, str, len + 1);

	StrSort(p_assist);

	int count = 0;
	char pre = '\0';
	for (size_t j = 0; j < len; ++j)
	{
		if (pre != p_assist[j] && (p_assist[j]<'0' || p_assist[j]>'9'))
		{
			++count;
			pre = p_assist[j];
		}

	}
	if (p_assist != NULL)
	{
		free(p_assist);
	}
	return count;
}

//最多的字符
wchar_t  GetMostCharFromStringW(const char *str)
{
	if (str == NULL)
	{
		return 0;
	}

	size_t len = strlen(str);
	if (len == 1)
	{
		return *str;
	}

	char* p_assist = (char*)calloc(len + 1, sizeof(char));
	memcpy(p_assist, str, len + 1);

	StrSort(p_assist);

	char ret;
	int ccount = 0;
	char pre = '\0';
	for (size_t i = 0; i < len; ++i)
	{
		int t_cout = 0;
		for (size_t j = i + 1; j < len && (p_assist[i] == p_assist[j]); ++j)
		{
			++t_cout;
		}
		if (t_cout>ccount)
		{
			ccount = t_cout;
			ret = p_assist[i];
		}
	}
	if (p_assist != NULL)
	{
		free(p_assist);
	}
	return ret;
}

void VariablePram(int a, ...)
{
	va_list li;
	va_start(li,a);
	for (int i = 0; i < a; ++i)
	{
		printf("%d ", va_arg(li, int));
	}
	printf("\n");
}

typedef struct _tag_Student {

	char name[24];

	int age;

} Student;

typedef struct _listNode {

	Student *stu;

	struct _listNode *next;

}ListNode;


int GetStudentInfo(char *studentInfo, Student *stu)
{
	if (studentInfo == NULL || *studentInfo == '\n' || *studentInfo == '\0')
	{
		return -1;
	}
	if (strcmp(studentInfo, "\r\n") == 0)
	{
		return -1;
	}

	char* p_info = studentInfo;

	p_info = strchr(studentInfo, '=');
	++p_info;//跳过=
	while (p_info != NULL&&*p_info == ' ')
	{
		++p_info;
	}

	char* p_back = strchr(p_info, ' ');
	strncpy(stu->name, p_info, strlen(p_info) - strlen(p_back));

	p_info = strchr(p_info, '=');
	++p_info;//跳过=
	while (p_info != NULL&&*p_info == ' ')
	{
		++p_info;
	}
	p_back = strchr(p_info, ' ');
	if (p_back != NULL)
	{
		*p_back = 0;
	}

	stu->age = atoi(p_info);
	return 1;
}
void TestStudent()
{
	FILE* file = fopen("./student.txt","rb");
	if (file == NULL)
	{
		return;
	}

	char buf[1024] = { 0 };

	while (!feof(file))
	{
		fgets(buf, 1024, file);
		if (buf != NULL)
		{
			Student* stu = (Student*)calloc(1, sizeof(Student));
			GetStudentInfo(buf, stu);
			ListNode node;
		}
		memset(buf, 0, 1024);
	}





}


int main_exam(int argc, char* argv[])
{
	char buf[64] = { "fhddddadrfffaetw" };
	char han[] = { "aaabbbccc" };
	char han1[] = { "aaabbbccc" };
	int count = CalcuCharCount(buf);
	char ret = GetMostCharFromString(buf);
	cout << count << endl;
	cout << han << endl;
	
	cout << wcslen((wchar_t*)han1) << "  " << strlen(han) << endl;
	VariablePram(5,1,2,3,4,5);
	system("pause");
	return EXIT_SUCCESS;
}


