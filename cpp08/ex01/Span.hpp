/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 11:22:11 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/11 12:24:30 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

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
					template <typename Container>
	void			addNumbers(const Container& container, typename Container::const_iterator begin, typename Container::const_iterator end);

	void			addNumbers(const int* begin, const int* end);
	void			addNumber(const int n);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;

private:
	// helper functions
	int*			cloneNumbers(void) const;

	// attributes
	unsigned int	size;
	unsigned int	used;
	int*			numbers;
};
