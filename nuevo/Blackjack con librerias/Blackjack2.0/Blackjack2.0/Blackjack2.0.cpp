#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "repartir.h"
using namespace std;
bool thisIsTheCard = true;
int playerCard;
int iaCard;
int num;
char play = 'y';

int main() {

	srand(time(NULL));

	cout << "The goal of any blackjack hand is to beat the dealer. \nTo do this, you must have a hand that scores higher than the banker's hand, but does not exceed 21 points in total value. \nOr, you can win with a score below 22 when the banker's hand exceeds 21 points\n\n";


	do
	{
		cout << "You Whant to Play??? \ny/n\n";

		cin >> play;
	} while (play != 'y' && play != 'n');
	system("pause");
	system("cls");
	while (play == ('y'))
	{
		Repartir::Cartas::shuffle();


		for (size_t i = 0; i < 2; i++)
		{
			Repartir::Cartas::repartirCartas(num);
			playerCard += num;


		}
		cout << "You have " << playerCard << " points\n";
		Repartir::Cartas::repartirCartas(num);
		iaCard += num;
		cout << "Banker have " << iaCard << " points\n";
		system("pause");
		Repartir::Cartas::moreCards(play);
		while (play == 'y')
		{
			Repartir::Cartas::repartirCartas(num);
			playerCard += num;
			if (playerCard > 21)
			{

				play = 'n';
				cout << "You have " << playerCard << " points\n";
				system("pause");
				system("cls");
			}
			else if (playerCard < 21)
			{
				Repartir::Cartas::moreCards(play);

			}
		}

		system("cls");
		if (playerCard <= 21)
		{
			do
			{
				Repartir::Cartas::repartirCartas(num);
				iaCard += num;
				cout << "Banker have " << iaCard << " points\n";
				system("pause");
			} while (iaCard < playerCard && iaCard <= 21);
		}
		if (iaCard > 21)
		{
			system("cls");
			cout << "You win\n\n";

			system("pause");
			system("cls");
		}
		else {
			system("cls");
			cout << "You lost\n\n";

			system("pause");
			system("cls");
		}


		cout << "You whant to Replay????\ny/n\n";
		cin >> play;
		system("cls");
	}
}
