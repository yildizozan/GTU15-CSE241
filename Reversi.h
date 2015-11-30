/*
* File:   Cell.cpp
* Author: Ozan YILDIZ
*
* Created on November 25, 2015, 4:06 PM
*/

#ifndef REVERSI_H
#define REVERSI_H

#include <vector>
#include <string>
#include "Cell.h"

using namespace std;

class Reversi {
public:
    Reversi();
	Reversi(const int, const int);
    Reversi(const Reversi& orig);
    
    // Play Functions
    void playGame();
    void playGame(const int, const string);
    
    // Output Function
    void output() const;
    
    // Ancestor & Mutators Functions
    int getRow() const { return row; }
    void setRow(const int temp) { row = temp; }
    
    int getColumn() const { return column; }
    void setColumn(const int temp) { column = temp; }
    
    char getWho() const { return who; }
    void setWho(const char newWho) { who = newWho; }
    
private:
    vector<vector<Cell> > gameCell;
    int who;
    
    int row, column;

	/* Other Functions */
	void expand(const int, const int);
	void refresh();
	void newValue();
	void controlValue(const int, const string, const char);
	int controlPosition(const int, const int, const char);
	void add(const int, const int);
	void fillCell(const int, const int, int, int);
};

#endif /* REVERSI_H */

