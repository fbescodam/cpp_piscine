/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 19:07:56 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/03 20:25:07 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void)
{
	// int
	try {
		Array<int> intArr(4);
		for (size_t i = 0; i < intArr.size(); i++) {
			intArr[i] = 2 * i;
		}
		for (size_t i = 0; i < intArr.size(); i++) {
			std::cout << "intArr[" << i << "]: " << intArr[i] << std::endl;
		}
		intArr[5] = 42;
	}
	catch (std::exception e) {
		std::cerr << "Index out of range exception caught" << std::endl;
	}
	std::cout << std::endl;

	// strings
	Array<std::string> strArr(5);
	for (size_t i = 0; i < strArr.size(); i++) {
		strArr[i] = "test " + std::to_string(i);
		std::cout << "strArr[" << i << "]: " << strArr[i] << std::endl;
	}
	std::cout << std::endl;

	// empty
	Array<std::string> emptyArr;
	std::cout << "Empty array size: " << emptyArr.size() << std::endl;

	// copy constructor
	emptyArr = strArr;
	std::cout << "Copied array size: " << emptyArr.size() << std::endl;
	for (size_t i = 0; i < emptyArr.size(); i++) {
		std::cout << "emptyArr[" << i << "]: " << emptyArr[i] << std::endl;
	}

	// system("leaks array");
	return (0);
}
