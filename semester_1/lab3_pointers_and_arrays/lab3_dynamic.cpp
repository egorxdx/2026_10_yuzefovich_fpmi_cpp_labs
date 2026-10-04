#include <iostream>
#include <random>

//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std
//include namespace std

void create_xvect(int* arr, int n, int ran, int min, int max, std::mt19937& gen);
void create_yvect(int* arr, int n, int ran, int min, int max, std::mt19937& gen);
void create_zvect(int* xvect, int* yvect, double* zvect, int n, double scMult);
void print_zvect(double* arr, int n);

int main() {
	//razmer massiva
	int n;
	std::cout << "Vvedite chislo elementov massiva\n";
	std::cin >> n;

	if (n < 0) {
		std::cout << "?";
		std::exit(-1);
	}

	//random ili net
	int ran;
	std::cout << "Vvedite 0 dlya sozdaniya massiva vruchnuyu\n";
	std::cin >> ran;

	//min i max elementi
	int min = 1;
	int max = 1;
	if (ran != 0) {
		std::cout << "Vvedite min i max element\n";
		std::cin >> min >> max;
	}

	//randomizer
	std::random_device rd;
	std::mt19937 gen(rd());
	
	//massivi
	int* xvect = new int[n] {};
	int* yvect = new int[n] {};
	double* zvect = new double[n] {};

	//sozdanie x vectora
	std::cout << "x vector\n";
	create_xvect(xvect, n, ran, min, max, gen);

	//sozdanie y vectora
	std::cout << "y vextor\n";
	create_yvect(yvect, n, ran, min, max, gen);

	//scalyarnoe proizvedenie
	double scMult = 0;
	for (int i = 0; i < n; i++) {
		scMult += xvect[i] * yvect[i];
	}

	//sozdanie z vectora
	create_zvect(xvect, yvect, zvect, n, scMult);
	std::cout << "z vector\n";
	print_zvect(zvect, n);

	//otchistka pamyati
	delete[] xvect;
	delete[] yvect;
	delete[] zvect;
	
	return 0;
}



void create_xvect(int* arr, int n, int ran, int min, int max, std::mt19937& gen) {
	for (int i = 0; i < n; i++) {
		if (ran == 0) {
			std::cin >> arr[i];
		}
		else {
			std::uniform_int_distribution<int> dist(min, max);
			arr[i] = dist(gen);
			std::cout << arr[i] << ' ';
		}
	}
	std::cout << std::endl;
}

void create_yvect(int* arr, int n, int ran, int min, int max, std::mt19937& gen) {
	for (int i = 0; i < n; i++) {
		if (ran == 0) {
			std::cin >> arr[i];
		}
		else {
			std::uniform_int_distribution<int> dist(min, max);
			arr[i] = dist(gen);
			std::cout << arr[i] << ' ';
		}
	}
	std::cout << std::endl;
}

void create_zvect(int* xvect, int* yvect, double* zvect, int n, double scMult) {
	for (int i = 0; i < n; i++) {
		zvect[i] = sqrt((xvect[i] * xvect[i]) + (yvect[i] * yvect[i])) / scMult;
	}
}

void print_zvect(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
}