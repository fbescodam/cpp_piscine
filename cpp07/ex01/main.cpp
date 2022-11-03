/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 18:38:56 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/03 19:02:24 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void printt(T t)
{
	std::cout << t << ", ";
}

template <typename T>
void sett(T& t)
{
	static T setTo = 42;
	std::cout << "changing " << t << " to " << setTo << std::endl;
	t = setTo;
}

template <typename T>
void setstr(T& t)
{
	static T setTo = "it works";
	std::cout << "changing " << t << " to " << setTo << std::endl;
	t = setTo;
}

int main(void)
{
	const size_t len = 4;

	// integer
	std::array<int, len> test;
	for (size_t i = 0; i < len; i++)
		test[i] = i + 1;
	iter<int, len>(&test, len, &printt);
	std::cout << std::endl;

	// overwriting the integer
	iter<int, len>(&test, len, &sett);
	iter<int, len>(&test, len, &printt);
	std::cout << std::endl << std::endl;

	// character
	// also showcase the len is not required
	std::array<char, len> test2;
	iter<char>(&test2, len, &sett);
	iter<char>(&test2, len, &printt);
	std::cout << std::endl << std::endl;

	// strings
	// also showcase the template types are not required
	std::array<std::string, len> test3;
	for (size_t i = 0; i < len; i++)
		test3[i] = "test " + std::to_string(i);
	iter<>(&test3, len, &setstr);
	iter<>(&test3, len, &printt);
	std::cout << std::endl;
}
