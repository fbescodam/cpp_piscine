/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:17:16 by fbes          #+#    #+#                 */
/*   Updated: 2022/10/06 15:29:07 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"
#include <iostream>

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data		data;
	uintptr_t 	serialized;
	Data*		deserialized;

	data.content = 42;
	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Original content: " << data.content << std::endl;

	serialized = serialize(&data);
	std::cout << "Serialized address: " << serialized << std::endl;

	deserialized = deserialize(serialized);
	std::cout << "Deserialized pointer: " << deserialized << std::endl;
	std::cout << "Deserialized content: " << deserialized->content << std::endl;

	deserialized->content = 7;
	std::cout << "Original content after change: " << data.content << std::endl;
	std::cout << "Deserialized content after change: " << deserialized->content << std::endl;

	return (0);
}