#include <iostream>

int main() {
	int n, N;
	std::cout << "Vvedide kolichectvo dney" << std::endl;
	std::cin >> N;

	if ((N < 1) || (N > 99)) {
		std::cout << "2zn chislo";
		return -1;
	}

	std::cout << "vvedite den nedeli" << std::endl;
	std::cin >> n;

	if ((n < 1) || (n > 7)) {
		std::cout << "Ot 1 do 7";
		return -1;
	}

	for (int i = 1; i < n; i++) {
		std::cout << ' ' << ' ' << ' ';
	}

	/*  int a = 1;
		while(a < n) {
		std::cout << "   ";
		a += 1;
	}  */

	for (int i = 1; i <= N; i++) {
		if (i / 10 == 0) {
			std::cout << ' ' << ' ' << i;
		}
		else {
			std::cout << ' ' << i;
		}
		n += 1;
		if ((n - 1) % 7 == 0) {
			std::cout << std::endl;
		}
	}

	if ((n - 1) % 7 != 0) {
		std::cout << std::endl;
	}

	return 0;
}