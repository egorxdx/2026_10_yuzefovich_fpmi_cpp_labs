#include <iostream>

int main() {
	int a;
	std::cout << "Vvedite 6zn chislo" << std::endl;
	std::cin >> a;

	if ((100000 > a) || (a > 999999)) {
		std::cout << "eto ne 6zn chislo";
		return -1;
	}

	int b = a % 1000;
	a = a / 1000;
	int x = 0;

	while (a, b) {
		x = x + (a % 10 - b % 10);
		a /= 10;
		b /= 10;
	}

	if (x == 0) {
		std::cout << "It is a happy nubmer";
	}
	else {
		std::cout << "It is not a happy number";
	}

	return 0;
}