#include <iostream>
#include "Enemigo.h"
using namespace std;

int main() {
	
	Enemigo enemigo1;
	enemigo1.setHP(500);
	enemigo1.setAttack(100);
	enemigo1.setName("Morgot");
	Enemigo enemigo2 = Enemigo("Rani", 600, 150);
	
	enemigo1.getParameters();
	enemigo2.getParameters();
	

}