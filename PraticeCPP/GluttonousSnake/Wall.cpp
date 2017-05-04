
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

	GetConsoleCursorInfo(hout, &cursorinfo);//�õ���ǰ�Ĺ����Ϣ

	cursorinfo.bVisible = false;//���ÿɼ���

	SetConsoleCursorInfo(hout, &cursorinfo);//����ָ��Ŀ���̨���ù����Ϣ

	for (pair<char, COORD> p : this->snake.Ls_Body)
	{
		DWORD buf = 0;
		WriteConsoleOutputCharacterA(hout, &(p.first), 1, p.second, &buf);//���һ��Ҫ��ָ��
	
	}
}

void Wall::SetWallPos(int x, int y, char val)
{
	WallPic[x][y] = val;
}



void Wall::StartGame()
{
		SetConsoleCursorPosition(hout, coord);

		GetConsoleCursorInfo(hout, &cursorinfo);//�õ���ǰ�Ĺ����Ϣ

		cursorinfo.bVisible = false;//���ÿɼ���

		SetConsoleCursorInfo(hout, &cursorinfo);//����ָ��Ŀ���̨���ù����Ϣ
		
		Direction PreD = RIGHT;//��һ�εķ���
		Food food;
		DWORD buf = 0;
		bool isd = true;
		int PauseTime = 1000;
		char ch = (char)RIGHT;
		coord = food.RandCreateFood(this->Height, this->Weight);
		//������һ��ʳ��
		WriteConsoleOutputCharacterA(hout, "#", 1, coord, &buf);//���һ��Ҫ��ָ��
		
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
				if (_kbhit()==1)//�ж��Ƿ��м�������
				{
					isd = true;
					ch = _getch();//�ӻ�������ȡһ���ַ�
					if (ch == -32)//Ī���ĳ�����һ��-32 Ҫ�ж���
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

				
				//�˴ΰ����Ƿ���� ���Ҳ��Ƿ����򰴼�
				if (isd && PreD != (ch + 2) && PreD != (ch - 2) && PreD != (ch + 8) && PreD != (ch - 8))
				{
					char cfood;
					ReadConsoleOutputCharacterA(hout, &cfood, 1, coord, &buf);//�ӿ���ָ̨��λ�ö�ȡһ���ַ�

					if (cfood == '#')
					{
						snake.EatFood(coord);
						COORD fcoord = food.RandCreateFood(this->Height, this->Weight);
						WriteConsoleOutputCharacterA(hout, "#", 1, fcoord, &buf);//���һ��Ҫ��ָ��
					}

					snake.Move(hout, coord);

					if (cfood == '*' || coord.Y == this->Height)//���λ��Ҫ��ǽ�ķ�Χ�� ���ھ���ζ��ײǽ���� 
					{
						SetConsoleCursorPosition(hout, { 0, this->Height });//���ù��λ�õ������½� ���Game Over
						return;
					}
					PreD = (Direction)ch;
				}

			}
			Sleep(PauseTime);
			
		}

}
