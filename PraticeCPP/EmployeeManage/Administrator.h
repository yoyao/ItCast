
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifdef __cplusplus
extern "C"{
#endif
#define NAMELENGTH 64
#define PWDLENGTH 1024

	struct _administrator{
		int ID;
		char Name[NAMELENGTH];
		char PassWord[PWDLENGTH];
	};

	typedef struct _administrator Administrator;



#ifdef __cplusplus
}
#endif