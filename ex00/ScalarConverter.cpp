/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkroger <jkroger@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:41:04 by jkroger           #+#    #+#             */
/*   Updated: 2023/06/14 12:07:51 by jkroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "default constructor called" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter const &converter)
{
	std::cout << "copy constructor called" << std::endl;
	*this = converter;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "deconstructor called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &converter)
{
	if (this == &converter)
		return *this;
	std::cout << "copy assigment constructor called" << std::endl;
	return *this;
}

bool ScalarConverter::isPrintableChar(const std::string& str) {

	if (str.length() == 1)
		return (isprint(str[0]));
	if (isNumber(str)) {
		double d = stringToDouble(str);
		if (d >= 0 && d <= 127)
			return true;
		else
			return false;
	}
	return false;
}

bool ScalarConverter::isNumber(const std::string& str) {
	int length = str.length();
	for (std::size_t i = 0; i < length; ++i) {
		if (!isdigit(str[i])) {
			if (i == 0 && str[i] == '-')
				continue;
			else
				return false;
		}
	}
	return true;  // All characters are digits
}

bool ScalarConverter::isChar(const std::string& str) {
	if (str.empty())
		return false;
	if (isPrintableChar(str))
		return true;
	std::istringstream iss(str);
	char result;
	iss >> result;
	if (iss.fail()) {
		return false;
	}
	return true;
}

bool ScalarConverter::isInt(const std::string& str) {
	if (isPrintableChar(str))
		return true;
	std::istringstream iss(str);
	int result;
	iss >> result;
	if (iss.fail()) {
		return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string& str) {
	if (isPrintableChar(str))
		return true;
	std::istringstream iss(str);
	double result;
	iss >> result;
	if (iss.fail()) {
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
	if (isPrintableChar(str))
		return true;
	std::istringstream iss(str);
	float result;
	iss >> result;
	if (iss.fail()) {
		return false;
	}
	return true;
}








