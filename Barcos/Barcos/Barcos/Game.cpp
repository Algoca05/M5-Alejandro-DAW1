#include "Game.h"
//private
void Game::initVariables()
{
	this->window = nullptr;

	
}

void Game::initWindow()
{
	this->VideoMode.height =768 ;
	this->VideoMode.width = 1366;
	
	this->window = new sf::RenderWindow(sf::VideoMode(1366, 768), "Ship Race", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}
void Game::initEnemies()
{
	ship.loadFromFile("Files/ship.png");

	ship1.setTexture(ship);
	this->ship1.setPosition(-25.f,370.f);
	this->ship1.setScale(sf::Vector2f(0.1f, 0.1f));

	ship.loadFromFile("Files/ship.png");

	ship2.setTexture(ship);
	this->ship2.setPosition(-25.f, 570.f);
	this->ship2.setScale(sf::Vector2f(0.1f, 0.1f));

	moon.loadFromFile("Files/moon.png");

	spriteMoon.setTexture(moon);
	this->spriteMoon.setPosition(1150.f, 0.f);
	this->spriteMoon.setScale(sf::Vector2f(0.1f, 0.1f));
	
	/*this->enemy.setOutlineColor(sf::Color::Cyan);
	this->enemy.setOutlineThickness(1.f);*/

}
void Game::initDice()
{
	
	int time = reloj.getElapsedTime().asMilliseconds();
	float frameDuration = 150;
	int numFrames = 6;
	int frame = static_cast<int>(time / frameDuration) % numFrames +1;
	if (frame != currentFrame)
	{
		


			currentFrame = frame;
			if (!moon.loadFromFile("Files/Dado/" + std::to_string(frame) + ".png")) {
				// Manejar error
			}
			spriteMoon.setTexture(moon);
		
	}
	

}
void Game::loadFiles()
{
	//Background
	city.loadFromFile("Files/Background.jpg");
	spriteCity.setTexture(city);
	spriteCity.scale(0.50,0.35);
	

}
//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;

}

// Accesors
const bool Game::running() const
{
	return this->window->isOpen();
}
//Functions
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}


int Game::dice()
{
	int number = rand() % 6 + 1;

	return number;
}

void Game::shipMove(int number)
{
	int count1 = 0;
	int count2 = 0;



}



void Game::update()
{
	this->pollEvents();

	//update mouse position
	//std::cout << "Mouse pos:" << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";
	this->updateEnemies();
	this->updateMousePosition();
}

void::Game::updateMousePosition() {
	
	this->MousePosWindow = sf::Mouse::getPosition(*this->window);
	this->MousePosView = this->window->mapPixelToCoords(this->MousePosWindow);
}

void Game::updateEnemies()
{
	

	bool yourTurn = true;

		//check click
	if (yourTurn)
	{

	
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->spriteMoon.getGlobalBounds().contains(this->MousePosView))
			{
				this->initDice();


				int number = dice();
				yourTurn = false;
				shipMove(number);
			}

		}
	}
}

void Game::render()
{
	//render objects
	this->window->clear(); 

	//Sprites
	this->window->draw(spriteCity);
	//Draw Game objects
	this->renderEnemies();
	

	this->window->display();
}

void Game::renderEnemies()
{
	
	this->window->draw(ship1); 
	this->window->draw(ship2);
	this->window->draw(spriteMoon);

}


