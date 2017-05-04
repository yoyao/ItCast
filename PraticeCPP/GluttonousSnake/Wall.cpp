
#include "Wall.h"



Wall::Wall(Snake& s) :snake(s)
{

}
void Wall::InitWall()
{
	for (int i = 0; i < Height; ++i)
	{
		for (int j = 0; j < Weight; ++j)
		{
			if (i == 0 || j == 0 || i == (Height - 1) || j == (Weight - 1))
			{
				WallPic[i][j] = '*';
			}
			else
			{
				WallPic[i][j] = ' ';
			}
		}
	}
}



void Wall::DrawWall()
{
	for (int i = 0; i < Height; ++i)
	{
		for (int j = 0; j < Weight; ++j)
		{
			printf("%c ", WallPic[i][j]);
		}
		if (i == 6)
		{
			printf("  CreatTime:%s", "2017-04-28");
		}
		printf("\n");
	}
     coord = { INITROWPOS, INITCOLPOS };
	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hout, coord);

	GetConsoleCursorInfo(hout, &cursorinfo);//得到当前的光标信息

	cursorinfo.bVisible = false;//设置可见性

	SetConsoleCursorInfo(hout, &cursorinfo);//向句柄指向的控制台设置光标信息

	for (pair<char, COORD> p : this->snake.Ls_Body)
	{
		DWORD buf = 0;
		WriteConsoleOutputCharacterA(hout, &(p.first), 1, p.second, &buf);//最后一个要给指针
	
	}
}

void Wall::SetWallPos(int x, int y, char val)
{
	WallPic[x][y] = val;
}



void Wall::StartGame()
{
		SetConsoleCursorPosition(hout, coord);

		GetConsoleCursorInfo(hout, &cursorinfo);//得到当前的光标信息

		cursorinfo.bVisible = false;//设置可见性

		SetConsoleCursorInfo(hout, &cursorinfo);//向句柄指向的控制台设置光标信息
		
		Direction PreD = RIGHT;//上一次的方向
		Food food;
		DWORD buf = 0;
		bool isd = true;
		int PauseTime = 1000;
		char ch = (char)RIGHT;
		coord = food.RandCreateFood(this->Height, this->Weight);
		//随机输出一个食物
		WriteConsoleOutputCharacterA(hout, "#", 1, coord, &buf);//最后一个要给指针
		
		if (coord.X == 0 || coord.Y == 0)
		{
			SetConsoleCursorPosition(hout, { 0, this->Height });
			return;
		}
	
		while (1)
		{
			bool ishit = false;

			if (GetConsoleScreenBufferInfo(hout, &csbi))
			{
				coord = csbi.dwCursorPosition;
				if (_kbhit()==1)//判断是否有键盘输入
				{
					isd = true;
					ch = _getch();//从缓冲区读取一个字符
					if (ch == -32)//莫名的出现了一个-32 要判断下
					{
						continue;
					}
				}
                #pragma region Switch

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
            #pragma endregion

				
				//此次按键是方向键 并且不是反方向按键
				if (isd && PreD != (ch + 2) && PreD != (ch - 2) && PreD != (ch + 8) && PreD != (ch - 8))
				{
					char cfood;
					ReadConsoleOutputCharacterA(hout, &cfood, 1, coord, &buf);//从控制台指定位置读取一个字符

					if (cfood == '#')
					{
						snake.EatFood(coord);
						COORD fcoord = food.RandCreateFood(this->Height, this->Weight);
						WriteConsoleOutputCharacterA(hout, "#", 1, fcoord, &buf);//最后一个要给指针
					}

					snake.Move(hout, coord);

					if (cfood == '*' || coord.Y == this->Height)//光标位置要在墙的范围内 不在就意味着撞墙而死 
					{
						SetConsoleCursorPosition(hout, { 0, this->Height });//设置光标位置到最左下角 输出Game Over
						return;
					}
					PreD = (Direction)ch;
				}

			}
			Sleep(PauseTime);
			
		}

}
