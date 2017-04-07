#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"
#include"MyTools.h"

#ifdef __cplusplus
extern "C"{
#endif

#define EMNAMELENGTH 64
#define EMBORNLENGTH 64
#define EMADDRLENGTH 128

	typedef struct _employee Employee;

	struct _employee{
		int ID;
		char Name[EMNAMELENGTH];
		int Age;
		char Address[EMADDRLENGTH];
		char Born[EMBORNLENGTH];
	};

	
	LinkList* GetEmployeeList();

	int WriteEmployeeList(LinkList* list);





#ifdef __cplusplus
}
#endif