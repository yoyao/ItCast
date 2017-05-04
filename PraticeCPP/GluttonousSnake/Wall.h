
#ifndef _WALL_H
#define _WALL_H
#include <Windows.h>
#include <conio.h>
#include <list>
#include <iostream>
#include <time.h>
#include "Snake.h"
#include "food.h"
using namespace std;

enum Direction{
	UP = 0x48,//72
	LEFT = 0x4b,//75
	RIGHT = 0x4d,//77
	DOWN = 0x50//80
};

class Wall
{
public:
	Wall(Snake& s);
	void InitWall();
	void DrawWall();
	void SetWallPos(int x, int y, char val);
	void StartGame();
private:
	static const int Height = 26;
	static const int Weight = 40;
	char WallPic[Height][Weight];
	Snake snake;
	HANDLE hout;
	COORD coord;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	_CONSOLE_CURSOR_INFO cursorinfo;
};




#endif