#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
// Sonidos
  /*

  PlaySound(TEXT("punetazo.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("muerto.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("ganador.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("fireball.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("espada.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("desembainar.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("inicio.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("boss1.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("shadow.wav"), NULL, SND_FILENAME);
 */

 // Colores
  /*
  rojo \033[031m
  verde \033[032m
  amarillo \033[033m
  azul oscuro \033[034m
  morado \033[035m
  azul claro \033[036m
  blanco \033[037m
*/

//Main character

string characterName;
int characterAtackValuePunch1;
int characterAtackValuePunch2;
int characterAtackValueMagic;
int characterAtackValueSword;
int characterAtackValueCharged;
int characterAtackValueHealth;
int selectAttack;
int manacounter = 3; 
int magicPotions = 2;
string manaAttack = "Fire ball";
bool heroIsAlive = true;
bool charged = false;
int characterHPValue = rand() % 501 + 2500;

//Boss Character 1
string boss1Name = "\033[035m8-BIT\033[037m";
int boss1AtackValue;
int boss1HPValue = rand() % 701 + 2400;
//Boss Character 2
string boss2Name = "\033[035mShadow\033[037m";
int boss2AtackValue;
int boss2HPValue = rand() % 501 + 3000;
int bossNumber;

void introduction() {

    // Enter Character Name
    cout << "Bienvenido a la batalla final, me recuerdas tu nombre:\n";
    cin >> characterName;
    characterName = "\033[033m" + characterName + "\033[037m";
    system("cls");
    // Declaracion valores en el juego
    cout << "You will have to fight against\n" << boss1Name << " that have \033[032m" << boss1HPValue << " HP\033[037m \n" << boss2Name << " that have \033[032m" << boss2HPValue << " HP \033[037m\n";
    cout << characterName << " will have \033[032m" << characterHPValue << " HP\n\033[037m";
   // PlaySound(TEXT("inicio.wav"), NULL, SND_FILENAME);

    system("pause");
    system("cls");

}
bool boss1Atk() {
    if (boss1HPValue > 0 && characterHPValue > 0)
    {
       
        {


            characterHPValue = characterHPValue - boss1AtackValue;
            if (characterHPValue < 0) {
                characterHPValue = 0;
            }
            cout << boss1Name << " attacks you ";

            PlaySound(TEXT("boss1.wav"), NULL, SND_FILENAME);
            system("cls");
            cout << boss1Name << " attack you and deals a total of damage of \033[031m" << boss1AtackValue << "\033[037m and now you have \033[032m" << characterHPValue << " HP\n\033[037m";
            system("pause");
            system("cls");
        }
        if (characterHPValue < 0)
        {
            
            cout << "Estas muerto";
            return false;
        }
        else if (characterHPValue>0)
        {
            return true;
        }
    }
}
bool boss2Atk() {
    if (boss2HPValue > 0 && characterHPValue > 0)
    {
        characterHPValue = characterHPValue - boss2AtackValue;
        if (characterHPValue < 0) {
            characterHPValue = 0;
        }
        cout << boss2Name << " attacks you";
        PlaySound(TEXT("shadow.wav"), NULL, SND_FILENAME);
        PlaySound(TEXT("shadow.wav"), NULL, SND_FILENAME);


        system("cls");
        cout << boss2Name << " attack you and deals a total of damage of \033[031m" << boss2AtackValue << "\033[037m and now you have \033[032m" << characterHPValue << " HP\n\033[037m";
        system("pause");
        system("cls");
        if (characterHPValue < 0)
        {

            cout << "Estas muerto";
            return false;
        }
        else if (characterHPValue > 0)
        {
            return true;
        }
    }
}
void final() {
    if (heroIsAlive)
    {
        cout << "You have win against " << boss1Name << " and " << boss2Name;
        cout << "\n---------------\033[033mYOU WIN\033[037m---------------";
        PlaySound(TEXT("ganador.wav"), NULL, SND_FILENAME);

    }
    else if (!heroIsAlive && boss1HPValue > 0 && boss2HPValue < 0)
    {
        cout << boss1Name << " have defeat you\n";
        cout << "---------------\033[031mDEFEAT\033[037m---------------";
        PlaySound(TEXT("muerto.wav"), NULL, SND_FILENAME);

    }
    else if (!heroIsAlive && boss2HPValue > 0 && boss1HPValue < 0)
    {
        cout << boss2Name << " have defeat you\n";
        cout << "---------------\033[031mDEFEAT\033[037m---------------";
    }
    else {
        cout << "You have been defeated for both booses\n";
        cout << "---------------\033[031mDEFEAT\033[037m---------------";
        PlaySound(TEXT("muerto.wav"), NULL, SND_FILENAME);
    }
}
void ataque1() {

}
int selectionBoss() {
    int number = 0;
    while (number !=2 && number !=1)
    {

    
    cout << "select the boss you want to attack:\n";
    if (boss1HPValue > 0)
    {
        cout << " 1-- > " << boss1Name << "\n";
    }
    if (boss2HPValue > 0)
    {
        cout << " 2-- > " << boss2Name << "\n";
    }
    
    cin >> number;
    system("cls");

    }
    return number;
}
void atkSelection1() {
    selectAttack = 0;
    while (selectAttack != 1 && selectAttack != 2 && selectAttack != 3 && selectAttack != 4 && selectAttack != 5  )
    {

    
    cout << "Select an attack to fight against " << boss1Name << ": \n 1-->\033[036m Fire Ball\033[037m \n 2--> \033[036mSword Attack\033[037m\n 3--> \033[036mPunch Attack\033[037m\n 4--> \033[036mSolar Beam\033[037m\n 5--> \033[036mHealth Potion\033[037m\n";
    cin >> selectAttack;
    system("cls");
    }
}
void atkSelection2() {
    selectAttack = 0;
    while (selectAttack != 1 && selectAttack != 2 && selectAttack != 3 && selectAttack != 4 && selectAttack != 5) {
        cout << "Select an attack to fight against " << boss2Name << ": \n 1-->\033[036m Fire Ball\033[037m \n 2--> \033[036mSword Attack\033[037m\n 3--> \033[036mPunch Attack\033[037m\n 4--> \033[036mSolar Beam\033[037m\n 5--> \033[036mHealth Potion\033[037m\n";
        cin >> selectAttack;

        system("cls");
    }
}

int main()
{
    srand(time(NULL));

    introduction();

    while ((boss1HPValue > 0 || boss2HPValue > 0) && characterHPValue > 0) {

        /*Main Game*/
        //ATK Declaration
        characterAtackValuePunch1 = rand() % 251 + 150;
        characterAtackValuePunch2 = rand() % 251 + 150;
        characterAtackValueMagic = rand() % 901 + 150;
        characterAtackValueSword = rand() % 200 + 550;
        characterAtackValueCharged = rand() % 1500 + 800;
        characterAtackValueHealth = rand() % 100 + 700;
        boss1AtackValue = rand() % 325 + 100;
        boss2AtackValue = rand() % 400 + 150;
        //Variables de vida 0
        /*
        if (boss1HPValue < 0) {
            boss1HPValue = 0;
        }
        if (boss2HPValue < 0) {
            boss2HPValue = 0;
        }
        if (characterHPValue < 0) {
            characterHPValue = 0;
        }*/
       
        //Seleccion del boss
        




        bossNumber = selectionBoss();
     
        
        if (bossNumber == 1)
            {
            if (boss1HPValue == 0)
            {
                cout << "This BOSS is DEAD";
            }
                atkSelection1();
                if (selectAttack == 1 && manacounter > 0)
                {
                    PlaySound(TEXT("fireball.wav"), NULL, SND_FILENAME);

                    boss1HPValue = boss1HPValue - characterAtackValueMagic;
                    if (boss1HPValue < 0) {
                        boss1HPValue = 0;
                    }

                    cout << "you have make\033[031m " << characterAtackValueMagic << " \033[037m to ";
                    cout << boss1Name << " now have \033[032m" << boss1HPValue << " HP\033[037m \n";
                    manacounter = manacounter - 1;
                    cout << "Now your mana is lower and you have " << manacounter << " attacks with " << manaAttack << "\n";
                    system("pause");
                    system("cls");
                }
                else if (selectAttack == 2)
                {
                    PlaySound(TEXT("desembainar.wav"), NULL, SND_FILENAME);

                    boss1HPValue = boss1HPValue - characterAtackValueSword;
                    if (boss1HPValue < 0) {
                        boss1HPValue = 0;
                    }
                    PlaySound(TEXT("espada.wav"), NULL, SND_FILENAME);
                    cout << "you have make\033[031m " << characterAtackValueSword << " \033[037m to ";
                    cout << boss1Name << " now have \033[032m" << boss1HPValue << " HP\033[037m \n";
                    system("pause");
                    system("cls");
                }
                else if (selectAttack == 3)
                {
                    PlaySound(TEXT("punetazo.wav"), NULL, SND_FILENAME);
                    boss1HPValue = boss1HPValue - characterAtackValuePunch1;
                    if (boss1HPValue < 0) {
                        boss1HPValue = 0;
                    }

                    cout << "you have make\033[031m " << characterAtackValuePunch1 << " \033[037m to ";
                    cout << boss1Name << " now have \033[032m" << boss1HPValue << " HP\033[037m \n";
                    if (boss1HPValue > 0)
                    {
                        boss1HPValue = boss1HPValue - characterAtackValuePunch2;
                        if (boss1HPValue < 0) {
                            boss1HPValue = 0;

                        }
                        cout << "you have make\033[031m " << characterAtackValuePunch2 << " \033[037m to ";
                        cout << boss1Name << " now have \033[032m" << boss1HPValue << " HP\033[037m \n";
                    }
                    system("pause");
                    system("cls");
                }
                else if (selectAttack == 4)
                {
                    if (charged)
                    {
                        boss1HPValue = boss1HPValue - characterAtackValueCharged;
                        if (boss1HPValue < 0) {
                            boss1HPValue = 0;

                        }
                        cout << "you have make\033[031m " << characterAtackValueCharged << " \033[037m to ";
                        cout << boss1Name << " now have \033[032m" << boss1HPValue << " HP\033[037m \n";
                        charged = false;
                    }
                    else if(!charged)
                    {
                        cout << "Charging solar beam\n";
                        charged = true;
                    
                    }
                  
                    system("pause");
                    system("cls");
                }
                else if (selectAttack == 5)
                {
                    characterHPValue = characterHPValue + characterAtackValueHealth;

                    cout << "you have health\033[031m " << characterAtackValueHealth << " \033[037m to ";
                    cout << characterName << " now have \033[032m" << characterHPValue << " HP\033[037m \n";
                    
                       magicPotions = magicPotions - 1;
                    cout << "Now your mana is lower and you have " << magicPotions << " attacks with health potions\n";
                    system("pause");
                    system("cls");
                }
                else {
                    cout << "You don't have mana or you have select a wrong Attack-----------　　YOU FLINT!!!! \n";

                    system("pause");
                    system("cls");
                }
                //Ataques del boss

                heroIsAlive = boss1Atk();

                heroIsAlive = boss2Atk();
            }
        

        else if (bossNumber == 2)
        {
            if (boss2HPValue == 0)
            {
                cout << "This BOSS is DEAD";
            }
          atkSelection2();
            if (selectAttack == 1 && manacounter > 0)
            {
                boss2HPValue = boss2HPValue - characterAtackValueMagic;
                if (boss2HPValue < 0) {
                    boss2HPValue = 0;
                }
                PlaySound(TEXT("fireball.wav"), NULL, SND_FILENAME);



                cout << "you have make \033[031m " << characterAtackValueMagic << " \033[037m to ";
                cout << boss2Name << " now have \033[032m" << boss2HPValue << " HP \033[037m\n";
                manacounter = manacounter - 1;
                cout << "Now your mana is lower and you have " << manacounter << " attacks with " << manaAttack << "\n";
                system("pause");
                system("cls");
            }
            else if (selectAttack == 2)
            {
                PlaySound(TEXT("desembainar.wav"), NULL, SND_FILENAME);

                boss2HPValue = boss2HPValue - characterAtackValueSword;
                if (boss2HPValue < 0) {
                    boss2HPValue = 0;
                }
                PlaySound(TEXT("espada.wav"), NULL, SND_FILENAME);
                cout << "you have make \033[031m " << characterAtackValueSword << " \033[037m to ";
                cout << boss2Name << " now have \033[032m" << boss2HPValue << " HP \033[037m\n";
                system("pause");
                system("cls");
            }
            else if (selectAttack == 3)
            {
                PlaySound(TEXT("punetazo.wav"), NULL, SND_FILENAME);

                boss2HPValue = boss2HPValue - characterAtackValuePunch1;
                if (boss2HPValue < 0) {
                    boss2HPValue = 0;
                }
                cout << "you have make \033[031m " << characterAtackValuePunch1 << " \033[037m to ";
                cout << boss2Name << " now have \033[032m" << boss2HPValue << " HP \033[037m\n";
                if (boss2HPValue > 0)
                {
                    boss2HPValue = boss2HPValue - characterAtackValuePunch2;
                    if (boss2HPValue < 0) {
                        boss2HPValue = 0;

                    }
                    cout << "you have make \033[031m " << characterAtackValuePunch2 << " \033[037m to ";
                    cout << boss2Name << " now have \033[032m" << boss2HPValue << " HP\033[037m \n";
                }
                system("pause");
                system("cls");
            }
            else if (selectAttack == 4)
            {
                if (charged == true)
                {
                    boss2HPValue = boss2HPValue - characterAtackValueCharged;
                    if (boss2HPValue < 0) {
                        boss2HPValue = 0;

                    }
                    cout << "you have make\033[031m " << characterAtackValueCharged << " \033[037m to ";
                    cout << boss2Name << " now have \033[032m" << boss2HPValue << " HP\033[037m \n";
                    charged = false;
                }
                else if (charged == false)
                {
                    cout << "Charging solar beam\n";
                    charged = true;

                }

                system("pause");
                system("cls");
            }
            else if (selectAttack == 5)
            {
                characterHPValue = characterHPValue + characterAtackValueHealth;

                cout << "you have health\033[031m " << characterAtackValueHealth << " \033[037m to ";
                cout << characterName << " now have \033[032m" << characterHPValue << " HP\033[037m \n";

                magicPotions = magicPotions - 1;
                cout << "Now your mana is lower and you have " << magicPotions << " attacks with health potions\n";
                system("pause");
                system("cls");
            }
            else {
                cout << "You don't have mana or you have select a wrong Attack-----------　　YOU FLINT!!!! \n";
            }
            //Ataques del boss

            boss1Atk();

            boss2Atk();
        }

       
    }

    //Declaracion del ganador
    final();
}

