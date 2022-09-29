/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:17:20 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/29 14:34:08 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <sstream>
#include "scalar.hpp"

static void invalidInput(void)
{
	std::cerr << "Error: invalid input" << std::endl;
	exit(1);
}

static enum::literal_e getLiteralType(const std::string& str)
{
	if (str == "nan")
		return FLOAT_L;
	if (str.find_first_not_of("0123456789.f") != std::string::npos
		|| (str == "f" || str == "."))
	{
		if (str.length() != 1)
			invalidInput();
		return CHAR_L;
	}
	if (str.find_first_of(".") == std::string::npos)
	{
		if (str.find_first_not_of("0123456789") != std::string::npos)
			invalidInput();
		return INT_L;
	}
	if (str.find_first_of("f") == std::string::npos)
		return DOUBLE_L;
	if (str.find_first_of(".") > str.find_first_of("f"))
		invalidInput();
	return FLOAT_L;
}

static void convert_char(char& c)
{
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void convert_int(int& i)
{
	char c = static_cast<char>(i);
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void convert_float(float& f)
{
	if (std::isnan(f))
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(f);
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void convert_double(double& d)
{
	char c = static_cast<char>(d);
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

int main(int argc, char** argv)
{
	union input in;
	enum::literal_e type;
	std::stringstream ss;

	if (argc < 2)
	{
		std::cerr << "Error: missing parameter to convert" << std::endl;
		return (1);
	}

	try {
		type = getLiteralType(argv[1]);
		std::cout << "[DEBUG] Type: " << type << std::endl;
		ss << argv[1];
		switch (type)
		{
			case CHAR_L:
				ss >> in.c;
				convert_char(in.c);
				break;
			case INT_L:
				ss >> in.i;
				convert_int(in.i);
				break;
			case FLOAT_L:
				ss >> in.f;
				convert_float(in.f);
				break;
			case DOUBLE_L:
				ss >> in.d;
				convert_double(in.d);
				break;
		}
	}
	catch ( ... )
	{
		std::cerr << "Error: conversion failed" << std::endl;
		return (1);
	}
	return (0);
}