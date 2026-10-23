#include <iostream>
#include <random>

void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void create1(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

void create2(int* arr, int n, int min, int max, std::mt19937 gen) {
	std::uniform_int_distribution<int> dist(min, max);
	for (int i = 0; i < n; i++) {
		arr[i] = dist(gen);
	}
}

void func(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			arr[i] = 0;
		}
	}
}


int main() {
	int n;
	std::cout << "Number of elements\n";
	if (!(std::cin >> n) || n < 0){
		std::exit(-1);
	}

	int ran;
	std::cout << "if 0 random else not\n";
	std::cin >> ran;

	std::random_device rd;
	std::mt19937 gen(rd());

	int min = 0, max = 1;
	if (ran != 0) {
		std::cout << "min i max\n";
		if (!(std::cin >> min >> max) || min > max) std::exit(-2);
	}

	int* arr = new int[n];

	if (ran == 0) create1(arr, n);
	
	if (ran != 0) {
		create2(arr, n, min, max, gen);
		print(arr, n);
	}

	func(arr, n);
	print(arr, n);


	delete[] arr;
}