
#include"MyTools.h"


void StringTrim( char* str, char* buf)
{
	int len = strlen(str);
	char* p = (char*)str;
	int f = 0;
	int b = 0;
	while (p[f] == ' ')
	{
		++f;
	}
	while (p[len - b - 1] == ' ')
	{
		++b;
	}
	strncpy(buf, str + f, (len - f - b));
	buf[(len - f - b)] = '\0';
}

