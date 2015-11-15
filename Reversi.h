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

    
    const int get_row() const { return row; }
    const int get_column() const { return column; }

private:
    int row, column;
    
    vector< vector<Cell> > gameCell;

};

#endif	/* REVERSI_H */

    
