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
	: dim(2), gameOver(0), who(0), playerScore(0), AIScore(0) // ba?lang?ç de?erleri
{
	gameCell.resize(getDim());
	for (int i = 0; i < getDim(); i++)
		gameCell[i].resize(getDim());

	expand();

	gameCell[1][1] = Cell(2, "x2", 'X');
	gameCell[1][2] = Cell(2, "x3", 'O');
	gameCell[2][1] = Cell(3, "x2", 'O');
	gameCell[2][2] = Cell(3, "x3", 'X');

}


// Input & Output Functions
void Reversi::input(const int newAxisX, const string newAxisY)
{
	find(newAxisX, newAxisY);
}

// Output function
void Reversi::output(void)
{
	for (int i = 0; i < getDim() + 1; i++)
	{
		if (i < getDim())
		{
			cout << i + 1 << "\t";

			for (int j = 0; j < getDim(); j++)
				cout << " " << gameCell[i][j].get_Who() << " ";
			cout << "\n";
		}
		else
		{
			cout << "\t";

			for (int k = 0; k < getDim(); k++)
			{
				cout << "x" << k+1 << " ";
			}
		}
	}

}

// Other
void Reversi::score() // Her defas?nda puanlar ba?tan say?lacak
{
	int countPlayer = 0;
	int countAI = 0;

	for (int i = 0; i < getDim(); i++)
	{
		for (int j = 0; j < getDim(); j++)
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

	setPlayerScore(countPlayer - 2);
	setAIScore(countAI - 2);
}

// Private Functions
void Reversi::expand()
{
	gameCellTemp = gameCell;


	// New row value
	int temp = getDim();
	setDim(temp + 2);

	// Row expand for gameCell
	gameCell.resize(getDim());

	// Column expand for gameCell
	for (int i = 0; i < gameCell.size(); i++)
		gameCell[i].resize(getDim());

	// All member of vector should be zero
	for (int i = 0; i < getDim(); i++)
		for (int j = 0; j < getDim(); j++)
		{
			string str = "x" + to_string(j + 1);		// Y koordinat?n? string ?eklinde olu?turur.
			gameCell[i][j] = Cell(i + 1, str, 217);	// ?lgili hücreye gerekli bilgiler doldurur.
		}

	// Create new matrix and copy (burada önceki matrixi kullanmal?y?m o sebeple -2)
	for (int i = 0; i < getDim() - 2; i++)
		for (int j = 0; j < getDim() - 2; j++)
			gameCell[i + 1][j + 1].setWho(gameCellTemp[i][j].get_Who()); // Eski tasla?? büyümü? olan matrixe kopyalar
}

void Reversi::refresh()
{
	gameCellTemp = gameCell;

	// All member of vector should be zero
	for (int i = 0; i < getDim(); i++)
		for (int j = 0; j < getDim(); j++)
		{
			string str = "x" + to_string(j + 1);		// Y koordinat?n? string ?eklinde olu?turur.
			gameCell[i][j] = Cell(i + 1, str, 217);	// ?lgili hücreye gerekli bilgiler doldurur.
		}

	// Create new matrix and copy (burada önceki matrixin boyutunu(dimension) kullanmal?y?m -2)
	for (int i = 0; i < getDim() - 2; i++)
		for (int j = 0; j < getDim() - 2; j++)
			gameCell[i][j].setWho(gameCellTemp[i][j].get_Who()); // Eski tasla?? büyümü? olan matrixe kopyalar

}

void Reversi::find(const int x, const string y)	// Uygun karakterde
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
		z = '-';
	}
	for (int i = 0; i < getDim(); i++)
	{
		if (gameCell[i][0].get_AxisX() == x)	// Uygun sat?r? h?zl?ca buluyoruz
		{
			for (int j = 0; j < getDim(); j++)
			{
				if (gameCell[i][j].get_AxisY() == y) // Uygun sat?rdaki sütunu buluyoruz
				{
					if (1 == i + 1 || i + 1 == getDim() || 1 == j + 1 || j + 1 == getDim())	// E?er koordinatlar s?n?rda ise geni?letir.
					{
						expand();
						gameCell[i + 1][j + 1] = Cell(z);	// ?lgili hücreye gerekli bilgiler doldurur.
					}
					else
					{
						refresh();
						gameCell[i][j] = Cell(z);	// ?lgili hücreye gerekli bilgiler doldurur.
					}
				}
			}
		}
	}

}


