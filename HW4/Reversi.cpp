/*
* File:   Cell.cpp
* Author: Ozan YILDIZ
*
* Created on November 25, 2015, 4:06 PM
*/


#include <vector>
#include <string>
#include <iostream>

#include "Cell.h"
#include "Reversi.h"


Reversi::Reversi()
    : row(8), column(8), who(0)
{
	expand(getRow(), getColumn());
}

Reversi::Reversi(const int x, const int y)
	: row(x), column(y)
{
	expand(x, y);
}

Reversi::Reversi(const Reversi& orig)
{
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  PLAY FUNCTIONS
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

void Reversi::playGame()
{
	setWho('X');

	vector<Cell> AIBPosition;
	vector<int> AIBScore;

	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			AIBPosition.push_back(gameCell[i][j]);
			AIBScore.push_back(controlPosition(i, j));
		}
	}
}

void Reversi::playGame(const int x, const string y)
{
	setWho('O');


	controlValue(x, y, 'O');
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  OUTPUT FUNCTION
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-



void Reversi::output() const
{
    for (int i = 0; i < getRow() + 1; i++)
    {
		if (i < getRow())
		{
			cout << i + 1 << "\t|";
			for (int j = 0; j < getColumn(); j++)
			{
				if (gameCell[i][j].getWho() == 0)
				{
					cout << " - ";
				}
				else
				{
					cout << " " << gameCell[i][j].getWho() << " ";
				}
			}
			cout << "\n";
		}
		else
		{
			cout << "\t ";
			for (int k = 0; k < getColumn(); k++)
			{
				cout << "y" << k + 1 << " ";
			}
		}
    }
    
    return;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  OTHER
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

void Reversi::expand(const int x, const int y)
{
	gameCell.resize(getRow());
	for (int i = 0; i < getRow(); i++)
		gameCell[i].resize(getColumn());


	int xp = (getRow() / 2) - 1;
	int yp = (getColumn() / 2) - 1;

	refresh();
	gameCell[xp][yp].setWho('X');
	gameCell[xp][yp + 1].setWho('O');
	gameCell[xp + 1][yp].setWho('O');
	gameCell[xp + 1][yp + 1].setWho('X');
}

void Reversi::refresh()
{
	// All member of vector should be zero
	for (int i = 0; i < getRow(); i++)
		for (int j = 0; j < getColumn(); j++)
		{
			string str = "y" + to_string(j + 1);		// Y koordinatini string seklinde olusturur.
			gameCell[i][j] = Cell(i + 1, str, 0);		// ?lgili hücreye gerekli bilgiler doldurur.
		}
}

void Reversi::newValue()
{
    cout << "\nX again: ";
    int a;
    cin >> a;
    
    cout << "Y again: ";
    string b;
    cin >> b;
    
	controlValue(a, b, getWho());
    return;
}

// Girilen degerin karsiligi varmi diye control ediyoruz.
// Eger yanlis girilmisse tekrar girmesini sagliyoruz.
void Reversi::controlValue(const int x, const string y, const char z)
{
	if (z == 'O') setWho(z);
	else if (z == 'X') setWho(z);

	int temp = -1;

	if (0 < x && x <= getRow())
	{
		for (int j = 0; j < getColumn(); ++j)
			if (gameCell[x - 1][j].getColumn() == y)
			{
				temp = j;
			}
		if (temp != -1)
		{
			controlPosition(x - 1, temp);
		}
		else
		{
			newValue();
		}
	}
	else
	{
		newValue();
	}
	return;
}


/*
*      A-------B
*      |       |
*      |       |
*      |       |
*      D-------C
*/
int Reversi::controlPosition(int x, int y) // argümanlar const olmamal? çünkü de?erleri de?i?ecek
{

	int tempI = x;
	int tempJ = y;

	int count = 0;

	if (gameCell[x][y].getWho() == 0)
	{
		// A Corner
		if (x == 0 && y == 0)
		{
			if (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				while (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)
				{
					++count;
					++y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				while (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)
				{
					++count;
					++x;
				}
			}

			x = tempI;
			y = tempJ;
			if (gameCell[x + 1][y + 1].getWho() != getWho() && gameCell[x + 1][y + 1].getWho() != 0)		//  8
			{
				while (gameCell[x + 1][y + 1].getWho() != getWho() && gameCell[x + 1][y + 1].getWho() != 0)
				{
					++count;
					++x;
					++y;
				}
			}
			// Count
			if (0 == count && getWho() == 'O')
			{
				newValue();
			}
			else if (0 == count && getWho() == 'X')
			{
				return 0;
			}
			else if (0 != count && getWho() == 'X')
			{
				return count;
			}
			else
			{
				add(x, y);
			}
		}

		// B Corner
		else if (x == 0 && y == getRow() - 1)
		{
			if (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				while (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)
				{
					++count;
					--y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x + 1][y - 1].getWho() != getWho() && gameCell[x + 1][y - 1].getWho() != 0)     //  6
			{
				while (gameCell[x + 1][y - 1].getWho() != getWho() && gameCell[x + 1][y - 1].getWho() != 0)
				{
					++count;
					++x;
					--y;
				}
			}

			x = tempI;
			y = tempJ;
			if (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				while (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)
				{
					++count;
					++x;
				}
			}
			// Count
			if (0 == count && getWho() == 'O')
			{
				newValue();
			}
			else if (0 == count && getWho() == 'X')
			{
				return 0;
			}
			else if (0 != count && getWho() == 'X')
			{
				return count;
			}
			else
			{
				add(x, y);
			}
		}

		// C Corner
		else if (x == getRow() - 1 && y == getColumn() - 1)
		{
			if (gameCell[x - 1][y - 1].getWho() != getWho() && gameCell[x - 1][y - 1].getWho() != 0)     //  1
			{
				while (gameCell[x - 1][y - 1].getWho() != getWho() && gameCell[x - 1][y - 1].getWho() != 0)
				{
					++count;
					--x;
					--y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				while (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
				}
			}

			x = tempI;
			y = tempJ;

			if (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				while (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)
				{
					++count;
					--y;
				}
			}
			// Count
			if (0 == count && getWho() == 'O')
			{
				newValue();
			}
			else if (0 == count && getWho() == 'X')
			{
				return 0;
			}
			else if (0 != count && getWho() == 'X')
			{
				return count;
			}
			else
			{
				add(x, y);
			}
		}

		// D Corner
		else if (x == getRow() - 1 && y == 0)
		{
			if (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				while (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x - 1][y + 1].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)         //  3
			{
				while (gameCell[x - 1][y + 1].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
					++y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				while (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)
				{
					++count;
					++y;
				}
			}
			// Count
			if (0 == count && getWho() == 'O')
			{
				newValue();
			}
			else if (0 == count && getWho() == 'X')
			{
				return 0;
			}
			else if (0 != count && getWho() == 'X')
			{
				return count;
			}
			else
			{
				add(x, y);
			}
		}

		// A-B Side
		else if (x == 0)
		{
			if (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				while (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)
				{
					++count;
					--y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				while (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)
				{
					++count;
					++y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x + 1][y - 1].getWho() != getWho() && gameCell[x + 1][y - 1].getWho() != 0)     //  6
			{
				while (gameCell[x + 1][y - 1].getWho() != getWho() && gameCell[x + 1][y - 1].getWho() != 0)
				{
					++count;
					++x;
					--y;
				}
			}

			x = tempI;
			y = tempJ;
			if (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				while (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)
				{
					++count;
					++x;
				}
			}

			x = tempI;
			y = tempJ;
			if (gameCell[x + 1][y + 1].getWho() != getWho() && gameCell[x + 1][y + 1].getWho() != 0)		//  8
			{
				while (gameCell[x + 1][y + 1].getWho() != getWho() && gameCell[x + 1][y + 1].getWho() != 0)
				{
					++count;
					++x;
					++y;
				}
			}
			// Count
			if (0 == count && getWho() == 'O')
			{
				newValue();
			}
			else if (0 == count && getWho() == 'X')
			{
				return 0;
			}
			else if (0 != count && getWho() == 'X')
			{
				return count;
			}
			else
			{
				add(x, y);
			}
		}

		// B-C Side
		else if (y == getColumn() - 1)
		{
			if (gameCell[x - 1][y - 1].getWho() != getWho() && gameCell[x - 1][y - 1].getWho() != 0)     //  1
			{
				while (gameCell[x - 1][y - 1].getWho() != getWho() && gameCell[x - 1][y - 1].getWho() != 0)
				{
					++count;
					--x;
					--y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				while (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				while (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)
				{
					++count;
					--y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x + 1][y - 1].getWho() != getWho() && gameCell[x + 1][y - 1].getWho() != 0)     //  6
			{
				while (gameCell[x + 1][y - 1].getWho() != getWho() && gameCell[x + 1][y - 1].getWho() != 0)
				{
					++count;
					++x;
					--y;
				}
			}

			x = tempI;
			y = tempJ;
			if (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				while (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)
				{
					++count;
					++x;
				}
			}
			// Count
			if (0 == count && getWho() == 'O')
			{
				newValue();
			}
			else if (0 == count && getWho() == 'X')
			{
				return 0;
			}
			else if (0 != count && getWho() == 'X')
			{
				return count;
			}
			else
			{
				add(x, y);
			}
		}

		// C-D Side
		else if (x == getRow() - 1)
		{
			if (gameCell[x - 1][y - 1].getWho() != getWho() && gameCell[x - 1][y - 1].getWho() != 0)     //  1
			{
				while (gameCell[x - 1][y - 1].getWho() != getWho() && gameCell[x - 1][y - 1].getWho() != 0)
				{
					++count;
					--x;
					--y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				while (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x - 1][y + 1].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)         //  3
			{
				while (gameCell[x - 1][y + 1].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
					++y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				while (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)
				{
					++count;
					--y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				while (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)
				{
					++count;
					++y;
				}
			}
			// Count
			if (0 == count && getWho() == 'O')
			{
				newValue();
			}
			else if (0 == count && getWho() == 'X')
			{
				return 0;
			}
			else if (0 != count && getWho() == 'X')
			{
				return count;
			}
			else
			{
				add(x, y);
			}
		}

		// D-A Side
		else if (y == 0)
		{
			if (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				while (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x - 1][y + 1].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)         //  3
			{
				while (gameCell[x - 1][y + 1].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
					++y;
				}
			}
			x = tempI;
			y = tempJ;

			if (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				while (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)
				{
					++count;
					++y;
				}
			}

			x = tempI;
			y = tempJ;
			if (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				while (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)
				{
					++count;
					++x;
				}
			}

			x = tempI;
			y = tempJ;
			if (gameCell[x + 1][y + 1].getWho() != getWho() && gameCell[x + 1][y + 1].getWho() != 0)		//  8
			{
				while (gameCell[x + 1][y + 1].getWho() != getWho() && gameCell[x + 1][y + 1].getWho() != 0)
				{
					++count;
					++x;
					++y;
				}
			}
			// Count
			if (0 == count && getWho() == 'O')
			{
				newValue();
			}
			else if (0 == count && getWho() == 'X')
			{
				return 0;
			}
			else if (0 != count && getWho() == 'X')
			{
				return count;
			}
			else
			{
				add(x, y);
			}
		}

		// Ortalarda
		else
		{
			if (gameCell[x - 1][y - 1].getWho() != getWho() && gameCell[x - 1][y - 1].getWho() != 0)     //  1
			{
				while (gameCell[x - 1][y - 1].getWho() != getWho() && gameCell[x - 1][y - 1].getWho() != 0)
				{
					++count;
					--x;
					--y;
					if (gameCell[x - 1][y - 1].getWho() == 0)
					{
						count = 0;
					}
				}
				x = tempI;
				y = tempJ;
				if (count != 0 && getWho() == 'O')
				{
					fillCell(1, count, x, y);
				}
			}

			if (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				while (gameCell[x - 1][y].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
					if (gameCell[x - 1][y].getWho() == 0)
					{
						count = 0;
					}
				}
				x = tempI;
				y = tempJ;
				if (count != 0 && getWho() == 'O')
				{
					fillCell(2, count, x, y);
				}
			}

			if (gameCell[x - 1][y + 1].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)         //  3
			{
				while (gameCell[x - 1][y + 1].getWho() != getWho() && gameCell[x - 1][y].getWho() != 0)
				{
					++count;
					--x;
					++y;
					if (gameCell[x - 1][y + 1].getWho() == 0)
					{
						count = 0;
					}
				}
				x = tempI;
				y = tempJ;
				if (count != 0 && getWho() == 'O')
				{
					fillCell(3, count, x, y);
				}
			}

			if (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				while (gameCell[x][y - 1].getWho() != getWho() && gameCell[x][y - 1].getWho() != 0)
				{
					++count;
					--y;
					if (gameCell[x][y - 1].getWho() == 0)
					{
						count = 0;
					}
				}
				x = tempI;
				y = tempJ;
				if (count != 0 && getWho() == 'O')
				{
					fillCell(4, count, x, y);
				}
			}

			if (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				while (gameCell[x][y + 1].getWho() != getWho() && gameCell[x][y + 1].getWho() != 0)
				{
					++count;
					++y;
					if (gameCell[x][y + 1].getWho() == 0)
					{
						count = 0;
					}
				}
				x = tempI;
				y = tempJ;
				if (count != 0 && getWho() == 'O')
				{
					fillCell(5, count, x, y);
				}
			}

			if (gameCell[x + 1][y - 1].getWho() != getWho() && gameCell[x + 1][y - 1].getWho() != 0)     //  6
			{
				while (gameCell[x + 1][y - 1].getWho() != getWho() && gameCell[x + 1][y - 1].getWho() != 0)
				{
					++count;
					++x;
					--y;
					if (gameCell[x + 1][y - 1].getWho() == 0)
					{
						count = 0;
					}
				}
				x = tempI;
				y = tempJ;
				if (count != 0 && getWho() == 'O')
				{
					fillCell(6, count, x, y);
				}
			}

			if (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				while (gameCell[x + 1][y].getWho() != getWho() && gameCell[x + 1][y].getWho() != 0)
				{
					++count;
					++x;
					if (gameCell[x + 1][y].getWho() == 0)
					{
						count = 0;
					}
				}
				x = tempI;
				y = tempJ;
				if (count != 0 && getWho() == 'O')
				{
					fillCell(7, count, x, y);
				}
			}

			if (gameCell[x + 1][y + 1].getWho() != getWho() && gameCell[x + 1][y + 1].getWho() != 0)		//  8
			{
				while (gameCell[x + 1][y + 1].getWho() != getWho() && gameCell[x + 1][y + 1].getWho() != 0)
				{
					++count;
					++x;
					++y;
					if (gameCell[x + 1][y + 1].getWho() == 0)
					{
						count = 0;
					}
				}
				x = tempI;
				y = tempJ;
				if (count != 0 && getWho() == 'O')
				{
					fillCell(8, count, x, y);
				}
			}

			// Count
			if (0 == count && getWho() == 'O')
			{
				newValue();
			}
			else if (0 == count && getWho() == 'X')
			{
				return 0;
			}
			else if (0 != count && getWho() == 'X')
			{
				return count;
			}
			else
			{
				add(x, y);
			}
		}
	}
	else
	{
		newValue();
	}
	return 0;
}

void Reversi::add(const int x, const int y)
{
	if (getWho() == 'O')
	{
		gameCell[x][y].setWho('O');
	}
	else
	{
		gameCell[x][y].setWho('X');
	}
	return;
}

void Reversi::fillCell(const int mode, const int movement, int x, int y)
{
	int who, move = 0;

	if (getWho() == 'O') { who = 'O'; }
	else if (getWho() == 'X') { who = 'X'; }

	if (mode == 1)
	{
		while (move < movement)
		{
			gameCell[x - 1][y - 1].setWho(getWho());
			--x;
			--y;
			++move;
		}
	}
	else if (mode == 2)
	{
		while (move < movement)
		{
			gameCell[x - 1][y].setWho(getWho());
			--x;
			++move;
		}
	}
	else if (mode == 3)
	{
		while (move < movement)
		{
			gameCell[x - 1][y + 1].setWho(getWho());
			--x;
			--y;
			++move;
		}
	}
	else if (mode == 4)
	{
		while (move < movement)
		{
			gameCell[x][y - 1].setWho(getWho());
			--y;
			++move;
		}
	}
	else if (mode == 5)
	{
		while (move < movement)
		{
			gameCell[x][y + 1].setWho(getWho());
			++y;
			++move;
		}
	}
	else if (mode == 6)
	{
		while (move < movement)
		{
			gameCell[x + 1][y - 1].setWho(getWho());
			++x;
			--y;
			++move;
		}
	}
	else if (mode == 7)
	{
		while (move < movement)
		{
			gameCell[x + 1][y].setWho(getWho());
			++x;
			++move;
		}
	}
	else if (mode == 8)
	{
		while (move < movement)
		{
			gameCell[x + 1][y + 1].setWho(getWho());
			++x;
			++y;
			++move;
		}
	}

}
