/*
* File:   Reversi.h
* Author: ozan
*
* Created on November 12, 2015, 4:09 PM
*/

#ifndef REVERSI_H
#define	REVERSI_H

using namespace std;

class Reversi {
public:
	Reversi();

	// Mutator & Accessor
	int getRow() { return row; }
	void setRow(const int newRow) { row = newRow; }

	int getColumn() { return column; }
	void setColumn(const int newColumn) { column = newColumn; }

	// Input & Output Function
	void input(const int, const char);
	void output(void);

	// Other

private:
	int row, column;

	vector< vector<Cell> > gameCell;
	vector< vector<Cell> > gameCellTemp;

	// Other
	void expand();
	void copy();




};

#endif	/* REVERSI_H */


