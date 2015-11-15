/*
* File:   Cell.h
* Author: ozan
*
* Created on November 12, 2015, 4:06 PM
*/

#ifndef CELL_H
#define	CELL_H

class Cell {
public:
	Cell();
	Cell(const Cell& copyCell);
	Cell(char);
	Cell(int, char, char);

	// Mutator & Accessor Functions
	int get_AxisX() const { return axisX; }
	char get_AxisY() const { return axisY; }
	char get_Who() const { return who; }


private:
	int axisX;
	char axisY;
	char who;
};

#endif	/* CELL_H */

