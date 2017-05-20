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
	std::cout << "Enter the first number: ";
	int g = 0;
	int h = 0;
	std::cin >> g;
	std::cout << "Enter the second number: ";
	std::cin >> h;
	std::cout << "+--------------------------------+" << std::endl;
	std::cout << "|             " << add(g, h) << " Is +           |" << std::endl << "|             " << subtract(g, h) << " Is -           |" << std::endl <<  "|             " << multiply(g, h) << " Is *           |" << std::endl << "|             " << divide(g, h) << " Is /           |" << std::endl;
	std::cout << "+--------------------------------+" << std::endl;
}
