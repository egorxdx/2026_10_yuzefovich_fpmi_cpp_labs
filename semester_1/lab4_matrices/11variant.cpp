#include <iostream>
#include <random>
#include <iomanip>

void create_matr(int** matr, int n, int m, int ran);
void print(int** matr, int n, int rowInd, int m, int colInd);
void maxHistogram(int** matr, int n, int m);

int main() {
	
	int n, m;
	std::cout << "Vvedite kolichestvo strok (n) i stobcov (m)\n";
	if (!(std::cin >> n >> m) || n <= 0 || m <= 0) {
		std::cout << "Vvedite normalniy razmer";
		std::exit(-1);
	}

	int ran;
	std::cout << "Vvedite 0 dlya zadaniya matrici vruchnuyu\n";
	std::cin >> ran;

	int** matr = new int* [n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[m];
	}

	create_matr(matr, n, m, ran);
	if (ran != 0) {
		std::cout << "matrix\n";
		print(matr, n, 0, m, 0);
	}

	maxHistogram(matr, n, m);


	for (int i = 0; i < n; i++) {
		delete[] matr[i];
	}
	delete[] matr;
	return 0;
}

void create_matr(int** matr, int n, int m, int ran) {
	if (ran == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cin >> matr[i][j];
			}
		}
	}
	else {
		//min i max elem
		int min, max;
		std::cout << "Vvedite min i max elem\n";
		if (!(std::cin >> min >> max) || min > max) {
			std::cout << "?";
			std::exit(-2);
		}

		//randomizer
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(min, max);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matr[i][j] = dist(gen);
			}
		}
	}
}

void print(int** matr, int n, int rowInd, int m, int colInd) {
	for (int i = rowInd; i < n; i++) {
		for (int j = colInd; j < m; j++) {
			std::cout << std::setw(3) << matr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void maxHistogram(int** matr, int n, int m) {
	int max_area = 0; //max histogram
	int max_height = 0;
	int max_width = 0;
	int best_r = -1; // koord stroki elem 
	int best_q = -1; // koord stobca elem

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matr[i][j] > 0) {
				int max_length = m - j;

				// nahojdenie plochadi max histogrami
				for (int r = 1; r + i - 1 < n; r++) { // prohodka po strokam
					
					// nahojdenie max width
					int q = 0;
					while ((q < max_length) && (matr[r + i - 1][q + j] > 0)) {
						q++;
					}
					
					max_length = q;
					if (max_length == 0) break;

					int area = r * q;

					if (area > max_area) {
						max_area = area;
						max_height = r;
						max_width = q;
						best_r = i;
						best_q = j;
					}
				}
			}
		}
	}
	if (max_area == 0) {
		std::cout << "Vse elem <0";
		std::exit(0);
	}
	else {
		std::cout << "Razmer matrici: " << max_height << ' ' << max_width << std::endl;
		std::cout << "Koord levogo verhnego elem: " << best_r << ' ' << best_q << std::endl;
		std::cout << "Matrica P\n";
		print(matr, best_r + max_height, best_r, best_q + max_width, best_q);
	}
}
