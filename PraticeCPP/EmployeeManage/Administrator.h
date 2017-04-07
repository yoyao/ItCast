#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#ifdef __cplusplus
extern "C"{
#endif
#define NAMELENGTH 64
#define PWDLENGTH 128

	struct _administrator{
		int ID;
		char Name[NAMELENGTH];
		char PassWord[PWDLENGTH];
		time_t AddTime;
	};

	typedef struct _administrator Administrator;



#ifdef __cplusplus
}
#endif