#include <iostream>

int add(int x,int y) {
	return x + y;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int c, int d) {
	return c * d;
}

int divide(int e, int f) {
	return e / f;
}

int main() {
	std::cout << "Enter the first number to add/subtract/multiply/divide: ";
	int g = 0;
	int h = 0;
	std::cin >> g;
	std::cout << "Enter the second number: ";
	std::cin >> h;
	std::cout << "+--------------------------------+" << std::endl;
	std::cout << g << " + " << h << " = " << add(g,h) << std::endl << g << " - " << h << " = " << subtract(g,h) << std::endl << g << " * " << h << " = " << multiply(g,h) << std::endl << g << " / " << h << " = " << divide(g,h) << std::endl;
	std::cout <<  "*answers are rounded down* " << std::endl << "+--------------------------------+" << std::endl << std::endl;
}
