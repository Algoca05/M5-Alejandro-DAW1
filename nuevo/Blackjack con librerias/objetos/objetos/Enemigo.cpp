#include "Enemigo.h"
#include <iostream>

int Enemigo::getHP() {
	return HP;
}
int Enemigo::getAttack() {
	return attack;
}
std::string Enemigo::getName() {
	return name;
}

void Enemigo::setHP(int pHP) {
	HP = pHP;
}
void Enemigo::setAttack(int pAttack) {
	attack = pAttack;
}
void Enemigo::setName(std::string pName) {
	name = pName;
}
void Enemigo::getParameters() {
	std::cout << "Name: " << name << "\nHealth: "<< HP << "\nAttack: "<< attack ;
	
}
Enemigo::Enemigo(std::string pName , int pHP, int pAttack ) {
	name = pName;
	HP = pHP;
	attack = pAttack;
}
