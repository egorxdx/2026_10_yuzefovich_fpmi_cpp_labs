#include <iostream>

int main() {

	int a, b, d;
	std::cout << "Vvedite a, b ,d" << std::endl;
	std::cin >> a >> b >> d;

	if ((a > b) || (d <= 0)) {
		std::cout << "a < b and d > 0";
		return -1;
	}

	std::cout << "chleni progressii, kratnie 3" << std::endl;
	
	for (int i = a; i <= b; i += d) {
		if (i % 3 == 0) {
			std::cout << i << ' ';
		}
	}


return 0;
}