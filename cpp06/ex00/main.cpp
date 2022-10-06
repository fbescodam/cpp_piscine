/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:17:20 by fbes          #+#    #+#                 */
/*   Updated: 2022/10/06 15:11:46 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "scalar.hpp"



static void printOutput(const output_t& out)
{
	// char & int
	if (!isnan(out.f))
	{
		// char
		if (!out.c_overflows)
		{
			if (isprint(out.c))
				std::cout << "char: " << out.c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: overflows" << std::endl;
		
		// int
		if (!out.i_overflows)
			std::cout << "int: " << out.i << std::endl;
		else
			std::cout << "int: overflows" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
		
	// float & double (without scientific notation)
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << out.f << "f" << std::endl;
	std::cout << "double: " << out.d << std::endl;
}

int main(int argc, char** argv)
{
	std::stringstream	ss;
	std::string			str_in;
	input_t				in;
	literal_t			type;
	output_t			out;

	if (argc < 2)
	{
		std::cerr << "Error: missing parameter to convert" << std::endl;
		return (1);
	}

	str_in = argv[1];

	try {
		type = getLiteralType(str_in);
		if (type == FLOAT_L && str_in.back() == 'f')
			str_in.erase(str_in.end() - 1);	// remove the f from the input to ease float conversion
		ss << str_in;
		switch (type)
		{
			case CHAR_L:
				in.c = str_in[0];
				convertChar(in.c, out);
				break;
			case INT_L:
				ss >> in.i;
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