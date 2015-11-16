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
	int getDim() { return dim; }
	void setDim(const int newDim) { dim = newDim; }

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
	void score();

private:
	int dim;	// Row and Column
	int who;			// S?ran?n kimde oldu?unu tutuyor
	int gameOver;		// It check game for game over!
	int playerScore, AIScore;

	vector< vector<Cell> > gameCell;
	vector< vector<Cell> > gameCellTemp;

	// Other
	void expand();
	void refresh();
	void find(const int, const string);




};

#endif	/* REVERSI_H */


