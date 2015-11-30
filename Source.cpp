/*
* File:   Cell.cpp
* Author: Ozan YILDIZ
*
* Created on November 25, 2015, 4:06 PM
*/

#include <iostream>
#include "Reversi.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

	int laps = 0;

	Reversi game;

	while (true)
	{
		game.setWho(laps % 2);
		game.output();
		cout << "\nX: ";
		int x;
		cin >> x;

		cout << "Y: ";
		string y;
		cin >> y;

		game.playGame(x, y);
		//game.playGame();
		laps++;
		system("CLS");
	}

    return 0;
}

