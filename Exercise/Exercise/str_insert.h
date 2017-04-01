#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<assert.h>

void StrInsert(char source[], char search[], char insert[]);
void _StrInsert_(char source[], char search[], char insert[]);
void  __cdecl  StrAppendAtStr(const char* s_In, const char* s_Search, const char* s_Append, char* s_Out);

// 参数说明:
// in， 源字符串
// out, 存放最后结果的字符串
// outlen，out最大的大小
// src，要替换的字符串
// dst，替换成什么字符串
char *strrpl(char *in, char *out, int outlen, const char *src, char *dst);

//自己写的字符串替换函数
// 参数说明:
// s_In， 源字符串
// s_Old， 要替换的字符串
// s_Src，要替换什么字符串
// s_Out，存放最后结果的字符串
void StringReplace(char const * s_In, const char * s_Old, const char * s_Src, char *s_Out);
//自己写的字符串替换函数 更简便的方法
// 参数说明:
// s_In， 源字符串
// s_Old， 要替换的字符串
// s_Src，要替换什么字符串
// s_Out，存放最后结果的字符串
void StrReplace(char const * s_In, const char * s_Old, const char * s_Src, char *s_Out);



//请将字符串  hiahua  love wangfang   改成  wangfang  love  haihua, 不允许使用rev函数.

void StrChange(char* s_Str, unsigned int start, unsigned int end);


double StrToDouble(char* express);


















































































