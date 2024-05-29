#include <iostream>
#include <time.h>
#include "Personaje.h"
#include "EnemigoFinal.h"


//en esta funcion cojemos los parametros del mapa y el de moves para poder escribir por pantalla el mapa dependiendo los numeros asociados en el mapa se printeara una cosa o otra.
void crearMapa(string moves[3], int mapa[5][5]) {
	
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (mapa[i][j] == 0 || mapa[i][j] == 2 || mapa[i][j] == 1)
			{
				cout << moves[0];
			}
			
			else if (mapa[i][j] == 3)
			{
				cout << moves[1];
			}
			else 
			{
				cout << moves[2];
			}
		}
		cout << "\n";
	}
}


int main() {
	srand(time(NULL));
	//Variables que se usan simpre
	int num;

	
	
	//miramos donde puede haber enemigos
	int mapa[5][5];
	//creamos lo que ira en el mapa luego
	//espacio sin visitar o vacio: "-" espacio del jugador "*" espacio con montruo "!".
	string moves[3] = { " - "," * "," ! "};


	//en este caso crearemos un total de 4 enemigos pequeños y un jefe que estara ne la salida
	Personaje heroe(2000,"nombre",150,4,0);
	Personaje enemigo1(150,"1",50,4,0);
	Personaje enemigo2(150,"2",30,3,0);
	Personaje enemigo3(160,"3",20,2,0);
	Personaje enemigo4(305,"4",15,1,0);
	EnemigoFinal boss(1000, "5", 300, 0, 0,400,600);
	//pondremos que los espacion seguroas son 0 los enemigos son 1 y el boss es 2
	//primero rellenamos la array con todo 0 para luego añadir los enemigos
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			mapa[i][j] = 0;
			
		}
	}
	//Ahora ponemos un enemigo en cada fila en una columns random y les iremos dando valor a todos los personajes
	
	//Enemigo 1
		num = rand() % 5;
		mapa[enemigo1.getPosicionX()][num] = 1;
		enemigo1.setPosicionY(num);
	//Enemigo 2
		num = rand() % 5;
		mapa[enemigo2.getPosicionX()][num] = 1;
		enemigo2.setPosicionY(num);
	//Enemigo 3
		num = rand() % 5;
		mapa[enemigo3.getPosicionX()][num] = 1;
		enemigo3.setPosicionY(num);
	//Enemigo 4
		num = rand() % 5;
		mapa[enemigo4.getPosicionX()][num] = 1;
		enemigo4.setPosicionY(num);
	
	//para finalizar ponemos el jefe en la fila 5 que en la array es la 0
		num = rand() % 5;
		mapa[0][num] = 2;
		boss.setPosicionY(num);
	
	//ahora colocamos al jugadoren la primera que es la ultima en el array usaremos el 3 como posicion inicial.
	do
	{
		
		if (true)
		{
			num = rand() % 5;
			if (mapa[4][num] ==0)
			{
				mapa[4][num] = 3;
				heroe.setPosicionY(num);
			}
		}
	} while (mapa[4][num] !=3);

	
	
	while (heroe.getHp()>0 && boss.getHp()>0)
	{

		

		//creamos el mapa a partir de la funcion
		crearMapa(moves, mapa);
		//dejamos elegir con wasd
		cout << "movimiento wasd\n";
		char letra;
		cin >>  letra;
		int x = heroe.getPosicionX();
		int y = heroe.getPosicionY();
		
		int antX = x;
		int antY = y;
		//la segunda condicion es para que no pete y "se salga de la pantalla"
		
		if (letra == 's' && x !=4 )
		{
			x += 1;
		}
		else if (letra == 'w' && x!=0  )
		{
			x -= 1;
		}
		else if (letra == 'd'  && y !=4 )
		{
			y += 1;
		}
		else if (letra == 'a' && y!=0  )
		{
			y -= 1;
		}
		else
		{
			cout << "tecla o movimiento incorrecto";
		}
		
		
		//comprobamos si hay algun enemigo en esa casilla
		if (mapa[x][y]==0)
		{
			mapa[x][y] = 3;
			mapa[antX][antY] = 0;
		
		}
		else if (mapa[x][y] == 1 || mapa[x][y] == 2)
		{
			mapa[x][y] = 4;
			mapa[antX][antY] = 0;
			system("cls");
			crearMapa(moves, mapa);
			if (enemigo1.getPosicionX() == x && enemigo1.getPosicionY()==y)
			{
				
				cout << "Ha aparecido " << enemigo1.getName()<<endl;
				while (heroe.getHp()>0 &&enemigo1.getHp()>0)
				{
					heroe.setHp(heroe.getHp()-enemigo1.getHp());
					enemigo1.setHp(enemigo1.getHp()-heroe.getHp());
				}
				if (heroe.getHp() > 0)
				{
					cout << "te queda:" << heroe.getHp() << " puntos de vida"<<endl;
				}
				else cout << "Has muerto"<<endl;
			}
			else if (enemigo2.getPosicionX() == x && enemigo2.getPosicionY() == y)
			{
				cout << "Ha aparecido " << enemigo2.getName() << endl;
				while (heroe.getHp() > 0 && enemigo2.getHp() > 0)
				{
					heroe.setHp(heroe.getHp() - enemigo2.getHp());
					enemigo2.setHp(enemigo2.getHp() - heroe.getHp());
				}
				if (heroe.getHp() > 0)
				{
					cout << "te queda:" << heroe.getHp() << " puntos de vida" << endl;
				}
				else cout << "Has muerto" << endl;
			}
			else if (enemigo3.getPosicionX() == x && enemigo3.getPosicionY() == y)
			{
				cout << "Ha aparecido " << enemigo3.getName() << endl;
				while (heroe.getHp() > 0 && enemigo3.getHp() > 0)
				{
					heroe.setHp(heroe.getHp() - enemigo3.getHp());
					enemigo3.setHp(enemigo3.getHp() - heroe.getHp());
				}
				if (heroe.getHp() > 0)
				{
					cout << "te queda:" << heroe.getHp() << " puntos de vida" << endl;
				}
				else cout << "Has muerto" << endl;
			}
			else if(enemigo4.getPosicionX() == x && enemigo4.getPosicionY() == y)
			{
				cout << "Ha aparecido " << enemigo4.getName() << endl;
				while (heroe.getHp() > 0 && enemigo4.getHp() > 0)
				{
					heroe.setHp(heroe.getHp() - enemigo4.getHp());
					enemigo4.setHp(enemigo4.getHp() - heroe.getHp());
				}
				if (heroe.getHp() > 0)
				{
					cout << "te queda:" << heroe.getHp() << " puntos de vida" << endl;
				}
				else cout << "Has muerto" << endl;
			}
			else if (boss.getPosicionX() == x && boss.getPosicionY() == y)
			{
				cout << "Ha aparecido " << boss.getName() << endl;
				while (heroe.getHp() > 0 && boss.getHp() > 0)
				{
					int dado = rand() % 10;
					if (dado <3)
					{
						heroe.setHp(heroe.getHp() - boss.getMegaAttack());
						boss.setHp(boss.getHp() - heroe.getHp());
					}
					else if (dado >7)
					{
						heroe.setHp(heroe.getHp() - boss.getHiperAttack());
						boss.setHp(boss.getHp() - heroe.getHp());
					}
					else {
						heroe.setHp(heroe.getHp() - boss.getHp());
						boss.setHp(boss.getHp() - heroe.getHp());
					}
				
				}
				if (heroe.getHp() > 0)
				{
					cout << "te queda:" << heroe.getHp() << " puntos de vida" << endl;
				}
				else cout <<     endl;
			}



			system("pause");
		}
		
			
		heroe.setPosicionX(x);
		heroe.setPosicionY(y);
		system("cls");
	}
	if (heroe.getHp() > 0)
	{
		cout << "Enhorabuena! Has derrotado a " << boss.getName() << " y has sobrevivido a esta batalla epica.\n";
		cout << "Te quedan " << heroe.getHp() << " puntos de vida.\n";
		cout << "La victoria es tuya, valiente héroe. El reino celebra tu triunfo y tu nombre será recordado en las leyendas.\n";
	}
	else
	{
		cout << "Has caido en combate contra " << boss.getName() << ".\n";
		cout << "Tu valentia no será olvidada. Descansa en paz, valiente guerrero.\n";
	}





	

}