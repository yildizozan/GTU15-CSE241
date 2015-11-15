/* 
 * File:   Reversi.cpp
 * Author: ozan
 * 
 * Created on November 12, 2015, 4:09 PM
 */
#include <vector>
#include <iostream>
#include "Cell.h"
#include "Reversi.h"


using namespace std;

Reversi::Reversi()
    :row(2), column(3)
{
    gameCell.resize(3);
    for(int i=0; i < 1; i++)
        gameCell[i].resize(1);
}

// Get functions

