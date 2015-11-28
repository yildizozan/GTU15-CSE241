/*
* File:   Cell.cpp
* Author: Ozan YILDIZ
*
* Created on November 25, 2015, 4:06 PM
*/

#include <string>
#include <iostream>

#include "Cell.h"

Cell::Cell()
{
    who = '2';
}

Cell::Cell(const int newAxisX, const string newAxisY, const char newWho)
	: axisX(newAxisX), axisY(newAxisY), who(newWho)
{
}

Cell::Cell(const Cell& orig)
{
}

