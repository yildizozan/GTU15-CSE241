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
<<<<<<< HEAD
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
//  PLAY FUNCTION-S
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

void Reversi::playGame()
{
}

void Reversi::playGame(const int x, const string y)
{
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

	refresh();

	int xp = (getRow() / 2) - 1;
	int yp = (getColumn() / 2) - 1;

	gameCell[xp][yp] = Cell('X');
	gameCell[xp][yp + 1] = Cell('O');
	gameCell[xp + 1][yp] = Cell('O');
	gameCell[xp + 1][yp + 1] = Cell('X');

}

void Reversi::refresh()
{
	// All member of vector should be zero
	for (int i = 0; i < getRow(); i++)
		for (int j = 0; j < getColumn(); j++)
		{
			string str = "y" + to_string(j + 1);		// Y koordinatini string seklinde olusturur.
			gameCell[i][j] = Cell(i + 1, str, 0);	// ?lgili hücreye gerekli bilgiler doldurur.
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
			controlPosition(x - 1, temp, getWho());
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

}


/*
*      A-------B
*      |       |
*      |       |
*      |       |
*      D-------C
*/
bool Reversi::controlPosition(int x, int y, const char who) // argümanlar const olmamal? çünkü de?erleri de?i?ecek
{

	int tempI = x;
	int tempJ = y;

	x = tempI;
	y = tempJ;

	int count = 0;

	if (gameCell[x][y].getWho() == 0)
	{
		// A Corner
		if (x == 0 && y == 0)
		{
			if (gameCell[x][y + 1].getWho() != who && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				while (gameCell[x][y + 1].getWho() != who && gameCell[x][y + 1].getWho() != 0)
				{
					++count;
					++y;
				}
			}
			x = tempI;
			y = tempJ;
			if (gameCell[x + 1][y].getWho() != who && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				while (gameCell[x + 1][y].getWho() != who && gameCell[x + 1][y].getWho() != 0)
				{
					++count;
					++x;
				}
			}
			x = tempI;
			y = tempJ;
			if (gameCell[x + 1][y + 1].getWho() != who && gameCell[x + 1][y + 1].getWho() != 0)     //  8
			{
				while (gameCell[x + 1][y + 1].getWho() != who && gameCell[x + 1][y + 1].getWho() != 0)
				{
					++count;
					++x;
					++y;
				}
			}
			// Count
			if (0 == count)
			{
				newValue();
			}
			else
			{
				add(x, y);
			}
		}

		// B Corner
		else if (x == 0 && y == getRow() - 1)
		{
			if (gameCell[x][y - 1].getWho() != who && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y - 1].getWho() != who && gameCell[x + 1][y - 1].getWho() != 0)     //  6
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y].getWho() != who && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				// asdasdasdasdasdasd
			}
		}

		// C Corner
		else if (x == getRow() - 1 && y == getColumn() - 1)
		{
			if (gameCell[x - 1][y - 1].getWho() != who && gameCell[x - 1][y - 1].getWho() != 0)     //  1
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x - 1][y].getWho() != who && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x][y - 1].getWho() != who && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				// asdasdasdasdasdasd
			}
		}

		// D Corner
		else if (x == getRow() - 1 && y == 0)
		{
			if (gameCell[x - 1][y].getWho() != who && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x - 1][y + 1].getWho() != who && gameCell[x - 1][y].getWho() != 0)         //  3
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x][y + 1].getWho() != who && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				// asdasdasdasdasdasd
			}
		}

		// A-B Side
		else if (x == 0)
		{
			if (gameCell[x][y - 1].getWho() != who && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x][y + 1].getWho() != who && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y - 1].getWho() != who && gameCell[x + 1][y - 1].getWho() != 0)     //  6
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y].getWho() != who && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y + 1].getWho() != who && gameCell[x + 1][y + 1].getWho() != 0)		//  8
			{
				// asdasdasdasdasdasd
			}
		}

		// B-C Side
		else if (y == getColumn() - 1)
		{
			if (gameCell[x - 1][y - 1].getWho() != who && gameCell[x - 1][y - 1].getWho() != 0)     //  1
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x - 1][y].getWho() != who && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x][y - 1].getWho() != who && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y - 1].getWho() != who && gameCell[x + 1][y - 1].getWho() != 0)     //  6
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y].getWho() != who && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				// asdasdasdasdasdasd
			}
		}

		// C-D Side
		else if (x == getRow() - 1)
		{
			if (gameCell[x - 1][y - 1].getWho() != who && gameCell[x - 1][y - 1].getWho() != 0)     //  1
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x - 1][y].getWho() != who && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x - 1][y + 1].getWho() != who && gameCell[x - 1][y].getWho() != 0)         //  3
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x][y - 1].getWho() != who && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x][y + 1].getWho() != who && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				// asdasdasdasdasdasd
			}
		}

		// D-A Side
		else if (y == 0)
		{
			if (gameCell[x - 1][y].getWho() != who && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x - 1][y + 1].getWho() != who && gameCell[x - 1][y].getWho() != 0)         //  3
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x][y + 1].getWho() != who && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y].getWho() != who && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y + 1].getWho() != who && gameCell[x + 1][y + 1].getWho() != 0)		//  8
			{
				// asdasdasdasdasdasd
			}
		}
		
		// Ortalarda
		else if (0 < x && x < getRow() && 0 < y && y < getColumn())
		{
			if (gameCell[x - 1][y - 1].getWho() != who && gameCell[x - 1][y - 1].getWho() != 0)     //  1
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x - 1][y].getWho() != who && gameCell[x - 1][y].getWho() != 0)             //  2
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x - 1][y + 1].getWho() != who && gameCell[x - 1][y].getWho() != 0)         //  3
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x][y - 1].getWho() != who && gameCell[x][y - 1].getWho() != 0)             //  4
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x][y + 1].getWho() != who && gameCell[x][y + 1].getWho() != 0)             //  5
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y - 1].getWho() != who && gameCell[x + 1][y - 1].getWho() != 0)     //  6
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y].getWho() != who && gameCell[x + 1][y].getWho() != 0)             //  7
			{
				// asdasdasdasdasdasd
			}
			if (gameCell[x + 1][y + 1].getWho() != who && gameCell[x + 1][y + 1].getWho() != 0)		//  8
			{
				// asdasdasdasdasdasd
			}
		}
	}
	else
	{
		newValue();
	}

	return false;
}

void Reversi::add(const int, const int)
{
}

=======
    : row(5), column(6), who(0)
{
    gameCell.resize(getRow());
    for (int i = 0; i < getRow(); i++)
        gameCell[i].resize(getColumn());

    gameCell[0][0] = Cell();
    gameCell[0][1] = Cell();
    gameCell[1][0] = Cell();
    gameCell[1][1] = Cell();
        gameCell[1][2] = Cell();
}

Reversi::Reversi(const Reversi& orig)
{
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  PLAY FUNCTIONS
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

void playGame()
{

}

void playGame(const int x, const string y)
{

}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  OUTPUT FUNCTION
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

void Reversi::output() const
{
    for (int i = 0; i < getRow(); i++)
    {
        for (int j = 0; j < getColumn(); j++)
        {
            if (gameCell[i][j].getWho() == 0)
                cout << " - ";
            else
            {
                cout << gameCell[i][j].getWho();
                cout << " i ";
            }
        }
        cout << "\n";
    }
    
    return;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  OTHER
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

/*
 *      A-------B
 *      |       |
 *      |       |
 *      |       |
 *      D-------C
 */
bool Reversi::control(const int x, const int y, const char who)
{
    vector<vector<Cell> > gameCellTemp;
    gameCellTemp = gameCell;
    
    // A Corner
    if (x == 0, y == 0)
    {
        if (gameCellTemp[x][y].getWho() == 0)
        {
            if (gameCellTemp[x][y + 1].getWho() != who && gameCellTemp[x][y + 1].getWho() != 0)             //  5
            {
            // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y].getWho() != who && gameCellTemp[x + 1][y].getWho() != 0)             //  7
            {
            // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y + 1].getWho() != who && gameCellTemp[x + 1][y + 1].getWho() != 0)     //  8
            {
            // asdasdasdasdasdasd
            }
        }
    }
    
    // B Corner
    else if (x == 0, y == getRow() - 1)
    {
        if (gameCellTemp[x][y].getWho() == 0)
        {
            if (gameCellTemp[x][y - 1].getWho() != who && gameCellTemp[x][y - 1].getWho() != 0)             //  4
            {
            // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y - 1].getWho() != who && gameCellTemp[x + 1][y - 1].getWho() != 0)     //  7
            {
            // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y].getWho() != who && gameCellTemp[x + 1][y].getWho() != 0)             //  8
            {
            // asdasdasdasdasdasd
            }
        }
    }
    
    // C Corner
    else if (x == getRow() - 1, y == 0)
    {
        if (gameCellTemp[x][y].getWho() == 0)
        {
            if (gameCellTemp[x - 1][y - 1].getWho() != who && gameCellTemp[x - 1][y - 1].getWho() != 0)     //  1
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x - 1][y].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)             //  2
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y - 1].getWho() != who && gameCellTemp[x][y - 1].getWho() != 0)             //  4
            {
               // asdasdasdasdasdasd
            }
        }
    }
    
    // D Corner
    else if (x == getRow() - 1, y == getColumn() - 1)
    {
        if (gameCellTemp[x][y].getWho() == 0)
        {
            if (gameCellTemp[x - 1][y].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)             //  2
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x - 1][y + 1].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)         //  3
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y + 1].getWho() != who && gameCellTemp[x][y + 1].getWho() != 0)             //  5
            {
               // asdasdasdasdasdasd
            }
        }
    }
    
    // A-B Side
    else if (x == 0)
    {
        if (gameCellTemp[x][y].getWho() == 0)
        {
            if (gameCellTemp[x][y - 1].getWho() != who && gameCellTemp[x][y - 1].getWho() != 0)             //  4
            {
               // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y + 1].getWho() != who && gameCellTemp[x][y + 1].getWho() != 0)             //  5
            {
               // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y - 1].getWho() != who && gameCellTemp[x + 1][y - 1].getWho() != 0)     //  6
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y].getWho() != who && gameCellTemp[x + 1][y].getWho() != 0)             //  7
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y - 1].getWho() != who && gameCellTemp[x][y - 1].getWho() != 0)             //  8
            {
                // asdasdasdasdasdasd
            }
        }
    }
    
    // B-C Side
    else if (y == getColumn() - 1)
    {
        if (gameCellTemp[x][y].getWho() == 0)
        {
            if (gameCellTemp[x - 1][y - 1].getWho() != who && gameCellTemp[x - 1][y - 1].getWho() != 0)     //  1
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x - 1][y].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)             //  2
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y - 1].getWho() != who && gameCellTemp[x][y - 1].getWho() != 0)             //  4
            {
               // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y - 1].getWho() != who && gameCellTemp[x + 1][y - 1].getWho() != 0)     //  6
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y].getWho() != who && gameCellTemp[x + 1][y].getWho() != 0)             //  7
            {
                // asdasdasdasdasdasd
            }
        }
    }
    
    // C-D Side
    else if (x == getRow() - 1)
    {
        if (gameCellTemp[x][y].getWho() == 0)
        {
            if (gameCellTemp[x - 1][y - 1].getWho() != who && gameCellTemp[x - 1][y - 1].getWho() != 0)     //  1
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x - 1][y].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)             //  2
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x - 1][y + 1].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)         //  3
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y - 1].getWho() != who && gameCellTemp[x][y - 1].getWho() != 0)             //  4
            {
               // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y + 1].getWho() != who && gameCellTemp[x][y + 1].getWho() != 0)             //  5
            {
               // asdasdasdasdasdasd
            }
        }
    }
    
    // D-A Side
    else if (y == 0)
    {
        if (gameCellTemp[x][y].getWho() == 0)
        {
            if (gameCellTemp[x - 1][y].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)             //  2
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x - 1][y + 1].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)         //  3
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y + 1].getWho() != who && gameCellTemp[x][y + 1].getWho() != 0)             //  5
            {
               // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y - 1].getWho() != who && gameCellTemp[x + 1][y - 1].getWho() != 0)     //  6
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y - 1].getWho() != who && gameCellTemp[x][y - 1].getWho() != 0)             //  8
            {
                // asdasdasdasdasdasd
            }
        }
    }
    
    else
    {
        if (gameCellTemp[x][y].getWho() == 0)
        {
            if (gameCellTemp[x - 1][y - 1].getWho() != who && gameCellTemp[x - 1][y - 1].getWho() != 0)     //  1
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x - 1][y].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)             //  2
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x - 1][y + 1].getWho() != who && gameCellTemp[x - 1][y].getWho() != 0)         //  3
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y - 1].getWho() != who && gameCellTemp[x][y - 1].getWho() != 0)             //  4
            {
               // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y + 1].getWho() != who && gameCellTemp[x][y + 1].getWho() != 0)             //  5
            {
               // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y - 1].getWho() != who && gameCellTemp[x + 1][y - 1].getWho() != 0)     //  6
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x + 1][y].getWho() != who && gameCellTemp[x + 1][y].getWho() != 0)             //  7
            {
                // asdasdasdasdasdasd
            }
            if (gameCellTemp[x][y - 1].getWho() != who && gameCellTemp[x][y - 1].getWho() != 0)             //  8
            {
                // asdasdasdasdasdasd
            }
        }
    }
    
}

void Reversi::newValue()
{
    
    cout << "\nX again: ";
    int a;
    cin >> a;
    
    cout << "\nY again: ";
    string b;
    cin >> b;
    
    find(a, b);
    return;
}

void Reversi::find(const int x, const string y)
{
   vector<vector<Cell> > gameCellTemp;
    gameCellTemp = gameCell;
    
    int axisX, axisY;
     
    for (int i = 0; i < getRow(); ++i)
        for (int j = 0; j < getColumn(); ++j)
           if (gameCellTemp[i][j].getRow() == x && gameCellTemp[i][j].getColumn() == y)
           {
               axisX = i;
               axisY = j;
           }
    
    control(axisX, axisY, getWho());
    return;
}
>>>>>>> origin/master
