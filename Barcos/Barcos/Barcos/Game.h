#pragma once
#include <SFML/Graphics.hpp>;
#include <SFML/System.hpp>;
#include <SFML/Window.hpp>;
#include <SFML/Audio.hpp>;
#include<iostream>
#include <Vector>
#include <ctime>
#include "Barcos.h"
#include <time.h>

class Game
{
private: 
	//Fondo
	sf::Texture city;
	sf::Texture ship;
	sf::Texture moon;
	//Window
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event ev;
	//Mouse position
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;

	//Font
	sf::Font font;

	//Reloj
	sf::Clock reloj;
	
	

	//game logic
	unsigned points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;
	int currentFrame =1;


	//game objects
	sf::Sprite ship1;
	sf::Sprite ship2;
	sf::Sprite spriteCity;
	sf::Sprite spriteMoon;
	//function
	void initVariables();
	void initWindow();
	void initEnemies();
	void initDice();
	
public:
	//constructors / destructors
	Game();
	virtual ~Game();
	//Accesors
	const bool running() const;

	//Funcion
	void update();
	void updateMousePosition();
	void updateEnemies();

	void render();
	void renderEnemies();

	void loadFiles();

	void pollEvents();
	void sapwnShip();
	int dice();
	void shipMove(int number);
};

