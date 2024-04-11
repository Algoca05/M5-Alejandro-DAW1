#pragma once
#include <iostream>

class Barcos {

private:
	int speed;
	int distance;
	int nitro;
	std::string name;

public:
	int getSpeed();
	int getDistance();
	int getNitro();
	std::string getName();

	void setSpeed(int pSpd);
	void setDistance(int pDis);
	void setNitro(int pNitro);
	void setName(std::string pName);
	void getParameters();

	Barcos();
	Barcos(int speed,int distance, int nitro, std::string name);
};

class parts {


};
