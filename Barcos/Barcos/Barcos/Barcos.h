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

class Part {
private:
	std::string name;
	int speed;
	int weight;
public:
	int getSpeed();
	int getWeight();
	std::string getName();

	void setSpeed(int pSpd);
	void setWeight(int pWght);
	void setName(std::string pName);

	Part();
	Part(int speed, int weight, int nitro, std::string name);
};

namespace ship {
	class fShip {
	public:

	};
}