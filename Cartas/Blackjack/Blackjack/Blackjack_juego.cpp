#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;

bool thisIsTheCard = true;
int paloClubs[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //1
int paloDiamonds[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //2
int paloHearts[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //3
int paloSpades[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //4
int playerCard;
int iaCard;
int num;
bool playerLose = false;
bool ia21 = false;
char play = 'y';
void numCard(int& repCards, string& suit, int& num, char play, int& iaCard) {

	
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
			cout << "J of " << suit << "\n";
		}
		else if (repCards == 11)
		{
			cout << "Q of " << suit << "\n";
		}
		else if (repCards == 12)
		{
			cout << "K of " << suit << "\n";
		}
	}

	if (repCards == 0 && play == 'y')
	{
		do
		{


			cout << "You AS of " << suit << " is a 1 or an 11\n";
			cin >> num;
			repCards = num;
			cout << repCards << " of " << suit << "\n";
		} while (num != 1 && num != 11);
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


void repartirCartas(int& num) {
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
void shuffle() {
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
void moreCards(char& play) {
	do
	{
		cout << "You have " << playerCard << " points\n";
		cout << "You whant another card???\ny/n\n";
		cin >> play;
	} while (play != 'y' && play != 'n');
}
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
		shuffle();


		for (size_t i = 0; i < 2; i++)
		{
			repartirCartas(num);
			playerCard += num;


		}
		cout << "You have " << playerCard << " points\n";
		repartirCartas(num);
		iaCard += num;
		cout << "Banker have " << iaCard << " points\n";
		system("pause");
		moreCards(play);
		while (play == 'y')
		{
			repartirCartas(num);
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
				moreCards(play);

			}
		}

		system("cls");
		if (playerCard <= 21)
		{
			do
			{
				repartirCartas(num);
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
