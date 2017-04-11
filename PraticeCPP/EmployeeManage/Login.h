#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifdef __cplusplus
extern "C"{
#endif

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include"Administrator.h"
#include"LinkList.h"
#include"Tools\memwatch.h"

#define LOGINSUC 1
#define LOGINFAIL 0
#define LOGINERROR -1
#define NAMELEN 64
#define PWDLEN 64
#define VERYERROR -2

	 Administrator CurrentAdmin;//别的.c文件可以引用 此处声明的全局变量  但是前提是必须引用此头文件
	 LinkList* list;
	int VerifyLogin(char* Name, char* Pwd,Administrator* admin);

	int LoginForm(char* Name, char* Pwd);







#ifdef __cplusplus
}
#endif