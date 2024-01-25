//#include <iostream>
//#include<stdlib.h>
//#include<time.h>
//#include<windows.h>
//using namespace std;
//
//bool thisIsTheCard = true;
//int paloClubs[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //1
//int paloDiamonds[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //2
//int paloHearts[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //3
//int paloSpades[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 }; //4
//
//int playerCard1 [2];
//int iaCard1 [2];
//int playerCard2 [2];
//int iaCard2[2];
//int tableCard1 [2];
//int tableCard2 [2];
//int tableCard3 [2];
//int tableCard4 [2];
//int tableCard5 [2];
//int num;
//bool playerLose = false;
//bool ia21 = false;
//char play = 'y';
//void numCard(int& repCards, string& suit, int& num, char play, int& iaCard) {
//
//	;
//	if (repCards < 10 )
//	{
//		num = repCards + 1;
//		cout << num << " of " << suit << "\n";
//	}
//	else if (repCards >= 10)
//	{
//
//		num = 10;
//		if (repCards == 10)
//		{
//			cout << "J of " << suit << "\n";
//		}
//		else if (repCards == 11)
//		{
//			cout << "Q of " << suit << "\n";
//		}
//		else if (repCards == 12)
//		{
//			cout << "K of " << suit << "\n";
//		}
//	}
//
//	
//
//}
//void repartirCartas(int& num) {
//	int repPalo;
//	int repCards;
//	string suit;
//	thisIsTheCard = false;
//	do
//	{
//		repPalo = rand() % 4 + 1;
//		repCards = rand() % 13;
//
//		if (repPalo == 1 && paloClubs[repCards] == 1)
//		{
//			paloClubs[repCards] = 0;
//			thisIsTheCard = true;
//			suit = "Clubs ";
//
//		}
//		if (repPalo == 2 && paloDiamonds[repCards] == 1)
//		{
//			paloDiamonds[repCards] = 0;
//			thisIsTheCard = true;
//			suit = "Diamonds ";
//
//		}
//		if (repPalo == 3 && paloHearts[repCards] == 1)
//		{
//
//			paloHearts[repCards] = 0;
//			thisIsTheCard = true;
//			suit = "Hearts ";
//
//		}
//		if (repPalo == 4 && paloSpades[repCards] == 1)
//		{
//
//			thisIsTheCard = true;
//			paloSpades[repCards] = 0;
//			suit = "Spades ";
//
//		}
//	} while (!thisIsTheCard);
//	numCard(repCards, suit, num, play, iaCard);
//
//}
//void shuffle() {
//	for (size_t i = 0; i < 13; i++)
//	{
//		paloClubs[i] = 1;
//		paloDiamonds[i] = 1;
//		paloHearts[i] = 1;
//		paloSpades[i] = 1;
//	}
//
//	playerCard = 0;
//	iaCard = 0;
//	cout << "the cards been shuffled\n";
//	system("pause");
//	system("cls");
//}
//void moreCards(char& play) {
//	do
//	{
//		cout << "You have " << playerCard << " points\n";
//		cout << "You whant another card???\ny/n\n";
//		cin >> play;
//	} while (play != 'y' && play != 'n');
//}
//int main() {
//
//	srand(time(NULL));
//
//
//
//
//}