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

