#include <iostream>
#include <random>
#include <iomanip>

void initial(int**& matr, int n, int m) {
	matr = new int* [n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int [m];
	}
}

void create1(int** matr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> matr[i][j];
		}
	}
}

void create2(int** matr, int n, int m) {
	std::cout << "Enter min i max\n";
	int min, max;
	if (!(std::cin >> min >> max) && min > max) std::exit(-234);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min, max);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matr[i][j] = dist(gen);
		}
	}
}

void print(int** matr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << std::setw(3) << matr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void print(int** matr, int i_ind, int p, int j_ind, int q) {
	for (int i = i_ind; i < i_ind + p; i++) {
		for (int j = j_ind; j < j_ind + q; j++) {
			std::cout << std::setw(3) << matr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void del(int** matr, int n) {
	for (int i = 0; i < n; i++) {
		delete[] matr[i];
	}
	delete[] matr;
}

void subMatr(int** matr, int n, int m) {
	int q_ind;
	int max_area = 0, area = 0;
	int length = 0, height = 0;
	int p = 0, q = 0;
	int i_ind = -1, j_ind = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int end = m - 1;

			for (int p_ind = i; p_ind < n; p_ind++) {
				if (matr[p_ind][j] <= 0) break;

				q_ind = j;
				while(q_ind <= end && matr[p_ind][q_ind] > 0) {
					q_ind++;
				}
				q_ind--;
				end = q_ind;

				height = p_ind - i + 1;
				length = q_ind - j + 1;
				area = length * height;

				if (area > max_area) {
					max_area = area;
					p = height;
					q = length;
					i_ind = i;
					j_ind = j;
				}
			}
		}
	}
	if (max_area == 0) {
		std::cout << "No positive elements";
	}
	else {
		std::cout << "Max submatrix\n" << "height " << p << std::endl
			<< "length " << q << std::endl
			<< "pos of first elem " << i_ind << ' ' << j_ind << std::endl
			<< "submatrix:\n";
		print(matr, i_ind, p, j_ind, q);
	}
}

int main() {
	int n, m;
	std::cout << "Enter size of matrix (n) >> (m)\n";
	if (!(std::cin >> n >> m) && n < 1 && m < 1) std::exit(-12);

	int ran;
	std::cout << "Enter 0 if not random\n";
	std::cin >> ran;

	int** matr;
	initial(matr, n, m);


	if (ran == 0) {
		std::cout << "Enter matrix\n";
		create1(matr, n, m);
	}
	else {
		create2(matr, n, m);
		std::cout << "Matrix\n";
		print(matr, n, m);
	}

	subMatr(matr, n, m);

	del(matr, n);
	return 0;
}