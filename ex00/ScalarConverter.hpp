
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
# include <cctype>
# include <cstring>
# include <cmath>
#include <stdexcept>

class ScalarConverter
{
private:

	static char	_c;
	static int		_i;
	static float	_f;
	static double	_d;

	static void printChar(std::string convert);
	static void printInt(std::string convert);
//	void printInt(std::string convert);
	static void printFloat(std::string convert);
	static void printDouble(std::string convert);

	static bool isChar(std::string convert);
	static bool isInt(std::string convert);
	static bool isFloat(std::string convert);
	static bool isDouble(std::string convert);

	static void printChar(std::string convert, int type);
	static void printInt(std::string convert, int type);
	static void printFloat(std::string convert, int type);
	static void printDouble(std::string convert, int type);


public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &converter);
	~ScalarConverter();
	ScalarConverter	&operator=(ScalarConverter const &converter);

	static int convertType(std::string convert);
	static void convert(const std::string convert);

};

#endif