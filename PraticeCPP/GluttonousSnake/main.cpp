
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <io.h>
#include <list>
#include "Snake.h"
#include "Wall.h"


using namespace std;

void SetConsole(Snake& snake)
{
	Snake s;
	Wall wall(snake);
	wall.InitWall();
	wall.DrawWall();

	HANDLE hout;
	COORD coord = { INITROWPOS, INITCOLPOS };
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	_CONSOLE_CURSOR_INFO cursorinfo;

	SetConsoleCursorPosition(hout, coord);

	GetConsoleCursorInfo(hout, &cursorinfo);//得到当前的光标信息

	cursorinfo.bVisible = false;//设置可见性

	SetConsoleCursorInfo(hout, &cursorinfo);//向句柄指向的控制台设置光标信息
	Direction PreD = RIGHT;
	while (1)
	{
		if (GetConsoleScreenBufferInfo(hout, &csbi))
		{
			coord = csbi.dwCursorPosition;
			char ch = _getch();
			bool isd = true;
				switch (ch)
				{
				case UP:
				{
						   if (coord.Y != 0)
						   {
							   coord.Y--;
						   }
						   break;
				}
				case DOWN:
				{
							 coord.Y++;
							 break;
				}
				case LEFT:
				{
							 if (coord.X != 0)
							 {
								 --(coord.X);
							 }
							 break;
				}
				case RIGHT:
				{
							  ++(coord.X);
							  break;
				}
				default:
				{
						   isd = false;
						   break;
				}
					
				}
				//此次按键是方向键 并且不是反方向按键
				if (isd && PreD != (ch + 2) && PreD != (ch - 2) && PreD != (ch + 8) && PreD != (ch - 8))
				{
					////存储是 **@存  逆序遍历就是@**读取
					//COORD coord_tmp = coord;
					//for (list<pair<char, COORD>>::reverse_iterator it = snake.Ls_Body.rbegin(); it != snake.Ls_Body.rend(); it++)
					//{
					//	DWORD buf = 0;
					//	char c = ' ';
					//	
					//	WriteConsoleOutputCharacterA(hout, &c, 1, it->second, &buf);//最后一个要给指针
					//	
					//	COORD tmp = it->second;
					//	it->second = coord_tmp;
					//	coord_tmp = tmp;
					//	//p.second.X += 1;//将原先的蛇的位置清空
					//}
					//将新的蛇身的位置填充屏幕
					snake.Ls_Body.back().second = coord;//设置蛇头位置就是当前光标的位置。
					for (pair<char, COORD>& p : snake.Ls_Body)
					{
						DWORD buf = 0;
						WriteConsoleOutputCharacterA(hout, &(p.first), 1, p.second, &buf);//最后一个要给指针
					}
					
					SetConsoleCursorPosition(hout, coord);//设置光标位置
					PreD = (Direction)ch;
				}
		}
	}
}

void InitGame()
{
	Snake snake;
	Wall wall(snake);
	wall.InitWall();
	wall.DrawWall();
	wall.StartGame();

	cout << "Game Over!" << endl;
	getchar();
}




int main()
{
	InitGame();
	
	system("pause");
	return EXIT_SUCCESS;
}