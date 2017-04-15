#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <fstream>
#include"ConsoleTest.h"
#include"DynamicProgramming.hpp"

using namespace std;


/*
��һ�����ң����еĹ��񶼷ǳ���ʵ����ĳ���������Լ��Ĺ��ҷ�����ʮ����󣬲�����ʮ������ڵ�ͼ���ų�һ��ֱ�ߣ�����֪�������Ϣ��ǳ����ˣ���ϣ���ܹ�����Щ���Ӷ��ڳ����츣��������������Щ������ڵ�ͼ�ϵ�λ�ô����������б�ţ�����Ϊ0��1��2��3��4��5��6��7��8��9��Ȼ����������������ȥ��ÿһ�������п��⣬�Ա�֪����ȡÿһ�������Ҫ���������Լ�ÿ������ܹ��ڳ����ٽ��ӣ�Ȼ��Ա�������ڽ��ӡ�
*/
const int max_n = 100;//����֧�ֵ��������

const int max_people = 10000;//����֧�ֵ��������



int GoldCount;//�����

int peopleTotal;//���������ڽ��ӵ�����

int peopleNeed[max_n];//ÿ�������Ҫ������

int gold[max_n];//ÿ������ܹ��ڳ����Ľ�����

int maxGold[max_people][max_n];//maxGold[i][j]������i������ǰj������ܹ��õ�����������������-1ʱ��ʾδ֪


//��ʼ������ 

void init()
{
	int t1 = 0;
	int t2 = 1;
	ifstream inputFile("beibao.in");
	inputFile >> peopleTotal >> GoldCount;//
	for (int i = 0; i < GoldCount; i++)
	{
		inputFile >> peopleNeed[i] >> gold[i];
	}
	inputFile.close();

	for (int i = 0; i <= peopleTotal; i++)
	{
		for (int j = 0; j < GoldCount; j++)
		{
			maxGold[i][j] = -1;//����-1ʱ��ʾδ֪ [��Ӧ��̬�滮�еġ�������¼��]
		}
	}
}


//����ڽ���people���˺�ǰmineNum�����ʱ�ܹ��õ�������������ע�⡰ǰ���ٸ���Ҳ�Ǵ�0��ʼ��ŵ�
int GetMaxGold(int people, int mineNum)
{
	//�������ص���������
	int retMaxGold;

	//�������������������  [��Ӧ��̬�滮�еġ�������¼��]
	if (maxGold[people][mineNum] != -1)
	{
		//��ñ���������ֵ
		retMaxGold = maxGold[people][mineNum];
	}
	else if (mineNum == 0)//�������һ�����ʱ [��Ӧ��̬�滮�еġ��߽硱]
	{
		//�������������㹻�����������
		if (people >= peopleNeed[mineNum])
		{
			//�õ������ֵ�����������Ľ�����
			retMaxGold = gold[mineNum];
		}
		else//������Ψһ��һ�����Ҳ���ܿ���

		{
			//�õ������ֵΪ0������
			retMaxGold = 0;
		}

	}
	else if (people >= peopleNeed[mineNum])//����������˹������������ [��Ӧ��̬�滮�еġ������ӽṹ��]
	{
		//���ǿ����벻�������������ȡ���ֵ

		retMaxGold = max(GetMaxGold(people - peopleNeed[mineNum], mineNum - 1) + gold[mineNum],GetMaxGold(people, mineNum - 1));

	}
	else//����������˲�������������� [��Ӧ��̬�滮�еġ������ӽṹ��]
	{
		//�����ǲ����ɵ����
		retMaxGold = GetMaxGold(people, mineNum - 1);
	}

	//������¼    
	maxGold[people][mineNum] = retMaxGold;

	return retMaxGold;

}



int MineTotal = 5;//һ���м������ ������������
int GoldMineGoldNum[5] = {92,22,87,46,90};//ÿ������ܳ����ٽ���
int GoldMineNeedPeople[5] = {77,22,29,50,99};//ÿ�������Ҫ������������
int Note[105][5];//����¼����¼�������ڼ�����������ڶ��ٽ��ӡ�

int CalculateMaxGolden(int PeopleCount, int MineCount)//Ϊ�˷�����㣬�����Ǵ�0��ʼ��ŵġ�
{
	for (int i = 0; i < 105; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			Note[i][j] = -1;
		}
	}
	int MaxGolden = 0;

 if (Note[PeopleCount][MineCount] != -1)//���ֹ� ��ô����  ������ô���� ��õ����Ľ�������
	{
		MaxGolden = Note[PeopleCount][MineCount];
	}
	else if (MineCount == 0)//���ֻ��һ����� ��ô������������---���ɺͲ����ɵ����
	{
		if (PeopleCount >= GoldMineNeedPeople[MineCount])
		{
			MaxGolden = GoldMineGoldNum[MineCount];//��������ɵ�����  ���Ľ����������ǿ�������������Ľ��ӡ�
		}
		else
		{
			MaxGolden = 0;
		}
	}
	else if (PeopleCount >= GoldMineNeedPeople[MineCount])//����� ���ɵĿ�ֹһ����������ͬ�����кܶ� ��Ҫ���Ƚ�
	{
		                //�� ���ɺͲ����ɴ˿����������Ƚ�
		      //��һ�������ǿ��ɵ������ ���� ����������ȥ���ɴ˿�����������ǽ�������Ҫ���Ͽ��ɴ˿󿪲ɳ����Ľ�����
		   //�ڶ���
		MaxGolden = max(CalculateMaxGolden(PeopleCount - peopleNeed[MineCount], MineCount - 1) + GoldMineGoldNum[MineCount], CalculateMaxGolden(PeopleCount, MineCount - 1));
	}
	else//�������˲��������⴦��
	{
		MaxGolden = CalculateMaxGolden(PeopleCount, MineCount - 1);//������������� �Ǿͼ���������һ����
	}


	Note[PeopleCount][MineCount] = MaxGolden;//���±���¼

	return MaxGolden;
}





















































































