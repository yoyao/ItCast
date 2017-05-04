

#ifndef _SNAKE_H
#define _SNAKE_H

#include <iostream>
#include <list>
#include <string>
#include <Windows.h>
#include <conio.h>
//#include "Wall.h"


#define INITROWPOS 12//初始行坐标
#define INITCOLPOS 5 //初始列坐标


using namespace std;

class Snake
{
public:
	Snake();
	void Move(HANDLE hout, COORD headpos);
	void EatFood(COORD pos);
	list<pair<char, COORD>> Ls_Body;
};























#endif