
#include"LoginLog.h"

static FILE* log;

void WriteLoginLogCustom(const char* msg)
{
	if (log == NULL)
	{
		log = fopen("./loginlog.log", "ab+");
	}

	fprintf(log, "%s\n", msg);
	fflush(log);
}

void WriteLoginLog(const char* username,const time_t time,int flag)
{
	if (log == NULL)
	{
		log = fopen("./loginlog.log", "ab+");
	}
	char* tms = ctime(&time);
	tms[strlen(tms) - 1] = 0;
	if (flag == LOGINSUCC)
	{
		fprintf(log, "%s at %s login sucess!\n", username, tms);
	}
	if (flag == LOGINFAIL)
	{
		fprintf(log, "%s at %s login failed!\n", username, tms);
	}
		
	fflush(log);
}

void WriteExitLogCustom(const char* msg)
{
	if (log == NULL)
	{
		log = fopen("./loginlog.log", "ab+");
	}
	fprintf(log, "%s\n", msg);
	fflush(log);
}


void WriteExitLog(const char* username, const time_t time)
{
	if (log == NULL)
	{
		log = fopen("./loginlog.log", "ab+");
	}
	char* tms = ctime(&time);
	tms[strlen(tms) - 1] = 0;
	fprintf(log, "%s at %s exit!\n", username, tms);
	fflush(log);
}

void ExitLog()
{
	if (log != NULL)
	{
		fclose(log);
	}
}