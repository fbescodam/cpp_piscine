/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:01:51 by fbes          #+#    #+#                 */
/*   Updated: 2022/08/25 20:15:33 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

// constructors
Brain::Brain(void)
{
	std::cout << "A brain has been created" << std::endl;
}


// copy constructor
Brain::Brain(const Brain& other)
{
	for (int i = 0; i < AMOUNT_OF_IDEAS; i++)
		this->ideas[i] = std::string(other.ideas[i]);
	std::cout << "A brain has been copied with a constructor" << std::endl;
}


// copy assignment
Brain& Brain::operator = (const Brain& other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < AMOUNT_OF_IDEAS; i++)
		this->ideas[i] = std::string(other.ideas[i]);
	std::cout << "A brain has been copied by assignment" << std::endl;
	return (*this);
}


// destructor
Brain::~Brain(void)
{
	std::cout << "A brain has been destroyed" << std::endl;
}
