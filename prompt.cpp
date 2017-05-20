#include <iostream>

int main() {
	std::cout << "Are you sure?" << std::endl;
	std::cout << "1=Yes, 2=no ";
	int x = 0;
	std::cin >> x;
	std::cout << "You need to go number " << x << "?" << std::endl;
	return 0;
}
