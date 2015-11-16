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

int main(int argc, int** argv)
{
	Reversi game;

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

		// X koordinatini girmemizi saglar
		cout << "\n";
		cout << "Axis X: ";
		int axisX;
		cin >> axisX;

		// Y koordinatini girmemizi saglar
		cout << "Axis Y: ";
		string axisY = "x1";
		cin >> axisY;

		// Girilen degerleri iletir
		game.input(axisX, axisY);

		// Ekrani temizleme
		system("CLS");

		// S?ran?n kimde oldu?unu belirleme
		who++;
		game.setWho(who % 2);
	}
	cout << "\n\n";


	return 0;
}

