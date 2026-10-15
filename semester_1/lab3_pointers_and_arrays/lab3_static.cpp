#include <iostream>
#include <random>

void create_vect(int* arr, int i, int ran, int min, int max, std::mt19937& gen);
void print(int* arr, int n);
void find_zvect(int* xvect, int* yvect, double* zvect, int i, int scMult);
void print_zvect(double* arr, int n);

int main() {

	//dlina massiva
	const int MaxLength = 10000;
	int n;
	std::cout << "Vvedite kolichestvo koordinat vectora\n";
	std::cin >> n;
	if (!(n > 0)) {
		std::cout << "n<0???";
		std::exit(-1);
	}

	//random ili net
	int ran;
	std::cout << "Vvedite 0 chtobi samomu sozdat massiv ili luboe drugoe chislo chtobi randomizirovat\n";
	std::cin >> ran;

	//genereator randomnih chisel
	std::mt19937 gen(346345);

	//min i max znacheniya
	int min = 1, max = 1;
	if (ran != 0) {
		std::cout << "Min i max elem\n";
		if (!(std::cin >> min >> max) || min > max) {
			std::cout << "?";
			std::exit(-1);
		}
	}

	//massivi
	int xvect[MaxLength]{};
	int yvect[MaxLength]{};
	double zvect[MaxLength]{};

	//zadanie massivov
	std::cout << "x vector\n";
	create_vect(xvect, n, ran, min, max, gen);
	if (ran != 0) print(xvect, n);
	
	std::cout << "y vector\n";
	create_vect(yvect, n, ran, min, max, gen);
	if (ran != 0) print(yvect, n);

	//nahozdenie scalyarnogo proizvedeniya
	int scMult = 0;
	for (int i = 0; i < n; i++) {
		scMult += xvect[i] * yvect[i];
	}

	//nahozdenie z vectora
	find_zvect(xvect, yvect, zvect, n, scMult);
	

	//vivod z vectora
	std::cout << "z vector\n";
	print_zvect(zvect, n);

	return 0;
}

void create_vect(int* arr, int n, int ran, int min, int max, std::mt19937& gen) {
	for (int i = 0; i < n; i++) {
		if (ran == 0) {
			std::cin >> arr[i];

		}
		else {
			std::uniform_int_distribution<int> dist(min, max);
			arr[i] = dist(gen);
		}
	}
}


void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void find_zvect(int* xvect, int* yvect, double* zvect, int n, int scMult) {
	for (int i = 0; i < n; i++) {
		zvect[i] = sqrt((xvect[i] * xvect[i]) + (yvect[i] * yvect[i])) / (1.0 * scMult);
	}
}

void print_zvect(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
}
