
#include "Snake.h"


Snake::Snake()
{
	COORD c = { INITROWPOS, INITCOLPOS };

	Ls_Body.push_front(make_pair('@',c));
	Ls_Body.push_front(make_pair('*', c = { INITROWPOS-1 , INITCOLPOS}));
	Ls_Body.push_front(make_pair('*', c = { INITROWPOS-2, INITCOLPOS }));
}



//��������ͷ������
void Snake::Move(HANDLE hout,COORD headpos)//�ƶ����ǰ���ͷ��λ�øı�ֵ����λ�ã��������������ǰ��
{
	DWORD buf = 0;
	//�ȰѾɵ�����λ�ö���Ϊ�ո�
	for (list<pair<char, COORD>>::reverse_iterator it = this->Ls_Body.rbegin(); it != this->Ls_Body.rend(); it++)
	{
		WriteConsoleOutputCharacterA(hout, " ", 1, it->second, &buf);//���һ��Ҫ��ָ��
	}
	
	//�洢�� **@��  �����������@**��ȡ
	//����ͷ��Ϊ���λ�� ��������ǰ��  
	COORD coord_tmp = headpos;
	for (list<pair<char, COORD>>::reverse_iterator it = this->Ls_Body.rbegin(); it != this->Ls_Body.rend(); it++)
	{
		COORD coord = it->second;
		it->second = coord_tmp;
		coord_tmp = coord;
	}

	//���µ������λ�������Ļ
	for (pair<char, COORD>& p : this->Ls_Body)
	{
		DWORD buf = 0;
		WriteConsoleOutputCharacterA(hout, &(p.first), 1, p.second, &buf);//���һ��Ҫ��ָ��
	}
	SetConsoleCursorPosition(hout, headpos);//���ù��λ��
}


void Snake::EatFood(COORD pos)
{

	this->Ls_Body.push_front(make_pair('*', this->Ls_Body.back().second));
}






































