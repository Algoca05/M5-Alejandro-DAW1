#pragma once
#include <iostream>
#include <ctime>
#include <time.h>
#include "Personaje.h"



class Boss : public Personaje
{
private:
	bool hCharge;

public:

	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE PADRE Y PROPIA
	Boss(int pHP, int pAtk, int pSpd, int pDef, std::string pName, bool pHCharge);

	//GETTERS AND SETTERS
	bool gethCharge();
	

	void sethCharge(bool pHCharge);
	

	//METODOS PROPIOS
	void printAllStats();

};