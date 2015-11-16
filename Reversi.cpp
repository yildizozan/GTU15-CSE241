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
	: row(2), column(2), gameOver(0), who(0), playerScore(0), AIScore(0) // ba?lang?ç de?erleri
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
void Reversi::input(const int newAxisX, const string newAxisY)
{
	find(newAxisX, newAxisY);
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
			}
		}
	}

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

void Reversi::find(const int x, const string y)
{
	char z;
	if (getWho() == 0)
	{
		z = 'X';
	}
	else if (getWho() == 1)
	{
		z = 'O';
	}
	else
	{
		z = 217;
	}

	for (int i = 0; i < getRow(); i++)
	{
		if (gameCell[i][0].get_AxisX() == x)
		{

			for (int j = 0; j < getColumn(); j++)
			{
				if (gameCell[i][j].get_AxisY() == y)
				{
					gameCell[i][j] = Cell(x, y, z);		// Koordinattaki veriyi de?i?tirir.
					if (1 == i + 1 || i + 1 == getRow() || 1 == j + 1 || j + 1 == getColumn())	// E?er koordinatlar s?n?rda ise geni?letir.
					{
						expand();
					}
				}
			}
		}
	}
}

void Reversi::score()
{
	int countPlayer = 0;
	int countAI = 0;

	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			if (gameCell[i][j].get_Who() == 'O')
			{
				countPlayer++;
			}
			else if (gameCell[i][j].get_Who() == 'X')
			{
				countAI++;
			}
		}
	}

	setPlayerScore(countPlayer);
	setAIScore(countAI);
}
