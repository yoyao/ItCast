

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<vector>
#include<socketapi.h>
#include<Windows.h>
#include<winsock.h>
#include"dlllib.h"
#include"staticlib.h"


#include"DynamicProgramming.hpp"
#include"LongestCommonSubstirng.hpp"


using namespace std;

//网上看到的求最长字串的方法
int longest_common_substring(char *str1, char *str2)
{
	int i, j, k, len1, len2, max, x, y;
	len1 = strlen(str1);
	len2 = strlen(str2);
	int **c = new int*[len1 + 1];
	for (i = 0; i < len1 + 1; i++)
		c[i] = new int[len2 + 1];
	for (i = 0; i < len1 + 1; i++)
		c[i][0] = 0;        //第0列都初始化为0  
	for (j = 0; j < len2 + 1; j++)
		c[0][j] = 0;        //第0行都初始化为0   
	max = -1;
	for (i = 1; i < len1 + 1; i++)
	{
		for (j = 1; j < len2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				//只需要跟左上方的c[i-1][j-1]比较就可以了  
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else
			{
				//不连续的时候还要跟左边的c[i][j-1]、上边的c[i-1][j]值比较，这里不需要  
				c[i][j] = 0;
			}
			
			if (c[i][j]>max)
			{
				max = c[i][j];
				x = i;
				y = j;
			}
		}
	}


	for (int k = 0; k < len1; ++k)//从1开始才会有左上角 从0开始就没有了
	{
		for (int h = 0; h < len2; ++h)
		{
			cout << c[k][h] << " ";
		}
		cout << endl;
	}

	//输出公共子串  
	char s[1000];
	k = max;
	i = x - 1, j = y - 1;
	s[k--] = '\0';
	while (i >= 0 && j >= 0)
	{
		if (str1[i] == str2[j])
		{
			s[k--] = str1[i];
			i--;
			j--;
		}
		else       //只要有一个不相等，就说明相等的公共字符断了，不连续了  
			break;
	}
	printf("最长公共子串为：");
	puts(s);
	for (i = 0; i < len1 + 1; i++)         //释放动态申请的二维数组  
		delete[] c[i];
	delete[] c;
	return max;
}


void TestGoldMine()
{
	//初始化数据
	init();

	//输出给定peopleTotal个人和n个金矿能够获得的最大金子数，再次提醒编号从0开始，所以最后一个金矿编号为n-1
	int MaxGoldCount = 0;
	//MaxGoldCount = GetMaxGold(peopleTotal, GoldCount - 1);
	MaxGoldCount = CalculateMaxGolden(100, 4);
	cout << MaxGoldCount << std::endl;
}

void TestMyLCS()//最长公共字串
{
	string str1 = "1256789";
	string str2 = "125050673";
	LCS(str1, str2);
}


void TestLCSubSence()
{
	string str1 = "13456778";
	string str2 = "357486782";
	LCSubSence(str1, str2);
}
class Person
{

};
// abcde 五件物品
//重量分别是 22654
//Capacity 10 
//6 3 5 4 6


/*
01背包问题
此问题是最简单的问题 每个物品只需要放一次，要是可以变化的放就是完全背包问题。
*/

static int Capacitys[5] = { 2,2,6,5,4};
static int Values[5] = { 6, 3, 5, 4, 6 };
static int Note[20][20];//记录第几个物品和剩余多少容量的二维数组。即 备忘录
//                     第几个物品 剩余多少容量


/*
处理某一个物品有两种选择，放或者不放，那么放就会有个最大的值，记录下来。
不放也会有个最大值，比较一下，最大的返回。
下一个背包同样是这个问题，同样处理。
*/
int CalculateMaxPrice(int index, int capacity)
{
	int price = 0;
	if (Capacitys[index] > capacity)//如果当前的索引的物品的容量大于了剩余容量,那就是装不下了，返回0 或者已经处理完了所有物品
	{
		return 0;
	}
	if (index<0)//如果当前的索引的物品的容量大于了剩余容量,那就是装不下了，返回0 或者已经处理完了所有物品
	{
		return 0;
	}
	//如果备忘录内有记录
	if (Note[index][capacity]>0)
	{
		return Note[index][capacity];
	}


	//能装下，那就比较装它和不装它谁比较大
	//CalculateMaxPrice(index + 1, capacity-capacity[index])+values[index]//装它
	// CalculateMaxPrice( index+1,capacity) //不装它
	price = max(CalculateMaxPrice(index -1, capacity - Capacitys[index]) + Values[index], CalculateMaxPrice(index -1, capacity));
	
	Note[index][capacity] = price;

	return price;
}


int main3(int argc, char* argv[])
{
	string str1 = "13456778";
	string str2 = "357486782";
	//TestLCSubSence();
	string str = R"(askdkl\nasdg)";//原始字符串

	int price=CalculateMaxPrice(4,10);

	system("pause");
	return 0;
}