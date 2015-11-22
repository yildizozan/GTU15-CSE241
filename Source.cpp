/*
* File:   main.cpp
* Author: Ozan YILDIZ
*
* Created on November 12, 2015, 4:06 PM
*/

#include <iostream>
#include <vector>
#include <string>

#include "Cell.h"
#include "Reversi.h"

using namespace std;

int main()
{
	int laps = 0;
	Reversi game(8);

	while (!game.getGameOver())
	{
		// Who is start game?
		int who = game.getWho();

		// Skorlar
		game.score();
		cout << "AI: " << game.getAIScore() << " | ";
		cout << "Player: " << game.getPlayerScore() << endl;;

		// Ekranda görmemizi saglar
		game.output();

		if (who == 0) // Oyuncu oynayacak demektir.
		{
			// X koordinatini girmemizi saglar
			cout << "\n";
			cout << "Axis X: ";
			int axisX = 1;
			cin >> axisX;

			// Y koordinatini girmemizi saglar
			cout << "Axis Y: ";
			string axisY = "x1";
			cin >> axisY;

			game.play(axisX, axisY);
		}
		else
		{
			game.play();
		}

		// Ekrani temizleme
		system("CLS");

		// S?ran?n kimde oldu?unu belirleme
		laps++;
		game.setWho(laps % 2);
	}
	cout << "\n\n";


	return 0;
}

