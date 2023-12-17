#include <iostream>
#include <cmath>
#include <sstream>

bool isPrintableChar(char c);
bool isNumber(const std::string& str);
void errorMessage(std::string &message);
double getNaN();


double stringToDouble(const std::string& str) {

	if (isPrintableChar(str[0]) && str.length() == 1) {
		if (std::isdigit(str[0]))
			return static_cast<double>(str[0] - '0');
		else
			return static_cast<double>(str[0]);
	 }
	 if (isNumber(str)) {
		char* endptr;
		double result = strtod(str.c_str(), &endptr);
		if (*endptr != '\0') {
			std::cerr << "Error: Invalid conversion to double." << std::endl;
		}
		return result;
	 }
	 return getNaN();
}

bool isNumber(const std::string& str) {
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[i] == '-') {
		++i;
	}
	for (; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool isPrintableChar(char c) {
	return isprint(c);
}

bool isChar(const std::string& str) {
	if (str.length() == 1 && isprint(str[0]))
		return true;
	return false;

}

void errorMessage(std::string &message){
	std::cout << message;
}

bool stringToInt(const std::string& str) {
    int result;
    std::istringstream iss(str);

    if (!(iss >> result))
		return false;
	return true;
}

union NaNUnion {
    unsigned long long nanLong;
    double nanDouble;
};

double getNaN() {
    NaNUnion nanUnion;
    nanUnion.nanLong = 0x7ff8000000000000ULL; // Bit pattern for NaN in IEEE 754 double precision
    return nanUnion.nanDouble;
}



int main(int argc, char **argv) {

	char *endptr;


	std::cout << "double: " << stringToDouble(argv[1]) << std::endl;
	//std::cout << "doubel_cast: " << static_cast<double>('a') << std::endl;
	//std::cout << "double test: " << strtod(argv[1], &endptr) << std::endl;
	//std::cout << "int_cast: " << stringToInt(argv[1]) << std::endl;
//	std::cout << "isChar: " << isChar(argv[1]) << std::endl;
	return 0;
}
