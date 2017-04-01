#define _CRT_SECURE_NO_WARNINGS
#include"str_insert.h"
/*
char str[200]=��wangfang love  money  love  sunshine ��,����love�������haihua than.Love   love  haihua than
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






//���ձ�׼C��д�� strstr
char* mystr_str_(char source[], char search[])
{
	while (*source)
	{
		char* tmp = source;
		while (*search && *tmp&&!(*tmp - *search))//����֮�� �����ַ��������ܵ���� ���������ַ����Ϊ0 ��˵����� ����!�Ϳ��Խ�ѭ��
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


//C��׼�⺯��
char * __cdecl str_str(const char * str1, const char * str2)
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

/*
s_In:�����ַ���
s_Append:����ַ�����
s_Search:�����ַ����ļ�Ҫ���ĸ��ַ��������
s_Out:������õ��Ľ�����ַ�����Ҫ�㹻����С�
*/
void  __cdecl  StrAppendAtStr(const char* s_In, const char* s_Search, const char* s_Append, char* s_Out)
{
	char* s_t_Out = s_Out;
	assert(s_In != NULL&&s_Search != NULL&&s_Append != NULL&&s_Out != NULL);

	char* s_substr = (char*)strstr(s_In, s_Search);

	size_t InLen = strlen(s_In);//�����ַ����ĳ���
	size_t AppendLen = strlen(s_Append);//����ַ����ĳ���
	size_t SearchLen = strlen(s_Search);//�����ַ����ĳ���
	size_t SubLen = strlen(s_substr);//���ҳ������ַ�������
	size_t index = 0;
	if (s_substr)
	{
		strncat(s_Out, s_In, (InLen - SubLen) + SearchLen);//׷���ҵ��ַ�����s_substr��ǰ����ַ���
		strncat(s_Out, s_Append, AppendLen);//׷��Ҫ׷�ӣ�s_Append�����ַ���
		index += ((InLen - SubLen) + SearchLen);
	}
	while (s_substr)
	{
		s_substr = (char*)strstr((s_substr + SearchLen), s_Search);
		if (s_substr)
		{
			size_t tmplen = strlen(s_substr);
			char* p = s_substr - (SubLen - tmplen - SearchLen);
			strncat(s_Out, p, (SubLen - tmplen));
			index += (SubLen - tmplen);
			SubLen = tmplen;
			strncat(s_Out, s_Append, AppendLen);//׷��Ҫ׷�ӣ�s_Append�����ַ���
		}
		else//Ϊ���� �͵ð�֮ǰ��substrȫ��׷����
		{
			strncat(s_Out, s_In + index, InLen - index);
		}

	}
}




//��һ���ַ�����ĳ���ִ�����׷���ַ��� ���˶�
void StrInsert(char source[], char search[],char insert[])
{
	 if (source != NULL&&search != NULL&&insert != NULL)
	{
		char* t_ptr = source;
		int index=mystrstr(source,search);//�����ַ���һ�γ��ֵ�λ��
		const char* ptr_ = strstr(source, search);
		size_t insert_len = strlen(insert);//�����ַ����ĳ���
		size_t search_len = strlen(search);//�����ַ����ĳ���
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



/*
�ַ����滻����
 ����˵��:
 in�� Դ�ַ���
 out, �����������ַ���
 outlen��out���Ĵ�С
 src��Ҫ�滻���ַ���
 dst���滻��ʲô�ַ���
*/
char *strrpl(char *in, char *out, int outlen, const char *src, char *dst)
{
	char *p = in;
	unsigned int  len = outlen - 1;

	// �⼸�μ������Ϸ���
	if ((NULL == src) || (NULL == dst) || (NULL == in) || (NULL == out))
	{
		return NULL;
	}
	if ((strcmp(in, "") == 0) || (strcmp(src, "") == 0))
	{
		return NULL;
	}
	if (outlen <= 0)
	{
		return NULL;
	}

	while ((*p != '\0') && (len > 0))
	{
		if (strncmp(p, src, strlen(src)) != 0)
		{
			int n = strlen(out);

			out[n] = *p;
			out[n + 1] = '\0';

			p++;
			len--;
		}
		else
		{
			strcat_s(out, outlen, dst);
			p += strlen(src);
			len -= strlen(dst);
		}
	}

	return out;
}



/*
�Լ�д���ַ����滻����
// ����˵��:
// s_In�� Դ�ַ���
// s_Old�� Ҫ�滻���ַ���
// s_Src��Ҫ�滻ʲô�ַ���
// s_Out�������������ַ���
*/
void StringReplace(char const * s_In, const char * s_Old, const char * s_Src, char *s_Out)
{
	assert(s_In != NULL||s_Old != NULL||s_Src != NULL||s_Out != NULL);

	size_t InLen = strlen(s_In);
	size_t OldLen = strlen(s_Old);
	size_t SrcLen = strlen(s_Src);
	int index = 0;
	char* substr=mystr_str_((char*)s_In, (char*)s_Old);
	
	if (substr)
	{
		strncat(s_Out, s_In, InLen - (strlen(substr)));//׷���ַ�����ʼ����һ�β����м���ַ���
		index += (InLen - strlen(substr) + OldLen);
		strncat(s_Out, s_Src, SrcLen);//�滻�ַ�
	}
	substr = mystr_str_((char*)(substr + OldLen), (char*)s_Old);
	
	while (substr)
	{
		size_t sublen = strlen(substr);
		strncat(s_Out, s_In + index, InLen - sublen-index);//׷����һ�β��ҽ�β�����˴β��ҽ����м���ַ���
		index += (InLen - sublen - index)+OldLen;
		strncat(s_Out, s_Src, SrcLen);//�滻�ַ�
		substr = mystr_str_((char*)(substr + OldLen), (char*)s_Old);
			
		if (!substr)
		{
			strncat(s_Out, s_In + index, InLen - index);//�滻�ַ�
		}
	}

}


int strncmp(char * s1, char * s2, size_t maxcout)
{
	int sign = 0;
	char* p_s = s1;
	int result = 0;
	while (*s1&&*s2)
	{
		if (*s1 == *s2)
		{
			sign = 0;
			char* p_tmp = s2;
			while (*s1 == *p_tmp)
			{

			}
		}
		++s1; 
		++s2;
	}


	return result;
}


/*�Լ�д���ַ����滻���� �����ķ���
// ����˵��:
// s_In�� Դ�ַ���
// s_Old�� Ҫ�滻���ַ���
// s_Src��Ҫ�滻ʲô�ַ���
 s_Out�������������ַ���
 */
void StrReplace(char const * s_In, const char * s_Old, const char * s_Src, char *s_Out)
{
	char b[] = "BBBDD654";
	char bb[] = "bbbhjhkdd";
	int sign = strncmp(b, bb,3);
	
	if (!sign)
	{

	}
}



//�뽫�ַ���  hiahua  love wangfang   �ĳ�  wangfang  love  haihua, ������ʹ��rev����.
void StrChange(char* s_Str, unsigned int start, unsigned int end,unsigned int len)
{

}



//586.21
double StrToDouble(char* express)
{
	double re = 0.0;
	double c = 0;
	int chu = 10;
	int sign = 0;
	while (*express>47 && *express<58||*express=='.')
	{
		if (*express != '.')
		{
			if (c ==0)
			{
				c = (*express - '0');
			}
			else if (c !=0 && sign == 0)
			{
				c *= 10;
				c += (*express - '0');
			}
			if (sign != 0)//С��λ
			{
				double cd=(*express - '0');
				double ddd = (double)(cd / chu);
				re = ddd + re;
				chu *= 10;
			}
		}
		if (*express == '.')
		{
			sign = 1;
		}
		
		++express;
	}

	return ((double)c+re);
}














































































































































