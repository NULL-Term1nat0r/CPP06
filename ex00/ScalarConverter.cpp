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

bool ScalarConverter::isChar(std::string convert){
	if (isprint(std::stoi(convert)))
	{
		std::cout << "true !\n";
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(std::string convert){
	try{
		std::stoi(convert);
	}
	catch (const std::exception &e){
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat(std::string convert){
	try{
		std::stof(convert);
	}
	catch (const std::exception &e){
		return false;
	}
	return true;
}

bool ScalarConverter::isDouble(std::string convert){
	try{
		std::stod(convert);
	}
	catch (const std::exception &e){
		return false;
	}
	return true;
}

int ScalarConverter::convertType(std::string convert){
	if (isChar(convert))
	{
		std::cout << "hit !\n";
		return 1;
	}
	if (isInt(convert))
		return 2;
	if (isFloat(convert))
		return 3;
	if (isDouble(convert))
		return 4;
	return 0;
}

void ScalarConverter::printChar(std::string convert, int type){
	if (type == 1) {
		try {
			std::cout << "char: " << static_cast<char>(std::stoi(convert)) << std::endl;
		}
		catch (const std::invalid_argument &e) {
			std::cerr << convert[0] << std::endl;
		}
	}
	try {
		if (type == 2)
			std::cout << "char: "<< "impossible"<< std::endl;
		if (type == 3)
			std::cout << "char: "<< "impossible" << std::endl;
		if (type == 4)
			std::cout << "char: "<< "impossible"<< std::endl;
	}
	catch (const std::exception &e){
		std::cerr << "char: impossible" << std::endl;
	}
}

void ScalarConverter::printInt(std::string convert, int type){
	if (type == 2)
		std::cout << "int: "<< std::stoi(convert) << std::endl;
	try {
		if (type == 1)
			std::cout << "int: "<< static_cast<int>(convert[0])<< std::endl;
		if (type == 3)
			std::cout << "int: "<< static_cast<int>(std::stof(convert))<< std::endl;
		if (type == 4)
			std::cout << "int: "<< static_cast<int>(std::stod(convert))<< std::endl;
	}
	catch (const std::exception &e){
		std::cerr << "int: impossible" << std::endl;
	}
}

void ScalarConverter::printFloat(std::string convert, int type){
	if (type == 3)
		std::cout << "float: "<< std::stof(convert) << std::endl;
	try {
		if (type == 1)
			std::cout << "float: "<< static_cast<float>(convert[0])<< std::endl;
		if (type == 2)
			std::cout << "float: "<< static_cast<float>(std::stoi(convert))<< std::endl;
		if (type == 4)
			std::cout << "float: "<< static_cast<float>(std::stod(convert))<< std::endl;
	}
	catch (const std::exception &e){
		std::cerr << "float: impossible" << std::endl;
	}
}

void ScalarConverter::printDouble(std::string convert, int type){
	if (type == 4)
		std::cout << "double: "<< std::stod(convert) << std::endl;
	try {
		if (type == 1)
			std::cout << "double: "<< static_cast<double>(convert[0])<< std::endl;
		if (type == 2)
			std::cout << "double: "<< static_cast<double>(std::stoi(convert))<< std::endl;
		if (type == 3)
			std::cout << "double: "<< static_cast<double>(std::stof(convert))<< std::endl;
	}
	catch (const std::exception &e){
		std::cerr << "double: impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string input) {
	int type = convertType(input);
	printChar(input, type);
	printInt(input, type);
	printFloat(input, type);
	printDouble(input, type);
}


