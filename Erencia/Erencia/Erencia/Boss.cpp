
#include "Boss.h"

Boss::Boss(int pHP, int pAtk, int pSpd, int pDef, std::string pName,bool pHCharge) : 
	Personaje( pHP,  pAtk,  pSpd,  pDef, pName)
{
	hCharge = pHCharge;
}

bool Boss::gethCharge()
{
	return hCharge;
}

void Boss::sethCharge(bool pHCharge)
{
}

void Boss::printAllStats()
{
}
