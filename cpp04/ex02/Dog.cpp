/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:39 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 17:38:36 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

// constructors
Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "A dog has been created" << std::endl;
}


// copy constructor
Dog::Dog(const Dog& other)
{
	this->type = other.type;
	std::cout << "A dog has been copied with a constructor" << std::endl;
}


// copy assignment
Dog& Dog::operator = (const Dog& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "A dog has been copied by assignment" << std::endl;
	return (*this);
}


// destructor
Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "A dog has been destroyed" << std::endl;
}


// methods
void	Dog::makeSound(void)
{
	std::cout << "woof." << std::endl;
}
