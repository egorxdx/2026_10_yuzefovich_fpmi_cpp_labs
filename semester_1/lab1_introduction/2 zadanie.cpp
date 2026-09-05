#include <iostream>

int main() {

	int n;
	std::cout << "vvedite kolichesto chisel" << std::endl;
	std::cin >> n;

	if (n <= 0) {
		std::cout << "nelza";
		return -1;
	}

	std::cout << "Summa naturalnih nechetnih chisel" << ' ';
	int sum = (((n+1) * n) / 2);
	std::cout << sum;
	return 0;
}