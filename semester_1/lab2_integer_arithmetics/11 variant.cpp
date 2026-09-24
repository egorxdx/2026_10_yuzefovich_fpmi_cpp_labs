#include <iostream>

int func(int);

int main() {
	int a, b;
	std::cout << "Vvedite a i b, gde a > 3; a < b" << std::endl;
	std::cin >> a >> b;
	
	if (!(a > 3 && a < b)) {
		std::cout << "Ne sootvetstvuet usloviu";
		return -1;
	}

	std::cout << "Chisla Kaprekara\n";
	for (int i = a; i <= b; i++) {
		if (func(i)) {
			std::cout << i << ' ';
		}
	}
	return 0;
}

int func(int c) {
	int m, n, k, sq;
	n = 1;
	k = 10;
	sq = c * c;
	while (n) {
		m = sq % k;
		n = sq / k;
		if ((m + n == c) && (m != 0)) {
			return c;
		}
		k *= 10;
	}
	return 0;
}


