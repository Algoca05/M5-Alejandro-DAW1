//#include "stdafx.h"

#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <locale>

using namespace std;

int main(){
	locale utf8_locale("es_US.UTF-8");

	locale::global(utf8_locale);
	string characters [6] = { "┌","─","┐","└","─","┘" };


	wcout << "┌──────────────────┐\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "│        ♦         │\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "│                  │\n";
	wcout << "└──────────────────┘\n";
	for (size_t i = 0; i < 5; i++)
	{
		cout << characters[i];
	}

}


