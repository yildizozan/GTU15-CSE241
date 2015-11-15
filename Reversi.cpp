/*
* File:   Reversi.cpp
* Author: ozan
*
* Created on November 12, 2015, 4:09 PM
*/
#include <vector>
#include <iostream>
#include "Cell.h"
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Reversi.h"


using namespace std;

Reversi::Reversi()
	: row(2), column(2)
{
	gameCell.resize(row);
	for (int i = 0; i < row; i++)
		gameCell[i].resize(column);

	gameCell[0][0] = Cell(1, 'a', 'X');
	gameCell[0][1] = Cell(1, 'b', 'O');
	gameCell[1][0] = Cell(1, 'a', 'O');
	gameCell[1][1] = Cell(1, 'b', 'X');

}

// Mutator & Accessor Functions

// Input & Output Functions
void Reversi::input(const int newAxisX, const char newAxisY)
{

}

void Reversi::output(void)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			cout << gameCell[i][j].get_Who();
		cout << "\n";
	}
}