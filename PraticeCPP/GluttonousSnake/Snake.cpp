
#include "Snake.h"


Snake::Snake()
{
	COORD c = { INITROWPOS, INITCOLPOS };

	Ls_Body.push_front(make_pair('@',c));
	Ls_Body.push_front(make_pair('*', c = { INITROWPOS-1 , INITCOLPOS}));
	Ls_Body.push_front(make_pair('*', c = { INITROWPOS-2, INITCOLPOS }));
}



//参数是蛇头的坐标
void Snake::Move(HANDLE hout,COORD headpos)//移动就是把蛇头的位置改变值光标的位置，其余的蛇身依次前移
{
	DWORD buf = 0;
	//先把旧的蛇身位置都置为空格
	for (list<pair<char, COORD>>::reverse_iterator it = this->Ls_Body.rbegin(); it != this->Ls_Body.rend(); it++)
	{
		WriteConsoleOutputCharacterA(hout, " ", 1, it->second, &buf);//最后一个要给指针
	}
	
	//存储是 **@存  逆序遍历就是@**读取
	//将蛇头变为光标位置 蛇身依次前移  
	COORD coord_tmp = headpos;
	for (list<pair<char, COORD>>::reverse_iterator it = this->Ls_Body.rbegin(); it != this->Ls_Body.rend(); it++)
	{
		COORD coord = it->second;
		it->second = coord_tmp;
		coord_tmp = coord;
	}

	//将新的蛇身的位置填充屏幕
	for (pair<char, COORD>& p : this->Ls_Body)
	{
		DWORD buf = 0;
		WriteConsoleOutputCharacterA(hout, &(p.first), 1, p.second, &buf);//最后一个要给指针
	}
	SetConsoleCursorPosition(hout, headpos);//设置光标位置
}


void Snake::EatFood(COORD pos)
{

	this->Ls_Body.push_front(make_pair('*', this->Ls_Body.back().second));
}






































