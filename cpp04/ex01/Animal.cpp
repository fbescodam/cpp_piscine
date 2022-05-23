/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:39 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 17:19:31 by fbes          ########   odam.nl         */
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


// public methods
void	Animal::makeSound(void) const
{
	std::string		types[] = { "Cat", "Dog" };
	int				i;
	int				types_amount = sizeof(types) / sizeof(*types);

	for (i = 0; i < types_amount + 1; i++)
		if (i == types_amount || types[i] == this->type)
			break;

	switch (i)
	{
		case 0:
			std::cout << "Meow" << std::endl;
			break;
		case 1:
			std::cout << "Woof" << std::endl;
			break;
	}
}

const std::string&	Animal::getType(void) const
{
	return (this->type);
}
