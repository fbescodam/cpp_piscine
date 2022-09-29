/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:17:20 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/29 13:53:23 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "scalar.hpp"

static enum::literal_e getLiteralType(const std::string& str)
{
	if (str.find_first_not_of("0123456789.f") != std::string::npos)
	{
		if (str.length() != 1)
		{
			std::cerr << "Error: too many characters in char input" << std::endl;
			exit(1);
		}
		return CHAR_L;
	}
	if (str.find_first_of(".") == std::string::npos)
		return INT_L;
	if (str.find_first_of("f") == std::string::npos)
		return DOUBLE_L;
	return FLOAT_L;
}

static void convert_char(char& c)
{
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << (int) c << std::endl;
	std::cout << "float: " << (float) c << std::endl;
	std::cout << "double: " << (double) c << std::endl;
}

static void convert_int(int& i)
{
	if (isprint((char) i))
		std::cout << "char: " << (char) i << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << (float) i << std::endl;
	std::cout << "double: " << (double) i << std::endl;
}

static void convert_float(float& f)
{
	if (isprint((char) f))
		std::cout << "char: " << (char) f << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << (int) f << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << (double) f << std::endl;
}

static void convert_double(double& d)
{
	if (isprint((char) d))
		std::cout << "char: " << (char) d << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << (int) d << std::endl;
	std::cout << "float: " << (float) d << std::endl;
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