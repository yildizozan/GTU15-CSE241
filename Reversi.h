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

	int getWho() const { return who; }
	void setWho(const int newWho) { who = newWho; }

	int getGameOver() const { return gameOver; }
	void setGameOver(const int newGameOver) { who = newGameOver; }

	int getPlayerScore() const { return playerScore; }
	void setPlayerScore(const int newPlayerScore) { playerScore = newPlayerScore; }

	int getAIScore() const { return AIScore; }
	void setAIScore(const int newAIScore) { AIScore = newAIScore; }

	// Input & Output Function
	void input(int, string);
	void output(void);

	// Other

private:
	int row, column;	// Row and Column
	int who;			// S?ran?n kimde oldu?unu tutuyor
	int gameOver;		// It check game for game over!
	int playerScore, AIScore;

	vector< vector<Cell> > gameCell;
	vector< vector<Cell> > gameCellTemp;

	// Other
	void expand();
	void copy();
	void find(const int, const string);
	void score();




};

#endif	/* REVERSI_H */


