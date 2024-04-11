#include "Barcos.h"
#include <iostream>


int Barcos::getSpeed() {
	return speed;
}
int Barcos::getDistance() {
	return distance;
}
int Barcos::getNitro() {
	return nitro;
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
void Barcos::setNitro(int pNitro) {	
	nitro = pNitro;
}
void Barcos::setName(std::string pName) {	
	name = pName;
}
void Barcos::getParameters() {
	std::cout << "You have: Speed "<<speed<<" and you are "<<distance<<" meters ";
	if (nitro ==1)
	{
		std::cout << "Nitro available: yes";
	}
	else std::cout << "Nitro available: no";
}