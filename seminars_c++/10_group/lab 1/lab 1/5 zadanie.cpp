#include <iostream>

int main() {

	int N;
	std::cout << "Enter number";
	std::cin >> N;
	if (N < 0) {
		std::cout << "nelza";
		return -1;
	}


	int fib[N] {};
	fib[0] = 0;
	fib[1] = 1;
	fib[i] = fib[i - 2] + fib[i - 1];


	std::cout << "Fibonacci Numbers" << std::endl;
	for (int i = 0; i <= N; i++) {
		std::cout << fib[i] << ' ';
	}
	return 0;
}