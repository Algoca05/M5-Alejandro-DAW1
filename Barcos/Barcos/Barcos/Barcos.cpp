#include "Barcos.h"
#include <iostream>


int Barcos::getSpeed() {
	return speed;
}
int Barcos::getDistance() {
	return distance;
}
bool Barcos::getNitro() {
	if (nitro)
	{
		return true;
	}
	else return false;
}
std::string Barcos::getName() {
	return name;
}

void Barcos::setSpeed(int pSpd) {
	speed = pSpd;
}
void Barcos::setDistance(int pDis) {
	distance = pDis;
}
void Barcos::setNitro(bool pNitro) {	
	nitro = pNitro;
}
void Barcos::setName(std::string pName) {	
	name = pName;
}



void Barcos::getParameters() {
	std::cout << "You have: Speed "<<speed<<" and you are "<<distance<<" meters ";
	if (nitro)
	{
		std::cout << "Nitro available: yes";
	}
	else std::cout << "Nitro available: no";
	std::cout << "Name: "<<name<<"\n";
}


Barcos::Barcos(int pSpd, int pDis, bool pNitro, std::string pName)
{
	speed = pSpd;
	distance = pDis;
	nitro = pNitro;
	name = pName;
}

Barcos::Barcos()
{
}




