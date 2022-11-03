/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 18:07:41 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/03 18:27:23 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "templates.hpp"

int main(void)
{
	int a = 42;
	int b = 10;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	swap<int>(a, b);
	std::cout << "swapped" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "min: "<< min<int>(a, b) << std::endl;
	std::cout << "max: "<< max<int>(a, b) << std::endl;
	std::cout << "equal min: "<< min<int>(12, 12) << std::endl;
	std::cout << "equal max: "<< max<int>(12, 12) << std::endl;
	return (0);
}
