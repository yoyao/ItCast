
#include "food.h"

Food::Food()
{
	srand((unsigned int)time(NULL));
}



COORD& Food::RandCreateFood(int height,int width)
{
	COORD coord = { 0, 0 };
	while (1)
	{
		int index = rand() % (height* width) + 1;
		int row = (index % width) ;
		int col = (index % height);
		if (row< (width - 1) && col<(height - 1))
		{
			coord = { row, col };
			return coord;
		}
	}
}











































































