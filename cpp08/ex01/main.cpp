/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 11:22:04 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/11 14:08:23 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>

void basic(void)
{
	std::cout << "Test from the subject" << std::endl;
	Span sp = Span(5);
	// sp.addNumber(INT_MAX);
	// sp.addNumber(INT_MIN);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void minMaxInt(void)
{
	std::cout << std::endl << "Test with INT_MIN and INT_MAX" << std::endl;
	Span sp = Span(5);
	sp.addNumber(INT_MAX);
	sp.addNumber(INT_MIN);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void iterativeAdd(void) {
	std::cout << std::endl << "Iterative test with a big Span and random numbers" << std::endl;
	unsigned int testSize = 15000;
	Span spBig = Span(testSize);
	int* inputArrBig = new int[testSize];
	srand(time(nullptr));
	for (size_t i = 0; i < testSize; i++)
		inputArrBig[i] = rand();
	spBig.addNumbers(inputArrBig, inputArrBig + testSize);
	std::cout << spBig.shortestSpan() << std::endl;
	std::cout << spBig.longestSpan() << std::endl;
	delete[] inputArrBig;

	std::cout << std::endl << "Iterative test with a small Span, only 0" << std::endl;
	Span spSmall = Span(5);
	int test[] = {0, 0, 0, 0, 0};
	spSmall.addNumbers(std::begin(test), std::end(test));
	std::cout << spSmall.shortestSpan() << std::endl;
	std::cout << spSmall.longestSpan() << std::endl;
}

void breakIt(void)
{
	std::cout << std::endl << "Test with too few numbers: should fail" << std::endl;
	Span sp = Span(5);
	sp.addNumber(0);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main(void)
{
	try {
		basic();
		minMaxInt();
		iterativeAdd();
		breakIt();
	}
	catch ( Span::TooFewNumbersException e ) {
		std::cout << "Exception caught: " <<  e.what() << std::endl;
	}
	catch ( Span::TooManyNumbersException e ) {
		std::cout << "Exception caught: " <<  e.what() << std::endl;
	}
}
