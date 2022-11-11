/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 10:26:25 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/11 11:19:25 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <list>
#include <iostream>

template <typename T>
void easyfindWrapper(T& container, int toFind)
{
	try {
		int found = easyfind(container, toFind);
		std::cout << "Found number " << found << " in container " << typeid(container).name() << std::endl;
	}
	catch ( ... ) {
		std::cerr << "Did not find number " << toFind << " in container " << typeid(container).name() << std::endl;
	}
}

int main(void)
{
	const size_t		s = 8;
	std::array<int, s>	arr;
	std::vector<int>	vect;
	std::list<int>		list;
	int					toFind;

	// populate std::array
	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = i * 4;

	// populate std::vector, std::list
	for (size_t i = 0; i < s; i++)
	{
		vect.push_back(i);
		list.push_back(i);
	}

	// find the numbers
	toFind = 5;
	easyfindWrapper(arr, toFind);
	easyfindWrapper(vect, toFind);
	easyfindWrapper(list, toFind);
}
