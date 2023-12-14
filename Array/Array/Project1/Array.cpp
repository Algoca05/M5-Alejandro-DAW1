#include <iostream>;

using namespace std;
int main() {

	int arrayNum[] = { 16,3,0,16,7,3 };

	string arrayNom[6] = { "Ramon","Alejandro","Javi","Pol"};
	int suma;

	for (size_t i = 0; i < sizeof(arrayNum)/sizeof(int); i++)
	{
		
		suma = arrayNum[i] + i;
		arrayNum[i] = suma;
			cout <<"Primera vuelta del array " <<suma << "\n";
			
	
	}
	for (size_t i = 0; i < sizeof(arrayNum) / sizeof(int); i++)
	{

		suma = arrayNum[i] + i;
		arrayNum[i] = suma;
		cout <<"Segunda vuelta del array "<< suma << "\n";
		

	}

}