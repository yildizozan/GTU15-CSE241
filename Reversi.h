/*
* File:   Reversi.h
* Author: Ozan YILDIZ
*
* Created on November 12, 2015, 4:06 PM
*/

#ifndef REVERSI_H
#define	REVERSI_H

using namespace std;

class Reversi {
public:
	Reversi();
	Reversi(const int);

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

	// Play game functions
	void play();
	void play(const int, const string);

	// Other
	void score();
	void newValue();

	// Operator Overloading

private:
	int row, column;	// Row and Column
	int who;			// Siranin kimde oldugunu tutuyor
	int gameOver;		// It check game for game over!
	int playerScore, AIScore;

	vector< vector<Cell> > gameCell;

	// Other
	void expand(const int, const int);
	void refresh();
	void adding(const int, const string);
	void control(const int, const string);
	void calculate(const int, const int, const char);
	
};

#endif	/* REVERSI_H */