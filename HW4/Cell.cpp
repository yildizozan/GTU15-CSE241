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
	: who(0)
{
}

Cell::Cell(const char newWho)
	: who(newWho)
{
}

Cell::Cell(const int newAxisX, const string newAxisY)
	: axisX(newAxisX), axisY(newAxisY)
{
}


Cell::Cell(const int newAxisX, const string newAxisY, const char newWho)
	: axisX(newAxisX), axisY(newAxisY), who(newWho)
{
}

Cell::Cell(const Cell& orig)
{
}

