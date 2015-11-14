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
    Cell(int);
    Cell(int, int);
    
    private:
        int axisX;
        int axisY;
        int who;
};

#endif	/* CELL_H */

