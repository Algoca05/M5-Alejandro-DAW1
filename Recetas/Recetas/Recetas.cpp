#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Recetas.h"
using namespace std;


namespace Recetas {
	string ingredient[4];
	int number;
	char whant;
	char next() {
		do
		{
			whant = 's';
			cout << "Do you what this recipe? (yes/no)?\n";
			cin >> whant;
			system("cls");
		} while (whant != 'y' && whant != 'n');
		return whant;
	}
	void comida1() {
		for (int i = 0; i < number; i++) {
			string item = ingredient[i];
			if (item == "tomatoe" || item == "pasta" || item == "spagueti")
			{
				cout << "spagueti whith tomatoe\n";
				if (next() == 'y')
				{
					cout << "recipe\n";

				}
				else cout << "next one.\n";
				system("pause");
				system("cls");
			}
		}

		system("pause");
		system("cls");
	}
	void comida2() {
		cout << "pasta pesto";


		system("pause");
		system("cls");
	}
	void comida3() {
		cout << "canelones";


		system("pause");
		system("cls");
	}
	void comida4() {
		cout << "tarta de queso";


		system("pause");
		system("cls");
	}
	void comida5() {
		cout << "brownie";


		system("pause");
		system("cls");
	}

	void ingr::ingredients() {

		cout << "How many ingredients do yo whant to cook?(4 max)\n";

		cin >> number;
		cout << "Tell me an ingredient that you want to cook\n";
		for (int i = 0; i < number; i++) {
			cin >> ingredient[i];
			//ingredient[i] = tolower(ingredient[i]);
		}
		system("pause");
		system("cls");
		comida1();
	}
}