#include <iostream>
#include "MathLibrary.h"

int main() {
	int a = 10;
	int b = 2;

    std::cout << "a + b = " <<
        MathLibrary::Aritmetica::sumar(a, b) << std::endl;
    std::cout << "a - b = " <<
        MathLibrary::Aritmetica::restar(a, b) << std::endl;
    std::cout << "a * b = " <<
        MathLibrary::Aritmetica::multiplicar(a, b) << std::endl;
    std::cout << "a / b = " <<
        MathLibrary::Aritmetica::dividir(a, b) << std::endl;





}