#include <iostream>

int main() {
	long long a, b, m, n, k, sum;
	std::cout << "Vvedite a i b, gde a > 3; a < b" << std::endl;
	std::cin >> a >> b;

	if ((a < 4) || (a > b)) {
		std::cout << "Ne podhodit pod uslovie";
		return -1;
	}

	std::cout << "Chisla Kaprekara" << std::endl;
	for (long long i = a; i <= b; i++) {
		k = 10;
		n = i * i;
		while (n) {
			n = i * i;
			m = n % k;
			n = n / k;
			sum = m + n;
			k *= 10;
			if ((sum == i) && (m != 0)) {
				std::cout << i << ' ';
				break;
			}
		}
	}
	return 0;
}