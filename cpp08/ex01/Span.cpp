/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 11:22:07 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/11 12:32:35 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iterator>
#include <algorithm>

// constructor
Span::Span(const unsigned int N)
{
	this->size = N;
	this->used = 0;
	this->numbers = new int[N];
}

// copy constructor
Span::Span(const Span& other)
{
	*this = other;
}

// copy assignment
Span& Span::operator=(const Span& other)
{
	this->size = other.size;
	this->numbers = new int[other.size];
	this->used = other.used;
	for (unsigned int i = 0; i < other.size; i++)
		this->numbers[i] = other.numbers[i];
	return (*this);
}

// destructor
Span::~Span(void)
{
	delete[] this->numbers;
}

// exceptions
const char*	Span::TooManyNumbersException::what(void) const _NOEXCEPT
{
	return ("Too many numbers in Span");
}
const char*	Span::TooFewNumbersException::what(void) const _NOEXCEPT
{
	return ("Too few numbers in Span");
}

// member functions
void Span::addNumber(const int n)
{
	if (this->used >= this->size)
		throw Span::TooManyNumbersException();
	this->numbers[this->used] = n;
	this->used++;
}

template <typename Container>
void Span::addNumbers(const Container& container, typename Container::const_iterator begin, typename Container::const_iterator end)
{
	typename Container::const_iterator it = begin;
	while (it != end)
	{
		this->addNumber(container.at(it));
		it++;
	}
}

void Span::addNumbers(const int* begin, const int* end)
{
	const int* it = begin;
	while (it != end)
	{
		this->addNumber(*it);
		it++;
	}
}

int* Span::cloneNumbers(void) const
{
	int* clone = new int[this->size];
	for (unsigned int i = 0; i < this->size; i++)
		clone[i] = this->numbers[i];
	return (clone);
}

unsigned int Span::shortestSpan(void) const
{
	if (this->used < 2)
		throw Span::TooFewNumbersException();

	// get a clone of the numbers and sort it
	int* clone = this->cloneNumbers();
	std::sort(clone, clone + this->used);

	// find the smallest span by comparing the absolute difference with i and i+1
	unsigned int smallestSpan = UINT_MAX;
	for (int* it = clone; it < clone + this->used - 1; it++)
	{
		unsigned int span = std::max(*it, *(it + 1)) - std::min(*it, *(it + 1));
		if (span < smallestSpan)
			smallestSpan = span;
	}

	// free the clone and return the smallest span
	delete[] clone;
	return (smallestSpan);
}

unsigned int Span::longestSpan(void) const
{
	if (this->used < 2)
		throw Span::TooFewNumbersException();

	// get a clone of the numbers and sort it
	int* clone = this->cloneNumbers();
	std::sort(clone, clone + this->used);

	// get the difference between the first and the last number
	int first = clone[0];
	int last = clone[this->used - 1];
	unsigned int span = std::max(first, last) - std::min(first, last);

	// free the clone and return the longest span
	delete[] clone;
	return (span);
}
