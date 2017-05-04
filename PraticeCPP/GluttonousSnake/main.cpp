
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

	GetConsoleCursorInfo(hout, &cursorinfo);//�õ���ǰ�Ĺ����Ϣ

	cursorinfo.bVisible = false;//���ÿɼ���

	SetConsoleCursorInfo(hout, &cursorinfo);//����ָ��Ŀ���̨���ù����Ϣ
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
				//�˴ΰ����Ƿ���� ���Ҳ��Ƿ����򰴼�
				if (isd && PreD != (ch + 2) && PreD != (ch - 2) && PreD != (ch + 8) && PreD != (ch - 8))
				{
					////�洢�� **@��  �����������@**��ȡ
					//COORD coord_tmp = coord;
					//for (list<pair<char, COORD>>::reverse_iterator it = snake.Ls_Body.rbegin(); it != snake.Ls_Body.rend(); it++)
					//{
					//	DWORD buf = 0;
					//	char c = ' ';
					//	
					//	WriteConsoleOutputCharacterA(hout, &c, 1, it->second, &buf);//���һ��Ҫ��ָ��
					//	
					//	COORD tmp = it->second;
					//	it->second = coord_tmp;
					//	coord_tmp = tmp;
					//	//p.second.X += 1;//��ԭ�ȵ��ߵ�λ�����
					//}
					//���µ������λ�������Ļ
					snake.Ls_Body.back().second = coord;//������ͷλ�þ��ǵ�ǰ����λ�á�
					for (pair<char, COORD>& p : snake.Ls_Body)
					{
						DWORD buf = 0;
						WriteConsoleOutputCharacterA(hout, &(p.first), 1, p.second, &buf);//���һ��Ҫ��ָ��
					}
					
					SetConsoleCursorPosition(hout, coord);//���ù��λ��
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