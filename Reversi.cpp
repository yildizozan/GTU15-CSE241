/*
* File:   Reversi.cpp
* Author: ozan
*
* Created on November 12, 2015, 4:09 PM
*/
#include <vector>
#include <iostream>
#include <string>

#include "Cell.h"
#include "Reversi.h"


using namespace std;

Reversi::Reversi()
	: row(2), column(2)
{
	gameCell.resize(row);
	for (int i = 0; i < row; i++)
		gameCell[i].resize(column);

	expand();

	gameCell[1][1] = Cell(1, 'X');
	gameCell[1][2] = Cell(1, 'O');
	gameCell[2][1] = Cell(1, 'O');
	gameCell[2][2] = Cell(1, 'X');

}

// Mutator & Accessor Functions

// Input & Output Functions
void Reversi::input(const int newAxisX, const char newAxisY)
{

}

// Output function
void Reversi::output(void)
{
	for (int i = 0; i < row + 1; i++)
	{
		if (i < row)
		{
			cout << i + 1 << "\t";

			for (int j = 0; j < column; j++)
				cout << " " << gameCell[i][j].get_Who() << " ";
			cout << "\n";
		}
		else
		{
			cout << "\t";

			for (int k = 0; k < column; k++)
			{
				cout << "x" << k+1 << " ";
			}	// end for j = 97
		}
	}

	expand();
}

void Reversi::expand()
{
	gameCellTemp = gameCell;

	// New row value
	int temp = getRow();
	setRow(temp + 2);

	// Row expand for gameCell
	gameCell.resize(getRow());

	// New column value
	temp = getColumn();
	setColumn(temp + 2);

	// Column expand for gameCell
	for (int i = 0; i < gameCell.size(); i++)
		gameCell[i].resize(getColumn());

	// All member of vector should be zero
	for (int i = 0; i < getRow(); i++)
		for (int j = 0; j < getColumn(); j++)
		{
			gameCell[i][j] = Cell();
			string str = "x" + to_string(j+1);
			gameCell[i][j] = Cell(i+1, str, 217);

		}
	copy();
}

void Reversi::copy()
{
	// Create new matrix
	for (int i = 0; i < getRow() - 2; i++)
		for (int j = 0; j < getColumn() - 2; j++)
			gameCell[i + 1][j + 1] = gameCellTemp[i][j];

}