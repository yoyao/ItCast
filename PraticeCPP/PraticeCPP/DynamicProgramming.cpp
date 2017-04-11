#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

void GetConsole()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO ConsoleScreeInfo ;
	
	GetConsoleScreenBufferInfo(ConsoleHandle, &ConsoleScreeInfo);
	COORD ConsoleCoord;

	ConsoleCoord.X = ConsoleScreeInfo.dwCursorPosition.X;
	ConsoleCoord.Y = ConsoleScreeInfo.dwCursorPosition.Y;
	//使用了
	ConsoleScreeInfo.dwCursorPosition.X += 10;
	char sign;
	while (1)
	{
		switch (_getch())
		{
		case '0'://0退出
		{
					 return;
					  break;
		}
		case 0x48://上
		{
		       if (ConsoleCoord.X > 0)
		       {
		     	  --ConsoleCoord.Y;
		       }
		      break;
		}
		case 0x50://下
		{
				 ++ConsoleCoord.Y;
					 break;
		}
		case 0x4b://左
		{
					  if (ConsoleCoord.X > 0)
					  {
						  --ConsoleCoord.X;
					  }
					 
					 break;
		}
		case 0x4d://右
		{
					  ++ConsoleCoord.X;
					 break;
		}
		case 0x0d://回车
		{
					  ++ConsoleCoord.Y;
					 break;
		}
		}
		SetConsoleCursorPosition(ConsoleHandle, ConsoleCoord);
	}

	



	
}
int main()
{
	GetConsole();
	
	system("pause");
	return EXIT_SUCCESS;
}