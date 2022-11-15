/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:37:35 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/15 13:21:10 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>
#include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	// constructor
	MutantStack() {};

	// copy constructor (calls copy operator)
	MutantStack(const MutantStack& other) { *this = other; };

	// copy operator
	MutantStack& operator = (const MutantStack& other) {
		std::stack<T, Container>::c = other.c;
		return *this;
	};

	// deconstructor
	~MutantStack() {};

	// typedefs
	typedef typename Container::iterator iterator;

	// iterative functions
	iterator begin(void) { return std::begin(std::stack<T, Container>::c); }
	iterator end(void) { return std::end(std::stack<T, Container>::c); }
};
