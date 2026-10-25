#include <iostream>
#include <string>

bool prime(std::string num) {
	int number = std::stoi(num);
	if (number == 3 || number == 2) return true;
	if (number == 1 || number % 2 == 0 || number % 3 == 0) return false;
	int i = 5;
	while(i * i <= number) {
		if (number % i == 0) {
			return false;
		}
		i++;
	}
	return true;
}

void find_prime(std::string& text, const std::string& chisla) {
	std::string::size_type begin = text.find_first_of(chisla, 0);
	std::string::size_type end = text.find_first_not_of(chisla, begin);

	std::string num;
	std::string str;

	while (begin != std::string::npos) {
		num = text.substr(begin, end - begin);
		if(!num.empty()) {
			if (prime(num) == 0) {
				begin = text.find_first_of(chisla, end);
				end = text.find_first_not_of(chisla, begin);
			}
			else {
				str = str + num + " ";
				text.erase(begin, end - begin);

				begin = text.find_first_of(chisla, begin);
				end = text.find_first_not_of(chisla, begin);
			}

		}
	}
	text.insert(0, str);
}


int main() {
	std::string text;
	std::cout << "Enter string with prime numbers\n";
	std::getline(std::cin, text);

	std::string chisla = "0123456789";

	find_prime(text, chisla);
	std::cout << "New string\n" << text;

	return 0;
}