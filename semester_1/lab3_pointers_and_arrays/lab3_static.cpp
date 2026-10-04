#include <iostream>
#include <random>

void create_xvect(int* arr, int i, int ran, std::mt19937& gen);
void create_yvect(int* arr, int i, int ran, std::mt19937& gen);
void print_xvect(int* arr, int n);
void print_yvect(int* arr, int n);
double find_zvect(int* xvect, int* yvect, double* zvect, int i, int scMult);
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

	//massivi
	int xvect[MaxLength]{};
	int yvect[MaxLength]{};
	double zvect[MaxLength]{};

	//zadanie massivov
	//esli vruchnuyu
	if (ran == 0) {
		std::cout << "Vvedite x vector\n";
		create_xvect(xvect, n, ran, gen);

		std::cout << "Vvedite y vector\n";
		create_yvect(yvect, n, ran, gen);
	}
	//esli random
	else {
		create_xvect(xvect, n, ran, gen);
		std::cout << "x vector\n";
		print_xvect(xvect, n);

		create_yvect(yvect, n, ran, gen);
		std::cout << "y vector\n";
		print_yvect(yvect, n);
	}

	//nahozdenie scalyarnogo proizvedeniya
	int scMult = 0;
	for (int i = 0; i < n; i++) {
		scMult += xvect[i] * yvect[i];
	}

	//nahozdenie z vectora
	for (int i = 0; i < n; i++) {
		find_zvect(xvect, yvect, zvect, i, scMult);
	}

	//vivod z vectora
	std::cout << "z vector\n";
	print_zvect(zvect, n);

	return 0;
}

void create_xvect(int* arr, int n, int ran, std::mt19937& gen) {
	for (int i = 0; i < n; i++) {
		if (ran == 0) {
			std::cin >> arr[i];

		}
		else {
			std::uniform_int_distribution<int> dist(-50, 50);
			arr[i] = dist(gen);
		}
	}
}
void create_yvect(int* arr, int n, int ran, std::mt19937& gen) {
	for (int i = 0; i < n; i++) {
		if (ran == 0) {
			std::cin >> arr[i];

		}
		else {
			std::uniform_int_distribution<int> dist(-50, 50);
			arr[i] = dist(gen);
		}
	}
}

void print_xvect(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void print_yvect(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

double find_zvect(int* xvect, int* yvect, double* zvect, int i, int scMult) {
	zvect[i] = sqrt((xvect[i] * xvect[i]) + (yvect[i] * yvect[i])) / (1.0 * scMult);
	return zvect[i];
}

void print_zvect(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
}
