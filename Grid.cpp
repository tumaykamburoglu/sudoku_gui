#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "Grid.h"
using namespace std;

Grid::Grid()
{
	srand(time(NULL));
	for (int row = 0; row < 9; row++) {
		for (int column = 0; column < 9; column++) {

			int number = (rand() % 9) + 1;
			int n_try = 0;
			while (!this->check(row, column, number) && (n_try < 50)) {
				number = (rand() % 9) + 1;
				n_try++;
			}
			if (n_try == 50) {

				for (int j = 0; j < 9; j++)
				{
					this->numbers[row][j] = 0;
				}
				row--;

			}
			else {
				this->numbers[row][column] = number;
			}

		}
	}
}

void Grid::hide(int difficulty) {
	srand(time(NULL));
	for (int i = 0; i < difficulty * 10; i++) {
		int row = rand() % 9;
		int column = rand() % 9;
		if (properity[row][column] != 1) {
			properity[row][column] = 1;
		}
		else {
			i--;
		}
	}
}

bool Grid::check(int row, int column, int number) {
	int square = 3 * (row / 3) + (column / 3);
	bool valid = true;
	for (int i = 0; i < 9; i++) {

		if (numbers[row][i] == number) {
			valid = false;
		}
		if (numbers[i][column] == number) {
			valid = false;
		}
	}
	row = (3 * (square / 3));
	column = (3 * (square % 3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (numbers[row + i][column + j] == number) {
				valid = false;
			}
		}
	}
	return valid;
}


