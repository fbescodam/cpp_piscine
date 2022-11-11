/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 11:22:04 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/11 12:23:49 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void basic(void)
{
	Span sp = Span(5);
	sp.addNumber(INT_MAX);
	sp.addNumber(INT_MIN);
	// sp.addNumber(6);
	// sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main(void)
{
	basic();
}
