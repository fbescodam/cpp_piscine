/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Basic.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:18 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/11 11:27:12 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Basic.hpp"

// constructors
Basic::Basic(void)
{

}


// copy constructor
Basic::Basic(const Basic& other)
{
	*this = other;
}


// copy assignment
Basic& Basic::operator = (const Basic& other)
{
	if (this == &other)
		return (*this);
	// TODO: copy things over from other into this
	return (*this);
}


// destructor
Basic::~Basic(void)
{

}
