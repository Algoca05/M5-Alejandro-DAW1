#include "Game.h"
//private
void Game::initVariables()
{
	this->window = nullptr;

	//game logic
	this->points = 0;
	this-> enemySpawnTimer = this-> enemySpawnTimerMax;
	this-> enemySpawnTimerMax= 10.f;
	this-> maxEnemies=50;
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
	
	/*this->enemy.setOutlineColor(sf::Color::Cyan);
	this->enemy.setOutlineThickness(1.f);*/

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

void Game::sapwnShip(){

//ship1.scale(0.50, 0.35);
//ship2.setTexture(ship);
//ship2.scale(0.50, 0.35);

	
	
	
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
	//if (this->enemies.size() < this-> maxEnemies)
	//{
	//if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
	//{
	//	this->sapwnEnemy();
	//	this->enemySpawnTimer = 0.f;
	//}
	//else this->enemySpawnTimer += 1.f;
	//}

	////Move enemies
	//for (int i = 0 ; i <this->enemies.size();i++)
	//{
	//	bool deleted = false;
	//	this->enemies[i].move(0.f,2.f);

	//	//check click
	//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//	{
	//		if (this->enemies[i].getGlobalBounds().contains(this->MousePosView))
	//		{
	//			deleted = true;
	//		}
	//	}
	//	if (this->enemies[i].getPosition().y>this->window->getSize().y)
	//	{
	//		deleted = true;
	//	}
	//	if (deleted)
	//	{
	//		this->enemies.erase(this->enemies.begin()+i);
	//	}
	//}
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
	/*for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}*/
	this->window->draw(ship1); 
	this->window->draw(ship2);

}


