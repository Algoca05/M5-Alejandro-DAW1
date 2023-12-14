#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#pragma comment(lib, "winmm.lib")
int main()
{
    
    using namespace std;
   /* Sonidos
      PlaySound(TEXT("punetazo.wav"), NULL, SND_FILENAME);
      PlaySound(TEXT("muerto.wav"), NULL, SND_FILENAME);
      PlaySound(TEXT("ganador.wav"), NULL, SND_FILENAME);
      PlaySound(TEXT("fireball.wav"), NULL, SND_FILENAME);
      PlaySound(TEXT("espada.wav"), NULL, SND_FILENAME);
      PlaySound(TEXT("desembainar.wav"), NULL, SND_FILENAME);
      PlaySound(TEXT("inicio.wav"), NULL, SND_FILENAME);
      PlaySound(TEXT("boss1.wav"), NULL, SND_FILENAME);
      PlaySound(TEXT("shadow.wav"), NULL, SND_FILENAME);


      Colores
      rojo \033[031m
      verde \033[032m
      amarillo \033[033m
      azul oscuro \033[034m
      morado \033[035m
      azul claro \033[036m
      blanco \033[037m
   */

    
    //Main character
    
    srand(time(NULL));
    string characterName;
    int characterAtackValuePunch1;
    int characterAtackValuePunch2;
    int characterAtackValueMagic;
    int characterAtackValueSword;
    int selectAttack;
    int manacounter;
    string manaAttack = "Fire ball";
    manacounter = 3;

    int characterHPValue = rand() % 501 + 2500;

    //Boss Character 1
    string boss1Name = "\033[035m8-BIT\033[037m";
    int boss1AtackValue;
    int boss1HPValue = rand() % 701 + 2200;
    //Boss Character 2
    string boss2Name = "\033[035mShadow\033[037m";
    int boss2AtackValue;
    int boss2HPValue = rand() % 501 + 2800;
    int bossNumber;

    // Enter Character Name
    cout << "Bienvenido a la batalla final, me recuerdas tu nombre:\n";
    cin >> characterName;
    characterName = "\033[033m" + characterName + "\033[037m";
    system("cls");
    // Declaracion valores en el juego
    cout << "You will have to fight against\n" << boss1Name << " that have \033[032m" << boss1HPValue << " HP\033[037m \n" << boss2Name << " that have \033[032m" << boss2HPValue << " HP \033[037m\n";
    cout << characterName << " will have \033[032m" << characterHPValue << " HP\n\033[037m";
    PlaySound(TEXT("inicio.wav"), NULL, SND_FILENAME);

    system("pause");
    system("cls");
    while ((boss1HPValue > 0 || boss2HPValue > 0) && characterHPValue > 0) {

        /*Main Game*/
        //ATK Declaration
        characterAtackValuePunch1 = rand() % 251 + 150;
        characterAtackValuePunch2 = rand() % 251 + 150;
        characterAtackValueMagic = rand() % 901 + 150;
        characterAtackValueSword = rand() % 200 + 550;
        boss1AtackValue = rand() % 325 + 75;
        boss2AtackValue = rand() % 400 + 100;
        /*variables de vida 0
        if (boss1HPValue < 0) {
            boss1HPValue = 0;
        }
        if (boss2HPValue < 0) {
            boss2HPValue = 0;
        }
        if (characterHPValue < 0) {
            characterHPValue = 0;
        }*/
        cout << "select the boss you want to attack:\n";
            if (boss1HPValue>0)
            {
                cout <<" 1-- > " << boss1Name<<"\n";
            }
            if (boss2HPValue > 0)
            {
                cout << " 2-- > " << boss2Name<<"\n";
            }
            
        cin >> bossNumber;
       
        system("cls");
        if (bossNumber == 1)
        {
            if (boss1HPValue == 0)
            {
                cout << "This BOSS is DEAD";
            }
            cout << "Select an attack to fight against " << boss1Name << ": \n 1-->\033[036m Fire Ball\033[037m \n 2--> \033[036mSword Attack\033[037m\n 3--> \033[036mPunch Attack\033[037m\n";
            cin >> selectAttack;
            system("cls");
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
                cout << "Now your mana is lower and you have " << manacounter << " attacks with "<< manaAttack <<"\n";
                system("pause");
                system("cls");
            }
            else if (selectAttack == 2 )
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
            else {
                cout << "You don't have mana or you have select a wrong Attack-----------　　YOU FLINT!!!! \n";

                system("pause");
                system("cls");
            }
        }
        else if (bossNumber == 2)
        {
            if (boss2HPValue == 0)
            {
                cout << "This BOSS is DEAD";
            }
            cout << "Select an attack to fight against "<< boss2Name<< ": \n 1-->\033[036m Fire Ball\033[037m \n 2--> \033[036mSword Attack\033[037m\n 3--> \033[036mPunch Attack\033[037m\n";
            cin >> selectAttack;
        
            system("cls");
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
            else {
                cout << "You don't have mana or you have select a wrong Attack-----------　　YOU FLINT!!!! \n";
            }
        }
        if (boss1HPValue > 0 && characterHPValue > 0)
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
        }

    }
    if (characterHPValue > 0)
    {
        cout << "You have win against " << boss1Name << " and " << boss2Name;
        cout << "\n---------------\033[033mYOU WIN\033[037m---------------";
        PlaySound(TEXT("ganador.wav"), NULL, SND_FILENAME);

    }
    else if (boss1HPValue > 0 && boss2HPValue < 0)
    {
        cout << boss1Name << " have defeat you\n";
        cout << "---------------\033[031mDEFEAT\033[037m---------------";
        PlaySound(TEXT("muerto.wav"), NULL, SND_FILENAME);

    }
    else if (boss2HPValue > 0 && boss1HPValue < 0)
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


        



    


