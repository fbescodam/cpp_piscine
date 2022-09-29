/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:17:20 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/29 15:57:04 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "scalar.hpp"

static void invalidInput(void)
{
	std::cerr << "Error: invalid input" << std::endl;
	exit(1);
}

static literal_t getLiteralType(const std::string& str)
{
	if (str.length() == 0)	// empty string
		invalidInput();
	
	if (str == "nan" || str == "NaN")	// edge case: NaN is a float
		return FLOAT_L;

	// char
	if (str.find_first_not_of("-0123456789.f") != std::string::npos	// check for non-numeric characters
		|| str == "-" || str == "f" || str == ".")	// edge case: single characters that also appear in numbers
	{
		if (str.length() != 1)	// check for more than one character in input
			invalidInput();
		return CHAR_L;
	}
	
	// int
	if (str.find_first_of(".") == std::string::npos)	// it's an int if there are no decimals (no dot)
	{
		if (str.find_first_not_of("-0123456789") != std::string::npos)
			invalidInput();
		if (str.find_first_of("-", 1) != std::string::npos)	// check if the minus character only appears at the first character
			invalidInput();
		return INT_L;
	}

	// double
	if (str.back() != 'f')	// it's a double if there is no f at the end of the string
		return DOUBLE_L;
	
	// float
	if (str.find_first_of(".") > str.find_first_of("f"))	// check if the f comes after the dot
		invalidInput();
	return FLOAT_L;	// TODO: fix float input
}

static void convertChar(const char& c, output_t& out)
{
	out.c = c;
	out.c_overflows = false;
	out.i = static_cast<int>(c);
	out.i_overflows = false;
	out.f = static_cast<float>(c);
	out.d = static_cast<double>(c);
}

static void convertInt(const int& i, output_t& out)
{
	out.c = static_cast<char>(i);
	out.c_overflows = (i < CHAR_MIN || i > CHAR_MAX);
	out.i = i;
	out.i_overflows = false;
	out.f = static_cast<float>(i);
	out.d = static_cast<double>(i);
}

static void convertFloat(const float& f, output_t& out)
{
	out.c = static_cast<char>(f);
	out.c_overflows = (f < CHAR_MIN || f > CHAR_MAX);
	out.i = static_cast<int>(f);
	out.i_overflows = (f < INT_MIN || f > INT_MAX);
	out.f = f;
	out.d = static_cast<double>(f);
}

static void convertDouble(const double& d, output_t& out)
{
	out.c = static_cast<char>(d);
	out.c_overflows = (d < CHAR_MIN || d > CHAR_MAX);
	out.i = static_cast<int>(d);
	out.i_overflows = (d < INT_MIN || d > INT_MAX);
	out.f = static_cast<float>(d);
	out.d = d;
}

static void printOutput(const output_t& out)
{
	if (!isnan(out.f))
	{
		if (!out.c_overflows)
		{
			if (isprint(out.c))
				std::cout << "char: " << out.c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: overflows" << std::endl;
		if (!out.i_overflows)
			std::cout << "int: " << out.i << std::endl;
		else
			std::cout << "int: overflows" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << out.f << "f" << std::endl;
	std::cout << "double: " << out.d << std::endl;
}

int main(int argc, char** argv)
{
	std::stringstream	ss;
	input_t				in;
	literal_t			type;
	output_t			out;
	long int			temp;

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
				convertChar(argv[1][0], out);
				break;
			case INT_L:
				ss >> in.i;
				temp = std::stol(argv[1]);
				if (temp < INT_MIN || temp > INT_MAX)
					invalidInput();
				convertInt(in.i, out);
				break;
			case FLOAT_L:
				ss >> in.f;
				convertFloat(in.f, out);
				break;
			case DOUBLE_L:
				ss >> in.d;
				convertDouble(in.d, out);
				break;
		}
	}
	catch ( ... )
	{
		std::cerr << "Error: conversion failed" << std::endl;
		return (1);
	}

	printOutput(out);
	return (0);
}