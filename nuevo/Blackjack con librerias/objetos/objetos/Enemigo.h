#pragma once

 #pragma once
#include <iostream>

class Enemigo
{
private:
	int HP;
	int attack;
	std::string name;

public:
	//g-s
	int getHP();
	int getAttack();
	std::string getName();

	void setHP(int pHP);
	void setAttack(int pAttack);
	void setName(std::string pName);

	void getParameters();
	Enemigo();
	Enemigo(std::string pName, int pHP, int pAttack);
};

