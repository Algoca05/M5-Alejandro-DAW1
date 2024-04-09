#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Recetas.h"
using namespace std;



namespace Recetas {
	string ingredient[4];
	int number;
	char whant;
	char next(){
	do
	{
		whant = 's';
		cout << "Do you wantt this recipe? (yes/no)?\n";
		cin >> whant;
		system("cls");
	} while (whant !='y'&& whant !='n');
	return whant;
	}
	void comida1() {
		for (int i = 0; i < number; i++) {
			string item = ingredient[i];
			if (item == "tomatoe" ||item == "pasta"||item == "spagueti")
			{
				cout << "spagueti whith tomatoe\n";
				number = 0;
				if ( next() == 'y')
				{
					cout << "8 ounces (about 225g) of spaghetti pasta\n2 tablespoons olive oil\n3 cloves garlic, minced\n1 can(14 - ounce) crushed tomatoes\n1 teaspoon dried oregano\n1 teaspoon dried basil\nSalt and pepper to taste\nGrated Parmesan cheese(optional, for serving)\nFresh basil leaves(optional, for garnish)\n\nInstructions:\nCook the spaghetti according to the package instructions in a large pot of salted boiling water until al dente.Drain and set aside, reserving about 1 / 2 cup of pasta water.\nWhile the pasta is cooking, heat the olive oil in a large skillet over medium heat.Add the minced garlic and sauté for about 1 minute until fragrant.\nPour in the crushed tomatoes and add the dried oregano and basil.Stir to combine and season with salt and pepper to taste.Allow the sauce to simmer for about 10 - 15 minutes, stirring occasionally, until it thickens slightly.\nOnce the sauce is ready, add the cooked spaghetti to the skillet with the tomato sauce.Toss the spaghetti in the sauce until evenly coated.If the sauce seems too thick, you can add some of the reserved pasta water to thin it out.\nServe the spaghetti with tomato sauce hot, garnished with grated Parmesan cheese and fresh basil leaves if desired.\n";

				}
				else cout << "next one.\n";
				system("pause");
				system("cls");
			}
		}

		
	}
	void comida2() {
		for (int i = 0; i < number; i++) {
			string item = ingredient[i];
			if (item == "pesto" || item == "pasta" || item == "spagueti")
			{
				cout << "pasta pesto\n";
				number = 0;
				if (next() == 'y')
				{
					cout << "the recipe";
				}
				else cout << "next one.\n";
				system("pause");
				system("cls");
			}
		}
	}
	void comida3() {
		for (int i = 0; i < number; i++) {
			string item = ingredient[i];
			if (item == "meat" || item == "milk" || item == "fluor")
			{
				cout << "canelones\n";
				number = 0;
				if (next() == 'y')
				{
					cout << "the recipe";
				}
				else cout << "next one.\n";
				system("pause");
				system("cls");
			}
		}
	}
	
	void comida4() {
		for (int i = 0; i < number; i++) {
			string item = ingredient[i];
			if (item == "fluor" || item == "cheese" || item == "milk")
			{
				cout << "cheese cake\n";
				number = 0;
				if (next() == 'y')
				{
					cout << "the recipe";
				}
				else cout << "next one.\n";
				system("pause");
				system("cls");
			}
		}
	}
	void comida5() {
		for (int i = 0; i < number; i++) {
			string item = ingredient[i];
			if (item == "chocolate" || item == "milk" || item == "fluor" || item == "nuts")
			{
				cout << "brownie\n";
				number = 0;
				if (next() == 'y')
				{
					cout << "the recipe";
				}
				else cout << "next one.\n";
				system("pause");
				system("cls");
			}
		}
	}
	
	
	void ingr::ingredients() {
		
		
		cout << "How many ingredients do yo whant to cook?(4 max)\n";

			cin >> number;
			int finNumber = number;
		cout << "Tell me an ingredient that you want to cook\n";
		for (int i=0; i <number; i++) {
			cin >> ingredient[i];
			//ingredient[i] = tolower(ingredient[i]);
	}
		system("pause");
		system("cls");
		comida1();
		number = finNumber;
		comida2();
		number = finNumber;
		comida3();
		number = finNumber;
		comida4();
		number = finNumber;
		comida5();
		number = finNumber;

		cout << "There aren't more recipes";
	}
}


