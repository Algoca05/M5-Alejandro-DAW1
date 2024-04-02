#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Recetas.h"

using namespace std;

int main() {
	cout << "Welcome to cooking with Alejandro.\nThe best program to think what do you whant to eat with the ingredients you have at home.\nOk let's START!!!\n";
	system("pause");
	system("cls");
	Recetas::ingr::ingredients();
	system("pause");
}