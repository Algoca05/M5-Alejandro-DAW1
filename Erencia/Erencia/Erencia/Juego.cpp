#include "Personaje.h"
#include "Boss.h"
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));

	cout << "Vamos a crear el campo de batalla: como de ancho quieres que sea?\n";
	int width = rand()%10+5;
	
	cout << "como de alto quiers que sea ?\n";
	int height = rand() % 5 + 5;

	int** hola = new int* [width];
	for (int i = 0; i < width; ++i) {
		hola[i] = new int[height];
	
		cout << "\n\n";
	}
	for (size_t i = 0; i <= width; i++)
	{
		cout << "  -" << i << "-  ";
	}cout<<"\n\n";
	for (int i = 0; i < height; i++)
		{
			cout << "  -" << height-i << "-  ";
			for (int j = 0; j < width; j++)
			{
				cout << "  _?_  ";
			}
			cout << "\n\n";
		}
	cout << "Como funciona el mapa:\n___ Espacio bacio\n_?_ Espacio sin mirar\n_X_ Tu localizacion\n_*_ Enemigo\nSTR Inicio\nFNL Salida";
}