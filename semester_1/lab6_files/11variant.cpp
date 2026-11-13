#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <locale>
#include <chrono>

std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4996)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    return is_utc_format
        ? std::put_time(std::gmtime(&time), "%x %X")
        : std::put_time(std::localtime(&time), "%x %X");

#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
}

void write_log(std::ofstream& log, const std::string& msg) {
	if (!log.is_open()) throw "Log is closed";
	log << FormatTime(Now(), false) << " | " << msg << "\n";
}

bool IsEmptyFile(std::ifstream& fin) {
	return fin.peek() == std::ifstream::traits_type::eof();
}

bool prime(std::string num) {
	int number = std::stoi(num);
	if (number == 3 || number == 2) return true;
	if (number <= 1 || number % 2 == 0 || number % 3 == 0) return false;
	int i = 5;
	while (i * i <= number) {
		if (number % i == 0) {
			return false;
		}
		i++;
	}
	return true;
}

std::string find_prime(std::string& text, const std::string& chisla, std::ofstream& log) {
	write_log(log, "finding prime numbers in line");
	
	std::string::size_type begin = text.find_first_of(chisla, 0);
	std::string::size_type end = text.find_first_not_of(chisla, begin);

	std::string num;
	std::string str;

	while (begin != std::string::npos) {
		num = text.substr(begin, end - begin);
		if (!num.empty()) {
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
	
	if (!str.empty()) {
		write_log(log, "numbers found " + str);
	}
	else {
		write_log(log, "numbers not found ");
	}

	return text;
}

std::vector<std::string> ReadLinesFromFile(const std::string& filename, std::ofstream& log) {
	write_log(log, "opening file \"" + filename + "\"");
	std::ifstream fin{ filename };

	if (!fin.is_open()) {
		throw "Error: could not open file \"" + filename + "\"!!!";
	}

	write_log(log, "file \"" + filename + "\" has been opened successfully");

	if (IsEmptyFile(fin)) {
		throw "Error: file \"" + filename + "\" is empty";
	}

	write_log(log, "reading lines from \"" + filename + "\"");
	std::vector<std::string> lines;
	std::string line;
	while (std::getline(fin, line)) {
		write_log(log, "got line: \"" + line + "\"");
		lines.push_back(line);
	}

	return lines;

}

void WriteLinesToFile(const std::string& filename, const std::vector<std::string>& lines, std::ofstream& log) {
	write_log(log, "opening file \"" + filename + "\"");
	std::ofstream fout(filename);

	if (!fout.is_open()) {
		throw "Error: could not open file \"" + filename + "\"!!!";
	}

	write_log(log, "file \"" + filename + "\" has been opened successfully");

	write_log(log, "writing lines to \"" + filename + "\"");
	for (auto line : lines) {
		fout << line << std::endl;
	}

	fout.close();
}

int main() {
	std::ofstream log("log.txt");
	if (!log.is_open()) {
		std::cout << "Error: cannot create log.txt\n";
		return -32;
	}

	write_log(log, "program started");

	std::string chisla = "0123456789";

	const std::string input_filename = "input.txt";
	const std::string output_filename = "output.txt";

	try {
		std::vector<std::string> lines = ReadLinesFromFile(input_filename, log);

		for (auto& line : lines) {
			line = find_prime(line, chisla, log);
		}

		WriteLinesToFile(output_filename, lines, log);

		write_log(log, "program has ended with code 0");
		log.close();
	}
	catch(const std::string& msg) {
		std::cout << msg << std::endl;
		write_log(log, msg);
		write_log(log, "program has ended with code 123");
		log.close();
		return 123;
	}

	return 0;
}
