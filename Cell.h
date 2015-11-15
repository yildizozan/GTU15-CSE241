/*
* File:   Cell.h
* Author: ozan
*
* Created on November 12, 2015, 4:06 PM
*/

#ifndef CELL_H
#define	CELL_H

using namespace std;

class Cell {
public:
	Cell();
	Cell(const Cell& copyCell);
	Cell(string);
	Cell(char);
	Cell(int, char);
	Cell(int, string, char);

	// Mutator & Accessor Functions
	int get_AxisX() const { return axisX; }
	string get_AxisY() const { return axisY; }
	char get_Who() const { return who; }


private:
	int axisX;
	string axisY;
	char who;
};

#endif	/* CELL_H */

