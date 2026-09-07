#include <iostream>

int main() {

	int N;
	std::cout << "Enter amount of numbers" << std::endl;
	std::cin >> N;
	if (N < 0) {
		std::cout << "nelza";
		return -1;
	}

	int a = 0;
	int b = 1;
	int n = 1;

	std::cout << "Fibonacci Numbers" << std::endl;
	for (int i = 1; i < N; i += 2 ) {
		std::cout << a << ' ' << b << ' ';
		a = a + b;
		b = a + b;
		n = n + 2;
	}

	if (n == N) {
		std::cout << a;
	}

	return 0;
}