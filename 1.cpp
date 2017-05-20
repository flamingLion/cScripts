# include <iostream>

int pee() {
	txt x = "";
	std::cout << "???";
	std::cin >> x;
	std::cout << x;
}

int poop() {
	std::cout << "poop... lel" << std::endl;
	return 0;
}

int main() {
	poop();
	pee();
	return 0;
}
