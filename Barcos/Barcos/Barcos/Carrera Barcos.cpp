// Barcos.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

#include <iostream>
#include"Barcos.h"

#include "Game.h"

int main()
{
	std::srand(static_cast<unsigned>(time(NULL)));
	//init game
	Game game;
	game.loadFiles();


	//Game loop
	while (game.running())
	{
		srand(time(NULL));


		//update
		game.update();
		//render
		game.render();
		//Draw your game
		
	}
	//End application
	return 0;
}


