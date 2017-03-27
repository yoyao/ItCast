#define _CRT_SECURE_NO_WARNINGS



#include<iostream>
#include"str_insert.h"

using namespace std;

char * __cdecl str_str(const char * str1,const char * str2)
{
	char *cp = (char *)str1;
	char *s1, *s2;

	if (!*str2)
		return((char *)str1);

	while (*cp)
	{
		s1 = cp;
		s2 = (char *)str2;

		while (*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;

		if (!*s2)
			return(cp);

		cp++;
	}

	return(NULL);

}
int main(int argc, char* argv[])
{
	char str[200] = "wangfang love  money  love  sunshine ";
	
	//StrInsert(str, "love", "haihua than.Love   love  haihua than");

	//std::cout << str_str(str,"love") << std::endl;


	int array[] = { 1, 2, 3, 4, 5 };
	int t = ((int)array + 1);
	int tt = (int)array;
	int pt = (int)&array[1];
	int *p = (int *)((int)array + 1);
	printf("%x\n", *p);

	return EXIT_SUCCESS;
}