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
	int get_Row() const { return row; }
	void set_Row(const int newRow) { row = newRow; }

	int get_Column() const { return column; }
	void set_Column(const int newColumn) { column = newColumn; }

	// Input & Output Function
	void input(const int, const char);
	void output(void);


private:
	int row, column;

	vector< vector<Cell> > gameCell;



};

#endif	/* REVERSI_H */


