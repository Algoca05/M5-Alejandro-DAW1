#include <iostream>
#include "MathLibrary.h"

using namespace std;
namespace MathLibrary
{
	int Aritmetica::sumar(int num1, int num2) {
		return num1 + num2;
	}
	int Aritmetica::restar(int num1, int num2) {
		return num1 - num2;
	}
	int Aritmetica::multiplicar(int num1, int num2) {
		return num1 * num2;
	}
	int Aritmetica::dividir(int num1, int num2) {
		return num1 / num2;
	}
}

