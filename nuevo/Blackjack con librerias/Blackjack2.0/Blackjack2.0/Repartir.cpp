#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "repartir.h"
using namespace std;


namespace Repartir {
	bool thisIsTheCard = true;
	int paloClubs[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //1
	int paloDiamonds[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //2
	int paloHearts[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //3
	int paloSpades[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //4
	int playerCard;
	int iaCard;
	string type;
	bool ia21 = false;
	char play = 'y';
	void numCard(int& repCards, string& suit, int& num, char play, int& iaCard) {

		;
		if (repCards < 10 && repCards>0)
		{
			num = repCards + 1;
			cout << num << " of " << suit << "\n";
		}
		else if (repCards >= 10)
		{

			num = 10;
			if (repCards == 10)
			{
				type = "J";
				cout << type << " of " << suit << "\n";
			}
			else if (repCards == 11)
			{
				type = "Q";
				cout << type << " of " << suit << "\n";
			}
			else if (repCards == 12)
			{
				type = "K";
				cout << type << " of " << suit << "\n";
			}
		}

		if (repCards == 0 && play == 'y')
		{
			do
			{


				cout << "You AS of " << suit << " is a 1 or an 11\n";
				cin >> num;
				repCards = num;

			} while (num != 1 && num != 11);
			cout << repCards << " of " << suit << "\n";
		}
		if (repCards == 0 && play == 'n')
		{
			if (iaCard <= 10)
			{
				num = 11;
				repCards = 11;
			}
			else if (iaCard > 10)
			{
				num = 1;
				repCards = 1;
			}
			cout << "A of " << suit << "\n";
			cout << repCards << " of " << suit << "\n";
		}



	}
	void Cartas::repartirCartas(int& num) {
		int repPalo;
		int repCards;
		string suit;
		thisIsTheCard = false;
		do
		{
			repPalo = rand() % 4 + 1;
			repCards = rand() % 13;

			if (repPalo == 1 && paloClubs[repCards] == 1)
			{
				paloClubs[repCards] = 0;
				thisIsTheCard = true;
				suit = "Clubs ";

			}
			if (repPalo == 2 && paloDiamonds[repCards] == 1)
			{
				paloDiamonds[repCards] = 0;
				thisIsTheCard = true;
				suit = "Diamonds ";

			}
			if (repPalo == 3 && paloHearts[repCards] == 1)
			{

				paloHearts[repCards] = 0;
				thisIsTheCard = true;
				suit = "Hearts ";

			}
			if (repPalo == 4 && paloSpades[repCards] == 1)
			{

				thisIsTheCard = true;
				paloSpades[repCards] = 0;
				suit = "Spades ";

			}
		} while (!thisIsTheCard);
		numCard(repCards, suit, num, play, iaCard);

	}
	void Cartas::shuffle() {
		for (size_t i = 0; i < 13; i++)
		{
			paloClubs[i] = 1;
			paloDiamonds[i] = 1;
			paloHearts[i] = 1;
			paloSpades[i] = 1;
		}

		playerCard = 0;
		iaCard = 0;
		cout << "the cards been shuffled\n";
		system("pause");
		system("cls");
	}
	void Cartas::moreCards(char& play) {
		do
		{
			cout << "You have " << playerCard << " points\n";
			cout << "You whant another card???\ny/n\n";
			cin >> play;
		} while (play != 'y' && play != 'n');
	}
}