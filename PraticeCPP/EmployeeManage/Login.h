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

	 Administrator CurrentAdmin;//���.c�ļ��������� �˴�������ȫ�ֱ���  ����ǰ���Ǳ������ô�ͷ�ļ�
	 LinkList* list;
	int VerifyLogin(char* Name, char* Pwd,Administrator* admin);

	int LoginForm(char* Name, char* Pwd);













#ifdef __cplusplus
}
#endif