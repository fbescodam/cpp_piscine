/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 11:22:11 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/15 11:32:46 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <list>

class Span
{
public:
	// constructors
	Span(const unsigned int N);

	// copy constructor (calls copy operator)
	Span(const Span& other);

	// copy operator
	Span& operator = (const Span& other);

	// deconstructor
	~Span(void);

	// exceptions
	class TooManyNumbersException: public std::exception {
		public:
			const char*	what(void) const _NOEXCEPT;
	};
	class TooFewNumbersException: public std::exception {
		public:
			const char*	what(void) const _NOEXCEPT;
	};

	// member functions
	template <typename T>
	void			addNumbers(const T source, typename T::const_iterator start, typename T::const_iterator end);
	void 			addNumbers(const int* start, const int* end);
	void			addNumber(const int n);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;

private:
	// attributes
	unsigned int	size;
	std::list<int>	container;
};
