#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


#ifdef __cplusplus
extern "C"{
#endif
#define LOGINSUCC 1
#define LOGINFAIL 0
	void WriteLoginLogCustom(const char* msg);
	void WriteLoginLog(const char* username, const time_t time, int flag);
	void WriteExitLogCustom(const char* msg);
	void WriteExitLog(const char* username, const time_t time);
	void ExitLog();








#ifdef __cplusplus
}
#endif

