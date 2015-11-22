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


	gameCell[0][0] = Cell(1, "x1", 'X');
	gameCell[0][1] = Cell(1, "x2", 'O');
	gameCell[1][0] = Cell(2, "x1", 'O');
	gameCell[1][1] = Cell(2, "x2", 'X');

}

Reversi::Reversi(const int a)
	: row(2), column(2), gameOver(0), who(0), playerScore(0), AIScore(0)
{
	gameCell.resize(getRow());
	for (int i = 0; i < getRow(); i++)
		gameCell[i].resize(getColumn());


	gameCell[0][0] = Cell(1, "x1", 'X');
	gameCell[0][1] = Cell(1, "x2", 'O');
	gameCell[1][0] = Cell(2, "x1", 'O');
	gameCell[1][1] = Cell(2, "x2", 'X');


	expand(a, a);
}


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Input & Output Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

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
			{
				if (gameCell[i][j].get_Who() == NULL)
					cout << " " << "-" << " ";
				else
					cout << " " << gameCell[i][j].get_Who() << " ";
			}
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

void Reversi::play()
{
	vector<vector<Cell> > gameCellTemp;
	gameCellTemp = gameCell;

	vector <Cell> AIBest;
	vector<int> AIBScore;

	char whois = 'X';

	for (int i = 0; i < getRow() - 1; i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			if (gameCellTemp[i][j].get_Who() == 'O')
			{
				// Sol ust capraz
				if (gameCell[i - 1][j - 1].get_Who() == NULL)
				{
					AIBest.push_back(gameCell[i - 1][j - 1]);
					AIBScore.push_back(findBestPosition(i - 1, j - 1));
				}
				// Ust
				if (gameCell[i - 1][j].get_Who() == NULL)
				{
					AIBest.push_back(gameCell[i - 1][j]);
					AIBScore.push_back(findBestPosition(i - 1, j));
				}
				// Sag ust capraz
				if (gameCell[i - 1][j + 1].get_Who() == NULL)
				{
					AIBest.push_back(gameCell[i - 1][j + 1]);
					AIBScore.push_back(findBestPosition(i - 1, j + 1));
				}
				// Sol
				if (gameCell[i][j - 1].get_Who() == NULL)
				{
					AIBest.push_back(gameCell[i][j - 1]);
					AIBScore.push_back(findBestPosition(i, j - 1));
				}
				// Sag
				if (gameCell[i][j + 1].get_Who() == NULL)
				{
					AIBest.push_back(gameCell[i][j + 1]);
					AIBScore.push_back(findBestPosition(i, j + 1));
				}
				// Sol alt capraz
				if (gameCell[i + 1][j - 1].get_Who() == NULL)
				{
					AIBest.push_back(gameCell[i + 1][j - 1]);
					AIBScore.push_back(findBestPosition(i + 1, j - 1));
				}
				// Alt
				if (gameCell[i + 1][j].get_Who() == NULL)
				{
					AIBest.push_back(gameCell[i + 1][j]);
					AIBScore.push_back(findBestPosition(i + 1, j));
				}
				// Sag alt capraz
				if (gameCell[i + 1][j + 1].get_Who() == NULL)
				{
					AIBest.push_back(gameCell[i + 1][j + 1]);
					AIBScore.push_back(findBestPosition(i + 1, j + 1));
				}
			}	// end if
		}	// end loop for j
	}	// end loop for i

	// Her hamleyi hesapladik ve en guclu hamleyi AIBScore vektorden yola cikarak bulacagiz
	int max = AIBScore[0];
	int	power = 0;
	for (int i = 0; i < AIBScore.size(); i++)
		if (max < AIBScore[i])
		{
			max = AIBScore[i];
			power = i;
		}

	// The power!
	// En guclu hamle..

	control(AIBest[power].get_AxisX(), AIBest[power].get_AxisY());

} // end play() function

// Play play
void Reversi::play(const int newAxisX, const string newAxisY)
{
	control(newAxisX, newAxisY);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Other Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

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
		cout << "\n" << "Wrong coordinate..\n";
		cout << "Axis X again: ";
		int axisX;
		cin >> axisX;

		// Y koordinatini yine girmemizi saglar
		cout << "Axis Y again: ";
		string axisY = "x1";
		cin >> axisY;

		control(axisX, axisY);
}


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Operator Overloading Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Private Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// Girilen koordinat ilk satir-sutun veya son satir-sutun ise oyun alan? genisler
void Reversi::expand(const int r, const int c)
{
	vector< vector<Cell> > gameCellTemp;
	gameCellTemp = gameCell;

	int a = getRow();

	// New row value
	setRow(r);

	// New column value
	setColumn(c);

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
	int k = (getRow() - 2) / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				gameCell[i + k][j + k].setWho(gameCellTemp[i][j].get_Who()); // Eski taslari buyumus olan matrixe kopyalar
}

// Matrix koordinatlarini tekrar duzenlerü
// Uygun koordinatlar bulunurken belirlemis oldugum Cell objesinin icinde yer alan
// axisX ve axisY degelerine bakarak bulur.
void Reversi::refresh()
{
	vector< vector<Cell> > gameCellTemp;
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
void Reversi::adding(const int x, const string y)
{
	char z;
	if (getWho() % 2 == 0)
	{
		z = 'O';
	}
	else if (getWho() % 2 == 1)
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
					gameCell[i][j].setWho(z);
					refresh();
					calculate(i, j, z);
				}
			}	// end for j
		}
	}	// end for i

}

// Girilen koordinatlar daha onceden girilmis mi?
// Hamle yapmaya musait mi onu kontrol edecek.
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
				goto bypass;	// donguler daha sonraki karakterleri arastirmasina gerek yok.
			}
		}
	}

	bypass:

	// Vector elemaninda herhangi bir deger girilmis mi onu kontrol ediyor.
	// ayri ayri yapmak yerine de?i?kene atay?p kontrol etmek daha dogru gibi, 1 islem daha az yap?yor.
	char control = gameCell[rowTemp][columnTemp].get_Who();
	
	// Oncelikle 
	// etrafindaki hucreler bos ise oraya hamle yapilamaz
	// Kenarlardaki junk degerleri sorgulamasin diye oraya tasmiyoruz
	// Sorgulama sekli bir tane bos kare secilecek ve etrafindaki komsu hucreler sorgulanacak

	/************************************************************************************

		A--------------B	// Matrix yapi sistemi
		|              |	// Eger secilen hucre kose veya kenarlarda ise bunlarin etrafindaki hucrelerin bos olmamasi gerekli
		|              |	// Eger bos ise tekrar secim yapmak zorunda
		|              |	// Veyahut ortalarda bir hucre secilmis ise etrafindaki hucreler yine bos olmamali
		|              |	// En az bir tanesi dolu olmali
		C--------------D

	************************************************************************************/


	// A kosesi kontrol ediyoruz
	if (rowTemp == 0 && columnTemp == 0)
	{
		if (gameCell[rowTemp][columnTemp + 1].get_Who() == NULL				// 6
			&& gameCell[rowTemp + 1][columnTemp].get_Who() == NULL			// 7
			&& gameCell[rowTemp + 1][columnTemp + 1].get_Who() == NULL)		// 9
		{
			newValue();
		}
	}
	// B kosesini kontrol ediyoruz
	else if (rowTemp == 0 && columnTemp == getColumn() - 1)
	{
		if (gameCell[rowTemp][columnTemp - 1].get_Who() == NULL				// 4
			&& gameCell[rowTemp + 1][columnTemp - 1].get_Who() == NULL		// 7
			&& gameCell[rowTemp + 1][columnTemp].get_Who() == NULL)			// 8
		{
			newValue();
		}
	}
	// C kosesini kontrol ediyoruz
	else if (rowTemp == getRow() - 1 && columnTemp == 0)
	{
		if (gameCell[rowTemp - 1][columnTemp].get_Who() == NULL				// 2
			&& gameCell[rowTemp - 1][columnTemp + 1].get_Who() == NULL		// 3
			&& gameCell[rowTemp][columnTemp + 1].get_Who() == NULL)			// 6
		{
			newValue();
		}
	}
	// D kosesini kontrol ediyoruz
	else if (rowTemp == getRow() - 1 && columnTemp == columnTemp)
	{
		if (gameCell[rowTemp - 1][columnTemp - 1].get_Who() == NULL			// 1
			&& gameCell[rowTemp - 1][columnTemp].get_Who() == NULL			// 2
			&& gameCell[rowTemp][columnTemp - 1].get_Who() == NULL)			// 4
		{
			newValue();
		}
	}
	// A-B kenari
	else if (rowTemp == 0)
	{
		if (gameCell[rowTemp][columnTemp - 1].get_Who() == NULL				// 4
			&& gameCell[rowTemp][columnTemp + 1].get_Who() == NULL			// 6
			&& gameCell[rowTemp + 1][columnTemp - 1].get_Who() == NULL		// 7
			&& gameCell[rowTemp + 1][columnTemp].get_Who() == NULL			// 8
			&& gameCell[rowTemp + 1][columnTemp + 1].get_Who() == NULL)		// 9
		{
			newValue();
		}
	}
	// C-D kenari
	else if (rowTemp == getRow() - 1)
	{
		if (gameCell[rowTemp - 1][columnTemp - 1].get_Who() == NULL			// 1
			&& gameCell[rowTemp - 1][columnTemp].get_Who() == NULL			// 2
			&& gameCell[rowTemp - 1][columnTemp + 1].get_Who() == NULL		// 3
			&& gameCell[rowTemp][columnTemp - 1].get_Who() == NULL			// 4
			&& gameCell[rowTemp][columnTemp + 1].get_Who() == NULL)			// 6
		{
			newValue();
		}
	}
	// A-C kenari
	else if (columnTemp == 0)
	{
		if (gameCell[rowTemp - 1][columnTemp].get_Who() == NULL				// 2
			&& gameCell[rowTemp - 1][columnTemp + 1].get_Who() == NULL		// 3
			&& gameCell[rowTemp][columnTemp + 1].get_Who() == NULL			// 6
			&& gameCell[rowTemp + 1][columnTemp].get_Who() == NULL			// 8
			&& gameCell[rowTemp + 1][columnTemp + 1].get_Who() == NULL)		// 9
		{
			newValue();
		}
	}
	// B-D kenari
	else if (columnTemp == getColumn() - 1)
	{
		if (gameCell[rowTemp - 1][columnTemp - 1].get_Who() == NULL			// 1
			&& gameCell[rowTemp - 1][columnTemp].get_Who() == NULL			// 2
			&& gameCell[rowTemp][columnTemp - 1].get_Who() == NULL			// 4
			&& gameCell[rowTemp + 1][columnTemp - 1].get_Who() == NULL		// 7
			&& gameCell[rowTemp + 1][columnTemp].get_Who() == NULL)			// 8
		{
			newValue();
		}
	}
	// Etrafindaki tum hucreler bos ise oraya hamlenin yapilamicagini belirtiyoruz.
	else if (gameCell[rowTemp - 1][columnTemp - 1].get_Who() == NULL		// 1
		&& gameCell[rowTemp - 1][columnTemp].get_Who() == NULL				// 2
		&& gameCell[rowTemp - 1][columnTemp + 1].get_Who() == NULL			// 3
		&& gameCell[rowTemp][columnTemp - 1].get_Who() == NULL				// 4
		&& gameCell[rowTemp][columnTemp + 1].get_Who() == NULL				// 6
		&& gameCell[rowTemp + 1][columnTemp - 1].get_Who() == NULL			// 7
		&& gameCell[rowTemp + 1][columnTemp].get_Who() == NULL				// 8
		&& gameCell[rowTemp + 1][columnTemp + 1].get_Who() == NULL)			// 9
	{
		newValue();
	}
	else if (control == 'X' || control == 'O')
	{
			newValue();
	}
	else
	{
		adding(axisX, axisY);
	}
}

void Reversi::calculate(const int x, const int y, const char whois)
{

	vector< vector<Cell> > gameCellTemp;
	gameCellTemp = gameCell;

	int count = 0;;
	int i = x,
		j = y,
		orginal_i,
		orginal_j;

	/*****************************************************************************************
	
			1-----2-----3	// Merkeze oynanacak tas geliyor sekilde kalibi yerlestiriyoruz
			|			|	// sirayla sayilardan birinin yonunde sirayla gitmeye basliyoruz
	Yönler	4			5	// taki kendi tasimiza denk gelene kadar
			|			|	// eger kendi tasimiza denk gelmez isek o islem yapilmiyor
			6-----7-----8	// ve diger taraflara bakiyoruz

	*****************************************************************************************/

	orginal_i = i;
	orginal_j = j;


	//	1 yonunde
	while (gameCellTemp[i - 1][j - 1].get_Who() != whois && gameCellTemp[i - 1][j - 1].get_Who() != NULL)
	{
		--i;
		--j;
		count++;
		if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
			count = 0;
	}	// end loop while()

	if (0 < count)
	{
		i = orginal_i;
		j = orginal_j;
		int movement = 0;
		while (movement <= count)
		{
			i--;
			j--;
			gameCellTemp[i][j].setWho(whois);
			movement++;
		}
	}

	//	2 yonunde
	count = 0;
	i = orginal_i;
	j = orginal_j;
	while (gameCellTemp[i - 1][j].get_Who() != whois && gameCellTemp[i - 1][j].get_Who() != NULL)
	{
		--i;
		count++;
		if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
			count = 0;
	}	// end loop while()

	if (0 < count)
	{
		i = orginal_i;
		int movement = 0;
		while (movement <= count)
		{
			i--;
			j--;
			gameCellTemp[i][j].setWho(whois);
			movement++;
		}
	}

	//	3 yonunde
	count = 0;
	i = orginal_i;
	j = orginal_j;
	while (gameCellTemp[i - 1][j + 1].get_Who() != whois && gameCellTemp[i - 1][j + 1].get_Who() != NULL)
	{
		--i;
		++j;
		count++;
		if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
			count = 0;
	}	// end loop while()

	if (0 < count)
	{
		i = orginal_i;
		j = orginal_j;
		int movement = 0;
		while (movement <= count)
		{
			i--;
			j++;
			gameCellTemp[i][j].setWho(whois);
			movement++;
		}	// end loop while()
	}	// end if


	//	4 yonunde
	count = 0;
	i = orginal_i;
	j = orginal_j;
	while (gameCellTemp[i][j-1].get_Who() != whois && gameCellTemp[i - 1][j].get_Who() != NULL)
	{
		--j;
		count++;
		if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
			count = 0;
	}	// end loop while()

	if (0 < count)
	{
		j = orginal_j;		// Degeri tazeliyoruz
		int movement = 0;	// Kac defa davranacagi
		while (movement <= count)
		{
			j--;
			gameCellTemp[i][j].setWho(whois);
			movement++;
		}	// end loop while()
	}

	//	5 yonunde
	count = 0;
	i = orginal_i;
	j = orginal_j;
	while (gameCellTemp[i][j + 1].get_Who() != whois && gameCellTemp[i][j + 1].get_Who() != NULL)
	{
		++j;
		count++;
		if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
			count = 0;
	}	// end loop while

	if (0 < count)
	{
		j = orginal_j;
		int movement = 0;
		while (movement <= count)
		{
			j++;
			gameCellTemp[i][j].setWho(whois);
			movement++;
		}	// end loop while
	}	// end if - count

	// 6 yonunde
	count = 0;
	i = orginal_i;
	j = orginal_j;
	while (gameCellTemp[i+1][j - 1].get_Who() != whois && gameCellTemp[i + 1][j - 1].get_Who() != NULL)
	{
		++i;
		--j;
		count++;
		if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
			count = 0;
	}	// endl loop while

	if (0 < count)
	{
		i = orginal_i;
		j = orginal_j;
		int movement = 0;
		while (movement <= count)
		{
			i++;
			j--;
			gameCellTemp[i][j].setWho(whois);
			movement++;
		}	// endl loop while
	}	// end if - count

	// 7 yonunde
	count = 0;
	i = orginal_i;
	j = orginal_j;
	while (gameCellTemp[i + 1][j].get_Who() != whois && gameCellTemp[i + 1][j].get_Who() != NULL)
	{
		++i;
		count++;
		if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
			count = 0;
	}	// end loop while

	if (0 < count)
	{
		i = orginal_i;
		int movement = 0;
		while (movement <= count)
		{
			i++;
			gameCellTemp[i][j].setWho(whois);
			movement++;
		}	// end loop while
	}	// end if - count
	 
	// 8 yonunde
	count = 0;
	i = orginal_i;
	j = orginal_j;
	while (gameCellTemp[i + 1][j + 1].get_Who() != whois && gameCellTemp[i + 1][j + 1].get_Who() != NULL)
	{
		++i;
		++j;
		count++;
		if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
			count = 0;
	}	// end loop while

	if (0 < count)
	{
		i = orginal_i;
		j = orginal_j;
		int movement = 0;
		while (movement <= count)
		{
			i++;
			j++;
			gameCellTemp[i][j].setWho(whois);
			movement++;
		}	// end loop while
	}	// end if - count

	// Hesaplanmis icerigi tekrar geri kopyaliyoruz
	gameCell = gameCellTemp;

	return;
}

// AI yapacagi en iyi hamleyi bulmak icin kullanacak
const int Reversi::findBestPosition(int i, int j) // degiskenler degisecek const olmamali
{
	vector<vector<Cell> > gameCellTemp;
	gameCellTemp = gameCell;

	int temp_i, temp_j;
	int count = 0;
	int AIBTotalScore = 0;

	temp_i = i;
	temp_j = j;

	// 1 yonu
	if (i < getRow() - 1 && j < getColumn() - 1 && gameCellTemp[i][j].get_Who() == NULL)
	{
		while (gameCellTemp[i - 1][j - 1].get_Who() == 'O')
		{
			i--;
			j--;
			count++;
		}	// end loop while
	}	// end if
	if (gameCellTemp[i - 1][j - 1].get_Who() == NULL)
		count = 0;

	AIBTotalScore += count;

	// 2 yonu
	count = 0;
	i = temp_i;
	j = temp_j;
	if (i < getRow() - 1 && gameCellTemp[i][j].get_Who() == NULL)
	{
		while (gameCellTemp[i - 1][j].get_Who() == 'O')
		{
			i++;
			count++;
		}	// end loop while
	}	// end if
	if (gameCellTemp[i + 1][j].get_Who() == NULL)
		count = 0;

	AIBTotalScore += count;

	// 3 yonu
	count = 0;
	i = temp_i;
	j = temp_j;
	if (i < getRow() - 1 && 0 < j && gameCellTemp[i][j].get_Who() == NULL)
	{
		while (gameCellTemp[i - 1][j + 1].get_Who() == 'O')
		{
			i++;
			j++;
			count++;
		}	// end loop while
	}	// end if
	if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
		count = 0;

	AIBTotalScore += count;

	// 4 yonu
	count = 0;
	i = temp_i;
	j = temp_j;
	if (j < getColumn() - 1 && gameCellTemp[i][j].get_Who() == NULL)
	{
		while (gameCellTemp[i][j - 1].get_Who() == 'O')
		{
			j--;
			count++;
		}	// end loop while
	}	// end if
	if (gameCellTemp[i][j - 1].get_Who() == NULL)
		count = 0;

	AIBTotalScore += count;

	// 5 yonunde
	count = 0;
	i = temp_i;
	j = temp_j;
	if (0 < j && gameCellTemp[i][j].get_Who() == NULL)
	{
		while (gameCellTemp[i][j + 1].get_Who() == 'O')
		{
			j++;
			count++;
		}	// end loop while
	}
	if (gameCellTemp[i][j + 1].get_Who() == NULL)
		count = 0;
	int temp = count;
	AIBTotalScore += count;

	// 6 yonunde
	count = 0;
	i = temp_i;
	j = temp_j;
	if (0 < i && j < getColumn() - 1 && gameCellTemp[i][j].get_Who() == NULL)
	{
		while (gameCellTemp[i + 1][j - 1].get_Who() == 'O')
		{
			i++;
			j--;
			count++;
		}	// end loop while
	}
	if (gameCellTemp[i + 1][j - 1].get_Who() == NULL)
		count = 0;

	AIBTotalScore += count;

	// 7 yonunde
	count = 0;
	i = temp_i;
	j = temp_j;
	if (i < 0 && gameCellTemp[i][j].get_Who() == NULL)
	{
		while (gameCellTemp[i + 1][j].get_Who() == 'O')
		{
			i++;
			count++;
		}	// end loop while
	}
	if (gameCellTemp[i + 1][j].get_Who() == NULL)
		count = 0;

	AIBTotalScore += count;

	// 8 yonunde
	count = 0;
	i = temp_i;
	j = temp_j;
	if (i < 0 && 0 < j && gameCellTemp[i][j].get_Who() == NULL)
	{
		while (gameCellTemp[i + 1][j + 1].get_Who() == 'O')
		{
			i++;
			j++;
			count++;
		}	// end loop while
	}
	if (gameCellTemp[i + 1][j + 1].get_Who() == NULL)
		count = 0;
	AIBTotalScore += count;

	return AIBTotalScore;
}