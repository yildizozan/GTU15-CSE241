/*
* File:   Reversi.cpp
* Author: Ozan YILDIZ
*
* Created on November 12, 2015, 4:06 PM
*/

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

#include "Cell.h"
#include "Reversi.h"


using namespace std;

Reversi::Reversi() // Constructor
	: row(2), column(2), gameOver(0), who(0), playerScore(0), AIScore(0)
{
	gameCell.resize(getRow());
	for (int i = 0; i < getRow(); i++)
		gameCell[i].resize(getColumn());

	expand();

	gameCell[1][1] = Cell(2, "x2", 'X');
	gameCell[1][2] = Cell(2, "x3", 'O');
	gameCell[2][1] = Cell(3, "x2", 'O');
	gameCell[2][2] = Cell(3, "x3", 'X');

}


/* INPUT & OUTPUT FUNCTIONS *************************/

// Girilen degerleri hemen control() fonksiyonuna gonderir

// Oyun alanini ekranda yazdirir.
void Reversi::output(void)
{
	for (int i = 0; i < getRow() + 1; i++)
	{
		if (i < getRow())
		{
			cout << i + 1 << "\t";

			for (int j = 0; j < getColumn(); j++)
				cout << " " << gameCell[i][j].get_Who() << " ";
			cout << "\n";
		}
		else
		{
			cout << "\t";

			for (int k = 0; k < getColumn(); k++)
			{
				cout << "x" << k+1 << " ";
			}
		}
	}

}

void Reversi::playComputer()
{
	// Rastgele degerler olusturuyoruz koordinatlar icin
	srand(time(NULL));
	int borderX = 1 + (rand() % getRow());
	int borderY = 1 + (rand() % getColumn());

	// Programin yap?s?ndan dolay? sutun islemleri icin x cinsinden string olarak yazmak gerekiyor
	string borderY_str = "x" + to_string(borderY);

	// Rakip oyuncunun taslarinin bulundugu koordinatlari yeni vektore atiyoruz
	// Boylece oyun alaninda bos olan yerleri taramamis oluruz
	vector <Cell> opponentCoord;

	// Bulundugu hucrenin tum yonlerini hesaplayacak
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			if (gameCell[i][j].get_Who() == 'O')
			{
				opponentCoord.push_back(gameCell[i][j]);
			}
		}
	}

	// Olusan degerleri control icin yolluyoruz
	//control(borderX, borderY_str);

}

void Reversi::playPlayer(const int newAxisX, const string newAxisY)
{
	control(newAxisX, newAxisY);
}

/* OTHER *******************************************/
// Skor sayimi yapan fonksiyon
// Oyun alani uzerindeki taslari sayar
void Reversi::score() // Her defasinda puanlar bastan hesaplanacak
{
	int countPlayer = 0;
	int countAI = 0;

	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			if (gameCell[i][j].get_Who() == 'O')
			{
				countPlayer++;
			}
			else if (gameCell[i][j].get_Who() == 'X')
			{
				countAI++;
			}
		}
	}

	setPlayerScore(countPlayer - 2);
	setAIScore(countAI - 2);
}

// Yeniden koordinat girilmesini saglar
// Girilen koordinatlari control() fonksiyonuna gonderir
// Recursive calisir
void Reversi::newValue()
{
		// X koordinatini yine girmemizi saglar
		cout << "\n";
		cout << "Axis X again: ";
		int axisX;
		cin >> axisX;

		// Y koordinatini yine girmemizi saglar
		cout << "Axis Y again: ";
		string axisY = "x1";
		cin >> axisY;

		control(axisX, axisY);
}

/* Private Functions ********************************/
// Girilen koordinat ilk satir-sutun veya son satir-sutun ise oyun alan? genisler
void Reversi::expand()
{
	gameCellTemp = gameCell;


	// New row value
	setRow(getRow() + 2);

	// New column value
	setColumn(getColumn() + 2);

	// Row expand for gameCell
	gameCell.resize(getRow());

	// Column expand for gameCell
	for (int i = 0; i < gameCell.size(); i++)
		gameCell[i].resize(getColumn());

	// All member of vector should be zero
	for (int i = 0; i < getRow(); i++)
		for (int j = 0; j < getColumn(); j++)
		{
			string str = "x" + to_string(j + 1);		// Y koordinatini string seklinde olusturur.
			gameCell[i][j] = Cell(i + 1, str, NULL);	// Ilgili hücreye gerekli bilgiler doldurur.
		}

	// Create new matrix and copy (burada önceki matrixi kullanmaliyim o sebeple -2)
	for (int i = 0; i < getRow() - 2; i++)
		for (int j = 0; j < getColumn() - 2; j++)
			gameCell[i + 1][j + 1].setWho(gameCellTemp[i][j].get_Who()); // Eski taslari buyumus olan matrixe kopyalar
}

// Matrix koordinatlarini tekrar duzenlerü
// Uygun koordinatlar bulunurken belirlemis oldugum Cell objesinin icinde yer alan
// axisX ve axisY degelerine bakarak bulur.
void Reversi::refresh()
{
	gameCellTemp = gameCell;

	// All member of vector should be zero
	for (int i = 0; i < getRow(); i++)
		for (int j = 0; j < getColumn(); j++)
		{
			string str = "x" + to_string(j + 1);		// Y koordinatini string seklinde olusturur.
			gameCell[i][j] = Cell(i + 1, str, NULL);	// ?lgili hücreye gerekli bilgiler doldurur.
		}

	// Create new matrix and copy (burada önceki matrixin boyutunu(dimension) kullanmaliyim -2)
	for (int i = 0; i < getRow(); i++)
		for (int j = 0; j < getColumn(); j++)
			gameCell[i][j].setWho(gameCellTemp[i][j].get_Who()); // Eski tasla?? büyümü? olan matrixe kopyalar

}

// who degiskeni oyun sirasinin kimde oldugunu belirler ona gore X veya O ekrana yazd?r?r.
// Girilen koordinat bulunur, oyun alaninin genislemesi gerekiyorsa oyun alani genisler ve deger girilir,
// Oyun alaninin genislemesine gerek yoksa deger girilir ve refresh() fonksiyonu ile koordinatlar tazelenir.
void Reversi::find(const int x, const string y)
{
	char z;
	if (getWho() == 0)
	{
		z = 'O';
	}
	else if (getWho() == 1)
	{
		z = 'X';
	}
	else
	{
		z = '-';
	}
	for (int i = 0; i < getRow(); i++)
	{
		if (gameCell[i][0].get_AxisX() == x)	// Uygun satiri buluyoruz sutun icin simdilik gerek yok
		{
			for (int j = 0; j < getRow(); j++)	
			{
				if (gameCell[i][j].get_AxisY() == y) // Bulmus oldugumuz satirdaki sutunu buluyoruz
				{
					if (1 == i + 1 || i + 1 == getRow() || 1 == j + 1 || j + 1 == getColumn())	// Eger koordinatlar sinirda ise oyun alani genisler ve deger atanir
					{
						expand();
						gameCell[i + 1][j + 1].setWho(z);
					}
					else	// Deger atanir ve koordinatlar tazelenir.
					{
						gameCell[i][j].setWho(z);
						refresh();
					}
				}
			}
		}
	}

}

// Girilen koordinatlar daha onceden girilmis mi?
// Hamle yapmaya musait mi onu kontrol edecek.
// Eger musait ise true dondurecek
void Reversi::control(const int axisX, const string axisY)
{
	int rowTemp, columnTemp;
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			if (gameCell[i][j].get_AxisX() == axisX && gameCell[i][j].get_AxisY() == axisY)
			{
				rowTemp = i;
				columnTemp = j;
				goto bypass;	// donguler daha sonraki karakterleri arast?rmas?na gerek yok.
			}
		}
	}

	bypass:

	// Vector elemaninda herhangi bir deger girilmis mi onu kontrol ediyor.
	// Ayr? ayr? yapmak yerine de?i?kene atay?p kontrol etmek daha dogru gibi, 1 islem daha az yap?yor.
	char control = gameCell[rowTemp][columnTemp].get_Who();
	if (control == 'X' || control == 'O')
	{
		if (getWho() == 0)	// Oyuncunun hamlesi demektir
		{
			newValue();
		}
		else	// PC'nin hamlesi
		{
			playComputer();
		}
	}
	else
	{
		find(axisX, axisY);
	}
}

