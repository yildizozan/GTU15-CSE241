/*
* File:   Cell.cpp
* Author: ozan
*
* Created on November 12, 2015, 4:06 PM
*/

#include <iostream>
#include <string>

#include "Cell.h"

Cell::Cell()
	: axisX(NULL), axisY(" "), who(NULL)
{

}

Cell::Cell(const Cell& copyCell)
{
	axisX = copyCell.axisX;
	axisY = copyCell.axisY;
	who = copyCell.who;
}

Cell::Cell(char newWho)
	: who(newWho)
{

}


Cell::Cell(int newAxisX, char newWho)
	: axisX(newAxisX), who(newWho)
{
}

Cell::Cell(int newAxisX, string newAxisY, char newWho)
	: axisX(newAxisX), axisY(newAxisY), who(newWho)
{

}
