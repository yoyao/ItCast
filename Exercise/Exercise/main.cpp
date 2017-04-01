#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include"str_insert.h"
#include"southair.h"
#include"memwatch.h"
#include<io.h>
#include<direct.h>
#include<string>

using namespace std;

#pragma region MyRegion

union U_Aa
{
	unsigned int i;
	char x[2];
};

U_Aa a;
#define TONAME(x) y##x//双#是连接参数和其他数据
#define TESTT(y) #y//字符串化
#define BUFFSIZE 256
#define NAMETOSTR(x) #x
#define ADDRTOSTR(x)  "arr"#x


#pragma endregion

#ifdef SIZE
#undef SIZE
#endif

char* str_str_(char source[], char search[])
{
	while (*source)
	{
		char* tmp = source;
		while (*search && *tmp&&!(*tmp - *search))//重中之重 两个字符串都不能到最后 并且两个字符相减为0 就说明相等 加上!就可以进循环
		{
			++tmp;
			++search;
		}
		if (!*search)
		{
			return source;
		}
		source++;
	}


	return NULL;
}



int main01(int argc, char* argv[])
{

    #pragma region 指针*转int练习 内存的划分
    #if 0
	char str[200] = "wangfang love  money  love  sunshine h";
	char s_search[] = "end";
	char s_Out[SIZE] = { 0 };

	int count = 569;
	int* pc = &count;
	a.x[0] = 10;
	a.x[1] = 1;
	a.i = 1;
	a.x[0] = 10;
	a.x[1] = 1;
	printf("a.i = %d\n", a.i);//266
	char* p_ua = (char*)&a;
	p_ua[2] = 1;
	printf("a.i = %d\n", a.i);//65802

	//StrInsert(str, "love", "haihua than.Love   love  haihua than");
	//StrAppendAtStr(str, "love", s_search,s_Out);
	//std::cout << s_Out << std::endl;

	// 牛哥让思考的
	/*
	int array[] = { 1, 2, 3, 4, 5 };
	int t = ((int)array + 1);
	int tt = (int)array;
	char* p_c = (char*)array;
	printf("%d\n",*p_c);

	char* p_c1 = (char*)array+1;
	printf("%d\n", *p_c1);

	int pt = (int)&array[1];
	int *p = (int *)((int)array + 1);
	int *p_two = (int*)((int)array + 4);
	printf("%x\n", *p);
	printf("%d\n", *p_two);
	*/
    #endif
    #pragma endregion
	time_t time_now;
	time(&time_now);
	srand(56);
	
	int TONAME(2) = 45;
	std::cout << TONAME(2) << std::endl;
	string str1=TESTT(gjd);//字符串化
	int r=rand();
	char buf[BUFFSIZE] = { " wangfang  like  money  like sunshine " };
	char result[BUFFSIZE];
	memset(result, 0, BUFFSIZE);

	StringReplace(buf,"like","love",result);
	r = rand();

	StrReplace(buf, "old", " ", result);
	assert(result != NULL);
	std::cout << result << std::endl;

	char res[BUFFSIZE] = { "58465.36895" };
	//strncpy(res, "5893.36",4);

	double  dou = StrToDouble(res);
	double df = 5.1 + 0.3;
	printf("%-0.8f\n", dou);
	std::cout << dou << std::endl;
	return EXIT_SUCCESS;
}


struct _person{
	char Name[13];
	//char* Name;
	int Age;
	char Address[17];
	//char* Address;
	double Score;
};

typedef struct _person Person;


//读写结构体 看看是否能对等读写
void WriteStruct()
{
	time_t time_;
	time(&time_);
	srand(time_);
	Person arr_person[10];
	for (int i = 0; i < 10; i++)
	{
    
     	memset(arr_person[i].Address, 0, 17);
		strcpy(arr_person[i].Address,"开发规划阿桑的歌");
		memset(arr_person[i].Name, 0, 13);
		strcpy(arr_person[i].Name, "过几天就如同");
		
		//arr_person[i].Address="阿里贷款机构拉";
		//arr_person[i].Name="房管局封口费";
		arr_person[i].Score = rand();
		arr_person[i].Age = rand() % 100;
	}

	FILE* file = fopen("f:\\struct.txt", "w");
	
	if (NULL == file)
	{
		printf("file open failed!\n");
		return;
	}
	//fwrite("啊跟旅客谨防啊老公会", 1, strlen("啊跟旅客谨防啊老公会"), file);

	fwrite(&arr_person, sizeof(arr_person), 1, file);
	

	fclose(file);

}



void ReadStruct()
{
	Person arr_person[10];

	FILE* file = fopen("f:\\struct.txt", "r");

	if (NULL == file)
	{
		printf("file open failed!\n");
		return;
	}
	fread(arr_person, sizeof(Person), 10, file);
	for (int i = 0; i < 10; i++)
	{
		//fread(&arr_person[i], sizeof(Person), 1, file);
		printf("name:%s,age:%d,score:%.2f,address:%s\n", arr_person[i].Name, arr_person[i].Age, arr_person[i].Score, arr_person[i].Address);
	}

	fclose(file);
}

int func(int x)//求x的二进制表示中有多少个1
{
	int countx = 0;
	while (x)
	{
		countx++;
		x = x&(x - 1);
	}
	return countx;
}

int main(int argc, char* argv[])
{
   // int a = 5;
	//unsigned int b = ~a;
	int arrb[6];
	int arrc[6][4];
	
	//WriteStruct();
	//ReadStruct();
	
	//scanf("%d%d", &a,&b);
	//KinsfolkNumber(a, b);
	//SumulateFormsClick();

#if 0

	int a[3][4] = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12
	};
	printf("%d\n", *(a[1]));
	printf("%d\n", *(&(a[0][0]) + 1));
	printf("%d\n", *(a[0] + 2));
	printf("%d\n", *(&a[1]+1)[-1]);
	printf("%d\n", (*a[0] + 2));
	
	//std::cout << *(a[0] + 5) << std::endl;
	//std::cout << *((a + 1)[1]) << "\n" << (a + 5) << std::endl;

	char mm[4][3] = { 
		"12",
		"34",
		"56",
		"78" }, *pn[4];
	int k, s = 0;
	for (k = 0; k<4; k++)
		pn[k] = mm[k];
	for (k = 1; k<4; k += 2)
		s = s * 10 + pn[k][1] - '0';
	printf("%d\n", s);
#endif // 0


	//int result = JieCheng(5);
	//JieChengNum(145);

	//LCS问题就是求两个字符串最长公共子串的问题
	char* substr= LCS("fdfljlkubbbbbbbeels","askdjglgbbbbbbbeelkjfi");
	std::cout << substr << std::endl;
	
	CompareStr("dfljlkuhelloel", "kdjglghellolkj");






	return EXIT_SUCCESS;
}