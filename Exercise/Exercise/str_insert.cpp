#define _CRT_SECURE_NO_WARNINGS
#include"str_insert.h"
/*
char str[200]=”wangfang love  money  love  sunshine ”,请在love后面插入haihua than.Love   love  haihua than
*/
int mystrstr(char source[], char search[])
{
	int index = 0;
	while (source[index] != '\0')
	{
		if (source[index] == search[0])
		{
			int t_index = index;
			int s_index = 0;
			for (s_index = 0; search[s_index] != '\0'; ++s_index)
			{
				if (search[s_index] != source[t_index])
				{
					break;
				}
				if (search[s_index+1] == '\0')
				{
					return index;
				}
				t_index++;
			}
		}
		++index;
	}
	return -1;
}







char* mystr_str_(char source[], char search[])
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



 char* _mystrstr_(char source[], char search[])
{
	int index = 0;
	char * p_tmp = source;
	while (source[index] != '\0')
	{
		if (source[index] == search[0])
		{
			int t_index = index;
			int s_index = 0;
			for (s_index = 0; search[s_index] != '\0'; ++s_index)
			{
				if (search[s_index] != source[t_index])
				{
					break;
				}
				if (search[s_index + 1] == '\0')
				{
					return source + index;
				}
				t_index++;
			}
		}
		++index;
	}
	return NULL;
}
//在一个字符串的某个字串后面追加字符串
void StrInsert(char source[], char search[],char insert[])
{
	 if (source != NULL&&search != NULL&&insert != NULL)
	{
		char* t_ptr = source;
		int index=mystrstr(source,search);//查找字符第一次出现的位置
		const char* ptr_ = _mystrstr_(source, search);
		size_t insert_len = strlen(insert);//插入字符串的长度
		size_t search_len = strlen(search);//查找字符串的长度
		size_t s_len = strlen(source);
		if(index > -1)
		{
			char* ptr = (char*)calloc(s_len, sizeof(char));
			strcpy(ptr, source + index + search_len);
			//ptr = source + index + search_len;
			memcpy((source + (index + search_len)), insert, insert_len);
			int t_len = strlen(source);
			strcat(source, ptr);
			if (ptr != NULL)
			{
				free(ptr);
				ptr = NULL;
			}
			StrInsert(source + t_len, search, insert);
		}
			
		
	}

}














void _StrInsert_(char source[], char search[], char insert[])
{
	char* pp = source;
	 const char* ptr = strstr(pp, search);

	if (source != NULL&&search != NULL&&insert != NULL&& ptr!=NULL)
	{
		char* t_ptr = source;
		int index = mystrstr(source, search);//查找字符第一次出现的位置
		const char* ptr_ = _mystrstr_(source, search);
		size_t insert_len = strlen(insert);//插入字符串的长度
		size_t search_len = strlen(search);//查找字符串的长度
		size_t s_len = strlen(source);
		sprintf(pp+s_len-insert_len+search_len,"%s",insert);
		sprintf(pp + search_len +insert_len, "%s", ptr);
		//StrInsert(source, search, insert);
		

	}

}