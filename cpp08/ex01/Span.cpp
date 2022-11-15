/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 11:22:07 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/15 11:33:35 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
// #include <iostream>

// constructor
Span::Span(const unsigned int N)
{
	this->size = N;
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
	this->addNumbers(other.container, other.container.begin(), other.container.end());
	return (*this);
}

// destructor
Span::~Span(void)
{

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
	if (this->container.size() > this->size)
		throw Span::TooManyNumbersException();
	this->container.push_back(n);
}

template <typename T>
void Span::addNumbers(const T source, typename T::const_iterator start, typename T::const_iterator end)
{
	unsigned long dist = static_cast<unsigned long>(std::distance(start, end));
	if (dist > (this->size - this->container.size()))
		throw Span::TooManyNumbersException();
	this->container.insert(this->container.end(), start, end);
	source.end(); // to make the compiler stop screaming about the unused source parameter
}

void Span::addNumbers(const int* start, const int* end)
{
	for (const int* it = start; it < end; it++)
		this->container.push_back(*it);
}

unsigned int Span::shortestSpan(void) const
{
	if (this->container.size() < 2)
		throw Span::TooFewNumbersException();

	std::list<int> clone(this->container);
	// std::sort(clone.begin(), clone.end());
	clone.sort();

	unsigned int smallestSpan = UINT_MAX;
	for (std::list<int>::iterator it = clone.begin(); it != clone.end(); it++)
	{
		std::list<int>::iterator nxt = std::next(it);
		if (nxt == clone.end())
			break;
		unsigned int span = std::max(*it, *nxt) - std::min(*it, *nxt);
		if (span < smallestSpan)
			smallestSpan = span;
	}
	return (smallestSpan);
}

unsigned int Span::longestSpan(void) const
{
	if (this->container.size() < 2)
		throw Span::TooFewNumbersException();

	std::list<int> clone(this->container);
	// std::sort(clone.begin(), clone.end());
	clone.sort();

	int first = clone.front();
	int last = clone.back();
	unsigned int span = std::max(first, last) - std::min(first, last);
	return (span);
}
