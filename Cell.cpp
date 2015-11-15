/*
* File:   Cell.cpp
* Author: ozan
*
* Created on November 12, 2015, 4:06 PM
*/

#include <iostream>
#include <vector>
#include "Cell.h"

Cell::Cell()
	: axisX(0), axisY(' '), who(' ')
{

}

Cell::Cell(const Cell& copyCell)
{
	axisX = copyCell.axisX;
	axisY = copyCell.axisY;
	who = copyCell.who;
}

Cell::Cell(int newAxisX, char newAxisY, char newWho)
	: axisX(newAxisX), axisY(newAxisY), who(newWho)
{

}
