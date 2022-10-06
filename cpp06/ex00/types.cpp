/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 16:11:01 by fbes          #+#    #+#                 */
/*   Updated: 2022/10/06 15:14:41 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "scalar.hpp"

static void invalidInput(void)
{
	std::cerr << "Error: invalid input" << std::endl;
	exit(1);
}

static literal_t checkReturnChar(const std::string& str)
{
	if (str.length() != 1)	// check for more than one character in input
		invalidInput();
	if (!isprint(str[0]))
		invalidInput();
	return CHAR_L;
}

static literal_t checkReturnInt(const std::string& str)
{
	long int	temp;
	
	if (str.find_first_not_of("-0123456789") != std::string::npos)
		invalidInput();
	if (str.find_first_of("-", 1) != std::string::npos)	// check if the minus character only appears at the first character
		invalidInput();
		
	temp = std::stol(str);
	if (temp < INT_MIN || temp > INT_MAX)	// check for overflow on input
		invalidInput();
	return INT_L;
}

static literal_t checkReturnFloat(const std::string& str)
{
	if (str.find_first_of(".") > str.find_first_of("f"))	// check if the f comes after the dot
		invalidInput();
	return FLOAT_L;
}

literal_t getLiteralType(const std::string& str)
{
	if (str.length() == 0)	// empty string
		invalidInput();
	
	if (str == "nan" || str == "NaN")	// edge case: NaN is a float
		return FLOAT_L;

	// char
	if (str.find_first_not_of("-0123456789.f") != std::string::npos	// check for non-numeric characters
		|| str == "-" || str == "f" || str == ".")	// edge case: single characters that also appear in numbers
		return checkReturnChar(str);
	
	// int
	if (str.find_first_of(".") == std::string::npos)	// it's an int if there are no decimals (no dot)
		return checkReturnInt(str);

	// double
	if (str.back() != 'f')	// it's a double if there is no f at the end of the string
		return DOUBLE_L;
	
	// float
	return checkReturnFloat(str);
}