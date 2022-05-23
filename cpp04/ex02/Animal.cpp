/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:39 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 17:27:15 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

// constructors
Animal::Animal(void)
{
	std::cout << "An animal has been created" << std::endl;
}


// copy constructor
Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << "An animal has been copied with a constructor" << std::endl;
}


// copy assignment
Animal& Animal::operator = (const Animal& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "An animal has been copied by assignment" << std::endl;
	return (*this);
}


// destructor
Animal::~Animal(void)
{
	std::cout << "An animal has been destroyed" << std::endl;
}

const std::string&	Animal::getType(void) const
{
	return (this->type);
}
