#pragma once
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>



class Grid
{
public:
	Grid();
	void hide(int);
	bool check(int, int, int);
	int numbers[9][10] = { 0 };
	int properity[9][9] = { 0 };
};



