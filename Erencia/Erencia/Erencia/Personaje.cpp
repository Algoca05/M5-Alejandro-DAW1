// Erencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
#include "Personaje.h"


//getters
int Personaje::getHP()
{
    return health;
}

int Personaje::getAtk()
{
    return attack;
}

int Personaje::getSpd()
{
    return speed;
}

int Personaje::getMAtk()
{
    return megaAttack;
}

int Personaje::getLives()
{
    return lives;
}

int Personaje::getDef()
{
    return defensa;
}

std::string Personaje::getName()
{
    return name;
}


//Setters

void Personaje::setHp(int pHP)
{
    health = pHP;
}

void Personaje::setAtk(int pAtk)
{
    attack = pAtk;
}

void Personaje::setSpd(int pSpd)
{
    speed = pSpd;
}

void Personaje::setMAtk(int pMAtk)
{
    megaAttack = pMAtk;
}

void Personaje::setLives(int pLives)
{
    lives = pLives;
}

void Personaje::setDef(int pDef)
{
    defensa = pDef;
}

void Personaje::setName(std::string pName)
{
    name = pName;
}


//Metodos propios
void Personaje::getParamsEnemies()
{
    std::cout << "Enemy: \nHP = " << health << "\nName = " << name;
}

void Personaje::getParamsHero()
{
    std::cout << "Hero: \nHP = " << health << "\nName = " << name << "\nCharge = " << megaAttack << "\nLives = " << lives;
}





