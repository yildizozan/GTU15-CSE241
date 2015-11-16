/*
* File:   main.cpp
* Author: ozan
*
* Created on November 12, 2015, 4:06 PM
*/

#include <iostream>
#include <vector>
#include <string>

#include "Cell.h"
#include "Reversi.h"

using namespace std;

/*
*
*/
int main()
{
	Reversi game;

	while (!game.getGameOver())
	{
		// Who is start game?
		int who = game.getWho();

		// Ekranda görmemizi sa?lar
		game.output();

		// X koordinatini girmemizi sa?lar
		cout << "\n";
		cout << "Axis X: ";
		int axisX;
		cin >> axisX;

		// Y koordinatini girmemizi sa?lar
		cout << "Axis Y: ";
		string axisY = "x1";
		cin >> axisY;

		// Girilen de?erleri i?lers
		game.input(axisX, axisY);

		// Ekran? temizleme
		system("CLS");

		// S?ran?n kimde oldu?unu belirleme
		who++;
		game.setWho(who % 2);
	}
	cout << "\n\n";


	system("PAUSE");
	return 0;
}

