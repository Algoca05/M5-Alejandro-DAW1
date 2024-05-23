#pragma once
#include "Boss.h"

class Personaje
{
private:
	int health;
	int attack;
	int speed;
	int megaAttack;
	int lives;
	int defensa;
	std::string name;

public:
	int getHP();
	int getAtk();
	int getSpd();
	int getMAtk();
	int getLives();
	int getDef();
	std::string getName();
	

	void setHp(int pHP);
	void setAtk(int pAtk);
	void setSpd(int pSpd);
	void setMAtk(int pMAtk);
	void setLives(int pLives);
	void setDef(int pDef);
	void setName(std::string pName);

	void getParamsEnemies();
	void getParamsHero();
};
