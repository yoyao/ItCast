#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<assert.h>

void StrInsert(char source[], char search[], char insert[]);
void _StrInsert_(char source[], char search[], char insert[]);
void  __cdecl  StrAppendAtStr(const char* s_In, const char* s_Search, const char* s_Append, char* s_Out);

// ����˵��:
// in�� Դ�ַ���
// out, �����������ַ���
// outlen��out���Ĵ�С
// src��Ҫ�滻���ַ���
// dst���滻��ʲô�ַ���
char *strrpl(char *in, char *out, int outlen, const char *src, char *dst);

//�Լ�д���ַ����滻����
// ����˵��:
// s_In�� Դ�ַ���
// s_Old�� Ҫ�滻���ַ���
// s_Src��Ҫ�滻ʲô�ַ���
// s_Out�������������ַ���
void StringReplace(char const * s_In, const char * s_Old, const char * s_Src, char *s_Out);
//�Լ�д���ַ����滻���� �����ķ���
// ����˵��:
// s_In�� Դ�ַ���
// s_Old�� Ҫ�滻���ַ���
// s_Src��Ҫ�滻ʲô�ַ���
// s_Out�������������ַ���
void StrReplace(char const * s_In, const char * s_Old, const char * s_Src, char *s_Out);



//�뽫�ַ���  hiahua  love wangfang   �ĳ�  wangfang  love  haihua, ������ʹ��rev����.

void StrChange(char* s_Str, unsigned int start, unsigned int end);


double StrToDouble(char* express);


















































































