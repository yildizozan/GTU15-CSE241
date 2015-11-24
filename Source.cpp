/*
* File:   main.cpp
* Author: Ozan YILDIZ
*
* Created on November 12, 2015, 4:06 PM
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Cell.h"
#include "Reversi.h"

using namespace std;

int main()
{
	ifstream in_file;
	ofstream o_file;

	bool gameOver = true;
	int laps = 0;

	Reversi game1(8, 8), game2(8, 8), game3(8, 8), game4(8, 8), game5(8, 8);
	int who1, who2, who3, who4, who5;

	int axisX;
	string axisY;

	while (gameOver)
	{
		// Ekranda görmemizi saglar
		cout << "\tGame 1\n\n";
		game1.output();
		cout << "\n\n\tGame 2\n";
		game2.output();
		cout << "\n\n\tGame 3\n";
		game3.output();
		cout << "\n\n\tGame 4\n";
		game4.output();
		cout << "\n\n\tGame 5\n";
		game5.output();

		// Who is start game?
		who1 = game1.getWho();

		// Skorlar
		game1.score();
		cout << "AI: " << game1.getAIScore() << " | ";
		cout << "Player: " << game1.getPlayerScore() << endl;;


		// X koordinatini girmemizi saglar
		cout << "\n";
		cout << "Axis X: ";
		cin >> axisX;

		// Y koordinatini girmemizi saglar
		cout << "Axis Y: ";
		cin >> axisY;

		game1.play(axisX, axisY);
		game1.play();

		// S?ran?n kimde oldu?unu belirleme
		laps++;
		game1.setWho(laps % 2);
		if (game1.getGameOver() == true)
		{
			gameOver = false;
		}


/*
		cout << "\nHangi oyunda hamle yapmak istiyorsunuz: (1)(2)(3)(4)(5)";
		int select;
		cin >> select;

		if (select == 1)
		{
			// Who is start game?
			who1 = game1.getWho();

			// Skorlar
			game1.score();
			cout << "AI: " << game1.getAIScore() << " | ";
			cout << "Player: " << game1.getPlayerScore() << endl;;


			// X koordinatini girmemizi saglar
			cout << "\n";
			cout << "Axis X: ";
			cin >> axisX;

			// Y koordinatini girmemizi saglar
			cout << "Axis Y: ";
			cin >> axisY;

			game1.play(axisX, axisY);
			game1.play();

			// S?ran?n kimde oldu?unu belirleme
			laps++;
			game1.setWho(laps % 2);
			if (game1.getGameOver() == 1)
			{
				gameOver = false;
			}
		}

		else if (select == 2)
		{
			// Who is start game?
			who2 = game2.getWho();

			// Skorlar
			game2.score();
			cout << "AI: " << game2.getAIScore() << " | ";
			cout << "Player: " << game2.getPlayerScore() << endl;;

				// X koordinatini girmemizi saglar
				cout << "\n";
				cout << "Axis X: ";
				cin >> axisX;

				// Y koordinatini girmemizi saglar
				cout << "Axis Y: ";
				cin >> axisY;

				game2.play(axisX, axisY);
				game2.play();

			// S?ran?n kimde oldu?unu belirleme
			laps++;
			game2.setWho(laps % 2);
			if (game1.getGameOver() == 1)
			{
				gameOver = false;
			}
		}

		else if (select == 3)
		{
			// Who is start game?
			who3 = game3.getWho();

			// Skorlar
			game3.score();
			cout << "AI: " << game3.getAIScore() << " | ";
			cout << "Player: " << game3.getPlayerScore() << endl;;

				// X koordinatini girmemizi saglar
				cout << "\n";
				cout << "Axis X: ";
				cin >> axisX;

				// Y koordinatini girmemizi saglar
				cout << "Axis Y: ";
				cin >> axisY;

				game3.play(axisX, axisY);
				game3.play();

			// S?ran?n kimde oldu?unu belirleme
			laps++;
			game3.setWho(laps % 2);
			if (game1.getGameOver() == 1)
			{
				gameOver = false;
			}
		}

		else if (select == 4)
		{
			// Who is start game?
			who4 = game4.getWho();

			// Skorlar
			game4.score();
			cout << "AI: " << game4.getAIScore() << " | ";
			cout << "Player: " << game4.getPlayerScore() << endl;;

				// X koordinatini girmemizi saglar
				cout << "\n";
				cout << "Axis X: ";
				cin >> axisX;

				// Y koordinatini girmemizi saglar
				cout << "Axis Y: ";
				cin >> axisY;

				game4.play(axisX, axisY);
				game4.play();

			// S?ran?n kimde oldu?unu belirleme
			laps++;
			game4.setWho(laps % 2);
			if (game1.getGameOver() == 1)
			{
				gameOver = 1;
			}
		}

		else if (select == 5)
		{
			// Who is start game?
			who5 = game5.getWho();

			// Skorlar
			game5.score();
			cout << "AI: " << game5.getAIScore() << " | ";
			cout << "Player: " << game5.getPlayerScore() << endl;;

				// X koordinatini girmemizi saglar
				cout << "\n";
				cout << "Axis X: ";
				cin >> axisX;

				// Y koordinatini girmemizi saglar
				cout << "Axis Y: ";
				cin >> axisY;

				game5.play(axisX, axisY);
				game5.play();

			// S?ran?n kimde oldu?unu belirleme
			laps++;
			game5.setWho(laps % 2);
			if (game1.getGameOver() == 1)
			{
				gameOver = 1;
			}

	}
	*/
	}
	cout << "\n\n";


	return 0;
}

