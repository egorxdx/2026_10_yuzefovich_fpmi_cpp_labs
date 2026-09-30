#include <iostream>
#include <cmath>

int create_xvect(int* arr, int i, int ran);
int create_yvect(int* arr, int i, int ran);
void print_xvect(int* arr, int n);
void print_yvect(int* arr, int n);
int find_zvect(int* xvect, int* yvect, int* zvect, int i, int scMult);
void print_zvect(int* arr, int n);

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
	std::cout << "Vvedite 0 chtobi samomu sozdat massiv ili 1 chtobi randomizirovat\n";
	std::cin >> ran;
	if (!(ran == 0 && 1)) {
		std::cout << "Nauchis chitat";
		std::exit(-1);
	}

	int xvect[MaxLength]{};
	int yvect[MaxLength]{};
	int zvect[MaxLength]{};

	//zadanie massivov
	//esli vruchnuyu
	if (ran == 0) {
		std::cout << "Vvedite x vector\n";
		for (int i = 0; i < n; i++) {
			create_xvect(xvect, i, ran);
		}

		std::cout << "Vvedite y vector\n";
		for (int i = 0; i < n; i++) {
			create_yvect(yvect, i, ran);
		}
	}
	//esli random
	else {
		for (int i = 0; i < n; i++) {
			create_xvect(xvect, i, ran);
		}
		std::cout << "x vector\n";
		print_xvect(xvect, n);

		for (int i = 0; i < n; i++) {
			create_yvect(yvect, i, ran);
		}
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


}

int create_xvect(int* arr, int i, int ran) {
	if (ran == 0) {
		std::cin >> arr[i];
		return arr[i];
	}
	//else { randomizer tipo
		//break;
	//}
}
int create_yvect(int* arr, int i, int ran) {
	if (ran == 0) {
		std::cin >> arr[i];
		return arr[i];
	}
	//else { randomizer tipo
		//break;
	//}
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

int find_zvect(int* xvect, int* yvect, int* zvect, int i, int scMult) {
	zvect[i] = scMult / sqrt((xvect[i] * xvect[i]) + (yvect[i] * yvect[i]));
	return zvect[i];
}

void print_zvect(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
}
