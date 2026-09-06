#include <iostream>

int main() {

	int a;
	std::cout << "Vvedite 4zn chislo" << std::endl;
	std::cin >> a;
	int b = 0;
	int c = a;

	if ((1000 > a) || (a > 9999)) {
		std::cout << "eto ne 4zn chislo";
		return -1;
	}

	while (a) {
		b = b * 10 + a % 10;
		a /= 10;
	}
	
	if (c == b) {
		std::cout << "Dannoe chislo - polindrom";
	}
	else {
		std::cout << "Dannoe chislo ne polindrom";
	}
	return 0;
}