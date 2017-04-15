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
有一个国家，所有的国民都非常老实憨厚，某天他们在自己的国家发现了十座金矿，并且这十座金矿在地图上排成一条直线，国王知道这个消息后非常高兴，他希望能够把这些金子都挖出来造福国民，首先他把这些金矿按照在地图上的位置从西至东进行编号，依次为0、1、2、3、4、5、6、7、8、9，然后他命令他的手下去对每一座金矿进行勘测，以便知道挖取每一座金矿需要多少人力以及每座金矿能够挖出多少金子，然后动员国民都来挖金子。
*/
const int max_n = 100;//程序支持的最多金矿数

const int max_people = 10000;//程序支持的最多人数



int GoldCount;//金矿数

int peopleTotal;//可以用于挖金子的人数

int peopleNeed[max_n];//每座金矿需要的人数

int gold[max_n];//每座金矿能够挖出来的金子数

int maxGold[max_people][max_n];//maxGold[i][j]保存了i个人挖前j个金矿能够得到的最大金子数，等于-1时表示未知


//初始化数据 

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
			maxGold[i][j] = -1;//等于-1时表示未知 [对应动态规划中的“做备忘录”]
		}
	}
}


//获得在仅有people个人和前mineNum个金矿时能够得到的最大金子数，注意“前多少个”也是从0开始编号的
int GetMaxGold(int people, int mineNum)
{
	//申明返回的最大金子数
	int retMaxGold;

	//如果这个问题曾经计算过  [对应动态规划中的“做备忘录”]
	if (maxGold[people][mineNum] != -1)
	{
		//获得保存起来的值
		retMaxGold = maxGold[people][mineNum];
	}
	else if (mineNum == 0)//如果仅有一个金矿时 [对应动态规划中的“边界”]
	{
		//当给出的人数足够开采这座金矿
		if (people >= peopleNeed[mineNum])
		{
			//得到的最大值就是这座金矿的金子数
			retMaxGold = gold[mineNum];
		}
		else//否则这唯一的一座金矿也不能开采

		{
			//得到的最大值为0个金子
			retMaxGold = 0;
		}

	}
	else if (people >= peopleNeed[mineNum])//如果给出的人够开采这座金矿 [对应动态规划中的“最优子结构”]
	{
		//考虑开采与不开采两种情况，取最大值

		retMaxGold = max(GetMaxGold(people - peopleNeed[mineNum], mineNum - 1) + gold[mineNum],GetMaxGold(people, mineNum - 1));

	}
	else//否则给出的人不够开采这座金矿 [对应动态规划中的“最优子结构”]
	{
		//仅考虑不开采的情况
		retMaxGold = GetMaxGold(people, mineNum - 1);
	}

	//做备忘录    
	maxGold[people][mineNum] = retMaxGold;

	return retMaxGold;

}



int MineTotal = 5;//一共有几个金矿 假设是五个金矿
int GoldMineGoldNum[5] = {92,22,87,46,90};//每座金矿能出多少金子
int GoldMineNeedPeople[5] = {77,22,29,50,99};//每座金矿需要多少人来开采
int Note[105][5];//备忘录，记录多少人挖几个矿最多能挖多少金子。

int CalculateMaxGolden(int PeopleCount, int MineCount)//为了方便计算，金子是从0开始标号的。
{
	for (int i = 0; i < 105; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			Note[i][j] = -1;
		}
	}
	int MaxGolden = 0;

 if (Note[PeopleCount][MineCount] != -1)//出现过 这么多人  开采这么多金矿 获得的最大的金子数量
	{
		MaxGolden = Note[PeopleCount][MineCount];
	}
	else if (MineCount == 0)//如果只有一个金矿 那么无外乎两种情况---开采和不开采的情况
	{
		if (PeopleCount >= GoldMineNeedPeople[MineCount])
		{
			MaxGolden = GoldMineGoldNum[MineCount];//如果够开采的人数  最大的金子数量就是开采这座矿出来的金子。
		}
		else
		{
			MaxGolden = 0;
		}
	}
	else if (PeopleCount >= GoldMineNeedPeople[MineCount])//这就是 开采的矿不止一个，而人数同样还有很多 需要作比较
	{
		                //在 开采和不开采此矿的情况下做比较
		      //第一个参数是开采的情况下 （即 现有人数减去开采此矿的人数）但是金子数量要加上开采此矿开采出来的金子数
		   //第二个
		MaxGolden = max(CalculateMaxGolden(PeopleCount - peopleNeed[MineCount], MineCount - 1) + GoldMineGoldNum[MineCount], CalculateMaxGolden(PeopleCount, MineCount - 1));
	}
	else//给出的人不够开采这处矿
	{
		MaxGolden = CalculateMaxGolden(PeopleCount, MineCount - 1);//不够开采这个矿 那就继续开采下一个矿
	}


	Note[PeopleCount][MineCount] = MaxGolden;//做下备忘录

	return MaxGolden;
}





















































































